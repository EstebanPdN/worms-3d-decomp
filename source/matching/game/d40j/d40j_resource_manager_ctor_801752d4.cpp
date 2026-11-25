// Resource manager constructor (Worms 3D GameCube PAL, 0x801752d4). Sets up the
// base and derived vtables and 256 hash buckets, publishes itself as a global,
// reads DRM.MaxInstances (default 3000) and DRM.MaxHooks (default 256), builds the
// hook array and its free list, sizes the used-instance bit array and allocates
// the instance reference table. Names are inferred.
extern "C" {
void *malloc(unsigned);
void w3d_handle_storage_release(void *);
void *memcpy_802eee50(void *, const void *, unsigned int, ...);
void *memmove_802eeef4(void *, const void *, unsigned int);
int settings_int_80206920(const char *, int *);
void bucket_init_8034cb20(void *);
void hook_init_801788e4(void *);
}
template <class T> inline const T &Max(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline const T &Min(const T &a, const T &b) { return b < a ? b : a; }
template <class T> struct Array {
  T *start, *finish, *storage_end;
  Array() { storage_end = 0; finish = 0; start = 0; }
    void push_back(const T &v) {
    if (finish == storage_end) {
      unsigned used = (char *)finish - (char *)start;
      unsigned cap = (char *)storage_end - (char *)start;
      int a = cap + 1, b = cap + (cap >> 1);
      unsigned bytes = Max(a, b) * 4;
      T *p = (T *)malloc(bytes);
      if (start) {
        memcpy_802eee50(p, start, Min(bytes, used));
        w3d_handle_storage_release(start);
      }
      start = p; finish = (T *)((char *)p + used); storage_end = (T *)((char *)p + bytes);
    }
    *finish = v;
    finish++;
  }
  void resize(unsigned n, const T &v) {
    unsigned sz = finish - start;
    if (n < sz) {
      unsigned off = n * 4; T *e = (T *)(off + (int)start);
      T *l = finish;
      unsigned d = (char *)l - (char *)e;
      memcpy_802eee50(e, l, 0);
      finish = (T *)((char *)finish - d);
    } else {
      unsigned add = n - sz;
      T *pos = finish;
      if (pos + add > storage_end) {
        unsigned used = (char *)pos - (char *)start, cap = (char *)storage_end - (char *)start;
        int a = cap + (add - (storage_end - pos)), b = cap + (cap >> 1);
        unsigned bytes = Max(a, b) * 4;
        T *p = (T *)malloc(bytes);
        if (start) {
          memcpy_802eee50(p, start, Min(bytes, used));
          w3d_handle_storage_release(start);
        }
        pos = p + sz;
        start = p; finish = (T *)((char *)p + used); storage_end = (T *)((char *)p + bytes);
      }
      if (pos == finish) {
        for (unsigned i = 0; i < add; i++) finish[i] = v;
        finish += add;
      } else {
        T val = v;
        memmove_802eeef4(pos + add, pos, (char *)finish - (char *)pos);
        finish += add;
        for (unsigned i = 0; i < add; i++) *pos = val;
      }
    }
  }
};
struct Bits { Array<unsigned> words; int count;
  Bits() : count(0) {}
  void resize(int n) {
    if (n == 0) { unsigned *f = words.finish, *s = words.start; unsigned d = (char *)f - (char *)s; memcpy_802eee50(s, f, 0); count = n; words.finish = (unsigned *)((char *)words.finish - d); }
    else { words.resize(((unsigned)(n - 1) >> 5) + 1, 0); count = n; }
  }
};
struct Bucket { int a, b; Bucket() { bucket_init_8034cb20(this); } };
extern void *vt_80412318[], *vt_80412250[], *vt_804123e0[];
struct Hook { void *vt; int w[4]; int w5; Hook() { vt = vt_804123e0; w5 = 0; hook_init_801788e4(this); } };
struct Held { int *p; Held() : p(0) {} ~Held(); };
struct D40jResourceManager;
extern D40jResourceManager *lbl_804ab5c4;
extern int lbl_804ab5c0, lbl_804ab5ac, lbl_804ab5b0, lbl_804ab5b4, lbl_804ab5b8, lbl_804ab5bc;
extern char name_max_instances_803a6830[], name_max_hooks_803a6844[];
struct Tagged { unsigned pointer : 24; unsigned kind : 8; };
struct Flags { unsigned short a, b; Tagged w; Flags() { w.kind = 2; w.pointer = 0; } void clr() { a = 0; b = 0; } };
struct Pair { int r12, r16; Pair() : r12(0), r16(0) {} };
struct Root { void *vt; Root() { vt = vt_80412318; } };
struct Base0 : Root { Flags f; Pair p; Base0() { f.clr(); } };
struct Base1 : Base0 { Base1() { vt = vt_80412250; } };
struct D40jResourceManager : Base1 {
  int f20; Held *held; Bits bits; Bucket buckets[256];
  int max2; Hook *hooks; int nhooks; Array<unsigned> free_list; int maxInst;
  D40jResourceManager();
};
D40jResourceManager::D40jResourceManager() {
  lbl_804ab5c4 = this;
  if (settings_int_80206920(name_max_instances_803a6830, &maxInst) < 0) maxInst = 3000;
  f20 = 0;
  max2 = maxInst;
  lbl_804ab5ac = 0; lbl_804ab5b0 = 0; lbl_804ab5b4 = 0; lbl_804ab5b8 = 0; lbl_804ab5bc = 0; lbl_804ab5c0 = 0;
  if (settings_int_80206920(name_max_hooks_803a6844, &nhooks) < 0) nhooks = 256;
  hooks = new Hook[nhooks];
  for (unsigned i = 0; i < (unsigned)nhooks; i++) free_list.push_back(i);
  bits.resize(maxInst);
  held = new Held[maxInst];
}
