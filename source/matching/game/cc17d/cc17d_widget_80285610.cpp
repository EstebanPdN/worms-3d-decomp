// cc17d: widget constructor at 0x80285610 (same family as cx12b 0x8025f1b8).
// Observed: base constructor 0x8015fef0, member constructor 0x802afb20 at +28,
// vtables 0x8041bf90 at +0 and 0x8041bf40 at +208, then zeroed words.
struct Cc17dSub { int a; int b; int c; };
struct Cc17dWidget {
    void *vtable;
    unsigned char opaque[204];
    void *second;                      // +208
    int w212, w216, w220, w224, w228;  // +212..+228
    Cc17dSub sub;                      // +232
    int entries[3];                    // +244
    int w256, w260, w264, w268;        // +256..+268
};
extern "C" int base_8015fef0(Cc17dWidget *);
extern "C" void * member_802afb20(void *);
extern "C" unsigned char table_8041bf90[], table_8041bf40[];
// The +236 word is cleared through a pointer to the +232 member (inline member
// initializer), as the original addi r10,r31,232; stw 4(r10) shows.
static inline void cc17d_sub_init(Cc17dSub *s) { s->b = 0; }
extern "C" Cc17dWidget *w3d_cc17d_widget_construct_80285610(Cc17dWidget *self)
{
    volatile char pad[8];              // reserves the original 8-byte frame slot (unused local)
    base_8015fef0(self);
    member_802afb20((unsigned char *)self + 28);
    self->second = table_8041bf40;
    self->vtable = table_8041bf90;
    self->w224 = 0;
    self->w228 = 0;
    cc17d_sub_init(&self->sub);
    int *p = self->entries;
    int n = 3;
    do { *p++ = 0; } while (--n);
    self->w256 = 0; self->w260 = 0; self->w264 = 0; self->w268 = 0;
    self->w212 = 0; self->w216 = 0;
    self->sub.c = 0;
    self->w220 = 0;
    return self;
}
