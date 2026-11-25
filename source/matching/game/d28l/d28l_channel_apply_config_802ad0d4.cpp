// GWMP8P rev0 0x802ad0d4. Copies a channel's configuration block into its
// live fields: packs two-bit per-channel masks into the two halfword
// bitfields, clears the entry past the last one, then opens the device and
// maps the status (-1, 0, other) to a result code. Field roles are inferred;
// the two call arms cross-jump in the original.
struct Config {
    char u0[46];
    unsigned char flags;
    char u47[1];
    int w48;
    unsigned short mask;
    char u54[2];
    int w56;
    unsigned count;
    unsigned short masks[8];
    char u80[1];
    unsigned char mode;
};
struct Channel {
    int port;
    char u4[4];
    Config *config;
    int result;
    char u16[52];
    int w68;
    char w72[46];
    unsigned char flags;
    char u119[1];
    int w120;
    unsigned short low;
    unsigned short high;
    int w128;
    char u132[100];
    int w232;
    int w236;
};
extern "C" int fn_80318b48(int, int, void *);
extern "C" int fn_802fb7ac(const char *, ...);
extern const char s_803d70d4[];
extern "C" void d28l_channel_apply_config_802ad0d4(Channel *self) {
    unsigned i;
    self->w128 = self->config->w56;
    self->w120 = self->config->w48;
    self->flags = self->config->flags | (self->flags & 0xfc);
    self->flags = self->config->mode | (self->flags & 0xfb);
    for (i = 0; i < self->config->count; i++) {
        int shift = i + i;
        int m = ~(3 << shift);
        self->low = (self->low & m) | (self->config->mask << shift);
        self->high = (self->high & m) | (self->config->masks[i] << shift);
    }
    if (self->config->count < 8) {
        self->low &= ~(3 << (self->config->count + self->config->count));
        self->high &= ~(3 << (self->config->count + self->config->count));
    }
    int r; if (self->w236) r = fn_80318b48(self->port, self->w68, self->w72); else r = fn_80318b48(self->port, self->w232, self->w72);
    switch (r) {
    case -1:
        self->result = 229;
        break;
    case 0:
        if (self->w236) self->result = 230; else self->result = 233;
        break;
    default:
        fn_802fb7ac(s_803d70d4, r);
        self->result = 0;
        break;
    }
}
