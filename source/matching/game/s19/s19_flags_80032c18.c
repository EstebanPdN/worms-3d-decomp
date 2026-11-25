#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
extern void *w3d_empty_80342a74(void *);
extern float w3d_auto_80178df0(void *);
void s19_set_priority_flags_80032c18(void *self)
{
    float v = w3d_auto_80178df0(w3d_empty_80342a74(FIELD(self, void *, 752)));
    unsigned a, b;
    if (v > 0.0f) {
        a = FIELD(self, unsigned, 728);
        b = FIELD(self, unsigned, 596);
        a |= 0x800000;
    } else {
        a = FIELD(self, unsigned, 728);
        b = FIELD(self, unsigned, 596);
        a &= ~0x800000u;
    }
    b |= 0x800000;
    FIELD(self, unsigned, 728) = a;
    FIELD(self, unsigned, 596) = b;
}
