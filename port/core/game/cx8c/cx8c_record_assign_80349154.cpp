#include "w3d_ptr.h"
#line 1 "cx8c_record_assign_80349154.cpp"
/* Observed layout: scalar +0, three held interfaces +4/+8/+12,
 * 12-byte subobject +16, scalar +28. Names and ownership interpretation inferred. */
struct Cx8cInterface {Ptr32<Ptr32<void>> vtable;};
struct Cx8cSubrecord {unsigned int unknown[3];};
struct Cx8cRecord {unsigned int key;Ptr32<Cx8cInterface> first; Ptr32<Cx8cInterface> second; Ptr32<Cx8cInterface> third;Cx8cSubrecord member;unsigned int tail;};
extern "C" Ptr32<void> cx8c_assign_member_80210eb4(Ptr32<Cx8cSubrecord>,Ptr32<const Cx8cSubrecord>);
static inline void cx8c_assign(Ptr32<Cx8cInterface> &destination,Ptr32<Cx8cInterface> const &source) {
 if(source) ((Ptr32<void (Ptr32<Cx8cInterface>)>)source->vtable[3])(source);
 if(destination) ((Ptr32<void (Ptr32<Cx8cInterface>)>)destination->vtable[4])(destination);
 destination=source;
}
extern "C" Ptr32<Cx8cRecord> w3d_cx8c_record_assign_80349154(Ptr32<Cx8cRecord> self,Ptr32<const Cx8cRecord> other) {
 self->key=other->key;cx8c_assign(self->first,other->first);cx8c_assign(self->second,other->second);cx8c_assign(self->third,other->third);
 cx8c_assign_member_80210eb4(&self->member,&other->member);self->tail=other->tail;return self;
}


