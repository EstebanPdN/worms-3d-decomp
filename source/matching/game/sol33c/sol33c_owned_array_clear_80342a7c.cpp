// GWMP8P rev0. Replacement candidate for admitted 0x80342a7c (228 bytes).
// Allocation ownership: 0x8001d5bc loads 132, 0x8001d5c4 allocates through
// 0x8001523c, and 0x8001d980..0x8001d994 appends that pointer to owner+88.
// 0x8001cb10..0x8001cb18 passes this same owner+88 list to this clear routine.
// Rejection cleanup at 0x8001d700..0x8001d8ac and sibling removal at
// 0x8001da3c..0x8001dac4 perform the same member destruction and free.
// Allocator 0x8001523c and deallocator 0x80015264 use arena 0x804ac898.
// The class-specific deallocation declaration below binds directly to native
// 0x80015264 via the selected-body call at 0x80342b38. It has no wrapper body.
// The class suffix identifies that deallocation import, not a constructor.
// Complete semantic class names remain inferred; unknown fields stay opaque.

extern "C" void fn_800152ac(void*);
extern "C" void fn_8001d1d8(void*);

struct sol33c_Slot_80342a7c {
    void* data;
    char unknown[12];
    ~sol33c_Slot_80342a7c() {
        if (data) fn_800152ac(data);
    }
};

struct sol33c_ArenaElement_80015264 {
    char unknown[36];
    sol33c_Slot_80342a7c a[2], b[2], c[2];
    ~sol33c_ArenaElement_80015264() {
        fn_8001d1d8(this);
    }
    static void operator delete(void*);
};

typedef char sol33c_slot_size[(sizeof(sol33c_Slot_80342a7c) == 16) ? 1 : -1];
typedef char sol33c_element_size[(sizeof(sol33c_ArenaElement_80015264) == 132) ? 1 : -1];

struct sol33c_List_80342a7c {
    sol33c_ArenaElement_80015264** begin;
    sol33c_ArenaElement_80015264** end;
};

extern "C" void w3d_sol33c_owned_array_clear_80342a7c(sol33c_List_80342a7c* self) {
    while (self->begin != self->end) {
        sol33c_ArenaElement_80015264* element = self->end[-1];
        --self->end;
        delete element;
    }
}
