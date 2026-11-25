// All names are inferred. Interface and container views are external only.
struct G1aInterface { void **table; };
inline void retain(G1aInterface *p) { if(p) ((void(*)(G1aInterface*))p->table[3])(p); }
inline void release(G1aInterface *p) { if(p) ((void(*)(G1aInterface*))p->table[4])(p); }
struct G1aHeld {
 G1aInterface *p;
 G1aHeld():p(0) {}
 G1aHeld(G1aInterface *v):p(v) { retain(p); }
 ~G1aHeld() { release(p); }
 G1aHeld &operator=(const G1aHeld &v) { if(v.p) {retain(v.p);release(p);p=v.p;}return *this; }
};
extern "C" void fn_80178474(void*,int);
struct G1aDescriptor_80178474 {
 unsigned value,tag;
 G1aDescriptor_80178474():value(0),tag(0xe3a8) {}
 ~G1aDescriptor_80178474();
};
struct G1aKey { const char *text; G1aKey(const char *p):text(p){} };
extern const char key_803ceaa0[];
extern "C" int fn_800fc1b0(G1aKey*,G1aHeld*);
extern "C" G1aInterface *fn_80341584(G1aInterface*);
extern "C" G1aInterface *fn_80179598(G1aInterface*,G1aDescriptor_80178474*);
struct G1aBarracksEntryView { char unknown[64]; unsigned state; };
struct G1aArrayView { char unknown[24]; unsigned count; unsigned unknown28; G1aBarracksEntryView *entries[1]; };
struct G1aBarracksView { void **table; char unknown[20]; G1aArrayView *array; };
extern "C" void w3d_g1a_reset_barracks_802847cc() {
 G1aDescriptor_80178474 descriptor;
 G1aHeld found;
 G1aKey key(key_803ceaa0);
 if(fn_800fc1b0(&key,&found)<0) return;
 G1aHeld barracks;
 barracks=G1aHeld(fn_80179598(fn_80341584(found.p),&descriptor));
 G1aArrayView *array=((G1aBarracksView*)barracks.p)->array;
 unsigned count=array->count;
 G1aBarracksEntryView **it=array->entries;
 for(unsigned i=0;i<count;++i,++it) (*it)->state=0;
}
