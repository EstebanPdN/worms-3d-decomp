// Tipos que comparten muchas funciones del juego reescritas a mano: arrays XOM, objetos con contador de referencias, cadenas y vectores.
#ifndef W3D_NATIVE_GAME_H
#define W3D_NATIVE_GAME_H
#include "native_common.h"

extern "C" {
w3d_u32 A801ef048(void *reference, int count, int element, int mode);  // Devuelve los datos de un array con esa longitud, copiándolo si hace falta.
w3d_u32 A80212fd4(w3d_u32 bytes);
void A802134fc(void *block);
void A802eee50(void *to, const void *from, w3d_u32 bytes);
}

// Array XOM: cabecera de objeto, contador de referencias, longitud, cerrojos de escritura y datos en línea.
template <class T> struct XomArray {
    w3d_u32 table;
    uint16_t references;  // +4
    char pad[0x18 - 6];
    int count;            // +0x18
    uint16_t locks;       // +0x1c
    uint16_t pad2;
    T data[1];            // +0x20
};
// Acceso de escritura: sin copia si solo lo usa este objeto y la longitud ya es esa.
template <class T> inline T *lock_xom_array(Ptr32<XomArray<T>> &array, int count, int element, int mode) {
    if (array->references == 1 && array->count == count) {
        array->locks++;
        return array->data;
    }
    return at<T>(A801ef048(&array, count, element, mode));
}

// Contador de referencias de los objetos del motor: métodos virtuales 0xc (sumar) y 0x10 (restar).
inline void add_reference(void *object) { call_virtual<void>(object, 0xc); }
inline void release_reference(void *object) { call_virtual<void>(object, 0x10); }
inline void release_if_set(void *object) { if (object) release_reference(object); }
// Sustituye lo que apunta una referencia guardada.
template <class T> inline void assign_reference(Ptr32<T> &slot, T *object) {
    if (object) add_reference(object);
    release_if_set(slot.get());
    slot = object;
}

// Cadena de String: apunta al texto; delante, referencias en -6 y longitud en -4.
struct StringHeader { uint16_t references; uint16_t length; char pad[2]; char text[1]; };
struct GameString {
    Ptr32<char> text;
    StringHeader *header() const { return (StringHeader *)(text.get() - 6); }
    // Asignación por referencia: suma en la nueva y libera la anterior si era la última.
    void assign(const GameString &other);
};
extern "C" void A8020bb2c(void *header);
inline void GameString::assign(const GameString &other) {
    other.header()->references++;
    StringHeader *old = header();
    if (--old->references == 0) A8020bb2c(old);
    text = other.text;
}

// Vector del juego que crece de una forma particular: toma la medida en bytes como si fueran elementos, así que reserva de más.
template <class T> struct OddVector {
    Ptr32<T> begin, end, capacity;
    int size() const { return (int)(end.v - begin.v) / (int)sizeof(T); }
    void push_back(const T &value) {
        if (end.v == capacity.v) grow();
        *end = value;
        end.v += sizeof(T);
    }
    void grow() {
        const int used = (int)(end.v - begin.v);
        const int half = (int)((w3d_u32)used >> 1);
        const int wanted = used + 1 >= used + half ? used + 1 : used + half;
        const w3d_u32 bytes = (w3d_u32)(wanted * (int)sizeof(T));
        const w3d_u32 storage = A80212fd4(bytes);
        if (begin) {
            A802eee50(g2h(storage), begin.get(), bytes > (w3d_u32)used ? (w3d_u32)used : bytes);
            A802134fc(begin.get());
        }
        begin.v = storage;
        end.v = storage + used;
        capacity.v = storage + bytes;
    }
};
typedef OddVector<w3d_u32> WordVector;

// vector<u32> de STLport: {inicio, fin, asignador vacío, capacidad}, crece al doble (mínimo 1) y se mueve con memmove.
extern "C" {
void A802eeef4(void *to, const void *from, w3d_u32 bytes);
w3d_u32 A803413d8(w3d_u32 bytes);
}
struct StlWordVector {
    Ptr32<w3d_u32> begin, end;
    w3d_u32 allocator;
    Ptr32<w3d_u32> capacity;
    int size() const { return (int)(end.v - begin.v) >> 2; }
    void push_back(w3d_u32 value) {
        if (end.v != capacity.v) {
            *end = value;
            end.v += 4;
            return;
        }
        const w3d_u32 used = (w3d_u32)size();
        const w3d_u32 bytes = (used + (used < 1 ? 1 : used)) << 2;
        w3d_u32 storage = 0;
        if (bytes) {
            storage = A80212fd4(bytes);
            if (!storage) storage = A803413d8(bytes);
        }
        const w3d_u32 used_bytes = end.v - begin.v;
        if (used_bytes) A802eeef4(g2h(storage), begin.get(), used_bytes);
        *at<w3d_u32>(storage + used_bytes) = value;
        if (begin) A802134fc(begin.get());
        begin.v = storage;
        end.v = storage + used_bytes + 4;
        capacity.v = storage + bytes;
    }
};

// Cadena local: se construye vacía y se libera al salir.
extern "C" { void A803426b8(GameString *string); void A8020bb54(GameString *string, const char *text); void A80341588(GameString *string); }
struct ScopedString : GameString {
    ScopedString() { A803426b8(this); }
    explicit ScopedString(const char *from) { A8020bb54(this, from); }
    ~ScopedString() { A80341588(this); }
};

// Referencia a un recurso con su tipo: el original la construye con esa segunda palabra y la destruye con el método 0x40 del recurso.
struct ResourceRef {
    w3d_u32 object = 0, second = 0xe3a8;
};
extern "C" {
void A80341584();
w3d_u32 A80179598(void *found, ResourceRef *ref);
void A80178474(ResourceRef *ref, w3d_u32 how);
}
// El recurso que ha encontrado la búsqueda, con una referencia más para quien llama.
inline void *typed_resource(void *found, ResourceRef *ref) {
    A80341584();
    void *object = g2h(A80179598(found, ref));
    if (object) add_reference(object);
    return object;
}
#endif
