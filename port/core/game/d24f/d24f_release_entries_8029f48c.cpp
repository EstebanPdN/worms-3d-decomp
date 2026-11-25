#include "w3d_ptr.h"
#line 1 "d24f_release_entries_8029f48c.cpp"
// GWMP8P rev0 0x8029f48c. Observed partial layouts. Entry fields and slot
// names describe observed use only; inline begin()/end() give the duplicated
// loop test.
struct D24fIface;
struct D24fIfaceTable { char pad[16]; Ptr32<void (Ptr32<D24fIface>)> release; char pad20[4]; Ptr32<Ptr32<D24fIface> (Ptr32<D24fIface>)> owner; char pad28[68]; Ptr32<void (Ptr32<D24fIface>, Ptr32<D24fIface>)> detach; };
struct D24fIface { Ptr32<D24fIfaceTable> vt; };
struct D24fString { unsigned w[2]; };
extern "C" void w3d_string_base_finish(Ptr32<D24fString>);
extern "C" void w3d_string_release(Ptr32<D24fString>);
extern "C" void w3d_actor_member_delete_backend(Ptr32<void>);
struct D24fEntry { Ptr32<D24fIface> obj; unsigned pad; D24fString name; };
struct D24fList { Ptr32<Ptr32<D24fEntry>> first; Ptr32<Ptr32<D24fEntry>> last; Ptr32<Ptr32<D24fEntry>> begin() {return first;} Ptr32<Ptr32<D24fEntry>> end() {return last;} };
struct D24fOwner { char pad[336]; D24fList entries; };
extern "C" void d24f_release_entries_8029f48c(Ptr32<D24fOwner> self) {
  Ptr32<Ptr32<D24fEntry>> it = self->entries.begin();
  while (it != self->entries.end()) {
    Ptr32<D24fEntry> e = *it;
    if (e) {
      if (e->obj) {
        if (e->obj->vt->owner(e->obj)) {
          Ptr32<D24fIface> o = e->obj->vt->owner(e->obj);
          o->vt->detach(o, e->obj);
        }
        Ptr32<D24fIface> none = 0;
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


