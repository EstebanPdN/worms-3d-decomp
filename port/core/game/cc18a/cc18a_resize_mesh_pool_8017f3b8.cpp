#include "w3d_ptr.h"
#line 1 "cc18a_resize_mesh_pool_8017f3b8.cpp"
typedef unsigned int size_t;
struct Cc18aPool_element_80180880 {
    Ptr32<Ptr32<void>> vtable;
    char payload[200];
    Cc18aPool_element_80180880();
    ~Cc18aPool_element_80180880() { ((Ptr32<void (Ptr32<Cc18aPool_element_80180880>, int)>)vtable[33])(this, 0); }
    static void *operator new[](__SIZE_TYPE__);
    static void operator delete[](void *);
};
extern Ptr32<Cc18aPool_element_80180880> lbl_804ab60c;
extern Ptr32<unsigned short> lbl_804ab618;
extern unsigned short lbl_804ab610;
extern unsigned short lbl_804ab61c;
extern "C" int fn_8017f52c(void);
extern "C" Ptr32<void> fn_801fe220(size_t);
extern "C" void fn_801fe240(Ptr32<void>);
typedef Ptr32<void (Ptr32<Cc18aPool_element_80180880>, unsigned short)> Cc18aAssignIndex_80180880;
extern "C" int w3d_cc18a_resize_mesh_pool_8017f3b8(unsigned int count)
{
    if (fn_8017f52c()) return 0x80004005;
    if (count != lbl_804ab610) {
        w3d::delete_array(lbl_804ab60c);
        if (lbl_804ab618) fn_801fe240(lbl_804ab618);
        if (!count) { lbl_804ab60c = 0; lbl_804ab618 = 0; }
        else {
            lbl_804ab60c = w3d::new_array<Cc18aPool_element_80180880>(count);
            lbl_804ab618 = (Ptr32<unsigned short>)fn_801fe220(count * 2);
        }
        lbl_804ab610 = count;
        lbl_804ab61c = count;
        for (unsigned short i=0; i<count; i++) {
            Ptr32<Cc18aPool_element_80180880> entry = (Ptr32<Cc18aPool_element_80180880>)w3d::G(((i * 204) + (int)w3d::H(lbl_804ab60c)));
            ((Cc18aAssignIndex_80180880)(*(Ptr32<Ptr32<Ptr32<void>>>)entry)[13])(entry, i);
            lbl_804ab618[i] = i;
        }
    }
    return 0;
}



