#include "w3d_ptr.h"
#line 1 "d31s_queue_dump_80165018.cpp"
/* GWMP8P rev0 0x80165018. Builds a text dump of the two category queues: copies each real STLport
 * 4.5.3 priority_queue of {handle, value} records and prints and pops every entry whose handle
 * still resolves to an object. The comparator derives binary_function, as its copied byte requires. */
#include "compat/stlport_sn_oom.h"
#include <queue>
#include <vector>
struct D31sQueueRecord { int handle; int value; };
struct D31sQueueLess : _STL::binary_function<D31sQueueRecord, D31sQueueRecord, bool> {
    bool operator()(const D31sQueueRecord &a, const D31sQueueRecord &b) const;
};
typedef _STL::vector<D31sQueueRecord> D31sQueueVector;
typedef _STL::priority_queue<D31sQueueRecord, D31sQueueVector, D31sQueueLess> D31sQueue;
template <> D31sQueueVector &D31sQueueVector::operator=(const D31sQueueVector &);
namespace _STL { template <> void pop_heap(Ptr32<D31sQueueRecord>, Ptr32<D31sQueueRecord>, D31sQueueLess); }
extern "C" void w3d_string_release_header(Ptr32<unsigned short>);
extern "C" int w3d_text_format_80343b0c(Ptr32<char>, Ptr32<const char>, ...);
extern char category_format_803a4ad0[];
extern char entry_format_803a4ae0[];
struct D31sQueueString {
    Ptr32<char> text;
    Ptr32<unsigned short> header() const { return (Ptr32<unsigned short>)(text - 6); }
    D31sQueueString &operator=(const D31sQueueString &o) {
        ++*o.header();
        Ptr32<unsigned short> h = header();
        if (--*h == 0) w3d_string_release_header(h);
        text = o.text;
        return *this;
    }
    void append(Ptr32<const char> s);
};
extern D31sQueueString empty_string_804b06a0[];
struct D31sQueueObject {
    void w3d_r_query() __asm__(W3D_SYM("_ZN15D31sQueueObject5queryEv"));
    void w3d_r_retain() __asm__(W3D_SYM("_ZN15D31sQueueObject6retainEv"));
    void w3d_r_release() __asm__(W3D_SYM("_ZN15D31sQueueObject7releaseEv"));
    Ptr32<void> w3d_r_type() __asm__(W3D_SYM("_ZN15D31sQueueObject4typeEv"));
 __attribute__((always_inline)) inline void query() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D31sQueueObject, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void retain() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D31sQueueObject, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D31sQueueObject, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<void> type() { return ((Ptr32<void> (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D31sQueueObject, 5))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_D31sQueueObject; };
extern "C" Ptr32<D31sQueueObject> w3d_s20_lookup_handle_object_80164fc8(int);
extern "C" Ptr32<const char> w3d_auto_801ffea8(Ptr32<void>);
struct D31sQueueLine {
    char text[128];
    D31sQueueLine() { text[0] = 0; }
    Ptr32<char> get() { return text; }
};
struct D31sQueueCategory { Ptr32<D31sQueue> queue; int unknown4; int unknown8; };
struct D31sQueueTable { char unknown[40]; D31sQueueCategory categories[3]; };
struct D31sQueueGlobal { char unknown[28]; Ptr32<D31sQueueTable> table; };
extern Ptr32<D31sQueueGlobal> queue_global_804b178c;
extern "C" void d31s_queue_dump_80165018(Ptr32<D31sQueueString> out) {
    *out = empty_string_804b06a0[0];
    D31sQueueLine line;
    for (unsigned i = 0; i <= 2; i++) {
        if (i < 2) {
            D31sQueueCategory &c = queue_global_804b178c->table->categories[i];
            w3d_text_format_80343b0c(line.text, category_format_803a4ad0, i);
            out->append(line.get());
            if (c.queue) {
                D31sQueue q;
                q = *c.queue;
                while (q.size()) {
                    const D31sQueueRecord &r = q.top();
                    if (w3d_s20_lookup_handle_object_80164fc8(r.handle)) {
                        int v = r.value;
                        w3d_text_format_80343b0c(line.text, entry_format_803a4ae0, v, w3d::VA(w3d_auto_801ffea8(w3d_s20_lookup_handle_object_80164fc8(r.handle)->type())));
                        out->append(line.get());
                    }
                    q.pop();
                }
            }
        }
    }
}


