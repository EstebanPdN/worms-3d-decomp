// Compara dos objetos XOM propiedad por propiedad, según su descriptor de tipo. Lo usa la agrupación de materiales: dos objetos del
// mismo tipo con los mismos valores valen por uno. Devuelve 0 si son iguales.
#include "native_common.h"

namespace {
// Iterador de deque de STLport con nodos de 128 B.
struct DequeIterator { Ptr32<w3d_u32> current, first, last; Ptr32<Ptr32<w3d_u32>> node; };
struct PointerDeque {
    DequeIterator start, finish;
    char map[0x10];
    w3d_u32 back() const {
        DequeIterator it = finish;
        if (it.current.v == it.first.v) {
            it.node.v -= 4;
            it.first = *it.node;
            it.current.v = it.first.v + 128;
        }
        return *at<w3d_u32>(it.current.v - 4);
    }
};
}
extern "C" { void A80353880(PointerDeque *deque, const w3d_u32 *value); void A8035366c(PointerDeque *deque); }
namespace {
void push_back(PointerDeque *deque, const w3d_u32 *value) {
    if (deque->finish.current.v != deque->finish.last.v - 4) {
        *deque->finish.current = *value;
        deque->finish.current.v += 4;
    } else {
        A80353880(deque, value);
    }
}
void pop_back(PointerDeque *deque) {
    if (deque->finish.current.v != deque->finish.first.v) deque->finish.current.v -= 4;
    else A8035366c(deque);
}
struct PropertyDescriptor { char pad[7]; uint8_t flags; w3d_u32 kind_data; };
const uint8_t kPropertyIsList = 1, kPropertySkipped = 4;
// Puntero a método de GCC 2.95 para leer la referencia.
struct Property {
    Ptr32<PropertyDescriptor> descriptor;
    w3d_u32 table;                // +4: tabla de la interfaz de acceso
    w3d_u32 pad;
    int16_t this_delta;           // +0xc
    int16_t virtual_index;        // +0xe
    union {
        int16_t table_field;      // +0x10, si es virtual
        w3d_u32 function;         // +0x10, si no
    };
};
struct DispatchTable { char pad[0x18]; };
struct XomObject { w3d_u32 table; char pad[2]; uint16_t kind; };
struct TypeDescriptor { char pad[0x3c]; Ptr32<void> properties, properties_end; };
struct Comparer {
    w3d_u32 table;
    char visitor[0x2c - 4];   // +4: base que reparte por tipo; su tabla de funciones por clase está en su +0x18
    w3d_u32 strict;           // +0x2c
    PointerDeque theirs;      // +0x30
    PointerDeque ours;        // +0x60
};
const int kKindObject = 24;
const int kDifferent = 1;

w3d_u32 read_reference(const Property *property, void *owner) {
    w3d_u32 function = property->function;
    if (property->virtual_index >= 0) {
        const w3d_u32 table = *(const w3d_u32 *)((const char *)owner + property->table_field);
        function = at<w3d_u32>(table)[property->virtual_index - 1];
    }
    return ((w3d_u32 (*)(void *))g2h(function))((char *)owner + property->this_delta);
}
int dispatch(Comparer *self, w3d_u32 object) {
    const w3d_u32 functions = *(w3d_u32 *)(self->visitor + 0x18);
    const w3d_u32 function = at<w3d_u32>(functions)[at<XomObject>(object)->kind];
    return ((int (*)(void *, void *))g2h(function))(self->visitor, g2h(object));
}
}
extern "C" {
w3d_u32 A801e9db8(void *type, w3d_u32 index);
int A801fffc8(w3d_u32 data);

// 0x801a7680: self es la segunda base del comparador. El caso "las dos referencias nulas" termina con 0 sin mirar más propiedades: así
// lo hace el original.
int A801a7680(Ptr32<char> self_base, Ptr32<void> ours) {
    Comparer *self = self_base ? (Comparer *)(self_base.get() - 4) : nullptr;
    const w3d_u32 theirs_address = self->theirs.back();
    void *theirs = g2h(theirs_address);
    const w3d_u32 type = call_virtual(ours.get(), 0x14);
    if (type != call_virtual(theirs, 0x14)) return kDifferent;
    TypeDescriptor *descriptor = at<TypeDescriptor>(type);
    const w3d_u32 count = (w3d_u32)((int)(descriptor->properties_end.v - descriptor->properties.v) >> 2);
    for (w3d_u32 p = 0; p < count; p++) {
        Property *property = at<Property>(A801e9db8(descriptor, p));
        const uint8_t flags = property->descriptor->flags;
        if (flags & kPropertySkipped) continue;
        if (A801fffc8(property->descriptor->kind_data) != kKindObject) {
            if (!call_in_table<int>(property, property->table, 0xc, ours.get(), theirs)) return kDifferent;
            continue;
        }
        if (flags & kPropertyIsList) {
            w3d_u32 our_count, their_count;
            const w3d_u32 *our_list = at<const w3d_u32>(call_in_table(property, property->table, 0x20, ours.get(), &our_count));
            const w3d_u32 *their_list = at<const w3d_u32>(call_in_table(property, property->table, 0x20, theirs, &their_count));
            if (our_count != their_count) return kDifferent;
            for (w3d_u32 i = 0; i < our_count; i++) {
                if (our_list[i] == their_list[i]) continue;
                if (self->strict == 1) return kDifferent;
                push_back(&self->ours, &our_list[i]);
                push_back(&self->theirs, &their_list[i]);
                if (const int result = dispatch(self, our_list[i])) return result;
                pop_back(&self->theirs);
                pop_back(&self->ours);
            }
            continue;
        }
        w3d_u32 our_value = read_reference(property, ours.get());
        const w3d_u32 their_value = read_reference(property, theirs);
        if (!our_value) return their_value ? kDifferent : 0;
        if (!their_value) return kDifferent;
        if (self->strict) {
            if (our_value != their_value) return kDifferent;
            continue;
        }
        push_back(&self->theirs, &their_value);
        push_back(&self->ours, &our_value);
        if (const int result = dispatch(self, our_value)) return result;
        pop_back(&self->theirs);
        pop_back(&self->ours);
    }
    return 0;
}
}
