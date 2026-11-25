// Partial selection owner and separately observed interface roles; no complete
// class size or identity is inferred from this cleanup routine.
struct sol35e_SelectionFrame;
struct sol35e_SelectionLabel;
template<class T> struct sol35e_SelectionTable { unsigned int unknown00[4]; void (*release)(T *); };
struct sol35e_SelectionFrame { sol35e_SelectionTable<sol35e_SelectionFrame> *vtable; };
struct sol35e_SelectionLabel { sol35e_SelectionTable<sol35e_SelectionLabel> *vtable; };
template<class T> struct sol35e_SelectionHandle { T *value; void reset(T *next) {if(value)value->vtable->release(value);value=next;} };
struct sol35e_SelectionControl;
struct sol35e_SelectionList;
struct sol35e_SelectionBase;
struct sol35e_SelectionOwner {
    unsigned char unknown00[212]; sol35e_SelectionHandle<sol35e_SelectionFrame> frame; sol35e_SelectionHandle<sol35e_SelectionLabel> label;
    unsigned char unknowndc[64]; sol35e_SelectionControl *first,*second;
    unsigned char unknown124[112]; sol35e_SelectionList *list; int active;
};
extern int sol35e_selection_active_804abb4c;
extern "C" void sol35e_release_selection_control_8015fd1c(sol35e_SelectionControl *);
extern "C" void sol35e_destroy_selection_list_802bcfb4(sol35e_SelectionList *,unsigned int);
extern "C" void sol35e_release_selection_slots_802ba070(sol35e_SelectionOwner *);
extern "C" void sol35e_clear_selection_base_802b0fec(sol35e_SelectionBase *);
inline void sol35e_clear_selection(sol35e_SelectionOwner *self,sol35e_SelectionFrame *empty) {
    self->frame.reset(empty);self->label.reset(0);
    if(self->first) {sol35e_release_selection_control_8015fd1c(self->first);self->first=0;}
    if(self->active==1) {sol35e_selection_active_804abb4c=0;self->active=0;}
    if(self->list) {sol35e_destroy_selection_list_802bcfb4(self->list,3);self->list=0;}
    if(self->second) {sol35e_release_selection_control_8015fd1c(self->second);self->second=reinterpret_cast<sol35e_SelectionControl *>(empty);}
    sol35e_release_selection_slots_802ba070(self);
    sol35e_clear_selection_base_802b0fec(reinterpret_cast<sol35e_SelectionBase *>(reinterpret_cast<unsigned char *>(self)+28));
}

extern "C" void sol35e_clear_selection_802b66c4(sol35e_SelectionOwner *self) {sol35e_clear_selection(self,0);}
