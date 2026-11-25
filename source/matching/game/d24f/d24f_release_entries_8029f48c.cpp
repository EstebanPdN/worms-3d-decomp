// GWMP8P rev0 0x8029f48c. Observed partial layouts. Entry fields and slot
// names describe observed use only; inline begin()/end() give the duplicated
// loop test.
struct D24fIface;
struct D24fIfaceTable { char pad[16]; void (*release)(D24fIface *); char pad20[4]; D24fIface *(*owner)(D24fIface *); char pad28[68]; void (*detach)(D24fIface *, D24fIface *); };
struct D24fIface { D24fIfaceTable *vt; };
struct D24fString { unsigned w[2]; };
extern "C" void w3d_string_base_finish(D24fString *);
extern "C" void w3d_string_release(D24fString *);
extern "C" void w3d_actor_member_delete_backend(void *);
struct D24fEntry { D24fIface *obj; unsigned pad; D24fString name; };
struct D24fList { D24fEntry **first; D24fEntry **last; D24fEntry **begin() {return first;} D24fEntry **end() {return last;} };
struct D24fOwner { char pad[336]; D24fList entries; };
extern "C" void d24f_release_entries_8029f48c(D24fOwner *self) {
  D24fEntry **it = self->entries.begin();
  while (it != self->entries.end()) {
    D24fEntry *e = *it;
    if (e) {
      if (e->obj) {
        if (e->obj->vt->owner(e->obj)) {
          D24fIface *o = e->obj->vt->owner(e->obj);
          o->vt->detach(o, e->obj);
        }
        D24fIface *none = 0;
        if (e->obj) e->obj->vt->release(e->obj);
        e->obj = none;
      }
      w3d_string_base_finish(&e->name);
      w3d_string_release(&e->name);
      if (e->obj) e->obj->vt->release(e->obj);
      w3d_actor_member_delete_backend(e);
    }
    it++;
  }
  self->entries.last = self->entries.first;
}
