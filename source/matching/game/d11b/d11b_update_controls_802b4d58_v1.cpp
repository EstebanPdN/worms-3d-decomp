// Partial owner/control interfaces. Flags remain full-width XOR values; they are
// not normalized to C++ bool except the independently observed null test.
struct d11b_Control;
struct d11b_ControlTable { unsigned int unknown00[22]; void (*enable)(d11b_Control *,unsigned int); };
struct d11b_Control { d11b_ControlTable *vtable; };
struct d11b_ControlOwner {
    unsigned char unknown00[140]; unsigned int active;
    unsigned char unknown90[32]; unsigned int selected;
    unsigned char unknownb4[44]; d11b_Control *first,*second,*third;
    unsigned int getSelected() const {return selected;}
    unsigned int getActive() const {return active;}
};
extern "C" void d11b_update_controls_802b4d58(d11b_ControlOwner *self) {
    unsigned int selected=self->getSelected();
    unsigned int active=self->getActive();
    unsigned int first=selected^1;
    unsigned int third=active^1;
    if (active==0) { first=1;if(self->third)first=0; selected=0; }
    if (self->first) self->first->vtable->enable(self->first,first);
    if (self->second) self->second->vtable->enable(self->second,selected);
    if (self->third) self->third->vtable->enable(self->third,third);
}
