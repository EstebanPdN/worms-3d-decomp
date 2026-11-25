/* Observed 184-byte element stride and context pointer at +108. The array
 * allocation has the reference compiler's eight-byte cookie; its first
 * word holds the element count. Element/owner names are inferred. */
extern "C" void *cx9c_array_allocate_800dc5bc(unsigned int);
struct Cx9cRecord_800de6c4 {
 unsigned char opaque[108];void *context;unsigned char tail[72];
 Cx9cRecord_800de6c4();~Cx9cRecord_800de6c4(){}
 static void *operator new[](unsigned int bytes){return cx9c_array_allocate_800dc5bc(bytes);}
};
struct Cx9cOwner {unsigned int opaque;Cx9cRecord_800de6c4 *begin;void *context;};
extern "C" void w3d_cx9c_actor_array_80344a68(Cx9cOwner *self,unsigned int count) {
 self->begin=new Cx9cRecord_800de6c4[count];
 for(unsigned int i=0;i<count;++i)self->begin[i].context=self->context;
}
