/* Reference-only: a missing slot leaves index -1 and the original still accesses
   before the table. List counts beyond the observed two-index prefix are not
   validated; neither case establishes portable C behavior. */
/* Two helpers for the 16-entry, 64-byte slot table at 0x8045dbc8. The word at
   offset 60 of a slot holds flag bits: 0x40000000 marks a slot as armed, and
   the top two bits are cleared or the top bit is set when it is released or
   retained. The owner object keeps up to a few 16-bit slot indices (0xffff
   means none) behind a flag word. Offsets are observed; names and meanings
   are inferred. */
typedef struct { char p0[60]; unsigned flags; } Slot;
typedef struct { unsigned short ids[2]; unsigned flags; int p1; unsigned count; } SlotList;
typedef struct { int p0; SlotList list; } SlotOwner;
extern Slot lbl_8045dbc8[];
extern int fn_802f5320(Slot *);

void tsonnet_c29_slot_mark_801e59b4(int mode, Slot *slot) {
    int idx = -1;
    unsigned i;
    for (i = 0; i < 16; i++) if (&lbl_8045dbc8[i] == slot) { idx = i; break; }
    { Slot *s = &lbl_8045dbc8[idx]; if (s->flags & 0x40000000) { if (mode == -1) s->flags &= 0x3fffffff; else s->flags |= 0x80000000; fn_802f5320(&lbl_8045dbc8[idx]); } }
}

void tsonnet_c29_slots_release_801e5e74(SlotOwner *self) {
    if (self->list.flags & 0x200000) {
        unsigned i;
        for (i = 0; i < self->list.count; i++) {
            if (self->list.ids[i] <= 15) {
                Slot *s = &lbl_8045dbc8[self->list.ids[i]];
                s->flags &= 0x3fffffff;
                fn_802f5320(&lbl_8045dbc8[self->list.ids[i]]);
                self->list.ids[i] = -1;
            }
        }
    }
    *(unsigned char *)&self->list.flags = 0;
    self->list.flags &= ~0x200000;
}
