// Partial grid-owner layout. Each child record's observed stride is sixteen
// bytes; only its first pointer is interpreted. Complete owner size is unknown.
struct d11b_GridControl;
struct d11b_GridTable {
    unsigned int unknown00[4]; void (*release)(d11b_GridControl *);
    unsigned int unknown14[19]; void (*remove)(d11b_GridControl *,d11b_GridControl *);
};
struct d11b_GridControl { d11b_GridTable *vtable; };
struct d11b_GridHandle {
    d11b_GridControl *value;
    void reset(d11b_GridControl *next) { if(value)value->vtable->release(value);value=next; }
};
struct d11b_GridChild { d11b_GridHandle handle; unsigned char unknown04[12]; };
struct d11b_GridOwner {
    unsigned char unknown00[212]; d11b_GridHandle first,second,third;
    unsigned char unknowne0[20]; d11b_GridHandle root,parents[3];
    unsigned char unknown104[820]; d11b_GridChild children[3][5];
    unsigned char unknown528[36]; d11b_GridHandle finalA,finalB,clips[3];
};
struct d11b_GridBase;
extern "C" void d11b_clear_grid_base_802b0fec(d11b_GridBase *);
extern "C" void d11b_clear_grid_802a9f54(d11b_GridOwner *self) {
    self->root.reset(0);
    d11b_GridChild *children=&self->children[0][0];
    for (int i=0;i<3;++i) {
        unsigned int offset=i*sizeof(d11b_GridHandle);
        d11b_GridHandle *parent=reinterpret_cast<d11b_GridHandle *>(offset+reinterpret_cast<unsigned char *>(self)+248);
        d11b_GridChild *child=children+i*5;
        int remaining=5;
        do {
            if(child->handle.value) {
                parent->value->vtable->remove(parent->value,child->handle.value);
                child->handle.reset(0);
            }
            ++child;
        } while(--remaining);
        reinterpret_cast<d11b_GridHandle *>(offset+reinterpret_cast<unsigned char *>(self)+248)->reset(0);
        reinterpret_cast<d11b_GridHandle *>(offset+reinterpret_cast<unsigned char *>(self)+1364)->reset(0);
    }
    self->first.reset(0);self->second.reset(0);self->third.reset(0);
    self->finalB.reset(0);self->finalA.reset(0);
    d11b_clear_grid_base_802b0fec(reinterpret_cast<d11b_GridBase *>(reinterpret_cast<unsigned char *>(self)+28));
}
