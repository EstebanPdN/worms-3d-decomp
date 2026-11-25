#include "w3d_ptr.h"
#line 1 "d42e_stream_open_801e23c0.cpp"
// (Worms 3D GameCube PAL, 0x801e23c0).
//
// Opens a streamed asset from a descriptor: copies the name, file and
// playback settings, then opens the file with its two channel suffixes,
// falling back to the plain file name, and records how many channels opened.

struct String;
extern "C" Ptr32<String> w3d_string_assign(Ptr32<String>, Ptr32<const char>);
extern "C" Ptr32<String> w3d_string_append(Ptr32<String>, Ptr32<const char>);
extern "C" void w3d_string_format(Ptr32<String>, Ptr32<const char>, ...);
extern "C" void w3d_string_base_finish(Ptr32<String>);
extern "C" void w3d_string_release(Ptr32<String>);
struct String {
  Ptr32<char> p;
  String();
  template <class W3dU> String(Ptr32<W3dU> w3d_p) : String((const char *)w3d_p.get()) {}
 String(const char *);
  String(const String &);
  void Prefix(const String &o, int n);
  Ptr32<String> Append(Ptr32<const char> t) { return w3d_string_append(this, t); }
  ~String() { w3d_string_base_finish(this); w3d_string_release(this); }
};
extern "C" Ptr32<String> w3d_cx11b_string_prefix_assign_8020c048(Ptr32<String>, Ptr32<const String>, int);
extern "C" int fn_802f4ef0(Ptr32<const char>);
extern const char lbl_803b05e0[], lbl_803b05e8[];
struct Desc {
  Ptr32<const char> name; char p4[8]; Ptr32<const char> file; float f16; int v20, v24, v28;
  float f32, f36, f40, f44, f48;
  char p52[8];
  int v60;
};
inline void String::Prefix(const String &o, int n) { w3d_cx11b_string_prefix_assign_8020c048(this, &o, n); }
struct Stream {
  char p0[20];
  String name;
  int v24, v28;
  String file;
  float f36;
  int v40;
  float f44, f48, f52, f56, f60;
  char p64[4];
  int v68;
  int count;
  char p76[12];
  int handles[2];
};
extern "C" int w3d_d42e_stream_open_801e23c0(Ptr32<Stream> s, Ptr32<const Desc> d) {
  if (!d) return 0x80004005;
  w3d_string_assign(&s->name, d->name);
  w3d_string_assign(&s->file, d->file);
  s->v40 = d->v28;
  s->f44 = d->f32;
  s->f48 = d->f36;
  s->f60 = d->f44;
  s->f56 = d->f48;
  s->f52 = d->f40;
  s->v28 = d->v20;
  s->v24 = d->v24;
  s->f36 = d->f16;
  s->v68 = d->v60;
  s->count = 0;
  String path;
  Ptr32<String> pp = &path;
  w3d_cx11b_string_prefix_assign_8020c048(&path, &s->file, *(Ptr32<unsigned short>)(s->file.p - 4) - 4);
  w3d_string_append(&path, lbl_803b05e0);
  for (unsigned i = 0; i <= 1; i++) s->handles[i] = -1;
  s->handles[0] = fn_802f4ef0(path.p);
  if (s->handles[0] != -1) {
    s->count = 1;
    path.Prefix(s->file, *(Ptr32<unsigned short>)(s->file.p - 4) - 4);
    path.Append(lbl_803b05e8);
    s->handles[1] = fn_802f4ef0(path.p);
    if (s->handles[1] != -1) s->count = 2;
  } else {
    s->handles[0] = fn_802f4ef0(s->file.p);
    if (s->handles[0] != -1) s->count = 1;
  }
  return 0;
}


