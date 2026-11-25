struct K4bVec3 { float x, y, z; };
struct K4bBox {
    void **vtable;
    char base[16];
    struct K4bVec3 min;
    struct K4bVec3 max;
    int valid;
    int slots[4];
};
struct K4bLinkedBox {
    struct K4bBox box;
    int links[6];
    int owner;
};
extern void *lbl_80415a50[];
extern struct K4bBox *w3d_k4b_box_construct_801b5b30(struct K4bBox *self, void *);
struct K4bLinkedBox *w3d_k4b_linked_box_construct_801b6804(struct K4bLinkedBox *self, void * arg_r4)
{
    unsigned int i;
    w3d_k4b_box_construct_801b5b30(&self->box, arg_r4);
    self->box.vtable = lbl_80415a50;
    self->links[0] = 0;
    self->links[1] = 0;
    self->links[2] = 0;
    self->links[3] = 0;
    self->links[4] = 0;
    self->links[5] = 0;
    self->owner = 0;
    for (i = 0; i < 4; i++)
        self->box.slots[i] = 0;
    return self;
}
// desc: w3d_k4b_linked_box_construct_801b6804: Appears to construct a derived bounds object over 0x801b5b30: vtable 0x80415a50, six cleared link words, cleared owner and cleared slots.
