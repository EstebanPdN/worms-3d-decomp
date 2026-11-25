// Engine file owner (singleton at 0x804b17ec). Names and member meanings are
// inferred; offsets are observed. The matching destructor and the slot reads
// are in s3_runtime_integration.c.
#include "mx14oa_file_owner_8015be3c_base.h"

extern "C" void w3d_string_default(void *string);
extern "C" void w3d_string_from_text_8020bb54(void *string, const char *text);
extern "C" void w3d_setting_80206920(const char *key, int *value);
extern "C" void w3d_register_owner_80165594(void *owner);
extern const char w3d_str_run_from_cd_803a4348[];   // "PS2.RunFromCdRom"

// Four-byte engine string. The default argument selects the empty-string
// constructor; the zero it materializes before that call is the value the
// original keeps in a callee-saved register for the later clears.
struct Mx14oaText {
    char *data;
    Mx14oaText(const char *text = 0)
    {
        if (text)
            w3d_string_from_text_8020bb54(this, text);
        else
            w3d_string_default(this);
    }
};

// Tagged link at +4: the low byte of its second word is a kind tag (reloaded
// through memory, hence volatile); the first word is left untouched here.
struct Mx14oaTaggedLink {
    void *target;
    union { unsigned int word; volatile unsigned char byte[4]; } bits;
    Mx14oaTaggedLink(unsigned char kind) { bits.byte[3] = kind; bits.word = bits.byte[3]; }
};

// Base node: adds no virtual functions, so it shares the service table.
struct Mx14oaNode : Mx14oaService {
    Mx14oaTaggedLink link;
    Mx14oaNode() : link(2) {}
};

// Retained interface (released through slot 4 by the destructor).
struct Mx14oaInterface;

struct Mx14oaFileOwner : Mx14oaNode {
    Mx14oaText path;               // +12
    Mx14oaInterface *files;        // +16
    Mx14oaInterface *archives;     // +20
    int from_cd;                   // +24
    Mx14oaFileOwner();
    // Ten slots of table 0x80411168 (0x8015bdf4 0x8015bdec 0x8015bde4
    // 0x8015c154 0x8015c2a4 0x8015c2f8 0x8015bdcc 0x8015c114 0x8015c144
    // 0x8015c14c); defined elsewhere, so the table stays external.
    void slot0(); void slot1(); void slot2(); void slot3(); void slot4(); void slot5();
    virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9();
};

extern Mx14oaFileOwner *w3d_file_owner_804b17ec;

Mx14oaFileOwner::Mx14oaFileOwner()
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
