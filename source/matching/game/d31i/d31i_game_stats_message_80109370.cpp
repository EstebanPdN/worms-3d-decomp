// d31i: 0x80109370. Game stats message handler: start and leave messages,
// Stats.DestString, flush, tallies, score changes and the active flag.
struct Message { unsigned short id; unsigned short Id() const { return id; } };
struct Key { const char *name; };
struct Stats { unsigned char unknown00[120]; int active; };
extern "C" int base_8016293c(Stats *, Message *);
extern "C" void start_8010a0f0(Stats *);
extern "C" void leave_8010a4ac(Stats *);
extern "C" int eq_8015f65c(unsigned, int *);
extern "C" int read_text_800fc2b0(Key *, const char **);
extern "C" void append_8010a01c(Stats *, const char *);
extern "C" void flush_80109bec(Stats *);
extern "C" void clear_80109ae4(Stats *);
extern "C" int get_800a830c(Message *);
extern "C" void tally_80109b1c(Stats *, int);
extern "C" void a_80109bc4(Stats *, int);
extern "C" void b_80109bb4(Stats *);
extern "C" void c_80109b0c(Stats *);
extern "C" void add_80109ab8(Stats *, int);
extern "C" void expand_80109604(Stats *);
extern int id_804af238, id_804af240, id_804af248, id_804af250, id_804af258, id_804af260, id_804af268, id_804af270, id_804af278, id_804af280, id_804af288, id_804af290, id_804af298, id_804af2a0;
extern const char s_80399c08[];
extern "C" int d31i_game_stats_message_80109370(Stats *self, Message *m) {
    unsigned short id = m->Id();
    switch (m->Id()) {
    case 64:
        if (base_8016293c(self, m) >= 0) {
            start_8010a0f0(self);
            return 0;
        }
        return 0x80004005;
    case 66:
        leave_8010a4ac(self);
        goto tail;
    }
    if (eq_8015f65c(id, &id_804af238)) {
        Key k = {s_80399c08};
        const char *text;
        read_text_800fc2b0(&k, &text);
        append_8010a01c(self, text);
    } else if (eq_8015f65c(id, &id_804af270)) {
        flush_80109bec(self);
        clear_80109ae4(self);
    } else if (eq_8015f65c(id, &id_804af250)) {
        tally_80109b1c(self, get_800a830c(m));
    } else if (eq_8015f65c(id, &id_804af258)) {
        a_80109bc4(self, get_800a830c(m));
    } else if (eq_8015f65c(id, &id_804af240)) {
        b_80109bb4(self);
    } else if (eq_8015f65c(id, &id_804af260) || eq_8015f65c(id, &id_804af268)) {
        c_80109b0c(self);
    } else if (eq_8015f65c(id, &id_804af278)) {
        add_80109ab8(self, 3);
    } else if (eq_8015f65c(id, &id_804af280)) {
        add_80109ab8(self, 1);
    } else if (eq_8015f65c(id, &id_804af288)) {
        add_80109ab8(self, 10);
        add_80109ab8(self, -3);
    } else if (eq_8015f65c(id, &id_804af290)) {
        add_80109ab8(self, -7);
    } else if (eq_8015f65c(id, &id_804af298)) {
        expand_80109604(self);
    } else {
        int a = eq_8015f65c(id, &id_804af2a0);
        if (a) self->active = 1;
        else if (eq_8015f65c(id, &id_804af248)) self->active = a;
    }
tail:
    return base_8016293c(self, m);
}
