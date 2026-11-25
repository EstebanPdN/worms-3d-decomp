// Punteros del núcleo: 32 bits en memoria en todas las plataformas.
//
// GameCube y 3DS tienen punteros de 4 B; macOS arm64 de 8 B. Las estructuras del
// juego conservan la disposición de GameCube, así que un puntero guardado siempre
// ocupa 4 B. En macOS son los 32 bits bajos de la dirección real: el ejecutable,
// la arena del juego y las pilas viven en 0x1_0000_0000-0x1_FFFF_FFFF (macOS arm64
// rechaza mapear por debajo de 4 GB; ver docs/port-architecture.md). Así un puntero
// de 64 bits leído como w0 ya es el puntero guardado. En 3DS es el puntero real.
//
// Ptr32<T> es trivial a propósito: pasa y vuelve en un registro, igual que un int.
#ifndef W3D_PTR_H
#define W3D_PTR_H

// Sin cabeceras estándar: el núcleo se compila con su propia libc (core/libc).
typedef unsigned int w3d_u32;
typedef __UINTPTR_TYPE__ w3d_uptr;
namespace w3d {
template <bool B, class R = void> struct enable_if {};
template <class R> struct enable_if<true, R> { typedef R type; };
template <class T> struct is_void { static const bool value = false; };
template <> struct is_void<void> { static const bool value = true; };
template <> struct is_void<const void> { static const bool value = true; };
template <> struct is_void<volatile void> { static const bool value = true; };
template <> struct is_void<const volatile void> { static const bool value = true; };
template <class T> struct is_function { static const bool value = __is_function(T); };
template <class T> struct step_of { static const long value = sizeof(T); };
template <class R, class... A> struct step_of<R(A...)> { static const long value = 1; };
template <class R, class... A> struct step_of<R(A..., ...)> { static const long value = 1; };
template <> struct step_of<void> { static const long value = 1; };
template <> struct step_of<const void> { static const long value = 1; };
template <> struct step_of<volatile void> { static const long value = 1; };
template <> struct step_of<const volatile void> { static const long value = 1; };
}

#if defined(__LP64__)
#define W3D_POINTER_64 1
namespace w3d {
const w3d_uptr kWindow = (w3d_uptr)1 << 32;
inline w3d_u32 h2g(const volatile void *p) { return (w3d_u32)(w3d_uptr)p; }
inline void *g2h(w3d_u32 v) { return v ? (void *)(kWindow | v) : (void *)0; }
inline bool in_window(const volatile void *p) { return ((w3d_uptr)p >> 32) == 1; }
}
#else
#define W3D_POINTER_64 0
namespace w3d {
inline w3d_u32 h2g(const volatile void *p) { return (w3d_u32)(w3d_uptr)p; }
// Sin memoria baja real en 0x80000000: una dirección literal del juego va a su imagen. Sin coste si no es constante.
extern "C" char w3d_low_image[];
__attribute__((always_inline)) inline void *g2h(w3d_u32 v) {
    if (__builtin_constant_p(v) && v >= 0x80000000u && v < 0x80003100u) return w3d_low_image + (v - 0x80000000u);
    return (void *)(w3d_uptr)v;
}
}
#endif

namespace w3d {
template <class X, class = void> struct is_complete_ { static constexpr bool value = false; };
template <class X> struct is_complete_<X, decltype(void(sizeof(X)))> { static constexpr bool value = true; };
template <class To, class From> inline const volatile void *ptr_adjust(From *p) {
    using F = __remove_cv(From); using T = __remove_cv(To);
    if constexpr (__is_class(F) && __is_class(T) && !__is_same(F, T)) {
        if constexpr (is_complete_<F>::value && is_complete_<T>::value) {
            if constexpr (__is_base_of(T, F) || __is_base_of(F, T)) {
                return p ? static_cast<const volatile To *>(p) : nullptr;
            }
        }
    }
    return reinterpret_cast<const volatile void *>(p);
}
}
template <class T> struct Ptr32;

namespace w3d {
// Quita const/volatile de cualquier puntero, para las conversiones laxas de C.
template <class U> inline const volatile void *any_data(U *p) { return (const volatile void *)p; }
}

