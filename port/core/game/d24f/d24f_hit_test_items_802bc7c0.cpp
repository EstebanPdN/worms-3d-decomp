#include "w3d_ptr.h"
#line 1 "d24f_hit_test_items_802bc7c0.cpp"
// GWMP8P rev0 0x802bc7c0. Observed partial layouts. The inline copy
// constructor copies through three float temporaries; one saved-FPR non-leaf
// frame gap per FPR needs -mps-float.
struct D24fItem;
struct D24fVec3 { float x, y, z;
 D24fVec3() {}
 D24fVec3(const D24fVec3 &o) { float a = o.x; float b = o.y; float c = o.z; x = a; y = b; z = c; }
};
struct D24fBox { float a[9]; D24fVec3 origin; };
struct D24fNode;
struct D24fNodeTable { char pad[124]; Ptr32<void (Ptr32<D24fNode>, Ptr32<D24fBox>)> get_box; };
struct D24fNode { Ptr32<D24fNodeTable> vt; };
struct D24fItemList { Ptr32<Ptr32<D24fItem>> first; Ptr32<Ptr32<D24fItem>> last; Ptr32<Ptr32<D24fItem>> begin() {return first;} Ptr32<Ptr32<D24fItem>> end() {return last;} };
struct D24fHitPanel { unsigned pad0[14]; D24fItemList items; unsigned pad64[6]; Ptr32<D24fNode> node; };
extern "C" int w3d_get_802bd2bc(Ptr32<D24fItem> item);
extern "C" int w3d_cc37b_hit_line_802bfa70(Ptr32<D24fItem> item, float x, float y, Ptr32<int> line);
extern "C" int d24f_hit_test_items_802bc7c0(Ptr32<D24fHitPanel> self, float x, float y, Ptr32<int> line, Ptr32<int> id) {
  Ptr32<Ptr32<D24fItem>> it = self->items.begin();
  *line = 0;
  *id = 0;
  D24fBox box;
  self->node->vt->get_box(self->node, &box);
  Ptr32<const D24fVec3> p = &box.origin;
  D24fVec3 o(*p);
  float dx = x - o.x;
  float dy = y - o.y;
  while (it != self->items.end()) {
    if (w3d_get_802bd2bc(*it) != -1 && w3d_cc37b_hit_line_802bfa70(*it, dx, dy, line) == 1) {
      *id = w3d_get_802bd2bc(*it);
      return 1;
    }
    it++;
  }
  return 0;
}


