// Original [0x8004c378,0x8004c51c), 420 bytes. Names and complete types inferred.
// The sparse receiver describes observed GC32 fields, not a portable full class.
// clear(value) releases the actual held interface before storing its replacement.
struct Crate;
struct Interface { void **vtable; };
struct Team { unsigned char unknown00[213]; unsigned char index; };
struct Crate {
    unsigned char unknown00[28];
    int kind, index;
    unsigned char unknown24[44];
    unsigned actor;
    unsigned char unknown54[48];
    unsigned collected;
    unsigned char unknown88[8];
    unsigned showered;
    unsigned char unknown94[96];
    Interface *held;
    void clear(Interface *value) {
        if (held) ((void (*)(Interface *))held->vtable[4])(held);
        held = value;
    }
};
struct Engine { unsigned char unknown00[108]; Interface *effects; };
// The compiler supplies the alignment gap between the ID and table pointer.
struct Message { unsigned short id; void *table; };
inline void *operator new(unsigned, void *storage) { return storage; }
extern "C" {
Team *fn_800fc6dc(unsigned);
void fn_8004c598(Crate *, unsigned);
void fn_8004c814(Crate *, unsigned);
void fn_8004c670(Crate *, unsigned);
void *fn_801613f0(void *, unsigned);
unsigned fn_8015f5a0(void *, unsigned);
void *fn_800a82f0(void *, unsigned short, unsigned);
int fn_8016239c(void *);
int fn_800fc3b0(const char **, unsigned);
int fn_800e5ca4(void *, const char *, int, float);
void fn_8015fd1c(Crate *);
extern void *pool_804b1754;
extern unsigned cache_804ad3b0[2], cache_804ad358[2];
extern char table_8040db38[], name_80377118[], name_80376ed4[];
extern char name_803772cc[], name_803772dc[];
extern float f_803772ec[];
extern Engine *engine_804b1788;
}
extern "C" void sol35a6_crate_collect_8004c378(Crate *self) {
    if (!self->collected) {
        self->collected = 1;
        Team *team = fn_800fc6dc(self->actor);
        switch (self->kind) {
        case 1: fn_8004c598(self, self->actor); break;
        case 0: fn_8004c814(self, team->index); break;
        case 2: fn_8004c670(self, team->index); break;
        }
        void *message = fn_801613f0(pool_804b1754, 12);
        fn_8016239c(fn_800a82f0(message,
            (unsigned short)fn_8015f5a0(cache_804ad3b0, 1), self->actor));
        const char *index = name_80377118;
        fn_800fc3b0(&index, self->index);
        const char *showered = name_80376ed4;
        fn_800fc3b0(&showered, self->showered);
        Message *event = new (fn_801613f0(pool_804b1754, 8)) Message;
        event->id = fn_8015f5a0(cache_804ad358, 1);
        event->table = table_8040db38;
        fn_8016239c(event);
        self->clear(0);
        Interface *effects = engine_804b1788->effects;
        void *position = (char *)self + 40;
        if (effects)
            ((void (*)(Interface *, const char *, void *))effects->vtable[24])
                (effects, name_803772cc, position);
        fn_800e5ca4(position, name_803772dc, 0, f_803772ec[0]);
        fn_8015fd1c(self);
    }
}
// These assertions document the observed reference ABI without runtime work.
typedef char pointer_width[(sizeof(void *) == 4) ? 1 : -1];
typedef char message_size[(sizeof(Message) == 8) ? 1 : -1];
typedef char message_table_offset[((unsigned)&((Message *)0)->table == 4) ? 1 : -1];
