#include "w3d_ptr.h"
#line 1 "cc17c_resize_pool_8018a678.cpp"
/* Resizable global pool (same source shape as the admitted s9 resize-pool instances): array of
 * 276-byte polymorphic elements plus a 16-bit index table. Element virtual slot 13 assigns the
 * element index, slot 33 is the deleting destructor. Inferred names. */
typedef unsigned int size_t;
struct Cc17cPoolElement_8018bd30 {
    Ptr32<Ptr32<void>> vtable;
    char payload[272];
    Cc17cPoolElement_8018bd30();
    ~Cc17cPoolElement_8018bd30() { ((Ptr32<void (Ptr32<Cc17cPoolElement_8018bd30>, int)>)vtable[33])(this, 0); }
    static void *operator new[](__SIZE_TYPE__);
    static void operator delete[](void *);
};
extern Ptr32<Cc17cPoolElement_8018bd30> lbl_804b18b0;
extern Ptr32<unsigned short> lbl_804b18b4;
extern unsigned short lbl_804b18ac;
extern unsigned short lbl_804b18b8;
extern "C" int fn_8018a7ec(void);
extern "C" Ptr32<void> fn_801fe220(size_t);
extern "C" void fn_801fe240(Ptr32<void>);
typedef Ptr32<void (Ptr32<Cc17cPoolElement_8018bd30>, unsigned short)> Cc17cAssignIndex_8018bd30;
extern "C" int w3d_cc17c_resize_pool_8018a678(unsigned int count)
{
    if (fn_8018a7ec()) return 0x80004005;
    if (count != lbl_804b18ac) {
        w3d::delete_array(lbl_804b18b0);
        if (lbl_804b18b4) fn_801fe240(lbl_804b18b4);
        if (!count) { lbl_804b18b0 = 0; lbl_804b18b4 = 0; }
        else {
            lbl_804b18b0 = w3d::new_array<Cc17cPoolElement_8018bd30>(count);
            lbl_804b18b4 = (Ptr32<unsigned short>)fn_801fe220(count * 2);
        }
        lbl_804b18ac = count;
        lbl_804b18b8 = count;
        for (unsigned short i=0; i<count; i++) {
            Ptr32<Cc17cPoolElement_8018bd30> entry = (Ptr32<Cc17cPoolElement_8018bd30>)w3d::G(((i * 276) + (int)w3d::H(lbl_804b18b0)));
            ((Cc17cAssignIndex_8018bd30)(*(Ptr32<Ptr32<Ptr32<void>>>)entry)[13])(entry, i);
            lbl_804b18b4[i] = i;
        }
    }
    return 0;
}


