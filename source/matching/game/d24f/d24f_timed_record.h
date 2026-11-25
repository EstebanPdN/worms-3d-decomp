// Observed records: halfword +0, word +4 (due time), table 0x80410500 at +8; the derived
// shapes add words or floats and install their own table. `#pragma interface` keeps the
// tables external. Names describe observed use only.
#pragma interface
struct D24fTimedRecord {
    unsigned short id;
    unsigned due;
    virtual void *fire();
};
struct D24fTimedWord : D24fTimedRecord { unsigned extra; virtual void *fire(); };
struct D24fTimedWord2 : D24fTimedRecord { unsigned extra, extra2; virtual void *fire(); };
struct D24fTimedFloat : D24fTimedRecord { float extra; virtual void *fire(); };
struct D24fTimedFloat2 : D24fTimedRecord { float extra, extra2; virtual void *fire(); };
extern "C" void w3d_string_base_init(void *);
extern "C" unsigned short *w3d_string_header(const void *);
extern "C" void w3d_string_base_finish(void *);
extern "C" void w3d_string_release(void *);
extern "C" void w3d_string_release_header(void *);
struct D24fSharedString {
    char *text;
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
        ++*(unsigned short *)(o.text - 6);
        unsigned short *header = (unsigned short *)(text - 6);
        if (--*header == 0) w3d_string_release_header(header);
        text = o.text;
        return *this;
    }
};
struct D24fTimedString : D24fTimedRecord { D24fSharedString name; virtual void *fire(); };