// Las unidades de C admiten int<->puntero sin cast, como el C original.
#ifdef W3D_LOOSE_C
#define W3D_C_EXPLICIT
#else
#define W3D_C_EXPLICIT explicit
#endif

// v34: accesores sin volatile (W3D_PTR_FAST, tools/lift/cc_core.sh). Con solo la forma "const volatile", -O2 deja cada
// puntero local y cada parámetro del juego en la pila (SROA no promueve variables con accesos volátiles); sin ella, el código
// del juego baja un 17 %. No va por defecto: el marco nuevo destapa errores del código traducido que la pila de antes tapaba
// (variables locales más pequeñas que lo que escribe quien las recibe, llamadas con menos argumentos de los que se leen) y en
// Azahar no se ve ganancia. Ver docs/port-3ds-estado.md (v34) antes de activarlo.
// Con W3D_PTR_FAST la conversión implícita a T * va en una base: para datos, sin volatile y volatile; para funciones solo la
// volatile (dos conversiones al mismo puntero a función harían ambigua p(args)). En el espacio global para no cambiar la
// búsqueda por argumentos (ADL); tools/relink/ir_inherit.py la salta como los demás accesores (SKIP_CALL).
#ifdef W3D_PTR_FAST
template <class D, class T, bool = w3d::is_function<T>::value> struct W3dPtr32Conv {
    operator T *() const { return reinterpret_cast<T *>(w3d::g2h(static_cast<const D *>(this)->v)); }
    operator T *() const volatile { return reinterpret_cast<T *>(w3d::g2h(static_cast<const volatile D *>(this)->v)); }
};
template <class D, class T> struct W3dPtr32Conv<D, T, true> {
    operator T *() const volatile { return reinterpret_cast<T *>(w3d::g2h(static_cast<const volatile D *>(this)->v)); }
};
#define W3D_PTR32_BASE : W3dPtr32Conv<Ptr32<T>, T>
#else
#define W3D_PTR32_BASE
#endif
template <class T> struct Ptr32 W3D_PTR32_BASE {
    w3d_u32 v;

    Ptr32() = default;
    Ptr32(const Ptr32 &) = default;
    Ptr32 &operator=(const Ptr32 &) = default;
    Ptr32(T *p) : v(w3d::h2g(reinterpret_cast<const volatile void *>(p))) {}
    // Entre clases emparentadas se ajusta el puntero: la herencia múltiple cambia la dirección. Sin parentesco, como un cast de C.
    template <class U> Ptr32(U *p) : v(w3d::h2g(reinterpret_cast<const volatile void *>(w3d::ptr_adjust<T>(p)))) {}
    template <class U> Ptr32(const Ptr32<U> &o) : v(o.v ? w3d::h2g(reinterpret_cast<const volatile void *>(w3d::ptr_adjust<T>(reinterpret_cast<U *>(w3d::g2h(o.v))))) : 0) {}
    template <class U> Ptr32(const volatile Ptr32<U> &o) : v(o.v ? w3d::h2g(reinterpret_cast<const volatile void *>(w3d::ptr_adjust<T>(reinterpret_cast<U *>(w3d::g2h(o.v))))) : 0) {}
    // Plantillas a propósito: una asignación de copia propia dejaría de ser trivial.
    template <class U> Ptr32 &operator=(const Ptr32<U> &o) { v = Ptr32(o).v; return *this; }
    template <class U> Ptr32 &operator=(const volatile Ptr32<U> &o) { v = Ptr32(o).v; return *this; }
    template <class U> Ptr32 &operator=(U *p) { v = Ptr32(p).v; return *this; }
    template <class U> void operator=(const Ptr32<U> &o) volatile { v = Ptr32(o).v; }
    template <class U> void operator=(const volatile Ptr32<U> &o) volatile { v = Ptr32(o).v; }
    template <class U> void operator=(U *p) volatile { v = w3d::h2g(reinterpret_cast<const volatile void *>(p)); }
    // Sin plantilla, para que el 0 literal tenga destino sin ambigüedad.
    Ptr32 &operator=(T *p) { v = w3d::h2g(reinterpret_cast<const volatile void *>(p)); return *this; }
    void operator=(T *p) volatile { v = w3d::h2g(reinterpret_cast<const volatile void *>(p)); }
    // Enteros: siempre explícitos; el 0 literal entra por Ptr32(T *).
    W3D_C_EXPLICIT Ptr32(int i) : v((w3d_u32)i) {}
    W3D_C_EXPLICIT Ptr32(unsigned i) : v(i) {}
    explicit Ptr32(short i) : v((w3d_u32)(int)i) {}
    explicit Ptr32(unsigned short i) : v(i) {}
    explicit Ptr32(unsigned char i) : v(i) {}
    explicit Ptr32(long i) : v((w3d_u32)i) {}
    explicit Ptr32(unsigned long i) : v((w3d_u32)i) {}
    explicit Ptr32(long long i) : v((w3d_u32)i) {}
    explicit Ptr32(unsigned long long i) : v((w3d_u32)i) {}

#ifdef W3D_PTR_FAST
    T *get() const { return reinterpret_cast<T *>(w3d::g2h(v)); }
    template <class U> explicit operator U *() const { return reinterpret_cast<U *>(w3d::g2h(v)); }
    T *operator->() const { return get(); }
    template <class U = T> typename w3d::enable_if<!w3d::is_void<U>::value && !w3d::is_function<U>::value, U &>::type operator*() const { return *get(); }
    explicit operator w3d_u32() const { return v; }
    W3D_C_EXPLICIT operator int() const { return (int)v; }
    explicit operator unsigned long() const { return v; }
    explicit operator long() const { return (long)(int)v; }
    explicit operator unsigned long long() const { return v; }
    explicit operator long long() const { return (long long)(int)v; }
    explicit operator unsigned short() const { return (unsigned short)v; }
    explicit operator short() const { return (short)v; }
    explicit operator unsigned char() const { return (unsigned char)v; }
    explicit operator signed char() const { return (signed char)v; }
    explicit operator char() const { return (char)v; }
    explicit operator bool() const { return v != 0; }
#endif
    T *get() const volatile { return reinterpret_cast<T *>(w3d::g2h(v)); }
#ifndef W3D_PTR_FAST
    operator T *() const volatile { return get(); }
#endif
    template <class U> explicit operator U *() const volatile { return reinterpret_cast<U *>(w3d::g2h(v)); }
    T *operator->() const volatile { return get(); }
    template <class U = T> typename w3d::enable_if<!w3d::is_void<U>::value && !w3d::is_function<U>::value, U &>::type operator*() const volatile { return *get(); }
    explicit operator w3d_u32() const volatile { return v; }
    W3D_C_EXPLICIT operator int() const volatile { return (int)v; }
    explicit operator unsigned long() const volatile { return v; }
    explicit operator long() const volatile { return (long)(int)v; }
    explicit operator unsigned long long() const volatile { return v; }
    explicit operator long long() const volatile { return (long long)(int)v; }
    explicit operator unsigned short() const volatile { return (unsigned short)v; }
    explicit operator short() const volatile { return (short)v; }
    explicit operator unsigned char() const volatile { return (unsigned char)v; }
    explicit operator signed char() const volatile { return (signed char)v; }
    explicit operator char() const volatile { return (char)v; }
    explicit operator bool() const volatile { return v != 0; }

    // Aritmética con el paso de T. Con T=void, paso 1 como la extensión GNU.
    static long step_() { return w3d::step_of<T>::value; }
    Ptr32 &operator++() { v += (w3d_u32)step_(); return *this; }
    Ptr32 operator++(int) { Ptr32 o = *this; v += (w3d_u32)step_(); return o; }
    Ptr32 &operator--() { v -= (w3d_u32)step_(); return *this; }
    Ptr32 operator--(int) { Ptr32 o = *this; v -= (w3d_u32)step_(); return o; }
    Ptr32 &operator+=(long n) { v += (w3d_u32)(n * step_()); return *this; }
    Ptr32 &operator-=(long n) { v -= (w3d_u32)(n * step_()); return *this; }
    template <class U> Ptr32 &operator-=(const Ptr32<U> &n) { v -= (w3d_u32)((long)(int)n.v * step_()); return *this; }
    template <class U> Ptr32 &operator+=(const Ptr32<U> &n) { v += (w3d_u32)((long)(int)n.v * step_()); return *this; }
    Ptr32 operator+(long n) const { Ptr32 r; r.v = v + (w3d_u32)(n * step_()); return r; }
    Ptr32 operator-(long n) const { Ptr32 r; r.v = v - (w3d_u32)(n * step_()); return r; }
    Ptr32 operator+(int n) const { return *this + (long)n; }
    Ptr32 operator-(int n) const { return *this - (long)n; }
    Ptr32 operator+(unsigned n) const { return *this + (long)n; }
    Ptr32 operator-(unsigned n) const { return *this - (long)n; }
    Ptr32 operator+(unsigned long n) const { return *this + (long)n; }
    Ptr32 operator-(unsigned long n) const { return *this - (long)n; }
    int operator-(const Ptr32 &o) const { return (int)((long)(int)(v - o.v) / step_()); }
    template <class U> int operator-(U *o) const { return (int)((long)(int)(v - w3d::h2g(o)) / step_()); }
};
// n + p: sin esto el entero se suma a la dirección convertida, en bytes y no en elementos.
template <class T> inline Ptr32<T> operator+(long n, const Ptr32<T> &p) { return p + n; }
template <class T> inline Ptr32<T> operator+(int n, const Ptr32<T> &p) { return p + (long)n; }
template <class T> inline Ptr32<T> operator+(unsigned n, const Ptr32<T> &p) { return p + (long)n; }
template <class T> inline Ptr32<T> operator+(unsigned long n, const Ptr32<T> &p) { return p + (long)n; }
template <class T> inline Ptr32<T> operator+(short n, const Ptr32<T> &p) { return p + (long)n; }
template <class T> inline Ptr32<T> operator+(unsigned short n, const Ptr32<T> &p) { return p + (long)n; }
template <class T> inline Ptr32<T> operator+(char n, const Ptr32<T> &p) { return p + (long)n; }
template <class T> inline Ptr32<T> operator+(unsigned char n, const Ptr32<T> &p) { return p + (long)n; }
// Comparaciones laxas como en C: entre Ptr32 de cualquier tipo y con punteros anfitrión.
template <class A, class B> inline bool operator==(const Ptr32<A> &a, const Ptr32<B> &b) { return a.v == b.v; }
template <class A, class B> inline bool operator!=(const Ptr32<A> &a, const Ptr32<B> &b) { return a.v != b.v; }
template <class A, class B> inline bool operator<(const Ptr32<A> &a, const Ptr32<B> &b) { return a.v < b.v; }
template <class A, class B> inline bool operator>(const Ptr32<A> &a, const Ptr32<B> &b) { return a.v > b.v; }
template <class A, class B> inline bool operator<=(const Ptr32<A> &a, const Ptr32<B> &b) { return a.v <= b.v; }
template <class A, class B> inline bool operator>=(const Ptr32<A> &a, const Ptr32<B> &b) { return a.v >= b.v; }
template <class A, class B> inline bool operator==(const Ptr32<A> &a, B *b) { return a.v == Ptr32<B>(b).v; }
template <class A, class B> inline bool operator!=(const Ptr32<A> &a, B *b) { return a.v != Ptr32<B>(b).v; }
template <class A, class B> inline bool operator==(B *b, const Ptr32<A> &a) { return a.v == Ptr32<B>(b).v; }
template <class A, class B> inline bool operator!=(B *b, const Ptr32<A> &a) { return a.v != Ptr32<B>(b).v; }
template <class A, class B> inline bool operator<(const Ptr32<A> &a, B *b) { return a.v < Ptr32<B>(b).v; }
template <class A, class B> inline bool operator>(const Ptr32<A> &a, B *b) { return a.v > Ptr32<B>(b).v; }
template <class A, class B> inline bool operator<=(const Ptr32<A> &a, B *b) { return a.v <= Ptr32<B>(b).v; }
template <class A, class B> inline bool operator>=(const Ptr32<A> &a, B *b) { return a.v >= Ptr32<B>(b).v; }
template <class A> inline bool operator==(const Ptr32<A> &a, decltype(nullptr)) { return a.v == 0; }
template <class A> inline bool operator!=(const Ptr32<A> &a, decltype(nullptr)) { return a.v != 0; }
static_assert(sizeof(Ptr32<int>) == 4, "Ptr32<T> debe ocupar 4 B");
static_assert(alignof(Ptr32<int>) == 4, "Ptr32<T> debe alinear a 4 B");

