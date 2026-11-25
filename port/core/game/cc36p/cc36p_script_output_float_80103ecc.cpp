#include "w3d_ptr.h"
#line 1 "cc36p_script_output_float_80103ecc.cpp"
// Corrected lua_Number prototype: this project defines LUA_NUMBER=float.
// Default varargs promotion still passes the original FPR argument to sprintf.
// Script output concatenation: partial string/header and runtime views only.
struct cc36p_Lua;
struct cc36p_String{Ptr32<char> text;unsigned opaque;};
struct cc36p_Runtime {unsigned char unknown[68];Ptr32<cc36p_Lua> state;unsigned char gap72[292];cc36p_String output;};
extern Ptr32<char> cc36p_empty_804b06a0[];
extern const char cc36p_format_80399480[],cc36p_error_80399508[];
extern "C" {
int cc36p_top_802cd7f4(Ptr32<cc36p_Lua>);int cc36p_number_802cda9c(Ptr32<cc36p_Lua>,int);int cc36p_string_802cdaf4(Ptr32<cc36p_Lua>,int);
float cc36p_value_802cdc5c(Ptr32<cc36p_Lua>,int);Ptr32<const char> cc36p_text_802cdd04(Ptr32<cc36p_Lua>,int);
int cc36p_format_802ec254(Ptr32<char>,Ptr32<const char>,...);
Ptr32<void> cc36p_append_8020bf2c(Ptr32<cc36p_String>,Ptr32<const char>);void cc36p_free_8020bb2c(Ptr32<void>);
void cc36p_report_801022ec(Ptr32<cc36p_Runtime>,Ptr32<const char>);void cc36p_output_801022e8(Ptr32<cc36p_Runtime>,Ptr32<const char>);
void cc36p_settop_802cd808(Ptr32<cc36p_Lua>,int);
}
extern "C" int cc36p_script_output_float_80103ecc(Ptr32<cc36p_Runtime> self){
 int count=cc36p_top_802cd7f4(self->state);
 ++*(Ptr32<unsigned short>)(cc36p_empty_804b06a0[0]-6);
 Ptr32<unsigned short> header=(Ptr32<unsigned short>)(self->output.text-6);
 if(--*header==0)cc36p_free_8020bb2c(header);
 self->output.text=cc36p_empty_804b06a0[0];
 for(int index=1;index<=count;++index){
  if(cc36p_number_802cda9c(self->state,index)){
   char buffer[64];cc36p_format_802ec254(buffer,cc36p_format_80399480,cc36p_value_802cdc5c(self->state,index));
   cc36p_append_8020bf2c(&self->output,buffer);
  }else{
   if(!cc36p_string_802cdaf4(self->state,index)){cc36p_report_801022ec(self,cc36p_error_80399508);cc36p_settop_802cd808(self->state,-count-1);return 0;}
   cc36p_append_8020bf2c(&self->output,cc36p_text_802cdd04(self->state,index));
  }
 }
 cc36p_output_801022e8(self,self->output.text);
 cc36p_settop_802cd808(self->state,-count-1);return 0;
}


