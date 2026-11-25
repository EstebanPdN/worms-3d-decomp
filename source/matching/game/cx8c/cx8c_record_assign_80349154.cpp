/* Observed layout: scalar +0, three held interfaces +4/+8/+12,
 * 12-byte subobject +16, scalar +28. Names and ownership interpretation inferred. */
struct Cx8cInterface {void **vtable;};
struct Cx8cSubrecord {unsigned int unknown[3];};
struct Cx8cRecord {unsigned int key;Cx8cInterface *first,*second,*third;Cx8cSubrecord member;unsigned int tail;};
extern "C" void * cx8c_assign_member_80210eb4(Cx8cSubrecord *,const Cx8cSubrecord *);
static inline void cx8c_assign(Cx8cInterface *&destination,Cx8cInterface *const &source) {
 if(source) ((void (*)(Cx8cInterface *))source->vtable[3])(source);
 if(destination) ((void (*)(Cx8cInterface *))destination->vtable[4])(destination);
 destination=source;
}
extern "C" Cx8cRecord *w3d_cx8c_record_assign_80349154(Cx8cRecord *self,const Cx8cRecord *other) {
 self->key=other->key;cx8c_assign(self->first,other->first);cx8c_assign(self->second,other->second);cx8c_assign(self->third,other->third);
 cx8c_assign_member_80210eb4(&self->member,&other->member);self->tail=other->tail;return self;
}
