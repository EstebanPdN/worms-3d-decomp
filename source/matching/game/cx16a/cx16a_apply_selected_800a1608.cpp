// Observed PPC32 fields. The helper returns a three-word property value.
struct Cx16aValue { int x,y; };
struct Cx16aOwner { char pad[36]; void *target; void *selector; };
extern "C" unsigned select_80178c48(void*);
extern "C" void *cast_8034357c(void*);
extern "C" void * read_800fd388(void*,...);
extern "C" int apply_80173df0(void*,void*);
extern "C" void w3d_cx16a_apply_selected_800a1608(Cx16aOwner *self) {
 unsigned index=select_80178c48(self->selector);
 if(index<16) { Cx16aValue value; Cx16aValue *vp=&value; void *target=cast_8034357c(self->target); read_800fd388(vp,index); apply_80173df0(target,vp); }
}
