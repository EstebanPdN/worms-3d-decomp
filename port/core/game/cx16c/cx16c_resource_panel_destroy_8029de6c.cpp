#include "w3d_ptr.h"
#line 1 "cx16c_resource_panel_destroy_8029de6c.cpp"

// Observed held interfaces release through slot +16; semantic class names are inferred.
#define CX16C_FIELD(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char*)w3d::AG(p)+(o)))
struct Cx16cHeld { Ptr32<void> held; ~Cx16cHeld() { if(held) ((Ptr32<void (Ptr32<void>)>)(*(Ptr32<Ptr32<void>>)(*(Ptr32<Ptr32<char>>)held+16)))(held); } };
extern "C" void cx16c_context_destroy_802afc40(Ptr32<void>,int);
extern "C" void cx16c_base_destroy_8015ff2c(Ptr32<void>,int);

extern Ptr32<const void> cx16c_table_8041c2b0[];
extern Ptr32<const void> cx16c_table_8041c300[];
extern "C" void cx16c_storage_release_802134fc(Ptr32<void>);
extern "C" void cx16c_member_destroy_80210abc(Ptr32<void>,int);
struct Cx16cOwnedStorage { Ptr32<void> storage; ~Cx16cOwnedStorage() { if(storage) cx16c_storage_release_802134fc(storage); } };
struct Cx16cHandle { unsigned words[3]; ~Cx16cHandle() { cx16c_member_destroy_80210abc(this,2); } };
struct Cx16cContext { char reserved[192]; ~Cx16cContext() { cx16c_context_destroy_802afc40(this,0); } };
struct Cx16cResourceOwner {
 Ptr32<const void> table;char reserved[24];Cx16cContext context;
 Cx16cHeld field220,slots[2];char gap232[28];Cx16cHeld field260,field264;
 char gap268[40];Cx16cHeld field308,field312;char gap316[4];
 Cx16cHeld field320,field324,field328,field332;Cx16cOwnedStorage field336;
 char gap340[12];Cx16cHandle member352;Cx16cOwnedStorage field364;
 ~Cx16cResourceOwner() {}
};
extern "C" void w3d_cx16c_resource_panel_destroy_8029de6c(Ptr32<void> self,int flags) {
 Ptr32<Cx16cResourceOwner> owner=(Ptr32<Cx16cResourceOwner>)self;
 CX16C_FIELD(self,const void*,208)=cx16c_table_8041c2b0;
 owner->table=cx16c_table_8041c300;
 owner->~Cx16cResourceOwner();
 cx16c_base_destroy_8015ff2c(self,flags);
}


