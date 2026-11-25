// Partial external object/type/owner views; none is locally allocated.
// Type descriptors use the observed parent pointer at+20 and self-parent roots.
// Descriptor names and the reason for each sound family remain unidentified.
struct F15cSoundType{char unknown[20];F15cSoundType*parent;};
struct F15cSoundObject{void **vtable;};
struct F15cSoundOwner{char unknown0[20];int handle;char unknown24[280];const char *property;};
extern F15cSoundType type_80367b08[],type_80367ba8[],type_80367bf8[];
inline bool soundType0(F15cSoundType*p){while(p!=type_80367b08){if(p==p->parent)return false;p=p->parent;}return true;}
inline bool soundType1(F15cSoundType*p){while(p!=type_80367ba8){if(p==p->parent)return false;p=p->parent;}return true;}
inline bool soundType2(F15cSoundType*p){while(p!=type_80367bf8){if(p==p->parent)return false;p=p->parent;}return true;}
extern "C" {
void *lookup_80164fc8(int);int read_800fc330(const char**,F15cSoundObject**);
void pair0_800edc28(F15cSoundOwner*),pair1_800edca0(F15cSoundOwner*),single_800edd1c(F15cSoundOwner*);
void f15c_sound_dispatch_800ede3c(F15cSoundOwner*self){
 if(lookup_80164fc8(self->handle)){
  const char *property=self->property;F15cSoundObject *object;read_800fc330(&property,&object);
  F15cSoundType *type=((F15cSoundType*(*)(F15cSoundObject*))object->vtable[5])(object);
  if(soundType0(type))pair0_800edc28(self);
  if(soundType1(type))pair1_800edca0(self);
  else if(soundType2(type))single_800edd1c(self);
 }
}
}
