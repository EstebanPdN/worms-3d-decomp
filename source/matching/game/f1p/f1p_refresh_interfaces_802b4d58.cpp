// Recovered from the original DOL body at 0x802b4d58 (184 bytes).
//
// Three optional interfaces held at +0x0e0, +0x0e4 and +0x0e8 each receive an
// enable flag through virtual slot +0x58. The first two flags normally mirror
// the bytes at +0x0b0 and +0x08c, inverted for the first. When the +0x08c byte
// is zero, the first interface instead receives "the +0x0e8 interface is null"
// and the second receives zero. The branch layout of that inner decision is
// part of the original code, so both arms are written out explicitly.
//
// Offsets, interface slot numbering and flag meanings are inferred from this
// body; they are not recovered symbol names. No external data or functions are
// referenced.

struct W3dIface;

struct W3dIfaceVtable {
    unsigned int unknown00[22];
    void (*set_enabled)(W3dIface *self, unsigned int enabled);  // +0x58
};

struct W3dIface {
    W3dIfaceVtable *vtable;
};

struct W3dInterfaceOwner {
    unsigned char unknown00[140];   // +0x000
    unsigned int field_8c;          // +0x08c
    unsigned char unknown90[32];    // +0x090
    unsigned int field_b0;          // +0x0b0
    unsigned char unknownb4[44];    // +0x0b4
    W3dIface *first;                // +0x0e0
    W3dIface *second;               // +0x0e4
    W3dIface *third;                // +0x0e8
};

extern "C" void w3d_refresh_interfaces_802b4d58(W3dInterfaceOwner *self)
{
    unsigned int a = self->field_b0;
    unsigned int b = self->field_8c;
    unsigned int first = a ^ 1;
    unsigned int second = a;
    unsigned int third = b ^ 1;
    if (!b) {
        if (self->third != 0) {
            first = 0;
            second = 0;
        } else {
            first = 1;
            second = 0;
        }
    }
    if (self->first)
        self->first->vtable->set_enabled(self->first, first);
    if (self->second)
        self->second->vtable->set_enabled(self->second, second);
    if (self->third)
        self->third->vtable->set_enabled(self->third, third);
}
