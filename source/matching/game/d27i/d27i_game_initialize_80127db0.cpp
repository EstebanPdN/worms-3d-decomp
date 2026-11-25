// GWMP8P rev0 0x80127db0. Game startup sequence: subsystem setup, resource
// folder loading, controller and language defaults for each of 14 slots,
// option loading, logging and audio start.
struct Log;
struct LogVt { char u0[60]; void (*a60)(Log *, unsigned char *); void (*a64)(Log *, unsigned char *); char u68[28]; void (*a96)(Log *, const char *, const char *, int); };
struct Log { LogVt *vt; };
struct Sys { char u0[116]; Log *log; };
struct Name { const char *text; };
struct Game { char u0[76]; unsigned w76; char u80[108]; unsigned flags; };
extern Sys *sys_804b17ec;
extern const char s_8039bea0[], s_8039bea8[], s_8039beb8[], s_8039beec[], s_8039bef8[], s_8039bf30[], s_8039bf44[];
extern int v_804ab094, v_804ab098;
extern "C" void a1_80129108(Game *);
extern "C" int a2_8015c3ec();
extern "C" int a3_8015b424(void *);
extern "C" int a4_801fcd6c();
extern "C" void a5_801fcc48(int);
extern "C" int a6_801280b4(Game *);
extern "C" void a7_80128f6c(Game *);
extern "C" int a8_8015c670(Game *);
extern "C" int fa_800fd4c8(int, int);
extern "C" int fb_800fd504(const char *, int, int);
extern "C" int rd_800fc1f0(Name *, int *);
extern "C" int b1_80127da4(Game *);
extern "C" int b2_800fc550(Name *, int);
extern "C" void b3_800e64e8();
extern "C" int b4_80128bec(Game *);
extern "C" void b5_801297ec(Game *);
extern "C" void b6_80129770(Game *);
extern "C" void c1_801ea57c();
extern "C" int c2_80209b78();
extern "C" void d1_8015aee8(int);
extern "C" void d2_80128080(Game *);
extern "C" void d3_80129340(Game *);
extern "C" int d27i_game_initialize_80127db0(Game *self) {
    a1_80129108(self);a3_8015b424((void *)a2_8015c3ec());
    self->flags |= 0x20000000;
    int level = a4_801fcd6c();
    a5_801fcc48(1);
    a5_801fcc48(level);
    self->flags = (self->flags | 0x80000) & 0xb7cbeffe;
    int r = a6_801280b4(self);
    if (r < 0) return r;
    a7_80128f6c(self);
    r = a8_8015c670(self);
    if (r < 0) return r;
    {
        Name k1, k2;
        for (unsigned char i = 0; i <= 13; i++) {
            switch (i) {
            case 1:
            case 6:
            case 9:
                break;
            case 2:
                if (fa_800fd4c8(2, 2) < 0 && fa_800fd4c8(2, 1) < 0 && fb_800fd504(s_8039bea0, 2, 2) < 0)
                    fb_800fd504(s_8039bea0, 2, 1);
                k1.text = s_8039bea8;
                rd_800fc1f0(&k1, &v_804ab094);
                k2.text = s_8039beb8;
                rd_800fc1f0(&k2, &v_804ab098);
                break;
            default:
                if (fa_800fd4c8(i, 2) < 0)
                    fa_800fd4c8(i, 1);
                break;
            }
        }
    }
    Name k;
    k.text = s_8039beec;
    b2_800fc550(&k, b1_80127da4(self));
    fb_800fd504(s_8039bef8, 5, 1);
    b3_800e64e8();
    r = b4_80128bec(self);
    if (r < 0) return r;
    b5_801297ec(self);
    b6_80129770(self);
    unsigned f = self->flags;
    if (f & 0x20000000) {
        Log *log = sys_804b17ec->log;
        log->vt->a96(log, s_8039bf30, s_8039bf44, (f & 0x10000000) != 0);
    }
    if (self->flags & 0x10000000) {
        unsigned char i = 0;
        do {
            sys_804b17ec->log->vt->a60(sys_804b17ec->log, &i);
            sys_804b17ec->log->vt->a64(sys_804b17ec->log, &i);
            c1_801ea57c();
            c2_80209b78();
            i++;
        } while (i <= 88);
    }
    d1_8015aee8(5);
    d2_80128080(self);
    d3_80129340(self);
    if (self->flags & 0x100) self->w76 &= 0x7fffffff;
    self->w76 &= ~0x04000000;
    return r;
}
