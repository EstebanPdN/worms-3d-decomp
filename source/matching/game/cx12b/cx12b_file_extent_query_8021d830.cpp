
struct Stream {unsigned int words[6];};struct Extent {unsigned int value,opaque[3];};
extern "C" void construct_80207fec(Stream*);extern "C" int open_802080a0(Stream*,const char*,int);extern "C" void extent_802081c8(Stream*,Extent*);extern "C" int close_8020810c(Stream*);extern "C" void destroy_8020803c(Stream*,int);
extern "C" unsigned int w3d_cx12b_file_extent_query_8021d830(const char *path) {
 Stream s;construct_80207fec(&s);
 if(open_802080a0(&s,path,1)<0){destroy_8020803c(&s,2);return 0;}else{Extent out;extent_802081c8(&s,&out);close_8020810c(&s);unsigned int value=out.value;destroy_8020803c(&s,2);return value;}
}