namespace w3d {
// new[] y delete[] de GCC 2.95: si el tipo tiene destructor, 8 B de cabecera con el número de elementos en la primera
// palabra. Clang usa otro formato, y las funciones traducidas y las M2C leen este.
// Retorno de un método virtual que en PPC devuelve una referencia: 32 bits en w0, convertible a la referencia real.
template <class T> struct Ref32 { w3d_u32 v; operator T &() const { return *(T *)g2h(v); } };
struct array_place_ {};
inline void *w3d_any_host(void *p) { return p; }
template <class T> inline void *w3d_any_host(const Ptr32<T> &p) { return (void *)p.get(); }
template <class T, class = void> struct array_new_ { static void *call(unsigned long n) { return ::operator new[](n); } };
template <class T> struct array_new_<T, decltype(void(T::operator new[](1ul)))> { static void *call(unsigned long n) { return (void *)w3d_any_host(T::operator new[](n)); } };
template <class T, class = void> struct array_delete_ { static void call(void *p) { ::operator delete[](p); } };
template <class T> struct array_delete_<T, decltype(void(T::operator delete[]((void *)0)))> { static void call(void *p) { T::operator delete[](p); } };
template <class T> inline Ptr32<T> new_array(unsigned long count) {
    const bool cookie = !__is_trivially_destructible(T);
    char *raw = (char *)array_new_<T>::call(count * sizeof(T) + (cookie ? 8 : 0));
    if (cookie) { *(w3d_u32 *)raw = (w3d_u32)count; raw += 8; }
    T *items = (T *)raw;
    for (unsigned long i = 0; i < count; i++) ::new (array_place_{}, (void *)(items + i)) T;
    return Ptr32<T>(items);
}
template <class T> inline void delete_array(T *items) {
    if (!items) return;
    if (__is_trivially_destructible(T)) { array_delete_<T>::call((void *)items); return; }
    char *raw = (char *)items - 8;
    for (w3d_u32 i = *(w3d_u32 *)raw; i > 0; i--) items[i - 1].~T();
    array_delete_<T>::call(raw);
}
template <class T> inline void delete_array(const Ptr32<T> &items) { delete_array((T *)items.get()); }
inline void *G(w3d_u32 v) { return g2h(v); }
inline void *G(int v) { return g2h((w3d_u32)v); }
inline void *G(unsigned long v) { return g2h((w3d_u32)v); }
inline void *G(long v) { return g2h((w3d_u32)v); }
inline void *G(long long v) { return g2h((w3d_u32)v); }
inline void *G(unsigned long long v) { return g2h((w3d_u32)v); }
inline void *G(short v) { return g2h((w3d_u32)(int)v); }
inline void *G(unsigned short v) { return g2h((w3d_u32)v); }
inline void *G(signed char v) { return g2h((w3d_u32)(int)v); }
inline void *G(unsigned char v) { return g2h((w3d_u32)v); }
inline void *G(char v) { return g2h((w3d_u32)(int)v); }
inline void *G(bool v) { return g2h((w3d_u32)v); }
template <class E, class = typename enable_if<__is_enum(E)>::type>
inline void *G(E v) { return g2h((w3d_u32)v); }
// Vista en bytes para M2C_FIELD y similares: admite entero, puntero o Ptr32.
inline signed char *bytes(int v) { return (signed char *)g2h((w3d_u32)v); }
inline signed char *bytes(unsigned v) { return (signed char *)g2h(v); }
inline signed char *bytes(short v) { return (signed char *)g2h((w3d_u32)(int)v); }
inline signed char *bytes(unsigned short v) { return (signed char *)g2h(v); }
inline signed char *bytes(unsigned char v) { return (signed char *)g2h(v); }
template <class U> inline signed char *bytes(U *p) { return (signed char *)p; }
template <class U> inline signed char *bytes(const Ptr32<U> &p) { return (signed char *)g2h(p.v); }
// Operando de reinterpret_cast: Ptr32 a puntero anfitrión; el resto sin cambios.
template <class U> inline U *R(const Ptr32<U> &p) { return p.get(); }
template <class U> inline U *R(Ptr32<U> &p) { return p.get(); }
template <class U> inline U *R(Ptr32<U> &&p) { return p.get(); }
template <class U> inline U *R(const volatile Ptr32<U> &p) { return p.get(); }
template <class U> inline U *R(volatile Ptr32<U> &p) { return p.get(); }
template <class U> inline U &&R(U &&v) { return static_cast<U &&>(v); }
// Forma en memoria de un tipo que llega como argumento de macro: T * ocupa 4 B.
template <class T> struct slot { typedef T type; };
template <class U> struct slot<U *> { typedef Ptr32<typename slot<U>::type> type; };
template <class U> struct slot<U *const> { typedef const Ptr32<typename slot<U>::type> type; };
template <class U> struct slot<U *volatile> { typedef volatile Ptr32<typename slot<U>::type> type; };
template <class R, class... A> struct slot<R(A...)> { typedef typename slot<R>::type type(typename slot<A>::type...); };
template <class T> using slot_t = typename slot<T>::type;
// Dentro de cuerpos de macro no se conoce el tipo: AG da un puntero y AI un entero a partir de lo que llegue.
template <class U> inline U *AG(const Ptr32<U> &p) { return p.get(); }
template <class U> inline U *AG(U *p) { return p; }
inline void *AG(w3d_u32 v) { return g2h(v); }
inline void *AG(int v) { return g2h((w3d_u32)v); }
inline void *AG(short v) { return g2h((w3d_u32)(int)v); }
inline void *AG(unsigned short v) { return g2h((w3d_u32)v); }
inline void *AG(long v) { return g2h((w3d_u32)v); }
inline void *AG(unsigned long v) { return g2h((w3d_u32)v); }
template <class U> inline w3d_u32 AI(U *p) { return h2g(reinterpret_cast<const volatile void *>(p)); }
template <class U> inline w3d_u32 AI(const Ptr32<U> &p) { return p.v; }
template <class U> constexpr U AI(U v) { return v; }
template <class U> inline Ptr32<U> VA(U *p) { return Ptr32<U>(p); }
template <class U> inline Ptr32<U> VA(const Ptr32<U> &p) { return p; }
template <class U> inline w3d_u32 H(U *p) { return h2g(reinterpret_cast<const volatile void *>(p)); }
template <class U> inline w3d_u32 H(const Ptr32<U> &p) { return p.v; }
template <class R, class... A> inline w3d_u32 H(R (*p)(A...)) { return h2g(reinterpret_cast<const volatile void *>(p)); }
}
// virtual bajado a tabla explícita (ver port/tools/lift/lift.py). Cada entrada de la tabla es una dirección de 32 bits
// y self viaja en w0: la tabla apunta a la vista de 32 bits de cada función.
namespace w3d {
inline void *vfn(const Ptr32<void> &vptr, int slot) { return g2h(((const w3d_u32 *)vptr.get())[slot]); }
// delete de una clase con destructor virtual: por la tabla con 3 (bit 1 = liberar), como GCC 2.95.
template <class U> inline auto vdelete_(U *p, int) -> decltype(p->w3d_vdt(3), void()) { if (p) p->w3d_vdt(3); }
template <class U> inline void vdelete_(U *p, long) { delete p; }
template <class U> inline void vdelete(U *p) { vdelete_(p, 0); }
template <class U> inline void vdelete(const Ptr32<U> &p) { vdelete_(p.get(), 0); }
}
// Puntero a método con la forma de GCC 2.95: {short delta, short index, pfn o desplazamiento de tabla}, 8 bytes.
// Los medios están en el orden que deja la inversión por palabras de los datos del DOL.
// index < 0: pfn es la función. Si no: la función está en la tabla del objeto (en obj + voff), en la entrada index - 1.
namespace w3d {
// Array solapado con un escalar en una unión: el elemento 0 es el de mayor peso, como en PPC.
template <class T, int N> struct be_array {
    T e[N];
    T &operator[](long i) { return e[N - 1 - i]; }
    const T &operator[](long i) const { return e[N - 1 - i]; }
    T &operator[](long i) volatile { return const_cast<T &>(e[N - 1 - i]); }
};
template <class T> struct pmf_is_ref { static constexpr bool value = false; };
template <class T> struct pmf_is_ref<T &> { static constexpr bool value = true; };
template <class T> struct pmf_noref { typedef T type; };
template <class T> struct pmf_noref<T &> { typedef T type; };
struct PmfData {
    short delta, index;
    union { w3d_u32 pfn; struct { short voff, pad_; }; };
    PmfData() = default;
    constexpr PmfData(int) : delta(0), index(0), pfn(0) {}
    template <class D, class R2, class... A2> void set(R2 (D::*m)(A2...)) {
        struct { unsigned long ptr, adj; } h;
        __builtin_memcpy(&h, &m, sizeof h);
        delta = (short)(h.adj >> 1); index = -1; pfn = (w3d_u32)h.ptr;
    }
    void *target(void *obj, void **self) const {
        char *o = (char *)obj;
        *self = o + delta;
        if (index < 0) return g2h(pfn);
        w3d_u32 vptr = *(w3d_u32 *)(o + voff);
        return g2h(((const w3d_u32 *)g2h(vptr))[index - 1]);
    }
    explicit operator bool() const { return index != 0 || delta != 0 || pfn != 0; }
    bool operator==(const PmfData &o) const { return index == o.index && delta == o.delta && pfn == o.pfn; }
    bool operator!=(const PmfData &o) const { return !(*this == o); }
};
template <class C, class Sig> struct Pmf;
template <class C, class R, class... A> struct Pmf<C, R(A...)> : PmfData {
    Pmf() = default;
    constexpr Pmf(int z) : PmfData(z) {}
    template <class D, class R2, class... A2> Pmf(R2 (D::*m)(A2...)) { this->set(m); }
    template <class C2, class S2> Pmf(const Pmf<C2, S2> &o) { index = o.index; delta = o.delta; pfn = o.pfn; }
    R call(void *obj, A... a) const {
        void *self; void *fn = this->target(obj, &self);
        if constexpr (pmf_is_ref<R>::value) {
            unsigned long raw = ((unsigned long (*)(void *, A...))fn)(self, a...);
            return *(typename pmf_noref<R>::type *)g2h((w3d_u32)raw);
        } else {
            return ((R (*)(void *, A...))fn)(self, a...);
        }
    }
    template <class O> R operator()(O *obj, A... a) const { return call((void *)obj, a...); }
    template <class O> R operator()(const Ptr32<O> &obj, A... a) const { return call((void *)obj.get(), a...); }
};
template <class C, class R, class... A> struct Pmf<C, R(A..., ...)> : PmfData {
    Pmf() = default;
    constexpr Pmf(int z) : PmfData(z) {}
    template <class D, class R2, class... A2> Pmf(R2 (D::*m)(A2..., ...)) { this->set((R2 (D::*)(A2...))m); }
    template <class D, class R2, class... A2> Pmf(R2 (D::*m)(A2...)) { this->set(m); }
    template <class C2, class S2> Pmf(const Pmf<C2, S2> &o) { index = o.index; delta = o.delta; pfn = o.pfn; }
    R call(void *obj, A... a) const {
        void *self; void *fn = this->target(obj, &self);
        return ((R (*)(void *, A...))fn)(self, a...);
    }
    template <class O> R operator()(O *obj, A... a) const { return call((void *)obj, a...); }
    template <class O> R operator()(const Ptr32<O> &obj, A... a) const { return call((void *)obj.get(), a...); }
};
}
#if defined(__APPLE__)
#define W3D_SYM(x) "_" x
#else
#define W3D_SYM(x) x
#endif
// Una clase sin tabla propia en el DOL (no está en su mapa de enlazado) conserva la de su base.
#if defined(__APPLE__)
#define W3D_WEAK_IMPORT __attribute__((weak_import))
#else
#define W3D_WEAK_IMPORT __attribute__((weak))
#endif
#define W3D_SET_VPTR(field, var, sym) do { extern char var[] __asm__(W3D_SYM(sym)) W3D_WEAK_IMPORT; if (var) field = (void *)var; } while (0)
// Destructor solo declarado en la unidad: C++ lo llama sin el segundo argumento, y la dirección original lo espera.
#if defined(__aarch64__)
#define W3D_DT_THUNK(sym, in_charge, target) __asm__(".text\n.p2align 2\n" W3D_SYM(sym) ":\n  mov w1, #" #in_charge "\n  b " W3D_SYM(target) "\n")
#else
#define W3D_DT_THUNK(sym, in_charge, target) __asm__(".text\n.align 2\n" W3D_SYM(sym) ":\n  mov r1, #" #in_charge "\n  b " W3D_SYM(target) "\n")
#endif
template <class T, class U> inline int operator-(U *a, const Ptr32<T> &b) { return (int)((long)(int)(w3d::h2g(a) - b.v) / w3d::step_of<T>::value); }
#ifdef W3D_LOOSE_C
template <class T> inline bool operator==(const Ptr32<T> &a, int b) { return (int)a.v == b; }
template <class T> inline bool operator==(int a, const Ptr32<T> &b) { return a == (int)b.v; }
template <class T> inline bool operator==(const Ptr32<T> &a, unsigned b) { return a.v == b; }
template <class T> inline bool operator==(unsigned a, const Ptr32<T> &b) { return a == b.v; }
template <class T> inline bool operator!=(const Ptr32<T> &a, int b) { return (int)a.v != b; }
template <class T> inline bool operator!=(int a, const Ptr32<T> &b) { return a != (int)b.v; }
template <class T> inline bool operator!=(const Ptr32<T> &a, unsigned b) { return a.v != b; }
template <class T> inline bool operator!=(unsigned a, const Ptr32<T> &b) { return a != b.v; }
template <class T> inline bool operator<(const Ptr32<T> &a, int b) { return (int)a.v < b; }
template <class T> inline bool operator<(int a, const Ptr32<T> &b) { return a < (int)b.v; }
template <class T> inline bool operator<(const Ptr32<T> &a, unsigned b) { return a.v < b; }
template <class T> inline bool operator<(unsigned a, const Ptr32<T> &b) { return a < b.v; }
template <class T> inline bool operator>(const Ptr32<T> &a, int b) { return (int)a.v > b; }
template <class T> inline bool operator>(int a, const Ptr32<T> &b) { return a > (int)b.v; }
template <class T> inline bool operator>(const Ptr32<T> &a, unsigned b) { return a.v > b; }
template <class T> inline bool operator>(unsigned a, const Ptr32<T> &b) { return a > b.v; }
template <class T> inline bool operator<=(const Ptr32<T> &a, int b) { return (int)a.v <= b; }
template <class T> inline bool operator<=(int a, const Ptr32<T> &b) { return a <= (int)b.v; }
template <class T> inline bool operator<=(const Ptr32<T> &a, unsigned b) { return a.v <= b; }
template <class T> inline bool operator<=(unsigned a, const Ptr32<T> &b) { return a <= b.v; }
template <class T> inline bool operator>=(const Ptr32<T> &a, int b) { return (int)a.v >= b; }
template <class T> inline bool operator>=(int a, const Ptr32<T> &b) { return a >= (int)b.v; }
template <class T> inline bool operator>=(const Ptr32<T> &a, unsigned b) { return a.v >= b; }
template <class T> inline bool operator>=(unsigned a, const Ptr32<T> &b) { return a >= b.v; }
#endif
static_assert(__is_trivially_copyable(Ptr32<int>) && sizeof(Ptr32<int>) == 4, "Ptr32 debe pasar en un registro como un int");

// static_cast a través de Ptr32 pasaría por su conversión con reinterpret_cast y perdería el ajuste de la herencia múltiple.
namespace w3d {
template <class To, class U> inline To sc(const Ptr32<U> &p) { return static_cast<To>(p.get()); }
template <class To, class U> inline To sc(volatile const Ptr32<U> &p) { return static_cast<To>(p.get()); }
template <class To, class U> inline To sc(U *p) { return static_cast<To>(p); }
template <class To> inline To sc(decltype(nullptr)) { return static_cast<To>(nullptr); }
template <class To> inline To sc(int v) { return (To)(unsigned long)v; }
}
inline void *operator new(__SIZE_TYPE__, w3d::array_place_, void *p) { return p; }
inline void operator delete(void *, w3d::array_place_, void *) {}
#endif
