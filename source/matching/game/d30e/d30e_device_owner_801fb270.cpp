// (Worms 3D GameCube PAL, 0x801fb270).
//
// Constructs the device owner: base table 0x804182d0, tagged link at +8
// cleared with kind 2, final table 0x80418210, two empty pointer vectors at
// +36 and +52, then runs 0x80301cb4 and, for each of four channels, gets a
// device from service 0x804181f0, opens it through slot 22, appends it (or
// null on failure) to the vector at +52 and, with an added reference, to the
// one at +36. Vectors are unmodified STLport. Names are inferred.

#pragma interface
#include "compat/stlport_sn_oom.h"
#include <vector>
struct Dev { virtual void v0(); virtual void AddRef(); virtual void Release(); virtual void v3(),v4(),v5(),v6(),v7(),v8(),v9(),v10(),v11(),v12(),v13(),v14(),v15(),v16(),v17(),v18(),v19(),v20(),v21(); virtual int open(int, unsigned, int); };
struct Ref { Dev *p; Ref(Dev *o) { p = o; if (p) p->AddRef(); } Ref(const Ref &); ~Ref() { if (p) p->Release(); } operator Dev *() const { return p; } Dev *operator->() const { return p; } };
extern char lbl_804181f0[];
extern "C" int fn_80301cb4();
extern "C" Dev *w3d_s10_service_forward_8020b680(void *);
struct Service { virtual void s0() = 0; };
struct Sub { int a, b; void clear() { a = 0; b = 0; } };
struct Link {
  short a, b;
  unsigned int pointer : 24;
  unsigned int kind : 8;
  Sub s;
  Link(unsigned char tag) { kind = tag; pointer = 0; s.clear(); a = 0; b = 0; }
};
struct Node : Service { int x4; Link link; Node() : link(2) {} };
struct D30eDeviceOwner : Node {
  int y; int x28; int x32;
  std::vector<Dev *> opened;
  std::vector<Dev *> all;
  virtual void ko();
  D30eDeviceOwner();
};
D30eDeviceOwner::D30eDeviceOwner() {
  fn_80301cb4();
  x28 = 0;
  for (unsigned i = 0; i < 4; i++) {
    Ref dev(w3d_s10_service_forward_8020b680(lbl_804181f0));
    if (dev->open(0, i, 0) >= 0) all.push_back(dev);
    else all.push_back(0);
    dev->AddRef();
    opened.push_back(dev);
  }
}
