// Partial owner and reference-counted callback views; complete original sizes unknown.
struct d10b_LayoutControl;
struct d10b_LayoutTable {
    unsigned int unknown00[4]; void (*release)(d10b_LayoutControl *);
    unsigned int unknown14[19]; void (*remove)(d10b_LayoutControl *,d10b_LayoutControl *);
    unsigned int unknown64[4]; d10b_LayoutControl *(*item)(d10b_LayoutControl *,unsigned int);
    unsigned int (*count)(d10b_LayoutControl *);
};
struct d10b_LayoutControl { d10b_LayoutTable *vtable; };
struct d10b_LayoutHandle {
    d10b_LayoutControl *value;
    void reset(d10b_LayoutControl *next) { if(value)value->vtable->release(value); value=next; }
};
struct d10b_LayoutOwner {
    unsigned char unknown00[28]; d10b_LayoutControl *queue;
    unsigned int unknown20; d10b_LayoutHandle first,second,third,fourth,fifth,sixth;
    int ready; unsigned char unknown40[28]; int horizontal,vertical;
};
extern "C" void d10b_build_layout_802b3148(d10b_LayoutOwner *);
extern "C" void d10b_apply_layout_802b38d4(d10b_LayoutOwner *);
extern "C" void d10b_rebuild_layout_802b3d04(d10b_LayoutOwner *self,int horizontal,int vertical) {
    if(self->horizontal!=horizontal || self->vertical!=vertical) {
        self->horizontal=horizontal;
        self->vertical=vertical;
        if(self->ready==1) {
            while(self->queue->vtable->count(self->queue)) {
                d10b_LayoutControl *queue=self->queue;
                d10b_LayoutTable *table=queue->vtable;
                table->remove(queue,table->item(queue,0));
            }
            self->first.reset(0); self->second.reset(0); self->third.reset(0);
            self->fourth.reset(0); self->fifth.reset(0); self->sixth.reset(0);
            self->ready=0;
            d10b_build_layout_802b3148(self);
            d10b_apply_layout_802b38d4(self);
        }
    }
}
