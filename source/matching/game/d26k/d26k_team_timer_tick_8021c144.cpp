// Team timer tick (Worms 3D GameCube PAL, 0x8021c144).
// 
// While the panel is active, its team has a value, the runtime is not paused,
// property bit 64 is set and the panel is not forced, counts the timer down.
// When it passes zero, applies the first looked-up service to the team, resets
// the timer to 100 and, if the second service flag is set, prepares and applies
// the second one. Service references retain and release through table slots 3
// and 4 (one word; user copy constructor declared, block mode, slots sp+8/sp+16).

struct SharedString;
extern "C" void string_init_8020c5c0(SharedString *);
extern "C" unsigned short *string_header_80341884(SharedString *);
extern "C" void string_finish_8020c5c4(SharedString *);
extern "C" void string_release_80341588(SharedString *);
extern "C" void release_header_8020bb2c(unsigned short *);
extern "C" SharedString *string_from_text_8020bb54(SharedString *, const char *);
struct SharedString {
    char *text;
    SharedString(const char *s) { string_from_text_8020bb54(this, s); }
    SharedString(const SharedString &other) {
        string_init_8020c5c0(this);
        text = other.text;
        ++*string_header_80341884(this);
    }
    ~SharedString() {
        string_finish_8020c5c4(this);
        string_release_80341588(this);
    }
    SharedString &operator=(const SharedString &other) {
        ++reinterpret_cast<unsigned short *>(other.text)[-3];
        unsigned short *header = reinterpret_cast<unsigned short *>(text) - 3;
        if (--*header == 0) {
            release_header_8020bb2c(header);
        }
        text = other.text;
        return *this;
    }
};
struct Interface;
struct InterfaceTable {
    void *reserved[3];
    int (*retain)(Interface *);
    int (*release)(Interface *);
};
struct Interface { InterfaceTable *table; };
struct Ref {
    Interface *p;
    Ref(Interface *o) : p(o) { if (p) p->table->retain(p); }
    Ref(const Ref &);
    ~Ref() { if (p) p->table->release(p); }
};
struct Team;
struct Owner { char pad[24]; Team *team; };
struct Panel {
    char pad0[36]; Owner *owner; char pad1[92 - 40]; int active;
    char pad2[112 - 96]; int timer; int step; int second; char pad3[156 - 124]; int forced;
};
extern "C" int value_8021eb00(Team *);
extern "C" int paused_8015ccbc(void *);
extern "C" unsigned props_80240b84(Team *);
extern "C" Interface *lookup_8020b680(const void *);
extern "C" int apply_8021e930(Team *, Interface *);
extern "C" void *context_80165254(void);
extern "C" void prepare_8021e054(Interface *);
extern void *global_804b1788;
extern const char key_8041aac8[];
extern const char key_8041aae8[];
extern "C" void w3d_d26k_team_timer_tick_8021c144(Panel *self) {
    Team *team = self->owner->team;
    if (self->active != 0 && value_8021eb00(team) != 0 && paused_8015ccbc(global_804b1788) == 0
        && (props_80240b84(team) & 64) != 0 && self->forced == 0) {
        self->timer -= self->step;
        if (self->timer < 0) {
            Ref first(lookup_8020b680(key_8041aac8));
            apply_8021e930(team, first.p);
            self->timer = 100;
            if (self->second != 0) {
                context_80165254();
                Ref next(lookup_8020b680(key_8041aae8));
                prepare_8021e054(next.p);
                apply_8021e930(team, next.p);
            }
        }
    }
}
