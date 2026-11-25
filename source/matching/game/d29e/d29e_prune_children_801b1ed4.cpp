// (Worms 3D GameCube PAL, 0x801b1ed4).
//
// Walks the child array at +28 of a node through the scanner (self minus 4
// when non-null): optionally marks each child's flag bit, records the index
// of a child whose parent is an ancestor or whose references are missing,
// and replaces a flagged child with the result of the scanner factory's
// virtual slot 10; then erases the recorded indices through 0x801ef380,
// adjusting for prior removals. Returns 0. Names are inferred.

struct Parent {};
struct ItemBase {
  virtual void v0(); virtual void v1(); virtual void v2();
  virtual Parent *parent();
};
struct Item : ItemBase {
  struct Bits { char p[7]; unsigned char flags; } bits;
};
struct Array { char p[24]; unsigned count; int locks; Item *items[1]; };
struct Node { char p[28]; Array *items; };
struct Factory { virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7(); virtual void a8();
  virtual Item *convert(Item *); };
struct Scanner { char p[72]; Factory *factory; char q[4]; int mark; };
struct Second { int x; };
extern "C" int w3d_s10_has_ancestor_801b1de0(Scanner *, Parent *);
extern "C" int w3d_k4b_scanner_has_missing_801b1e48(Scanner *, Item *);
extern "C" void w3d_k5b_iface_array_field_set_801ef2ec(Node *, int, int, Item *, int);
extern "C" void fn_801ef380(Node *, int, int, int, int);
extern "C" int w3d_d29e_prune_children_801b1ed4(Second *base, Node *node) {
  Scanner *s = base ? (Scanner *)((char *)base - 4) : 0;
  unsigned char removed[64];
  unsigned k = 0;
  Array *a = node->items;
  unsigned n = a->count;
  Item **items = a->items;
  unsigned i = 0;
  if (i < n) {
    Item **p = items;
    do {
      Item *item = *p++;
      if (s->mark) { Item::Bits &b = item->bits; b.flags |= 1; }
      if (w3d_s10_has_ancestor_801b1de0(s, item->parent()) || w3d_k4b_scanner_has_missing_801b1e48(s, item)) {
        removed[k++] = i;
      } else if (item->bits.flags & 1) {
        w3d_k5b_iface_array_field_set_801ef2ec(node, 28, 3, s->factory->convert(item), i);
      }
      i++;
    } while (i < n);
  }
  for (unsigned j = 0; j < k; j++) fn_801ef380(node, 28, 3, removed[j] - j, 1);
  return 0;
}
