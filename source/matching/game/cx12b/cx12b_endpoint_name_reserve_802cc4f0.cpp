
struct Name{char bytes[128];};extern "C" Name names_804a9d38[];extern "C" char empty_803d9460[];extern "C" unsigned int enabled_804abce4,dirty_804abce8;extern "C" int compare_802ef234(const char*,const char*);extern "C" char*copy_802efbfc(char*,const char*,unsigned int);
extern "C" int w3d_cx12b_endpoint_name_reserve_802cc4f0(const char*name){if(!enabled_804abce4)return -1;unsigned int i=0;while(compare_802ef234(names_804a9d38[i].bytes,empty_803d9460)){if(i++==15)return -1;}names_804a9d38[i].bytes[127]=0;dirty_804abce8=1;copy_802efbfc(names_804a9d38[i].bytes,name,127);return i;}


