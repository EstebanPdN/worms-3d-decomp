/* Observed owner interface fields +56/+60/+64/+68/+112. Vtable retain
 * and release slots are +12/+16. Descriptor and service names inferred. */
struct Cx9cInterface {void **vtable;};
struct Cx9cDescriptor;
extern "C" Cx9cInterface *cx9c_lookup_8020b680(Cx9cDescriptor *);
struct Cx9cDescriptor {unsigned int opaque[4];Cx9cInterface *get(){return cx9c_lookup_8020b680(this);}};
extern "C" Cx9cDescriptor cx9c_descriptor_80413a68,cx9c_descriptor_804163f8,cx9c_descriptor_80413c78;
extern "C" Cx9cInterface *cx9c_lookup_8020b680(Cx9cDescriptor *);
struct Cx9cOwner {unsigned char opaque[56];Cx9cInterface *driver,*first,*second,*third;unsigned char unknown[40];Cx9cInterface *service;};
static inline void cx9c_assign(Cx9cInterface *&field,Cx9cInterface *value) {
 if(value)((void (*)(Cx9cInterface *))value->vtable[3])(value);
 if(field)((void (*)(Cx9cInterface *))field->vtable[4])(field);
 field=value;
}
extern "C" int w3d_cx9c_bind_services_80348570(Cx9cOwner *self) {
 cx9c_assign(self->first,cx9c_descriptor_80413a68.get());
 Cx9cInterface *second=cx9c_descriptor_80413a68.get();cx9c_assign(self->second,second);
 ((void (*)(Cx9cInterface *,int))second->vtable[14])(second,11);
 cx9c_assign(self->service,cx9c_descriptor_804163f8.get());
 Cx9cInterface *third=cx9c_descriptor_80413c78.get();cx9c_assign(self->third,third);
 ((void (*)(Cx9cInterface *,Cx9cInterface *))self->driver->vtable[6])(self->driver,third);
 return 0;
}
