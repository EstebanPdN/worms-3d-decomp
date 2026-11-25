#include "w3d_ptr.h"
#line 1 "cx11b_record_service_select_8020102c.cpp"
// PPC32 mode +24 and slot vector +28. Interface reference slots +12/+16.
struct Service;struct Vtable {Ptr32<void> unused[3];Ptr32<int (Ptr32<Service>)> retain;Ptr32<int (Ptr32<Service>)> release;};struct Service {Ptr32<Vtable> vtable;};
struct Reader {unsigned char opaque[24];int mode;Ptr32<Ptr32<Service>> slots;};
extern "C" int load_80202714(Ptr32<Reader>,Ptr32<Ptr32<Service>>);
extern "C" unsigned int index_802024f4(Ptr32<Reader>);
extern "C" int w3d_cx11b_record_service_select_8020102c(Ptr32<Reader> self,Ptr32<Ptr32<Service>> out){if(self->mode==0)return load_80202714(self,out);else if(self->mode==1){unsigned int i=index_802024f4(self);Ptr32<Service> s=self->slots[i];if(out){if(*out)(*out)->vtable->release(*out);*out=s;if(s)s->vtable->retain(s);}return 0;}return (int)0x80004005;}



