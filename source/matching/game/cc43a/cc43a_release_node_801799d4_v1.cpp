// Inferred partial views: only observed member offsets are declared. The opaque
// member views are not claims about original class names or complete sizes.
struct cc43a_Interface;
struct cc43a_Vtable { void* unknown00[4]; void (*release)(cc43a_Interface*); };
struct cc43a_Interface { cc43a_Vtable* vtable; };
struct cc43a_Member { unsigned int observed[3]; };
struct cc43a_Node { cc43a_Vtable* vtable; unsigned char unknown04[116]; cc43a_Interface* first; cc43a_Interface* second; cc43a_Member members[3]; };
extern "C" int cc43a_count_804ab5d8;
extern "C" cc43a_Interface* cc43a_shared_804b0160;
extern "C" cc43a_Vtable cc43a_vtable_804126d0[];
extern "C" void cc43a_member_destroy_801f2758(cc43a_Member*,unsigned int);
extern "C" void cc43a_member_destroy_80210abc(cc43a_Member*,unsigned int);
extern "C" void cc43a_base_destroy_801858fc(cc43a_Node*,unsigned int);
inline void cc43a_release(cc43a_Interface* p) { if(p) p->vtable->release(p); }
inline void cc43a_reset(cc43a_Interface*& slot,cc43a_Interface* value) { cc43a_release(slot); slot=value; }
extern "C" void cc43a_release_node_801799d4(cc43a_Node* self,unsigned int flags) {
 int remaining=cc43a_count_804ab5d8-1;
 self->vtable=cc43a_vtable_804126d0;
 cc43a_count_804ab5d8=remaining;
 if(remaining==0) { cc43a_release(cc43a_shared_804b0160); cc43a_shared_804b0160=0; }
 cc43a_reset(self->first,0);
 cc43a_reset(self->second,0);
 cc43a_member_destroy_801f2758(&self->members[2],2);
 cc43a_member_destroy_801f2758(&self->members[1],2);
 cc43a_member_destroy_80210abc(&self->members[0],2);
 cc43a_release(self->second); cc43a_release(self->first);
 cc43a_base_destroy_801858fc(self,flags);
}
