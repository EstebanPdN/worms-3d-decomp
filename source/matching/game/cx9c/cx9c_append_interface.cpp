/* Observed PPC32: count at +76, pointer array at +84; vtable retain/release
 * slots +12/+16. Class and method names are inferred. */
struct Cx9cInterface {void **vtable;};
struct Cx9cArray {unsigned int count,unknown;Cx9cInterface **begin;};
struct Cx9cOwner {unsigned char unknown[76];Cx9cArray array;};
extern "C" void cx9c_reserve_80210d54(Cx9cArray *,unsigned int);
extern "C" void w3d_cx9c_append_interface_8034b9bc(Cx9cOwner *self,Cx9cInterface *value) {
 Cx9cArray *array=&self->array;
 cx9c_reserve_80210d54(array,array->count+1);
 unsigned int offset=self->array.count<<2;Cx9cInterface **base=array->begin;
 if(value)((void (*)(Cx9cInterface *))value->vtable[3])(value);
 Cx9cInterface *old=*(Cx9cInterface **)(offset+(unsigned int)base);
 if(old)((void (*)(Cx9cInterface *))old->vtable[4])(old);
 *(Cx9cInterface **)(offset+(unsigned int)base)=value;
 self->array.count++;
}
