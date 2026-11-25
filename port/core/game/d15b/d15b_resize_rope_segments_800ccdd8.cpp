#include "w3d_ptr.h"
#line 1 "d15b_resize_rope_segments_800ccdd8.cpp"
// Ninja rope owner: resizes its array of retained segment interfaces.
// Native GC32 partial views; offsets observed, identities inferred. New
// segments are looked up by the original "NinjaRope.Rope" name string,
// referenced by address (no owned initialized data).
namespace D15bRope {
struct Interface {
    void w3d_r_slot0()  __asm__(W3D_SYM("_ZN8D15bRope9Interface5slot0Ev"));
    void w3d_r_retain()  __asm__(W3D_SYM("_ZN8D15bRope9Interface6retainEv"));
    void w3d_r_release()  __asm__(W3D_SYM("_ZN8D15bRope9Interface7releaseEv"));
 __attribute__((always_inline)) inline void slot0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Interface, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void retain() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Interface, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Interface, 4))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Interface; };
struct HeldInterface {
    Ptr32<Interface> pointer;
    HeldInterface() : pointer(0) {}
    ~HeldInterface() { if (pointer) pointer->release(); }
    HeldInterface &operator=(const HeldInterface &source) {
        if (source.pointer) source.pointer->retain();
        if (pointer) pointer->release();
        pointer = source.pointer;
        return *this;
    }
    void assign(Ptr32<Interface> source) {
        if (source) source->retain();
        if (pointer) pointer->release();
        pointer = source;
    }
    void clear() {
        if (pointer) pointer->release();
        pointer = 0;
    }
};
struct CountedRefs {
    unsigned count;
    unsigned short capacity, growth;
    Ptr32<HeldInterface> slots;
    void append(Ptr32<Interface> source);
};
}
extern "C" void w3d_string_from_text(Ptr32<void>, Ptr32<const char>);
extern "C" void w3d_string_base_finish(Ptr32<void>);
extern "C" void w3d_string_release(Ptr32<void>);
extern "C" Ptr32<void> w3d_handle_set_name(Ptr32<void>, Ptr32<void>, unsigned int);
extern "C" void w3d_cx11b_compact_vector_grow_80210d54(Ptr32<D15bRope::CountedRefs>, unsigned);
extern "C" void sol35d12_resize_refs_80210b90(Ptr32<D15bRope::CountedRefs>, unsigned);
extern "C" const char w3d_ninja_rope_name_80387e08[];
namespace D15bRope {
struct Name {
    Ptr32<const char> text;
    int unknown;
    template <class W3dU> Name(Ptr32<W3dU> w3d_p) : Name((const char *)w3d_p.get()) {}
 Name(const char *s);
    ~Name() { w3d_string_base_finish(this); w3d_string_release(this); }
};
inline void CountedRefs::append(Ptr32<Interface> source) {
    w3d_cx11b_compact_vector_grow_80210d54(this, count + 1);
    slots[count].assign(source);
    count++;
}
struct Owner {
    unsigned char unknown00[44];
    CountedRefs segments;
};
}
extern "C" void d15b_resize_rope_segments_800ccdd8(Ptr32<D15bRope::Owner> self, unsigned count) {
    using namespace D15bRope;
    if (count > self->segments.count) {
        unsigned added = count - self->segments.count;
        for (unsigned i = 0; i < added; ++i) {
            HeldInterface segment;
            w3d_handle_set_name(&Name(w3d_ninja_rope_name_80387e08), &segment, 255);
            self->segments.append(segment.pointer);
        }
    } else if (count < self->segments.count) {
        unsigned i = count;
        Ptr32<CountedRefs> segments = &self->segments;
        for (; i < self->segments.count; ++i) {
            Ptr32<HeldInterface> slots = segments->slots;
            slots[i].clear();
        }
        sol35d12_resize_refs_80210b90(segments, count);
    }
}


