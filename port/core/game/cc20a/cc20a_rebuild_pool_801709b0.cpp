#include "w3d_ptr.h"
#line 1 "cc20a_rebuild_pool_801709b0.cpp"
typedef unsigned int size_t;
struct Cc20aPool_element_80172b14 {
    Ptr32<Ptr32<void>> vtable;
    char payload[132];
    Cc20aPool_element_80172b14();
    ~Cc20aPool_element_80172b14() { ((Ptr32<void (Ptr32<Cc20aPool_element_80172b14>, int)>)vtable[33])(this, 0); }
    static void *operator new[](__SIZE_TYPE__);
    static void operator delete[](void *);
};
extern Ptr32<Cc20aPool_element_80172b14> lbl_804b189c;
extern Ptr32<unsigned short> lbl_804b18a0;
extern unsigned short lbl_804b18a4;
extern unsigned short lbl_804b18a6;
extern "C" int fn_80170b18(void);
extern "C" Ptr32<void> fn_801fe220(size_t);
extern "C" void fn_801fe240(Ptr32<void>);
typedef Ptr32<void (Ptr32<Cc20aPool_element_80172b14>, unsigned short)> Cc20aAssignIndex_80172b14;
extern "C" int w3d_cc20a_rebuild_pool_801709b0(unsigned int count)
{
    if (fn_80170b18()) return 0x80004005;
    {
        w3d::delete_array(lbl_804b189c);
        if (lbl_804b18a0) fn_801fe240(lbl_804b18a0);
        if (!count) { lbl_804b189c = 0; lbl_804b18a0 = 0; }
        else {
            lbl_804b189c = w3d::new_array<Cc20aPool_element_80172b14>(count);
            lbl_804b18a0 = (Ptr32<unsigned short>)fn_801fe220(count * 2);
        }
        lbl_804b18a4 = count;
        lbl_804b18a6 = count;
        for (unsigned short i=0; i<count; i++) {
            Ptr32<Cc20aPool_element_80172b14> entry = (Ptr32<Cc20aPool_element_80172b14>)w3d::G(((i * 136) + (int)w3d::H(lbl_804b189c)));
            ((Cc20aAssignIndex_80172b14)(*(Ptr32<Ptr32<Ptr32<void>>>)entry)[13])(entry, i);
            lbl_804b18a0[i] = i;
        }
    }
    return 0;
}



