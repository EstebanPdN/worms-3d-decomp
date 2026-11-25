// GWMP8P rev 0, 0x80342a7c. Names describe observed ownership only.
// The three arrays start at offsets 36, 68 and 100; each has two slots at
// stride 16. These views reproduce the native destructor sequence and do not
// establish the original complete class declarations or allocation size.

extern "C" void fn_800152ac(void*);
extern "C" void fn_80015264(void*);
extern "C" void fn_8001d1d8(void*);

struct cc32p_Slot_80342a7c {
    void* data;
    char unknown[12];

    ~cc32p_Slot_80342a7c() {
        if (data) fn_800152ac(data);
    }
};

struct cc32p_Element_80342a7c {
    char unknown[36];
    cc32p_Slot_80342a7c a[2], b[2], c[2];

    ~cc32p_Element_80342a7c() {
        fn_8001d1d8(this);
        // Native C++ member destruction visits c, b, a in reverse order.
    }

    static void operator delete(void* p) {
        fn_80015264(p);
    }
};

struct cc32p_List_80342a7c {
    cc32p_Element_80342a7c** begin;
    cc32p_Element_80342a7c** end;
};

extern "C" void w3d_cc32p_owned_array_clear_80342a7c(
    cc32p_List_80342a7c* self) {
    while (self->begin != self->end) {
        // The original loads the outgoing element before updating the end.
        cc32p_Element_80342a7c* element = self->end[-1];
        --self->end;
        delete element;
    }
}
