#include "w3d_ptr.h"
#line 1 "cx16c_menu_children_destroy_8026e148.cpp"

// Observed held interfaces release through slot +16; semantic class names are inferred.
#define CX16C_FIELD(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char*)w3d::AG(p)+(o)))
struct Cx16cHeld { Ptr32<void> held; ~Cx16cHeld() { if(held) ((Ptr32<void (Ptr32<void>)>)(*(Ptr32<Ptr32<void>>)(*(Ptr32<Ptr32<char>>)held+16)))(held); } };
extern "C" void cx16c_context_destroy_802afc40(Ptr32<void>,int);
extern "C" void cx16c_base_destroy_8015ff2c(Ptr32<void>,int);

extern Ptr32<const void> cx16c_table_8041bd60[];
extern Ptr32<const void> cx16c_table_8041bdb0[];
struct Cx16cContext { char reserved[184]; ~Cx16cContext() { cx16c_context_destroy_802afc40(this,0); } };
struct Cx16cMenuChildren {
 Ptr32<const void> table;char reserved[24];Cx16cContext context;
 Cx16cHeld field212,slots[2];char gap224[24];Cx16cHeld field248;
 char gap252[20];Cx16cHeld field272,field276,field280,field284;
 ~Cx16cMenuChildren() {}
};
extern "C" void w3d_cx16c_menu_children_destroy_8026e148(Ptr32<void> self,int flags) {
 Ptr32<Cx16cMenuChildren> menu=(Ptr32<Cx16cMenuChildren>)self;
 CX16C_FIELD(self,const void*,208)=cx16c_table_8041bd60;
 menu->table=cx16c_table_8041bdb0;
 menu->~Cx16cMenuChildren();
 cx16c_base_destroy_8015ff2c(self,flags);
}


