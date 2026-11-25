// Native temporary conversion scratch and two observed plane conversions.
namespace Sol35d6ConvertPlanes {
struct Scratch { void *data; unsigned count; };
extern "C" {
extern Scratch sol35d6_scratch_804b0554;
void *sol35d6_allocate_801fe220(unsigned);
void sol35d6_array_release_801fe240(void *);
void sol35d6_convert_first_801d8e20(unsigned,int,int,int,unsigned,unsigned,void *);
void sol35d6_convert_second_801d8cd4(unsigned,int,int,int,unsigned,unsigned,void *);
}
inline const unsigned &maximum(const unsigned &a,const unsigned &b) { return a<b?b:a; }
}
extern "C" int sol35d6_convert_planes_801d8f98(
    void *first,void *,void *,unsigned width,unsigned height,void *second) {
    using namespace Sol35d6ConvertPlanes;
    unsigned count=maximum(unsigned(8192),width*height);
    if(sol35d6_scratch_804b0554.data)
        sol35d6_array_release_801fe240(sol35d6_scratch_804b0554.data);
    sol35d6_scratch_804b0554.count=count;
    sol35d6_scratch_804b0554.data=sol35d6_allocate_801fe220(count*4);
    sol35d6_convert_first_801d8e20(0,(int(width)+63)>>6,0,0,width,height,first);
    unsigned halfWidth=width>>1, halfHeight=height>>1;
    sol35d6_convert_second_801d8cd4(0,(int(halfWidth)+63)>>6,0,0,halfWidth,halfHeight,second);
    if(sol35d6_scratch_804b0554.data)
        sol35d6_array_release_801fe240(sol35d6_scratch_804b0554.data);
    sol35d6_scratch_804b0554.data=0;
    sol35d6_scratch_804b0554.count=0;
    return 0;
}
