
// Construct a compact handle wrapper. The halfword at +2 is obtained from
// an allocator-like helper, configured by float and two words, and +4 stored.
struct Cx7aHandle {unsigned short unknown,id;unsigned int owner;};
extern "C" unsigned int allocate_8003f400(int);
extern "C" void bounds_8003fa2c(unsigned short,void *,float);
extern "C" void slot_8003fbb8(unsigned short,int);
extern "C" Cx7aHandle *w3d_cx7a_handle_construct_801261bc(Cx7aHandle *self,int a,float value,int b,unsigned int owner) {self->id=allocate_8003f400(0);bounds_8003fa2c(self->id,(void *)a,value);slot_8003fbb8(self->id,b);self->owner=owner;return self;}
