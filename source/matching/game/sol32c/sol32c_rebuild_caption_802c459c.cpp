// GWMP8P rev0 GC32 partial views. Fields are named from observed use only.
// String length is a halfword four bytes before its data pointer.
struct Sol32cCaptionIface { void **table; };
struct Sol32cCaptionHeld {
 Sol32cCaptionIface *pointer;
 Sol32cCaptionHeld():pointer(0) {}
 ~Sol32cCaptionHeld() { if(pointer) ((void(*)(Sol32cCaptionIface *))pointer->table[4])(pointer); }
 void clear() { if(pointer) ((void(*)(Sol32cCaptionIface *))pointer->table[4])(pointer); pointer=0; }
};
struct Sol32cCaptionText { char *data; unsigned short length() const { return *(unsigned short *)(data-4); } };
struct Sol32cCaptionKey { const char *data; Sol32cCaptionKey(const char *p):data(p) {} };
struct Sol32cCaptionVector { float x,y,z; Sol32cCaptionVector(float a,float b,float c):x(a),y(b),z(c) {} };
struct Sol32cCaptionState { unsigned words0[9]; Sol32cCaptionIface *parent; unsigned words40[51]; Sol32cCaptionHeld child; Sol32cCaptionText property,resource,caption; unsigned word260; int characters; };
extern "C" void sol32c_caption_assign_8020bd38(Sol32cCaptionText *,const char *);
extern "C" int sol32c_caption_create_8015adf4(Sol32cCaptionText *,Sol32cCaptionHeld *,unsigned char);
extern "C" Sol32cCaptionIface *sol32c_caption_identity_80343580(Sol32cCaptionIface *);
extern "C" Sol32cCaptionIface *sol32c_caption_property_identity_80343744(Sol32cCaptionIface *);
extern "C" Sol32cCaptionText *sol32c_caption_text_80179170(Sol32cCaptionIface *);
extern "C" int sol32c_caption_lookup_800fc1b0(Sol32cCaptionKey *,Sol32cCaptionHeld *);
extern "C" void sol32c_caption_format_8020c510(Sol32cCaptionText *,const char *,...);
extern "C" int sol32c_caption_count_8020c5cc(Sol32cCaptionText *);
extern "C" void sol32c_caption_mode_802c38cc(Sol32cCaptionState *,int);
extern "C" void sol32c_caption_refresh_802c4744(Sol32cCaptionState *);
extern int sol32c_caption_depth_804abb60;
extern const char sol32c_caption_empty_803d86a4[],sol32c_caption_format_803d8758[];
extern const float sol32c_caption_scale_xy_803d875c[],sol32c_caption_scale_z_803d8760[];
typedef char Sol32cCaptionStateSize[(sizeof(Sol32cCaptionState)==268)?1:-1];
extern "C" void sol32c_rebuild_caption_802c459c(Sol32cCaptionState *self) {
 if(self->parent && self->resource.length()) {
  if(self->child.pointer) {
   Sol32cCaptionIface *p=self->parent;
   ((void(*)(Sol32cCaptionIface *,Sol32cCaptionIface *))p->table[24])(p,self->child.pointer);
   self->child.clear();
  }
  sol32c_caption_assign_8020bd38(&self->caption,sol32c_caption_empty_803d86a4);
  sol32c_caption_create_8015adf4(&self->resource,&self->child,(unsigned char)(sol32c_caption_depth_804abb60+30));
  Sol32cCaptionIface *parent=self->parent;
  ((void(*)(Sol32cCaptionIface *,Sol32cCaptionIface *,int))parent->table[23])(parent,self->child.pointer,0);
  Sol32cCaptionIface *child=sol32c_caption_identity_80343580(self->child.pointer);
  Sol32cCaptionVector scale(sol32c_caption_scale_xy_803d875c[0],sol32c_caption_scale_xy_803d875c[0],sol32c_caption_scale_z_803d8760[0]);
  ((void(*)(Sol32cCaptionIface *,const Sol32cCaptionVector &,int))child->table[21])(child,scale,0);
  Sol32cCaptionHeld held;
  if(self->property.length()) {
   Sol32cCaptionKey key(self->property.data);
   if(sol32c_caption_lookup_800fc1b0(&key,&held)>=0) {
    Sol32cCaptionText *text=sol32c_caption_text_80179170(sol32c_caption_property_identity_80343744(held.pointer));
    sol32c_caption_format_8020c510(&self->caption,sol32c_caption_format_803d8758,text->data);
    self->characters=sol32c_caption_count_8020c5cc(&self->caption);
    if(self->characters) sol32c_caption_mode_802c38cc(self,2);
   }
  }
  sol32c_caption_refresh_802c4744(self);
 }
}
