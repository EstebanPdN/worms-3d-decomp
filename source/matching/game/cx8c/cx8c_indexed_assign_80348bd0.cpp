/* Observed offsets and 32-byte record stride; semantic names inferred. */
struct Cx8cInterface {void **vtable;};
struct Cx8cArray {unsigned int words[2];Cx8cInterface **begin;};
struct Cx8cRecord {unsigned char unknown[16];Cx8cArray array;unsigned int tail;};
struct Cx8cOwner {unsigned char unknown[24];Cx8cRecord *records;unsigned char unknown_1c[44];unsigned int capacity;};
extern "C" void cx8c_reserve_80210b90(Cx8cArray *,unsigned int);
extern "C" int w3d_cx8c_indexed_assign_80348bd0(Cx8cOwner *self,unsigned int record,unsigned int index,Cx8cInterface *value) {
 unsigned int record_offset=record<<5;unsigned int offset=index<<2;
 cx8c_reserve_80210b90(&((Cx8cRecord *)((unsigned int)self->records+record_offset))->array,self->capacity);
 Cx8cInterface **base=((Cx8cRecord *)((unsigned int)self->records+record_offset))->array.begin;
 if(value) ((void (*)(Cx8cInterface *))value->vtable[3])(value);
 Cx8cInterface *old=*(Cx8cInterface **)(offset+(unsigned int)base);
 if(old) ((void (*)(Cx8cInterface *))old->vtable[4])(old);
 *(Cx8cInterface **)(offset+(unsigned int)base)=value;return 0;
}
