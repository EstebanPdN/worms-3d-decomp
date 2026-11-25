// Partial selection owner and separately observed interface roles; no complete
// class size or identity is inferred from this cleanup routine.
struct d11b_SelectionFrame;
struct d11b_SelectionLabel;
template<class T> struct d11b_SelectionTable { unsigned int unknown00[4]; void (*release)(T *); };
struct d11b_SelectionFrame { d11b_SelectionTable<d11b_SelectionFrame> *vtable; };
struct d11b_SelectionLabel { d11b_SelectionTable<d11b_SelectionLabel> *vtable; };
template<class T> struct d11b_SelectionHandle { T *value; void reset(T *next) {if(value)value->vtable->release(value);value=next;} };
struct d11b_SelectionControl;
struct d11b_SelectionList;
struct d11b_SelectionBase;
struct d11b_SelectionOwner {
    unsigned char unknown00[212]; d11b_SelectionHandle<d11b_SelectionFrame> frame; d11b_SelectionHandle<d11b_SelectionLabel> label;
    unsigned char unknowndc[64]; d11b_SelectionControl *first,*second;
    unsigned char unknown124[112]; d11b_SelectionList *list; int active;
};
extern int d11b_selection_active_804abb4c;
extern "C" void d11b_release_selection_control_8015fd1c(d11b_SelectionControl *);
extern "C" void d11b_destroy_selection_list_802bcfb4(d11b_SelectionList *,unsigned int);
extern "C" void d11b_release_selection_slots_802ba070(d11b_SelectionOwner *);
extern "C" void d11b_clear_selection_base_802b0fec(d11b_SelectionBase *);
extern "C" void d11b_clear_selection_802b66c4(d11b_SelectionOwner *self) {
    self->frame.reset(0);self->label.reset(0);
    if(self->first) {d11b_release_selection_control_8015fd1c(self->first);self->first=0;}
    if(self->active==1) {d11b_selection_active_804abb4c=0;self->active=0;}
    if(self->list) {d11b_destroy_selection_list_802bcfb4(self->list,3);self->list=0;}
    if(self->second) {d11b_release_selection_control_8015fd1c(self->second);self->second=0;}
    d11b_release_selection_slots_802ba070(self);
    d11b_clear_selection_base_802b0fec(reinterpret_cast<d11b_SelectionBase *>(reinterpret_cast<unsigned char *>(self)+28));
}
