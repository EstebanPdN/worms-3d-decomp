#include "w3d_ptr.h"
#line 1 "d28k_gauge_message_80265294.cpp"
// Gauge control message handler (Worms 3D GameCube PAL, 0x80265294).
// Message 64 runs the base handler then the setup; 66 clears the controls. Others: when the
// context is current and the control is not locked, plays the click on one message id, steps
// up or down on four key ids, and on the pointer message hit-tests the two arrow rectangles.
// All fall through to the sub-object and the base handler. Names are inferred from use.

struct Msg { unsigned short id; };
struct Vec2 { float x, y; };
struct Pos { float x, y, z; };
struct Ctx { int current_802b264c(); void report_802b22b0(); void forward_802aff9c(Ptr32<Msg>); int a; };
struct Skin { char pad[8]; unsigned char flags; char w3d_tag_rest[3]; char pad2[128]; Ptr32<unsigned short> state; };
struct Gauge {
 char pad0[28]; Ctx ctx; char pad1[8]; Ptr32<Skin> skin; char pad2[84]; int locked; char pad3[8]; Ptr32<unsigned short> state; char pad4[44]; int mode; char pad5[304]; int active; char pad6[96]; Vec2 half; Vec2 a; char pad7[44]; Vec2 half2; Vec2 b;
};
extern "C" int fn_8015fb34(Ptr32<Gauge>, Ptr32<Msg>);
extern "C" int fn_80265d34(Ptr32<Gauge>);
extern "C" void fn_80265fb4(Ptr32<Gauge>);
extern "C" int fn_8015f65c(unsigned short, Ptr32<const void>);
extern "C" void fn_802b1258(Ptr32<unsigned short>);
extern "C" void fn_80069a50(Ptr32<Msg>, Ptr32<float>, Ptr32<float>);
extern "C" Ptr32<void> fn_802b22e4(Ptr32<Pos>, Ptr32<Ctx>);
extern "C" void fn_80268420(Ptr32<Gauge>);
extern "C" void fn_802684c4(Ptr32<Gauge>);
extern "C" int lbl_804abb48;
struct Cache { int a, b; };
extern "C" Cache lbl_804b0a94, lbl_804b0a9c, lbl_804b0aa4, lbl_804b0aac, lbl_804b0ab4, lbl_804b0abc;
extern "C" int w3d_d28k_gauge_message_80265294(Ptr32<Gauge> self, Ptr32<Msg> m) {
 float x, y, px, py, ax, ay, bx, by;
 Pos pos;
 switch (m->id) {
  case 64:
   if (fn_8015fb34(self, m) >= 0) {
    fn_80265d34(self);
    goto done;
   }
   return 0x80004005;
  case 66:
   fn_80265fb4(self);
   break;
  default: {
   if (self->ctx.current_802b264c()) {
    if (!lbl_804abb48 && !self->locked) {
     if (fn_8015f65c(m->id, &lbl_804b0a94)) {
      {
       Ptr32<Skin> sk = self->skin;
       if (!((sk->flags ^ 4) & 4) || !self->state) self->ctx.report_802b22b0();
       else if (*(sk->state - 2)) fn_802b1258(sk->state);
      }
      goto forward;
     }
     if (fn_8015f65c(m->id, &lbl_804b0a9c) && self->mode == 1) goto up;
     if (fn_8015f65c(m->id, &lbl_804b0aa4) && self->mode == 1) goto down;
     if (fn_8015f65c(m->id, &lbl_804b0aac) && self->mode == 1) goto up;
     if (fn_8015f65c(m->id, &lbl_804b0ab4) && self->mode == 1) goto down;
     if (fn_8015f65c(m->id, &lbl_804b0abc) && self->active == 1 && self->mode == 1) {
      fn_80069a50(m, &x, &y);
      fn_802b22e4(&pos, &self->ctx);
      px = pos.x; py = pos.y;
      ax = px + self->a.x; ay = py + self->a.y;
      bx = px + self->b.x; by = py + self->b.y;
      if (x >= ax - self->half.x && x <= ax + self->half.x && y >= ay - self->half.y && y <= ay + self->half.y) {
      up:
       fn_80268420(self);
       goto done;
      }
      if (x >= bx - self->half2.x && x <= bx + self->half2.x && y >= by - self->half2.y && y <= by + self->half2.y) {
      down:
       fn_802684c4(self);
       goto done;
      }
     }
    }
   forward:
    self->ctx.forward_802aff9c(m);
   }
  }
 }
 return fn_8015fb34(self, m);
done:
 return 0;
}


