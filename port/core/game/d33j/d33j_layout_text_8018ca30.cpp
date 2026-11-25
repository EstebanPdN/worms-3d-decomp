#include "w3d_ptr.h"
#line 1 "d33j_layout_text_8018ca30.cpp"
/* GWMP8P rev0 0x8018ca30. Lays out a text object's glyph quads: locks the index, position and UV arrays of the
 * geometry for one or (two-sided, drop shadow) two copies of each glyph, sizes the two engine arrays of glyph
 * positions and sizes, optionally fills the colour array, walks the string accumulating the pen position from each
 * glyph's width over twice the first glyph's weight, then shifts everything for centre or right alignment and calls
 * the update at 0x8018d660. The array class is the engine's (grows by half, no allocator). Names are inferred. */
extern "C" Ptr32<void> w3d_k5b_array_ref_lock_801ef048(Ptr32<void>, int, int, int);
extern "C" Ptr32<void> w3d_handle_storage_allocate(unsigned);
extern "C" void w3d_handle_storage_release(Ptr32<void>);
extern "C" Ptr32<void> fn_802eee50(Ptr32<void>, Ptr32<const void>, ...);
extern "C" Ptr32<void> memmove(Ptr32<void>, Ptr32<const void>, unsigned);
struct D33jVec2 { float x, y; D33jVec2() {} void Set(float a, float b) { x = a; y = b; } };
struct D33jOffset { float x, y; float Y() const { return y; } };
struct D33jVec { float x, y, z; D33jVec() {} D33jVec(const D33jVec &o) { x = o.x; y = o.y; z = o.z; }
  D33jVec(float a, float b, float c) { Ptr32<D33jVec> q = this; x = a; q->y = b; q->z = c; }
  D33jVec(const D33jOffset &o, float c) { float a = o.x, b = o.Y(); Ptr32<D33jVec> q = this; x = a; y = b; q->z = c; } };
