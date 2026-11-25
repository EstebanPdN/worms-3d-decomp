// Partial inferred string and factory views. The header reference field is an
// unsigned 16-bit value six bytes before the text, including wraparound.
struct cc42a_String_8020bb54 {char* text;cc42a_String_8020bb54(const char*);~cc42a_String_8020bb54();};
extern "C" void cc42a_string_finish_8020c5c4(cc42a_String_8020bb54*);
extern "C" void cc42a_string_release_80341588(cc42a_String_8020bb54*);
extern "C" void cc42a_header_release_8020bb2c(void*);
inline cc42a_String_8020bb54::~cc42a_String_8020bb54(){cc42a_string_finish_8020c5c4(this);cc42a_string_release_80341588(this);}
struct cc42a_DescriptorFlags {unsigned char unknown00[7];unsigned char value;};
struct cc42a_Descriptor {unsigned char unknown00[4];cc42a_DescriptorFlags flags;unsigned char unknown0c[8];void* record;};
struct cc42a_Factory;
struct cc42a_FactoryVtable {void* unknown00[29];cc42a_Descriptor* (*lookup)(cc42a_Factory*,const unsigned char*);};
struct cc42a_Factory {cc42a_FactoryVtable* vtable;};
struct cc42a_Created {unsigned char unknown00[36];cc42a_String_8020bb54 name;};
extern "C" void cc42a_append_801ef174(void*,unsigned int,unsigned int,cc42a_Created*);
inline void cc42a_set_flags(cc42a_DescriptorFlags* self){self->value|=2;}
extern "C" cc42a_Created* cc42a_name_created_8017e6d0(cc42a_Factory* self,const char* name,unsigned char group,unsigned int unused,cc42a_Created* result) {
 unsigned char key=group;
 cc42a_Descriptor* descriptor=self->vtable->lookup(self,&key);
 void* record=descriptor->record;
 {
  cc42a_String_8020bb54 temporary(name);
  ++*(unsigned short*)(temporary.text-6);
  unsigned short* old=(unsigned short*)(result->name.text-6);
  if(--*old==0)cc42a_header_release_8020bb2c(old);
  result->name.text=temporary.text;
 }
 cc42a_append_801ef174(record,44,3,result);
 cc42a_set_flags(&descriptor->flags);
 return result;
}
