// Engine file owner (singleton at 0x804b17ec). Names and member meanings are
// inferred; offsets are observed. The matching destructor and the slot reads
// are in s3_runtime_integration.c.
#include "mx14oa_file_owner_b_8015be3c_base.h"

extern "C" void w3d_string_default(void *string);
extern "C" void w3d_setting_80206920(const char *key, int *value);
extern "C" void w3d_register_owner_80165594(void *owner);
extern const char w3d_str_run_from_cd_803a4348[];   // "PS2.RunFromCdRom"

// Four-byte engine string; the default constructor is out of line.
struct Mx14oaTextB {
    char *data;
    Mx14oaTextB() { w3d_string_default(this); }
};

// Tagged link at +4: the second word packs a 24-bit pointer above an 8-bit
// kind tag. The static node getter 0x8020b208 shows the same pair of stores
// (kind byte, then the pointer field inserted with rlwimi). The first word is
// left untouched here.
struct Mx14oaTaggedLinkB {
    void *target;
    unsigned int pointer : 24;
    unsigned int kind : 8;
    Mx14oaTaggedLinkB(unsigned char tag) { kind = tag; pointer = 0; }
};

// Base node: adds no virtual functions, so it shares the service table.
struct Mx14oaNodeB : Mx14oaServiceB {
    Mx14oaTaggedLinkB link;
    Mx14oaNodeB() : link(2) {}
};

// Retained interface (released through slot 4 by the destructor).
struct Mx14oaInterfaceB;

struct Mx14oaFileOwnerB : Mx14oaNodeB {
    Mx14oaTextB path;              // +12
    Mx14oaInterfaceB *files;       // +16
    Mx14oaInterfaceB *archives;    // +20
    int from_cd;                   // +24
    Mx14oaFileOwnerB();
    // Ten slots of table 0x80411168 (0x8015bdf4 0x8015bdec 0x8015bde4
    // 0x8015c154 0x8015c2a4 0x8015c2f8 0x8015bdcc 0x8015c114 0x8015c144
    // 0x8015c14c); defined elsewhere, so the table stays external.
    void slot0(); void slot1(); void slot2(); void slot3(); void slot4(); void slot5();
    virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9();
};

extern Mx14oaFileOwnerB *w3d_file_owner_804b17ec;

Mx14oaFileOwnerB::Mx14oaFileOwnerB()
{
    files = 0;
    archives = 0;
    int setting = 0;
    w3d_setting_80206920(w3d_str_run_from_cd_803a4348, &setting);
    int result = setting;
    if (result)
        result = 1;
    from_cd = result;
    w3d_file_owner_804b17ec = this;
    w3d_register_owner_80165594(this);
}
