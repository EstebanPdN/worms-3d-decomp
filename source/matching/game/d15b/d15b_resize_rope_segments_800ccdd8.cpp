// Ninja rope owner: resizes its array of retained segment interfaces.
// Native GC32 partial views; offsets observed, identities inferred. New
// segments are looked up by the original "NinjaRope.Rope" name string,
// referenced by address (no owned initialized data).
namespace D15bRope {
struct Interface {
    virtual void slot0() = 0;
    virtual void retain() = 0;
    virtual void release() = 0;
};
struct HeldInterface {
    Interface *pointer;
    HeldInterface() : pointer(0) {}
    ~HeldInterface() { if (pointer) pointer->release(); }
    HeldInterface &operator=(const HeldInterface &source) {
        if (source.pointer) source.pointer->retain();
        if (pointer) pointer->release();
        pointer = source.pointer;
        return *this;
    }
    void assign(Interface *source) {
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
    HeldInterface *slots;
    void append(Interface *source);
};
}
extern "C" void w3d_string_from_text(void *, const char *);
extern "C" void w3d_string_base_finish(void *);
extern "C" void w3d_string_release(void *);
extern "C" void * w3d_handle_set_name(void *, void *, unsigned int);
extern "C" void w3d_cx11b_compact_vector_grow_80210d54(D15bRope::CountedRefs *, unsigned);
extern "C" void sol35d12_resize_refs_80210b90(D15bRope::CountedRefs *, unsigned);
extern "C" const char w3d_ninja_rope_name_80387e08[];
namespace D15bRope {
struct Name {
    const char *text;
    int unknown;
    Name(const char *s);
    ~Name() { w3d_string_base_finish(this); w3d_string_release(this); }
};
inline void CountedRefs::append(Interface *source) {
    w3d_cx11b_compact_vector_grow_80210d54(this, count + 1);
    slots[count].assign(source);
    count++;
}
struct Owner {
    unsigned char unknown00[44];
    CountedRefs segments;
};
}
extern "C" void d15b_resize_rope_segments_800ccdd8(D15bRope::Owner *self, unsigned count) {
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
        CountedRefs *segments = &self->segments;
        for (; i < self->segments.count; ++i) {
            HeldInterface *slots = segments->slots;
            slots[i].clear();
        }
        sol35d12_resize_refs_80210b90(segments, count);
    }
}
