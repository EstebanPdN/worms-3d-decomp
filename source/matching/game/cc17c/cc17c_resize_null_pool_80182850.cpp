/* Resizable global pool (same source shape as the admitted s9 resize-pool instances): array of
 * 176-byte polymorphic elements plus a 16-bit index table. Element virtual slot 13 assigns the
 * element index, slot 33 is the deleting destructor. Inferred names. */
typedef unsigned int size_t;
struct Cc17cPoolElement_80182de0 {
    void **vtable;
    char payload[172];
    Cc17cPoolElement_80182de0();
    ~Cc17cPoolElement_80182de0() { ((void (*)(Cc17cPoolElement_80182de0 *, int))vtable[33])(this, 0); }
    static void *operator new[](size_t);
    static void operator delete[](void *);
};
extern Cc17cPoolElement_80182de0 *lbl_804ab634;
extern unsigned short *lbl_804ab640;
extern unsigned short lbl_804ab638;
extern unsigned short lbl_804ab644;
extern "C" int fn_801829c4(void);
extern "C" void *fn_801fe220(size_t);
extern "C" void fn_801fe240(void *);
typedef void (*Cc17cAssignIndex_80182de0)(Cc17cPoolElement_80182de0 *, unsigned short);
extern "C" int w3d_cc17c_resize_null_pool_80182850(unsigned int count)
{
    if (fn_801829c4()) return 0x80004005;
    if (count != lbl_804ab638) {
        delete[] lbl_804ab634;
        if (lbl_804ab640) fn_801fe240(lbl_804ab640);
        if (!count) { lbl_804ab634 = 0; lbl_804ab640 = 0; }
        else {
            lbl_804ab634 = new Cc17cPoolElement_80182de0[count];
            lbl_804ab640 = (unsigned short *)fn_801fe220(count * 2);
        }
        lbl_804ab638 = count;
        lbl_804ab644 = count;
        for (unsigned short i=0; i<count; i++) {
            Cc17cPoolElement_80182de0 *entry = (Cc17cPoolElement_80182de0 *)((i * 176) + (int)lbl_804ab634);
            ((Cc17cAssignIndex_80182de0)(*(void ***)entry)[13])(entry, i);
            lbl_804ab640[i] = i;
        }
    }
    return 0;
}
