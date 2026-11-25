#include "w3d_ptr.h"
#line 1 "d40n_lua_fill_vertex_stream_8019e96c.cpp"
// GWMP8P rev0 0x8019e96c. Fills a locked stream from the Lua table on the
// stack: for each row accepts a number, a table of named element values, or
// failing any name a table of positional values, converting each through the
// service's converter into the row at the element's offset. Names inferred.
struct lua_State;
extern "C" int w3d_k6b_lua_table_length_802cd408(Ptr32<lua_State>, int);
extern "C" void lua_pushnumber(Ptr32<lua_State>, float);
extern "C" void lua_gettable(Ptr32<lua_State>, int);
extern "C" int lua_isnumber(Ptr32<lua_State>, int);
extern "C" float lua_tonumber(Ptr32<lua_State>, int);
extern "C" int lua_type(Ptr32<lua_State>, int);
extern "C" void lua_settop(Ptr32<lua_State>, int);
extern "C" void lua_pushstring(Ptr32<lua_State>, Ptr32<const char>);
struct Element;
extern "C" Ptr32<const char> fn_801ffea8(Ptr32<Element>);
extern "C" int fn_80200134(Ptr32<Element>);
struct Layout {
    void w3d_r_s8() __asm__(W3D_SYM("_ZN6Layout2s8Ev")); void w3d_r_s12() __asm__(W3D_SYM("_ZN6Layout3s12Ev")); void w3d_r_s16() __asm__(W3D_SYM("_ZN6Layout3s16Ev")); void w3d_r_s20() __asm__(W3D_SYM("_ZN6Layout3s20Ev")); void w3d_r_s24() __asm__(W3D_SYM("_ZN6Layout3s24Ev"));
    Ptr32<Ptr32<Element>> w3d_r_Elements(Ptr32<unsigned int> count) __asm__(W3D_SYM("_ZN6Layout8ElementsEPj"));
 __attribute__((always_inline)) inline void s8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Layout, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s12() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Layout, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s16() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Layout, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s20() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Layout, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s24() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Layout, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<Ptr32<Element>> Elements(Ptr32<unsigned int> w3d_a0) { return ((Ptr32<Ptr32<Element>> (*)(w3d_u32, Ptr32<unsigned int>))w3d::vfn(this->w3d_vptr_Layout, 7))(w3d::h2g(this), w3d_a0); }  Ptr32<void> w3d_vptr_Layout; };
extern "C" int fn_80200050(Ptr32<Layout>);
extern "C" Ptr32<Layout> fn_80200158(Ptr32<Element>);
extern char type_float_8045ed7c[];
extern char convert_key_80419500[];
struct Converter {
    void w3d_r_s8() __asm__(W3D_SYM("_ZN9Converter2s8Ev")); void w3d_r_retain() __asm__(W3D_SYM("_ZN9Converter6retainEv")); void w3d_r_release() __asm__(W3D_SYM("_ZN9Converter7releaseEv")); void w3d_r_s20() __asm__(W3D_SYM("_ZN9Converter3s20Ev"));
    void w3d_r_Convert(Ptr32<void> value, Ptr32<void> type, Ptr32<void> dst, Ptr32<struct Layout> layout) __asm__(W3D_SYM("_ZN9Converter7ConvertEPvS0_S0_P6Layout"));
 __attribute__((always_inline)) inline void s8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Converter, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void retain() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Converter, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Converter, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s20() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Converter, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void Convert(Ptr32<void> w3d_a0, Ptr32<void> w3d_a1, Ptr32<void> w3d_a2, Ptr32<struct Layout> w3d_a3) { ((void (*)(w3d_u32, Ptr32<void>, Ptr32<void>, Ptr32<void>, Ptr32<struct Layout>))w3d::vfn(this->w3d_vptr_Converter, 6))(w3d::h2g(this), w3d_a0, w3d_a1, w3d_a2, w3d_a3); }  Ptr32<void> w3d_vptr_Converter; };
