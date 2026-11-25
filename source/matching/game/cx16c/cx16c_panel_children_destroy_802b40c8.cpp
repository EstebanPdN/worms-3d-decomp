
// Observed lifetime order: four top fields, two other fields, reverse 3-slot array, embedded context, base.
#define CX16C_FIELD(p,T,o) (*(T*)((char*)(p)+(o)))
extern const void *cx16c_table_8041c6b0[];
extern const void *cx16c_table_8041c700[];
extern "C" void cx16c_context_destroy_802afc40(void*,int);
extern "C" void cx16c_base_destroy_8015ff2c(void*,int);
struct Cx16cHeld {
 void *held;
 ~Cx16cHeld() { if(held) ((void(*)(void*))(*(void**)(*(char**)held+16)))(held); }
};
struct Cx16cContext {
 char reserved[196];
 ~Cx16cContext() { cx16c_context_destroy_802afc40(this,0); }
};
struct Cx16cChildrenPanel {
 const void *table;char reserved[24];
 Cx16cContext context;
 Cx16cHeld slots[3];
 Cx16cHeld field236,field240;
 unsigned reserved244;
 Cx16cHeld field248,field252,field256,field260;
 ~Cx16cChildrenPanel() {}
};
extern "C" void w3d_cx16c_panel_children_destroy_802b40c8(void *self,int flags) {
 Cx16cChildrenPanel *panel=(Cx16cChildrenPanel*)self;
 CX16C_FIELD(self,const void*,208)=cx16c_table_8041c6b0;
 panel->table=cx16c_table_8041c700;
 panel->~Cx16cChildrenPanel();
 cx16c_base_destroy_8015ff2c(self,flags);
}
