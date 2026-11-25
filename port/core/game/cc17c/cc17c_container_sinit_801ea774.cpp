#include "w3d_ptr.h"
#line 1 "cc17c_container_sinit_801ea774.cpp"
inline void *operator new(__SIZE_TYPE__, void *place) { return place; }
/* Inferred static factory record (observed word offsets 0..20) and registration. */
struct Cc17cFactoryList;
typedef Ptr32<void (void)> Cc17cFactoryCallback;
struct Cc17cFactoryRecord {
    Ptr32<Cc17cFactoryRecord> next;
    Ptr32<char> name;
    Cc17cFactoryCallback first;
    Cc17cFactoryCallback second;
    int priority;
    Ptr32<Cc17cFactoryList> list;
};
extern "C" {
void fn_80200af8(Ptr32<Cc17cFactoryRecord>);
Ptr32<void> fn_8020fbd0(Ptr32<void>, Ptr32<void>, Ptr32<void>, Ptr32<void>, int, int);
Ptr32<void> fn_801e8a88(Ptr32<void>, Ptr32<void>, Ptr32<void>, Ptr32<void>, int, Ptr32<void>);
Ptr32<void> fn_802097ec(Ptr32<void>, Ptr32<char>, int, int);
int fn_801ea6d0(void);
int fn_801ea6c8(void);
int fn_801e89c0(void);
int fn_801e89b8(void);
int fn_801ea44c(Ptr32<void>);
Ptr32<void> fn_801e9f78(void);
extern char lbl_803b09ec[], lbl_803b0bb4[], lbl_803ea0a4[], lbl_803ea0c0[], lbl_8045e0b0[], lbl_80365788[];
extern Cc17cFactoryRecord lbl_8045e08c, lbl_8045e0e0;
extern Cc17cFactoryList lbl_8045e124;
struct Cc17cArenaHandle { int words[2]; };
extern Cc17cArenaHandle lbl_804b0580;
}
/* Three zeroed words (observed); inferred empty list/range object. */
struct Cc17cTriple { Ptr32<void> a; Ptr32<void> b; Ptr32<void> c; Cc17cTriple() { c = 0; b = 0; a = 0; } };
extern Cc17cTriple lbl_8045e080, lbl_8045e0a4;
extern "C" void w3d_cc17c_sinit_801ea774(int init, int priority)
{
    if (priority == 0xffff && init) {
        new (&lbl_8045e080) Cc17cTriple;
        Ptr32<Cc17cFactoryRecord> record = &lbl_8045e08c;
        record->first = (Ptr32<void (void)>)fn_801e89b8;
        record->second = (Ptr32<void (void)>)fn_801e89c0;
        record->name = lbl_803b09ec;
        record->priority = 0;
        record->list = &lbl_8045e124;
        fn_80200af8(record);
        new (&lbl_8045e0a4) Cc17cTriple;
        fn_8020fbd0(lbl_8045e0b0, lbl_803ea0a4, lbl_8045e0b0, 0, 4, 0);
        fn_801e8a88(lbl_80365788, lbl_803ea0c0, lbl_80365788, (Ptr32<void>)fn_801e9f78, 2, (Ptr32<void>)fn_801ea44c);
        fn_802097ec(&lbl_804b0580, lbl_803b09ec, 0, 0);
        Ptr32<Cc17cFactoryRecord> record2 = &lbl_8045e0e0;
        record2->name = lbl_803b0bb4;
        record2->first = (Ptr32<void (void)>)fn_801ea6c8;
        record2->second = (Ptr32<void (void)>)fn_801ea6d0;
        record2->priority = -10;
        record2->list = &lbl_8045e124;
        fn_80200af8(record2);
    }
}


