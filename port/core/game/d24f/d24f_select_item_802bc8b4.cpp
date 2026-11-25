#include "w3d_ptr.h"
#line 1 "d24f_select_item_802bc8b4.cpp"
// GWMP8P rev0 0x802bc8b4. Observed partial layouts. The item list's inline
// begin()/end() accessors give the duplicated loop test with the list
// address kept in a saved register.
struct D24fItem;
struct D24fItemList { Ptr32<Ptr32<D24fItem>> first; Ptr32<Ptr32<D24fItem>> last; Ptr32<Ptr32<D24fItem>> begin() {return first;} Ptr32<Ptr32<D24fItem>> end() {return last;} };
struct D24fPanel { unsigned pad0[14]; D24fItemList items; unsigned pad64[2]; int selected; };
extern "C" int w3d_s21_nested_value_802bc71c(Ptr32<D24fPanel> self);
extern "C" int w3d_get_802bd2bc(Ptr32<D24fItem> item);
extern "C" void w3d_auto_802bd318(Ptr32<D24fItem> item, int on);
extern "C" void d24f_select_item_802bc8b4(Ptr32<D24fPanel> self, int id) {
  if (w3d_s21_nested_value_802bc71c(self) <= id) id = -1;
  Ptr32<Ptr32<D24fItem>> it = self->items.begin();
  while (it != self->items.end()) {
      Ptr32<D24fItem> item = *it++;
      w3d_auto_802bd318(item, w3d_get_802bd2bc(item) == id);
  }
  self->selected = id;
}


