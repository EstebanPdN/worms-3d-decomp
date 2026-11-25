
struct String{char *text;};extern "C" unsigned int random_80162ba8();extern "C" void assign_8020bd38(String*,const char*);extern "C" void * write_8020be94(String*,unsigned int,signed char);extern "C" void truncate_8020c3a0(String*,unsigned int);extern "C" void * parse_8026c8a8(void*,const char*);extern "C" char spaces_803cbc84[];
inline void put(String*out,unsigned int index,unsigned int random){write_8020be94(out,index,(signed char)(random%9+48));}
extern "C" void w3d_cx12b_random_numeric_seed_8026cd1c(void*self,String*out){unsigned int count=random_80162ba8()%12;if(count<=4)count=5;assign_8020bd38(out,spaces_803cbc84);for(unsigned int i=0;i<count;++i){put(out,i,random_80162ba8());}truncate_8020c3a0(out,count);parse_8026c8a8(self,out->text);}


