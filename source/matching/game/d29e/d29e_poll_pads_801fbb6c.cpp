// (Worms 3D GameCube PAL, 0x801fbb6c).
//
// Reads the pad states at 0x8045e824 (0x80301e04) and notes whether any were
// read; for each of 4 pads sets its bit in the mask at +28 for error states
// 0 and -3, or collects it for reset for -1; clears and resets the collected
// pads (0x80301a90), runs virtual slot 5 with 1, clamps (0x8030110c), then
// sets the connected bit at +264 of each device in the list at +52 and
// updates it (slot 4 of the device's table), returning the last negative
// result or 0. Names are inferred.

struct Pad { char p[10]; signed char err; char q; };
extern Pad lbl_8045e824[];
extern "C" int fn_80301e04(Pad *);
extern "C" int fn_80301a90(unsigned);
extern "C" void fn_8030110c(Pad *);
struct DeviceBase {
  virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
  virtual int update(int);
};
struct Device : DeviceBase {
  char p[260];
  unsigned a : 2;
  unsigned connected : 1;
};
struct List { Device **b, **e; };
struct InputBase {
  virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
  virtual int poll(int);
};
struct Input : InputBase {
  char p[24];
  unsigned mask;
  char q[20];
  List devices;
};
extern "C" int w3d_d29e_poll_pads_801fbb6c(Input *self) {
  unsigned reset = 0;
  Device **it = self->devices.b;
  int result = 0;
  int any = 0;
  if (fn_80301e04(lbl_8045e824)) any = 1;
  int i = 0;
  List &list = self->devices;
  for (; i < 4; i++) {
    unsigned bit = 0x80000000u >> i;
    switch (lbl_8045e824[i].err) {
      case -2: break;
      case -3:
      case 0:
        self->mask |= bit;
        break;
      case -1:
        reset |= bit;
        break;
    }
  }
  if (reset) {
    self->mask &= ~reset;
    fn_80301a90(reset);
  }
  self->poll(1);
  fn_8030110c(lbl_8045e824);
  for (; it != list.e; it++) {
    if (*it) {
      (*it)->connected = any;
      int hr = (*it)->update(0);
      if (hr < 0) result = hr;
    }
  }
  return result;
}
