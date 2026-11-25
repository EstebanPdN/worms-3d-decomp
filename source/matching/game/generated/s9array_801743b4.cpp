/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

typedef unsigned int size_t;
struct s9_pool_element_80174b38 {
    void **vtable;
    char payload[168];
    s9_pool_element_80174b38();
    ~s9_pool_element_80174b38() { ((void (*)(s9_pool_element_80174b38 *, int))vtable[33])(this, 0); }
    static void *operator new[](size_t);
    static void operator delete[](void *);
};
extern s9_pool_element_80174b38 *lbl_804ab588;
extern unsigned short *lbl_804ab590;
extern unsigned short lbl_804ab58c;
extern unsigned short lbl_804ab594;
extern "C" int fn_80174528(void);
extern "C" void *fn_801fe220(size_t);
extern "C" void fn_801fe240(void *);
typedef void (*S9AssignIndex_80174b38)(s9_pool_element_80174b38 *, unsigned short);
struct s9_pool_element_80185110 {
    void **vtable;
    char payload[168];
    s9_pool_element_80185110();
    ~s9_pool_element_80185110() { ((void (*)(s9_pool_element_80185110 *, int))vtable[33])(this, 0); }
    static void *operator new[](size_t);
    static void operator delete[](void *);
};
extern s9_pool_element_80185110 *lbl_804ab658;
extern unsigned short *lbl_804ab664;
extern unsigned short lbl_804ab65c;
extern unsigned short lbl_804ab668;
extern "C" int fn_80183ebc(void);
typedef void (*S9AssignIndex_80185110)(s9_pool_element_80185110 *, unsigned short);
struct s9_pool_element_80188a68 {
    void **vtable;
    char payload[168];
    s9_pool_element_80188a68();
    ~s9_pool_element_80188a68() { ((void (*)(s9_pool_element_80188a68 *, int))vtable[33])(this, 0); }
    static void *operator new[](size_t);
    static void operator delete[](void *);
};
extern s9_pool_element_80188a68 *lbl_804ab680;
extern unsigned short *lbl_804ab68c;
extern unsigned short lbl_804ab684;
extern unsigned short lbl_804ab690;
extern "C" int fn_80187754(void);
typedef void (*S9AssignIndex_80188a68)(s9_pool_element_80188a68 *, unsigned short);

extern "C" int s9_resize_pool_801743b4(unsigned int count)
{
    if (fn_80174528()) return 0x80004005;
    if (count != lbl_804ab58c) {
        delete[] lbl_804ab588;
        if (lbl_804ab590) fn_801fe240(lbl_804ab590);
        if (!count) { lbl_804ab588 = 0; lbl_804ab590 = 0; }
        else {
            lbl_804ab588 = new s9_pool_element_80174b38[count];
            lbl_804ab590 = (unsigned short *)fn_801fe220(count * 2);
        }
        lbl_804ab58c = count;
        lbl_804ab594 = count;
        for (unsigned short i=0; i<count; i++) {
            s9_pool_element_80174b38 *entry = (s9_pool_element_80174b38 *)((i * 172) + (int)lbl_804ab588);
            ((S9AssignIndex_80174b38)(*(void ***)entry)[13])(entry, i);
            lbl_804ab590[i] = i;
        }
    }
    return 0;
}

extern "C" int s9_resize_pool_80183d48(unsigned int count)
{
    if (fn_80183ebc()) return 0x80004005;
    if (count != lbl_804ab65c) {
        delete[] lbl_804ab658;
        if (lbl_804ab664) fn_801fe240(lbl_804ab664);
        if (!count) { lbl_804ab658 = 0; lbl_804ab664 = 0; }
        else {
            lbl_804ab658 = new s9_pool_element_80185110[count];
            lbl_804ab664 = (unsigned short *)fn_801fe220(count * 2);
        }
        lbl_804ab65c = count;
        lbl_804ab668 = count;
        for (unsigned short i=0; i<count; i++) {
            s9_pool_element_80185110 *entry = (s9_pool_element_80185110 *)((i * 172) + (int)lbl_804ab658);
            ((S9AssignIndex_80185110)(*(void ***)entry)[13])(entry, i);
            lbl_804ab664[i] = i;
        }
    }
    return 0;
}

extern "C" int s9_resize_pool_801875e0(unsigned int count)
{
    if (fn_80187754()) return 0x80004005;
    if (count != lbl_804ab684) {
        delete[] lbl_804ab680;
        if (lbl_804ab68c) fn_801fe240(lbl_804ab68c);
        if (!count) { lbl_804ab680 = 0; lbl_804ab68c = 0; }
        else {
            lbl_804ab680 = new s9_pool_element_80188a68[count];
            lbl_804ab68c = (unsigned short *)fn_801fe220(count * 2);
        }
        lbl_804ab684 = count;
        lbl_804ab690 = count;
        for (unsigned short i=0; i<count; i++) {
            s9_pool_element_80188a68 *entry = (s9_pool_element_80188a68 *)((i * 172) + (int)lbl_804ab680);
            ((S9AssignIndex_80188a68)(*(void ***)entry)[13])(entry, i);
            lbl_804ab68c[i] = i;
        }
    }
    return 0;
}
