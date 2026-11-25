#include "w3d_ptr.h"
#line 1 "cx12b_random_numeric_seed_8026cd1c.cpp"

struct String{Ptr32<char> text;};extern "C" unsigned int random_80162ba8();extern "C" void assign_8020bd38(Ptr32<String>,Ptr32<const char>);extern "C" Ptr32<void> write_8020be94(Ptr32<String>,unsigned int,signed char);extern "C" void truncate_8020c3a0(Ptr32<String>,unsigned int);extern "C" Ptr32<void> parse_8026c8a8(Ptr32<void>,Ptr32<const char>);extern "C" char spaces_803cbc84[];
inline void put(Ptr32<String> out,unsigned int index,unsigned int random){write_8020be94(out,index,(signed char)(random%9+48));}
extern "C" void w3d_cx12b_random_numeric_seed_8026cd1c(Ptr32<void> self,Ptr32<String> out){unsigned int count=random_80162ba8()%12;if(count<=4)count=5;assign_8020bd38(out,spaces_803cbc84);for(unsigned int i=0;i<count;++i){put(out,i,random_80162ba8());}truncate_8020c3a0(out,count);parse_8026c8a8(self,out->text);}




