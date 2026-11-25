#include "w3d_ptr.h"
#line 1 "d25f_node_scene_setup_8028a900.cpp"
// GWMP8P rev0 0x8028a900. Observed partial layouts; names describe observed
// use only. Same shape as the admitted unit at 0x802c17bc with the handles
// at +984 and +988. One-word string and handle classes suffice here; no
// second unread word is used.
struct D25fString {
 Ptr32<char> text;
 template <class W3dU> D25fString(Ptr32<W3dU> w3d_p) : D25fString((const char *)w3d_p.get()) {}
 D25fString(const char *);
 D25fString(const D25fString &);
 ~D25fString();
};
extern "C" void w3d_string_finish_8020c5c4(Ptr32<D25fString>);
extern "C" void w3d_string_release_80341588(Ptr32<D25fString>);
inline D25fString::~D25fString()
{
 w3d_string_finish_8020c5c4(this);
 w3d_string_release_80341588(this);
}
struct D25fVec3 {
 float x, y, z;
 D25fVec3(float a, float b, float c) : x(a), y(b), z(c) {}
 D25fVec3(const D25fVec3 &o);
};
struct D25fColour { signed char r, g, b; unsigned char a; };
struct D25fObject;
struct D25fObjectVtable {
 Ptr32<void> slots0[3];
 Ptr32<void (Ptr32<D25fObject>)> retain;                     // +12
 Ptr32<void (Ptr32<D25fObject>)> release;                    // +16
 Ptr32<void> slots20[16];
 Ptr32<void (Ptr32<D25fObject>, const D25fVec3 &, int)> set_scale; // +84
 Ptr32<void> slot88;
 Ptr32<void (Ptr32<D25fObject>, Ptr32<D25fObject>, int)> attach;  // +92
 Ptr32<void (Ptr32<D25fObject>, Ptr32<D25fObject>)> detach;       // +96
};
struct D25fObject { Ptr32<D25fObjectVtable> vtable; };
extern "C" int w3d_handle_set_name_8015adf4(const D25fString &, Ptr32<Ptr32<D25fObject>>, unsigned char);
struct D25fRef {
 Ptr32<D25fObject> value;
 D25fRef() : value(0) {}
 D25fRef(const D25fString &n, unsigned char t) : value(0) { w3d_handle_set_name_8015adf4(n, &value, t); }
 D25fRef(const D25fRef &);
 ~D25fRef() { if (value) value->vtable->release(value); }
};
inline int d25f_load_resource(const D25fString &n, Ptr32<Ptr32<D25fObject>> o, unsigned char t) { return w3d_handle_set_name_8015adf4(n, o, t); }
struct D25fHeld {
 Ptr32<D25fObject> value;
 template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((D25fObject *)w3d_p.get()); }
 D25fHeld &operator=(D25fObject *p)
 {
  if (p) p->vtable->retain(p);
  if (value) value->vtable->release(value);
  value = p;
  return *this;
 }
};
extern int w3d_resource_base_804abb60;
extern "C" Ptr32<D25fObject> w3d_as_mesh_8034357c(Ptr32<D25fObject>);
struct Node;
struct NodeVt { Ptr32<void> s0[19]; Ptr32<int (Ptr32<Node>, Ptr32<const float>, int)> set_position; Ptr32<int (Ptr32<Node>, Ptr32<const float>, int)> set_rotation; Ptr32<int (Ptr32<Node>, Ptr32<const float>, int)> set_scale; Ptr32<void> s88; Ptr32<int (Ptr32<Node>, Ptr32<Node>, Ptr32<const char>)> attach; };
struct Node { Ptr32<NodeVt> vt; };
struct V { float x, y, z; V() {} V(const V &o) : x(o.x), y(o.y), z(o.z) {} };
extern V lbl_8045e788[];
struct Anim { unsigned w0[246]; Ptr32<Node> anim; Ptr32<Node> model; };
extern "C" void d25f_node_scene_setup_8028a900(Ptr32<Anim> self)
{
  w3d_handle_set_name_8015adf4(D25fString("NULL"), (Ptr32<Ptr32<D25fObject>>)&self->model, 255); 
  w3d_handle_set_name_8015adf4(D25fString("Frontend.Anim"), (Ptr32<Ptr32<D25fObject>>)&self->anim, 255); 
 V rot(lbl_8045e788[0]);
 V pos(lbl_8045e788[0]);
 V s;
 Ptr32<V> p = &s;
 p->x = 0.0f; p->y = 0.0f; p->z = 0.0f;
 self->anim->vt->set_position(self->anim, &p->x, 0);
 self->anim->vt->set_rotation(self->anim, &pos.x, 0);
 self->anim->vt->attach(self->anim, self->model, "locator1");
 self->model->vt->set_position(self->model, &p->x, 1);
 self->model->vt->set_rotation(self->model, &p->x, 1);
 p->x = 1.0f; p->y = 1.0f; p->z = 1.0f;
 self->anim->vt->set_scale(self->anim, &p->x, 0);
 self->model->vt->set_scale(self->model, &p->x, 0);
}


