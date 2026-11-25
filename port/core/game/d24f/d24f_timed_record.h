// Observed records: halfword +0, word +4 (due time), table 0x80410500 at +8; the derived
// shapes add words or floats and install their own table. `#pragma interface` keeps the
// tables external. Names describe observed use only.
#pragma interface
struct D24fTimedRecord {
    unsigned short id;
    unsigned due;
    Ptr32<void> w3d_r_fire() __asm__(W3D_SYM("_ZN15D24fTimedRecord4fireEv"));
 __attribute__((always_inline)) inline Ptr32<void> fire() { return ((Ptr32<void> (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D24fTimedRecord, 2))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_D24fTimedRecord; };
struct D24fTimedWord : D24fTimedRecord { unsigned extra __attribute__((aligned(__alignof__(D24fTimedRecord)))); Ptr32<void> w3d_r_fire() __asm__(W3D_SYM("_ZN13D24fTimedWord4fireEv"));  __attribute__((always_inline)) inline Ptr32<void> fire() { return this->D24fTimedRecord::fire(); } };
struct D24fTimedWord2 : D24fTimedRecord { unsigned extra __attribute__((aligned(__alignof__(D24fTimedRecord)))), extra2; Ptr32<void> w3d_r_fire() __asm__(W3D_SYM("_ZN14D24fTimedWord24fireEv"));  __attribute__((always_inline)) inline Ptr32<void> fire() { return this->D24fTimedRecord::fire(); } };
struct D24fTimedFloat : D24fTimedRecord { float extra __attribute__((aligned(__alignof__(D24fTimedRecord)))); Ptr32<void> w3d_r_fire() __asm__(W3D_SYM("_ZN14D24fTimedFloat4fireEv"));  __attribute__((always_inline)) inline Ptr32<void> fire() { return this->D24fTimedRecord::fire(); } };
struct D24fTimedFloat2 : D24fTimedRecord { float extra __attribute__((aligned(__alignof__(D24fTimedRecord)))), extra2; Ptr32<void> w3d_r_fire() __asm__(W3D_SYM("_ZN15D24fTimedFloat24fireEv"));  __attribute__((always_inline)) inline Ptr32<void> fire() { return this->D24fTimedRecord::fire(); } };
extern "C" void w3d_string_base_init(Ptr32<void>);
extern "C" Ptr32<unsigned short> w3d_string_header(Ptr32<const void>);
extern "C" void w3d_string_base_finish(Ptr32<void>);
extern "C" void w3d_string_release(Ptr32<void>);
extern "C" void w3d_string_release_header(Ptr32<void>);
struct D24fSharedString {
    Ptr32<char> text;
    D24fSharedString(const D24fSharedString &o) {
        w3d_string_base_init(this);
        text = o.text;
        ++*w3d_string_header(this);
    }
    ~D24fSharedString() {
        w3d_string_base_finish(this);
        w3d_string_release(this);
    }
    D24fSharedString &operator=(const D24fSharedString &o) {
        ++*(Ptr32<unsigned short>)(o.text - 6);
        Ptr32<unsigned short> header = (Ptr32<unsigned short>)(text - 6);
        if (--*header == 0) w3d_string_release_header(header);
        text = o.text;
        return *this;
    }
};
struct D24fTimedString : D24fTimedRecord { D24fSharedString name __attribute__((aligned(__alignof__(D24fTimedRecord)))); Ptr32<void> w3d_r_fire() __asm__(W3D_SYM("_ZN15D24fTimedString4fireEv"));  __attribute__((always_inline)) inline Ptr32<void> fire() { return this->D24fTimedRecord::fire(); } };
