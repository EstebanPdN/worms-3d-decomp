/* Inferred owner teardown, original 0x80344004: held interfaces at
 * observed offsets 128,124,120,116,112,108,104,100,96,92,88,84,80,76. Virtual release is slot+16;
 * complete-object deletion uses flag bit0 and the original small-data heap.
 * Calls are explicit in member order, matching observed unrolled destruction.
 */
struct Cx9cInterface{void **vtable;};
struct Cx9cHeap{unsigned int opaque[2];};
struct Cx9cOwner{unsigned char opaque[76];Cx9cInterface *held[14];};
extern "C" Cx9cHeap cx9c_heap_804b0044;
extern "C" void cx9c_base_destroy_8015a39c(Cx9cOwner*,int);
extern "C" void cx9c_heap_release_80209920(Cx9cHeap*,void*);
static inline void cx9c_release(Cx9cInterface *p){if(p)((void(*)(Cx9cInterface*))p->vtable[4])(p);}
extern "C" void w3d_cx9c_release_owner_80344004(Cx9cOwner *self,unsigned int flags){
 cx9c_release(self->held[13]);
 cx9c_release(self->held[12]);
 cx9c_release(self->held[11]);
 cx9c_release(self->held[10]);
 cx9c_release(self->held[9]);
 cx9c_release(self->held[8]);
 cx9c_release(self->held[7]);
 cx9c_release(self->held[6]);
 cx9c_release(self->held[5]);
 cx9c_release(self->held[4]);
 cx9c_release(self->held[3]);
 cx9c_release(self->held[2]);
 cx9c_release(self->held[1]);
 cx9c_release(self->held[0]);
 cx9c_base_destroy_8015a39c(self,0);
 if(flags&1)cx9c_heap_release_80209920(&cx9c_heap_804b0044,self);
}
