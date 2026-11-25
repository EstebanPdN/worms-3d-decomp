#include "w3d_ptr.h"
#line 1 "cx12b_wormpot_hit_dispatch_802aa2a4.cpp"

struct Panel{unsigned char opaque[176];int active;};extern "C" float miny_803d69b4[],maxy_803d69b8[],minx_803d69bc[],maxx_803d69c0[];extern "C" int selected_802ab5c0(Ptr32<Panel>, float, float);extern "C" int dispatch_802aa8a4(Ptr32<Panel>,int);
extern "C" int w3d_cx12b_wormpot_hit_dispatch_802aa2a4(Ptr32<Panel> self,float x,float y){if(y<miny_803d69b4[0]||y>maxy_803d69b8[0]||x<minx_803d69bc[0]||x>maxx_803d69c0[0])return 0;int entry=selected_802ab5c0(self, x, y);if(!entry)return 0;if(self->active)dispatch_802aa8a4(self,entry);return 1;}