struct ConverterRef {
    Ptr32<Converter> p;
    template <class W3dU> ConverterRef(Ptr32<W3dU> w3d_p) : ConverterRef((Converter *)w3d_p.get()) {}
 ConverterRef(Converter *q) : p(q) { if (p) p->retain(); }
    ConverterRef(const ConverterRef &o) : p(o.p) { if (p) p->retain(); }
    ~ConverterRef() { if (p) p->release(); }
};
struct Service {
    void w3d_r_s8() __asm__(W3D_SYM("_ZN7Service2s8Ev")); void w3d_r_s12() __asm__(W3D_SYM("_ZN7Service3s12Ev")); void w3d_r_s16() __asm__(W3D_SYM("_ZN7Service3s16Ev")); void w3d_r_s20() __asm__(W3D_SYM("_ZN7Service3s20Ev")); void w3d_r_s24() __asm__(W3D_SYM("_ZN7Service3s24Ev")); void w3d_r_s28() __asm__(W3D_SYM("_ZN7Service3s28Ev")); void w3d_r_s32() __asm__(W3D_SYM("_ZN7Service3s32Ev")); void w3d_r_s36() __asm__(W3D_SYM("_ZN7Service3s36Ev"));
    void w3d_r_s40() __asm__(W3D_SYM("_ZN7Service3s40Ev")); void w3d_r_s44() __asm__(W3D_SYM("_ZN7Service3s44Ev")); void w3d_r_s48() __asm__(W3D_SYM("_ZN7Service3s48Ev")); void w3d_r_s52() __asm__(W3D_SYM("_ZN7Service3s52Ev")); void w3d_r_s56() __asm__(W3D_SYM("_ZN7Service3s56Ev")); void w3d_r_s60() __asm__(W3D_SYM("_ZN7Service3s60Ev")); void w3d_r_s64() __asm__(W3D_SYM("_ZN7Service3s64Ev")); void w3d_r_s68() __asm__(W3D_SYM("_ZN7Service3s68Ev"));
    void w3d_r_s72() __asm__(W3D_SYM("_ZN7Service3s72Ev")); void w3d_r_s76() __asm__(W3D_SYM("_ZN7Service3s76Ev")); void w3d_r_s80() __asm__(W3D_SYM("_ZN7Service3s80Ev")); void w3d_r_s84() __asm__(W3D_SYM("_ZN7Service3s84Ev")); void w3d_r_s88() __asm__(W3D_SYM("_ZN7Service3s88Ev"));
    Ptr32<Converter> w3d_r_Find(Ptr32<void> key) __asm__(W3D_SYM("_ZN7Service4FindEPv"));
 __attribute__((always_inline)) inline void s8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s12() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s16() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s20() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s24() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s28() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s32() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s36() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s40() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s44() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s48() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s52() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s56() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 14))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s60() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 15))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s64() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 16))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s68() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 17))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s72() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 18))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s76() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 19))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s80() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 20))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s84() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 21))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s88() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 22))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<Converter> Find(Ptr32<void> w3d_a0) { return ((Ptr32<Converter> (*)(w3d_u32, Ptr32<void>))w3d::vfn(this->w3d_vptr_Service, 23))(w3d::h2g(this), w3d_a0); }  Ptr32<void> w3d_vptr_Service; };
extern "C" Ptr32<Service> fn_8020b648();
struct Format { char u0[8]; Ptr32<Layout> layout; };
struct Stream { Ptr32<Format> format; void w3d_r_s8() __asm__(W3D_SYM("_ZN6Stream2s8Ev")); void w3d_r_s12() __asm__(W3D_SYM("_ZN6Stream3s12Ev")); void w3d_r_s16() __asm__(W3D_SYM("_ZN6Stream3s16Ev")); void w3d_r_s20() __asm__(W3D_SYM("_ZN6Stream3s20Ev")); void w3d_r_s24() __asm__(W3D_SYM("_ZN6Stream3s24Ev")); void w3d_r_s28() __asm__(W3D_SYM("_ZN6Stream3s28Ev")); void w3d_r_s32() __asm__(W3D_SYM("_ZN6Stream3s32Ev"));
    Ptr32<char> w3d_r_Lock(int usage, int count, int a, int b) __asm__(W3D_SYM("_ZN6Stream4LockEiiii"));  __attribute__((always_inline)) inline void s8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s12() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s16() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s20() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s24() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s28() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s32() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<char> Lock(int w3d_a0, int w3d_a1, int w3d_a2, int w3d_a3) { return ((Ptr32<char> (*)(w3d_u32, int, int, int, int))w3d::vfn(this->w3d_vptr_Stream, 9))(w3d::h2g(this), w3d_a0, w3d_a1, w3d_a2, w3d_a3); }  Ptr32<void> w3d_vptr_Stream; };
inline Ptr32<Converter> FindConverter(Ptr32<void> key) { return fn_8020b648()->Find(key); }
extern "C" int w3d_d40n_lua_fill_vertex_stream_8019e96c(Ptr32<lua_State> L, int usage, Ptr32<Stream> stream) {
    int count = w3d_k6b_lua_table_length_802cd408(L, -1);
    ConverterRef conv(FindConverter(convert_key_80419500));
    Ptr32<char> dst = stream->Lock(usage, count, 1, 0);
    Ptr32<Layout> layout = stream->format->layout;
    int stride = fn_80200050(layout);
    for (int i = 1; i <= count; i++) {
        lua_pushnumber(L, (float)i);
        lua_gettable(L, -2);
        if (lua_isnumber(L, -1)) {
            float v = lua_tonumber(L, -1);
            conv.p->Convert(&v, type_float_8045ed7c, dst, layout);
        } else if (lua_type(L, -1) == 5) {
            unsigned n;
            Ptr32<Ptr32<Element>> elems = layout->Elements(&n);
            if (elems) {
                int named = 0;
                for (unsigned j = 0; j < n; j++) {
                    Ptr32<Element> e = elems[j];
                    lua_pushstring(L, fn_801ffea8(e));
                    lua_gettable(L, -2);
                    if (lua_type(L, -1) != 0) {
                        named = 1;
                        if (lua_isnumber(L, -1)) {
                            float v = lua_tonumber(L, -1);
                            conv.p->Convert(&v, type_float_8045ed7c, dst + fn_80200134(e), fn_80200158(e));
                        }
                    }
                    lua_settop(L, -2);
                }
                if (!named) {
                    unsigned len = w3d_k6b_lua_table_length_802cd408(L, -1);
                    for (unsigned j = 0; j < n && j < len; j++) {
                        Ptr32<Element> e = elems[j];
                        lua_pushnumber(L, (float)j + 1.0f);
                        lua_gettable(L, -2);
                        if (lua_type(L, -1) != 0 && lua_isnumber(L, -1)) {
                            float v = lua_tonumber(L, -1);
                            conv.p->Convert(&v, type_float_8045ed7c, dst + fn_80200134(e), fn_80200158(e));
                        }
                        lua_settop(L, -2);
                    }
                }
            }
        }
        lua_settop(L, -2);
        dst += stride;
    }
    return 0;
}