inline D33jVec operator+(const D33jVec &a, const D33jVec &b) { D33jVec r; r.x = a.x + b.x; r.y = a.y + b.y; r.z = a.z + b.z; return r; }
struct D33jBlob { char p0[4]; unsigned short kind; char p6[18]; int count; unsigned short locks; char p1e[2]; char data[1]; };
struct D33jHandle {
  Ptr32<D33jBlob> b;
  Ptr32<void> lock(int n, int stride) {
    Ptr32<D33jBlob> x = b;
    if (x->kind == 1 && n == x->count) { x->locks++; return x->data; }
    return w3d_k5b_array_ref_lock_801ef048(this, n, stride, 0);
  }
};
inline const int &Max(const int &a, const int &b) { return a < b ? b : a; }
inline const unsigned &Min(const unsigned &a, const unsigned &b) { return b < a ? b : a; }
template <class T> struct D33jArray {
  Ptr32<T> start; Ptr32<T> finish; Ptr32<T> end;
  unsigned size() const { return finish - start; }
  T &operator[](unsigned i) { return *(start + i); }
  void erase(Ptr32<T> first, Ptr32<T> last) { int d = (Ptr32<char>)last - (Ptr32<char>)first; fn_802eee50(first, last, finish - last); finish = (Ptr32<T>)((Ptr32<char>)finish - d); }
  void insert(Ptr32<T> pos, unsigned d, const T &v) {
    if (pos + d > end) {
      unsigned have = pos - start;
      unsigned used = (Ptr32<char>)finish - (Ptr32<char>)start;
      unsigned cap = (Ptr32<char>)end - (Ptr32<char>)start;
      int a = cap + (d - (end - pos)), b = cap + (cap >> 1);
      unsigned bytes = Max(a, b) << 3;
      Ptr32<T> q = (Ptr32<T>)w3d_handle_storage_allocate(bytes);
      if (start) { fn_802eee50(q, start, Min(bytes, used)); w3d_handle_storage_release(start); }
      start = q;
      pos = q + have;
      finish = (Ptr32<T>)((Ptr32<char>)q + used);
      end = (Ptr32<T>)((Ptr32<char>)q + bytes);
    }
    if (pos == finish) {
      for (unsigned i = 0; i < d; ++i) finish[i] = v;
      finish += d;
    } else {
      T x = v;
      memmove(pos + d, pos, (Ptr32<char>)finish - (Ptr32<char>)pos);
      finish += d;
      for (unsigned i = 0; i < d; ++i) *pos = x;
    }
  }
  void setsize(unsigned n, unsigned s, const T &v) {
    if (n < s) erase(start + n, finish);
    else insert(finish, n - s, v);
  }
  void resize(unsigned n) {
    unsigned s = size();
    if (s != n) setsize(n, s, T());
  }
};
struct D33jGeo { char p0[64]; D33jHandle pos, uv, colors; char p4c[4]; D33jHandle idx; };
struct D33jGlyph { float value, weight; };
struct D33jNode { unsigned slot[10]; };
struct D33jStyle { char p0[44]; D33jOffset o; unsigned backColor, frontColor; };
struct D33jText {
  char p0[116];
  Ptr32<void> style;
  char p78[48];
  Ptr32<D33jNode> font;
  Ptr32<D33jGeo> geo;
  char pb0[4];
  D33jArray<unsigned short> text;
  unsigned flags;
  char pc4[44];
  int twoSided;
  char pf4[4];
  char xf8[4];
  D33jArray<D33jVec2> a, c;
  int build();
};
extern "C" Ptr32<D33jStyle> w3d_empty_8034435c(Ptr32<void>);
extern "C" int w3d_cc29b_fill_text_8018d35c(Ptr32<D33jText>, Ptr32<void>);
extern "C" int fn_8018d660(Ptr32<D33jText>, Ptr32<void>);
int D33jText::build() {
  unsigned n = text.size();
  Ptr32<D33jStyle> fnt = w3d_empty_8034435c(style);
  unsigned total = n;
  if (twoSided) total = n * 2;
  Ptr32<unsigned short> ip = (Ptr32<unsigned short>)geo->idx.lock(total, 2);
  Ptr32<D33jVec> vp = (Ptr32<D33jVec>)geo->pos.lock(total, 12);
  Ptr32<D33jVec2> tp = (Ptr32<D33jVec2>)geo->uv.lock(total, 8);
  unsigned old = geo->colors.b->count;
  a.resize(n);
  c.resize(n);
  if (total == 0) return 0;
  if ((old > 1 && old != total) || twoSided) {
    if (twoSided) {
      Ptr32<unsigned int> c0 = (Ptr32<unsigned int>)geo->colors.lock(total, 4);
      for (unsigned j = 0; j < n; ++j) { c0[j] = fnt->frontColor; c0[n + j] = fnt->backColor; }
    } else w3d_cc29b_fill_text_8018d35c(this, &fnt->backColor);
  }
  int slot = 7;
  Ptr32<unsigned int> tracks = (Ptr32<unsigned int>)w3d::G((this->font->slot[slot] + 32));
  unsigned short g = text[0];
  Ptr32<D33jGlyph> values = (Ptr32<D33jGlyph>)w3d::G((((Ptr32<D33jNode>)w3d::G(tracks[g >> 8]))->slot[slot] + 32));
  float weight = values[g & 0xff].weight;
  float half = values[g & 0xff].value / (weight + weight);
  unsigned align = flags & 3;
  float y = 0.0f;
  if (align == 1) y = -0.5f;
  else if (align == 2) y = 0.5f;
  D33jVec p(half, y, 0.0f);
  D33jVec off(fnt->o, 0.0f);
  int i = 0;
  for (;;) {
    if (twoSided) {
      D33jVec q = p + off;
      vp[i] = q;
      ip[i] = g;
      tp[i].x = half;
      tp[i].y = 0.5f;
      vp[n + i] = p;
      ip[n + i] = g;
      tp[n + i].x = half;
      tp[n + i].y = 0.5f;
    } else {
      vp[i] = p;
      ip[i] = g;
      tp[i].x = half;
      tp[i].y = 0.5f;
    }
    a[i].Set(p.x, p.y);
    c[i].Set(half, 0.5f);
    ++i;
    if (i == (int)n) { p.x += half; break; }
    g = text[i];
    p.x += half;
    { int s = 7; Ptr32<D33jGlyph> vals = (Ptr32<D33jGlyph>)w3d::G((((Ptr32<D33jNode>)w3d::G(tracks[g >> 8]))->slot[s] + 32)); half = vals[g & 0xff].value / (weight + weight); }
    p.x += half;
  }
  float d;
  unsigned mode = flags & 12;
  if (mode != 0 && mode != 8) goto done;
  if (mode == 0) d = -p.x * 0.5f;
  else d = -p.x;
  for (unsigned j = 0; j < n; ++j) { vp[j].x += d; a[j].x += d; }
  if (twoSided) for (unsigned j = 0; j < n; ++j) vp[n + j].x += d;
done:
  fn_8018d660(this, xf8);
  return 0;
}


