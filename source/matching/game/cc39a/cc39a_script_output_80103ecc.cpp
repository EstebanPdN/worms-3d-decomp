// Script output concatenation: partial string/header and runtime views only.
struct cc39a_Lua;
struct cc39a_String{char* text;unsigned opaque;};
struct cc39a_Runtime {unsigned char unknown[68];cc39a_Lua* state;unsigned char gap72[292];cc39a_String output;};
extern char* cc39a_empty_804b06a0[];
extern const char cc39a_format_80399480[],cc39a_error_80399508[];
extern "C" {
int cc39a_top_802cd7f4(cc39a_Lua*);int cc39a_number_802cda9c(cc39a_Lua*,int);int cc39a_string_802cdaf4(cc39a_Lua*,int);
double cc39a_value_802cdc5c(cc39a_Lua*,int);const char* cc39a_text_802cdd04(cc39a_Lua*,int);
int cc39a_format_802ec254(char*,const char*,...);
void cc39a_append_8020bf2c(cc39a_String*,const char*);void cc39a_free_8020bb2c(void*);
void cc39a_report_801022ec(cc39a_Runtime*,const char*);void cc39a_output_801022e8(cc39a_Runtime*,const char*);
void cc39a_settop_802cd808(cc39a_Lua*,int);
}
extern "C" int cc39a_script_output_80103ecc(cc39a_Runtime* self){
 int count=cc39a_top_802cd7f4(self->state);
 ++*(unsigned short*)(cc39a_empty_804b06a0[0]-6);
 unsigned short* header=(unsigned short*)(self->output.text-6);
 if(--*header==0)cc39a_free_8020bb2c(header);
 self->output.text=cc39a_empty_804b06a0[0];
 for(int index=1;index<=count;++index){
  if(cc39a_number_802cda9c(self->state,index)){
   char buffer[64];cc39a_format_802ec254(buffer,cc39a_format_80399480,cc39a_value_802cdc5c(self->state,index));
   cc39a_append_8020bf2c(&self->output,buffer);
  }else{
   if(!cc39a_string_802cdaf4(self->state,index)){cc39a_report_801022ec(self,cc39a_error_80399508);cc39a_settop_802cd808(self->state,-count-1);return 0;}
   cc39a_append_8020bf2c(&self->output,cc39a_text_802cdd04(self->state,index));
  }
 }
 cc39a_output_801022e8(self,self->output.text);
 cc39a_settop_802cd808(self->state,-count-1);return 0;
}
