// PPC32 mode +24 and slot vector +28. Interface reference slots +12/+16.
struct Service;struct Vtable {void *unused[3];int (*retain)(Service *);int (*release)(Service *);};struct Service {Vtable *vtable;};
struct Reader {unsigned char opaque[24];int mode;Service **slots;};
extern "C" int load_80202714(Reader *,Service **);
extern "C" unsigned int index_802024f4(Reader *);
extern "C" int w3d_cx11b_record_service_select_8020102c(Reader *self,Service **out){if(self->mode==0)return load_80202714(self,out);else if(self->mode==1){unsigned int i=index_802024f4(self);Service *s=self->slots[i];if(out){if(*out)(*out)->vtable->release(*out);*out=s;if(s)s->vtable->retain(s);}return 0;}return (int)0x80004005;}

