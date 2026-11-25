#include "w3d_ptr.h"
#line 1 "d10b_clear_controls_80265fb4_v3.cpp"
// Partial owner, callback and handle views. Full original type identities and sizes unknown.
struct d10b_ClearControl;
struct d10b_ClearVtable {
    unsigned int unknown00[4];
    Ptr32<void (Ptr32<d10b_ClearControl>)> release;
    unsigned int unknown14;
    Ptr32<void (Ptr32<d10b_ClearControl>)> stop;
    unsigned int unknown1c[17];
    Ptr32<void (Ptr32<d10b_ClearControl>, Ptr32<d10b_ClearControl>)> remove;
    unsigned int unknown64[4];
    Ptr32<Ptr32<d10b_ClearControl> (Ptr32<d10b_ClearControl>, unsigned int)> item;
    Ptr32<unsigned int (Ptr32<d10b_ClearControl>)> count;
};
struct d10b_ClearControl { Ptr32<d10b_ClearVtable> vtable; };
struct d10b_ClearHandle {
    Ptr32<d10b_ClearControl> value;
    inline Ptr32<d10b_ClearControl> get() const { return value; }
    inline void reset(Ptr32<d10b_ClearControl> next) {
        if (value) value->vtable->release(value);
        value=next;
    }
};
struct d10b_ClearOwner {
    unsigned char unknown00[112]; Ptr32<d10b_ClearControl> parent;
    unsigned char unknown74[96]; d10b_ClearHandle queue;
    d10b_ClearHandle rows[6][7];
    unsigned char unknown180[112]; unsigned int state1f0,state1f4;
    unsigned char unknown1f8[60]; d10b_ClearHandle held;
    unsigned char unknown238[160]; d10b_ClearHandle audio;
};
struct d10b_BaseControlView;
extern "C" void d10b_clear_base_802b0fec(Ptr32<d10b_BaseControlView>);
extern "C" void d10b_clear_controls_80265fb4(Ptr32<d10b_ClearOwner> self) {
    if (self->queue.value) {
        while (self->queue.value->vtable->count(self->queue.value)) {
            Ptr32<d10b_ClearControl> queue=self->queue.value;
            Ptr32<d10b_ClearVtable> table=queue->vtable;
            table->remove(queue,table->item(queue,0));
        }
        for (unsigned int row=0;row<6;++row) {
            for (unsigned char col=0;col<7;++col) {
                if (self->rows[row][col].get()) self->rows[row][col].reset(0);
            }
        }
        self->parent->vtable->remove(self->parent,self->queue.value);
        self->queue.reset(0);
    }
    self->held.reset(0);
    if (self->audio.value) {
        self->audio.value->vtable->stop(self->audio.value);
        self->audio.reset(0);
    }
    self->state1f0=0;
    self->state1f4=0;
    d10b_clear_base_802b0fec(reinterpret_cast<d10b_BaseControlView *>(w3d::R(reinterpret_cast<unsigned char *>(w3d::R(self))+28)));
}


