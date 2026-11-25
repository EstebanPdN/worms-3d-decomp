// Inferred external UI entry storage: factory 8029f714 allocates twenty bytes.
// Its constructor writes held+0, scalar+4, text+8, float+12 and scalar+16.
// Owner is an external partial view and is never constructed here.
struct F19aIface { void **table; };
struct F19aHeld {
 F19aIface *p;
 ~F19aHeld() { if(p) ((void (*)(F19aIface*))p->table[4])(p); }
 void clear(F19aIface *value=0) { if(p) ((void (*)(F19aIface*))p->table[4])(p); p=value; }
};
extern "C" void fn_8020c5c4(void*);
extern "C" void fn_80341588(void*);
struct F19aText {
 char *data;
 ~F19aText() { fn_8020c5c4(this); fn_80341588(this); }
};
extern "C" void fn_801fe1f8(void*);
struct F19aEntry {
 F19aHeld object; unsigned unknown4; F19aText text; float scalar12; unsigned unknown16;
 ~F19aEntry() {
   if(object.p) {
    if(((F19aIface*(*)(F19aIface*))object.p->table[6])(object.p)) {
     F19aIface *owner=((F19aIface*(*)(F19aIface*))object.p->table[6])(object.p);
     ((void(*)(F19aIface*,F19aIface*))owner->table[24])(owner,object.p);
    }
    object.clear();
   }
 }
 static void operator delete(void *p) { fn_801fe1f8(p); }
};
struct F19aEntries {
 F19aEntry **begin, **end;
 void destroy(F19aEntry **it) {
  do { delete *it; ++it; } while(it!=end);
 }
};
struct F19aOwner { char unknown[336]; F19aEntries entries; };
extern "C" void w3d_f19a_clear_entries_8029f48c(F19aOwner *self) { F19aEntry **first=self->entries.begin; if(first!=self->entries.end) self->entries.destroy(first); self->entries.end=self->entries.begin; }
