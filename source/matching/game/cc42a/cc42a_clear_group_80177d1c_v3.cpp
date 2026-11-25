// Partial inferred table/interface views. Class declarations and callback names
// are not original symbols. Two out-of-line identity entries preserve r3.
struct cc42a_Property;
struct cc42a_PropertyVtable {void* unknown00[6];int (*kind)(cc42a_Property*);void* unknown1c[2];int (*group)(cc42a_Property*);};
struct cc42a_Property {cc42a_PropertyVtable* vtable;};
struct cc42a_PropertyTable {unsigned char unknown00[24];cc42a_Property** entries;unsigned char unknown1c[2088];unsigned int count;};
extern "C" cc42a_Property* cc42a_identity_80341584(cc42a_Property*);
extern "C" cc42a_Property* cc42a_identity_80343744(cc42a_Property*);
extern "C" void cc42a_clear_80179770(cc42a_Property*);
extern "C" int cc42a_set_text_801790bc(cc42a_Property*,const char*);
extern "C" const char cc42a_emptyText_803a6d34[];
extern "C" int cc42a_clear_group_80177d1c(cc42a_PropertyTable* self,int group) {
 cc42a_Property** p=self->entries;
 cc42a_Property** end=p+self->count;
 int status=0;
 for(;p!=end;++p) {
  if(*p && (*p)->vtable->group(*p)==group) {
   switch((*p)->vtable->kind(*p)) {
    case 5:cc42a_clear_80179770(cc42a_identity_80341584(*p));break;
    case 4:cc42a_set_text_801790bc(cc42a_identity_80343744(*p),cc42a_emptyText_803a6d34);break;
    case 0:break; case 1:break; case 2:break; case 3:break; case 6:break; case 7:break;
    default:status=(int)0x80004005;break;
   }
  }
 }
 return status;
}
