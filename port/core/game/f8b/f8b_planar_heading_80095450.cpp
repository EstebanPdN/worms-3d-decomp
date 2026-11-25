#include "w3d_ptr.h"
#line 1 "f8b_planar_heading_80095450.cpp"
// Inferred component and owner layouts; bitwise vector equality is intentional.
extern "C" float sqrt_802e82c0(float);
struct F8HeadingVec {float x,y,z;F8HeadingVec(){}F8HeadingVec(float a,float b,float c):x(a),y(b),z(c){}F8HeadingVec(const F8HeadingVec&o){float a=o.x,b=o.y,c=o.z;x=a;y=b;z=c;}F8HeadingVec operator-(const F8HeadingVec&o)const{F8HeadingVec r;r.x=x-o.x;r.y=y-o.y;r.z=z-o.z;return r;}bool operator==(const F8HeadingVec&o)const{return ((Ptr32<const int>)this)[0]==((Ptr32<const int>)&o)[0]&&((Ptr32<const int>)this)[1]==((Ptr32<const int>)&o)[1]&&((Ptr32<const int>)this)[2]==((Ptr32<const int>)&o)[2];}float norm2()const{return x*x+y*y+z*z;}void scale(float k){x*=k;y*=k;z*=k;}void cross(const F8HeadingVec&a,const F8HeadingVec&b){x=a.y*b.z-a.z*b.y;y=a.z*b.x-a.x*b.z;z=a.x*b.y-a.y*b.x;}};
struct F8HeadingEntry{int p;F8HeadingVec start,end;};struct F8HeadingTable{char p[312];int index;Ptr32<Ptr32<F8HeadingEntry>> entries;Ptr32<F8HeadingEntry> current(){return *(Ptr32<Ptr32<F8HeadingEntry>>)((Ptr32<char>)entries+(index<<2));}};extern Ptr32<F8HeadingTable> table_804aa8c8;extern const F8HeadingVec zero_8045e788[];
struct F8HeadingOwner{char p[256];F8HeadingVec heading,side;};
extern "C" void f8b_planar_heading_80095450(Ptr32<F8HeadingOwner> s){F8HeadingVec end=table_804aa8c8->current()->end;F8HeadingVec start=table_804aa8c8->current()->start;F8HeadingVec up(0,1,0);s->heading=end-start;s->heading.y=0;if(!(s->heading==zero_8045e788[0]))s->heading.scale(1.0f/sqrt_802e82c0(s->heading.norm2()));s->side.cross(s->heading,up);}


