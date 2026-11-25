typedef unsigned int size_t;
struct Cc18aPool_element_80180880 {
    void **vtable;
    char payload[200];
    Cc18aPool_element_80180880();
    ~Cc18aPool_element_80180880() { ((void (*)(Cc18aPool_element_80180880 *, int))vtable[33])(this, 0); }
    static void *operator new[](size_t);
    static void operator delete[](void *);
};
extern Cc18aPool_element_80180880 *lbl_804ab60c;
extern unsigned short *lbl_804ab618;
extern unsigned short lbl_804ab610;
extern unsigned short lbl_804ab61c;
extern "C" int fn_8017f52c(void);
extern "C" void *fn_801fe220(size_t);
extern "C" void fn_801fe240(void *);
typedef void (*Cc18aAssignIndex_80180880)(Cc18aPool_element_80180880 *, unsigned short);
extern "C" int w3d_cc18a_resize_mesh_pool_8017f3b8(unsigned int count)
{
    if (fn_8017f52c()) return 0x80004005;
    if (count != lbl_804ab610) {
        delete[] lbl_804ab60c;
        if (lbl_804ab618) fn_801fe240(lbl_804ab618);
        if (!count) { lbl_804ab60c = 0; lbl_804ab618 = 0; }
        else {
            lbl_804ab60c = new Cc18aPool_element_80180880[count];
            lbl_804ab618 = (unsigned short *)fn_801fe220(count * 2);
        }
        lbl_804ab610 = count;
        lbl_804ab61c = count;
        for (unsigned short i=0; i<count; i++) {
            Cc18aPool_element_80180880 *entry = (Cc18aPool_element_80180880 *)((i * 204) + (int)lbl_804ab60c);
            ((Cc18aAssignIndex_80180880)(*(void ***)entry)[13])(entry, i);
            lbl_804ab618[i] = i;
        }
    }
    return 0;
}

