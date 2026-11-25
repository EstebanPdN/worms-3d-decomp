#include "w3d_ptr.h"
#line 1 "d40j_resource_manager_ctor_801752d4.cpp"
// Resource manager constructor (Worms 3D GameCube PAL, 0x801752d4). Sets up the
// base and derived vtables and 256 hash buckets, publishes itself as a global,
// reads DRM.MaxInstances (default 3000) and DRM.MaxHooks (default 256), builds the
// hook array and its free list, sizes the used-instance bit array and allocates
// the instance reference table. Names are inferred.
extern "C" {
Ptr32<void> malloc(unsigned);
void w3d_handle_storage_release(Ptr32<void>);
Ptr32<void> memcpy_802eee50(Ptr32<void>, Ptr32<const void>, unsigned int, ...);
Ptr32<void> memmove_802eeef4(Ptr32<void>, Ptr32<const void>, unsigned int);
int settings_int_80206920(Ptr32<const char>, Ptr32<int>);
void bucket_init_8034cb20(Ptr32<void>);
void hook_init_801788e4(Ptr32<void>);
}
template <class T> inline const T &Max(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline const T &Min(const T &a, const T &b) { return b < a ? b : a; }
template <class T> struct Array {
  Ptr32<T> start; Ptr32<T> finish; Ptr32<T> storage_end;
  Array() { storage_end = 0; finish = 0; start = 0; }
    void push_back(const T &v) {
    if (finish == storage_end) {
      unsigned used = (Ptr32<char>)finish - (Ptr32<char>)start;
      unsigned cap = (Ptr32<char>)storage_end - (Ptr32<char>)start;
      int a = cap + 1, b = cap + (cap >> 1);
      unsigned bytes = Max(a, b) * 4;
      Ptr32<T> p = (Ptr32<T>)malloc(bytes);
      if (start) {
        memcpy_802eee50(p, start, Min(bytes, used));
        w3d_handle_storage_release(start);
      }
      start = p; finish = (Ptr32<T>)((Ptr32<char>)p + used); storage_end = (Ptr32<T>)((Ptr32<char>)p + bytes);
    }
    *finish = v;
    finish++;
  }
  void resize(unsigned n, const T &v) {
    unsigned sz = finish - start;
    if (n < sz) {
      unsigned off = n * 4; Ptr32<T> e = (Ptr32<T>)(off + (int)start);
      Ptr32<T> l = finish;
      unsigned d = (Ptr32<char>)l - (Ptr32<char>)e;
      memcpy_802eee50(e, l, 0);
      finish = (Ptr32<T>)((Ptr32<char>)finish - d);
    } else {
      unsigned add = n - sz;
      Ptr32<T> pos = finish;
      if (pos + add > storage_end) {
        unsigned used = (Ptr32<char>)pos - (Ptr32<char>)start, cap = (Ptr32<char>)storage_end - (Ptr32<char>)start;
        int a = cap + (add - (storage_end - pos)), b = cap + (cap >> 1);
        unsigned bytes = Max(a, b) * 4;
        Ptr32<T> p = (Ptr32<T>)malloc(bytes);
        if (start) {
          memcpy_802eee50(p, start, Min(bytes, used));
          w3d_handle_storage_release(start);
        }
        pos = p + sz;
        start = p; finish = (Ptr32<T>)((Ptr32<char>)p + used); storage_end = (Ptr32<T>)((Ptr32<char>)p + bytes);
      }
      if (pos == finish) {
        for (unsigned i = 0; i < add; i++) finish[i] = v;
        finish += add;
      } else {
        T val = v;
        memmove_802eeef4(pos + add, pos, (Ptr32<char>)finish - (Ptr32<char>)pos);
        finish += add;
        for (unsigned i = 0; i < add; i++) *pos = val;
      }
    }
  }
};
struct Bits { Array<unsigned> words; int count;
  Bits() : count(0) {}
  void resize(int n) {
    if (n == 0) { Ptr32<unsigned int> f = words.finish; Ptr32<unsigned int> s = words.start; unsigned d = (Ptr32<char>)f - (Ptr32<char>)s; memcpy_802eee50(s, f, 0); count = n; words.finish = (Ptr32<unsigned int>)((Ptr32<char>)words.finish - d); }
    else { words.resize(((unsigned)(n - 1) >> 5) + 1, 0); count = n; }
  }
};
struct Bucket { int a, b; Bucket() { bucket_init_8034cb20(this); } };
extern Ptr32<void> vt_80412318[]; extern Ptr32<void> vt_80412250[]; extern Ptr32<void> vt_804123e0[];
struct Hook { Ptr32<void> vt; int w[4]; int w5; Hook() { vt = vt_804123e0; w5 = 0; hook_init_801788e4(this); } };
struct Held { Ptr32<int> p; Held() : p(0) {} ~Held(); };
struct D40jResourceManager;
extern Ptr32<D40jResourceManager> lbl_804ab5c4;
extern int lbl_804ab5c0, lbl_804ab5ac, lbl_804ab5b0, lbl_804ab5b4, lbl_804ab5b8, lbl_804ab5bc;
extern char name_max_instances_803a6830[], name_max_hooks_803a6844[];
struct Tagged { unsigned int kind:8; unsigned int pointer:24; };
struct Flags { unsigned short a, b; Tagged w; Flags() { w.kind = 2; w.pointer = 0; } void clr() { a = 0; b = 0; } };
struct Pair { int r12, r16; Pair() : r12(0), r16(0) {} };
struct Root { Ptr32<void> vt; Root() { vt = vt_80412318; } };
struct Base0 : Root { Flags f __attribute__((aligned(__alignof__(Root)))); Pair p; Base0() { f.clr(); } };
struct Base1 : Base0 { Base1() { vt = vt_80412250; } };
struct D40jResourceManager : Base1 {
  int f20 __attribute__((aligned(__alignof__(Base1)))); Ptr32<Held> held; Bits bits; Bucket buckets[256];
  int max2; Ptr32<Hook> hooks; int nhooks; Array<unsigned> free_list; int maxInst;
  D40jResourceManager();
};
D40jResourceManager::D40jResourceManager() {
  lbl_804ab5c4 = this;
  if (settings_int_80206920(name_max_instances_803a6830, &maxInst) < 0) maxInst = 3000;
  f20 = 0;
  max2 = maxInst;
  lbl_804ab5ac = 0; lbl_804ab5b0 = 0; lbl_804ab5b4 = 0; lbl_804ab5b8 = 0; lbl_804ab5bc = 0; lbl_804ab5c0 = 0;
  if (settings_int_80206920(name_max_hooks_803a6844, &nhooks) < 0) nhooks = 256;
  hooks = w3d::new_array<Hook>(nhooks);
  for (unsigned i = 0; i < (unsigned)nhooks; i++) free_list.push_back(i);
  bits.resize(maxInst);
  held = w3d::new_array<Held>(maxInst);
}


