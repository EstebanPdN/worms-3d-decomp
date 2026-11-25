// (Worms 3D GameCube PAL, 0x801dcdc0).
//
// Value setter of a node with a child list: id 20 stores a non-negative value
// and forwards it to the first ready child, ids 21 to 23 store 0-or-1
// settings, and an invalid value returns E_FAIL.

struct Item {
  virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
  virtual int ready();
  virtual void w6(); virtual void w7(); virtual void w8(); virtual void w9(); virtual void w10();
  virtual void w11(); virtual void w12(); virtual void w13(); virtual void w14(); virtual void w15();
  virtual int set(int *value);
};
struct List { unsigned count; int cap; Item **items; };
struct Node {
  char p0[48];
  List list;
  char p1[44];
  int v104, v108, v112;
  char p2[4];
  int v120;
};
// Stores a 0-or-1 setting, or takes the invalid-value exit.
#define SET_BOOL(field, v) do { if (v != 1) if (v != 0) goto bad; self->field = v; } while (0)

extern "C" int w3d_d42e_node_set_value_801dcdc0(Node *self, int id, int *value) {
  switch (id) {
    case 20: {
      int v = *value;
      if (v < 0) goto bad;
      self->v120 = v;
      for (unsigned i = 0; i < self->list.count; i++) {
        List &list = self->list;
        if (list.items[i]->ready() == 1) return list.items[i]->set(value);
      }
      break;
    }
    case 21: {
      int v = *value;
      SET_BOOL(v112, v);
      return 0;
    }
    case 22: {
      int v = *value;
      SET_BOOL(v104, v);
      break;
    }
    case 23: {
      int v = *value;
      SET_BOOL(v108, v);
      return 0;
    }
    bad:
      return 0x80004005;
  }
  return 1;
}
