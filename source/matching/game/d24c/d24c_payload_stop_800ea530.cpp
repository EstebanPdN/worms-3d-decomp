// d24c: 0x800ea530 (252 bytes). Stop a payload: run the shared stop 0x800edbbc, write
// the entity id to the "Payload." setting and post a target-id message, release both
// actor handles (+252, +256, mode 3) and clear them, empty the word vector at +260
// (erase from begin: the memcpy of a size only known zero after CSE is kept), and
// release and clear the reference at +100. Names are inferred; the null local is the
// zero kept in a saved register across the calls.
typedef unsigned int size_t;
struct Object;
struct ObjectVtable {
    void *unknown00[4];
    void (*release)(Object *);      // +16
};
struct Object { ObjectVtable *vtable; };
struct Key { const char *text; };
extern "C" void *memcpy(void *, const void *, size_t);
struct Vec {
    int *start, *finish, *eos;
    void clear() {
        int *first = start;
        int *last = finish;
        int removed = (char *)last - (char *)first;
        memcpy(first, last, (char *)finish - (char *)last);
        finish = (int *)((char *)finish - removed);
    }
};
struct Payload {
    unsigned char u0[20];
    int id;            // +20
    unsigned char u24[76];
    Object *held;      // +100
    unsigned char u104[148];
    void *h252;        // +252
    void *h256;        // +256
    Vec list;          // +260
};
extern "C" void base_800edbbc(Payload *);
extern "C" int write_800fc43c(Key *, int);
extern "C" void *arena_801613f0(void *, int);
extern "C" short message_id_8015f5a0(int *, int);
extern "C" void *msg_init_801190b4(void *, unsigned short, int);
extern "C" int post_8016239c(void *);
extern "C" void member_80126230(void *, int);
extern void *arena_804b1754;
extern int cache_804aef28;
extern const char name_8038b3dc[];
extern "C" void d24c_payload_stop_800ea530(Payload *self) {
    base_800edbbc(self);
    int id = self->id;
    { Key k; k.text = name_8038b3dc; write_800fc43c(&k, id); }
    void *m = arena_801613f0(arena_804b1754, 12);
    post_8016239c(msg_init_801190b4(m, message_id_8015f5a0(&cache_804aef28, 1), id));
    if (self->h252) member_80126230(self->h252, 3);
    void *none = 0;
    self->h252 = none;
    if (self->h256) member_80126230(self->h256, 3);
    self->h256 = none;
    self->list.clear();
    if (self->held) self->held->vtable->release(self->held);
    self->held = (Object *)none;
}
