// Position array binding command handler recovered from 0x80169094. It flushes the
// command's dirty buffer. An owner of the skin type transforms the positions into
// temporary storage through a stack matrix table; any other owner does so through
// a vector of matrix pointers; no owner binds the source. Names are inferred;
// unread fields are partial views. The second read of the buffer pointer is
// volatile: see the array bind family.
#include "compat/stlport_sn_oom.h"
#include <vector>
struct Vec { float x, y, z; };
extern "C" {
void DCFlushRange(void *start, unsigned bytes);
void GXSetArray(int attr, void *base, unsigned char stride);
void *w3d_cc17b_temp_alloc_8016a21c(void *self, unsigned bytes);
void w3d_auto_8016805c(void *scene);
void f8c_skin_801a1460(void *src, unsigned influences, void *weights, void *indices, float **matrices, void *dst, int count, int srcStride, int dstStride);
void f13b_skin_801a1250(void *src, unsigned influences, void *weights, float **matrices, void *dst, int count);
}
extern void *global_804b1884;
extern char skin_type_80363654[];
struct Buf {
    unsigned char pad[24]; unsigned count; unsigned short dirty; unsigned short pad2; unsigned char data[16];
    void Sync(void *d, unsigned n) { if (dirty) { DCFlushRange(d, n); dirty = 0; } }
};
struct Mesh { unsigned char pad[20]; Buf *buffer; };
struct Type { char pad[20]; Type *parent; };
struct Bone { char p[48]; };
struct Skin;
struct SkinVt { void *u[5]; Type *(*type)(Skin *); };
struct Skin { SkinVt *vt; char p16[16]; Buf *weights; unsigned short influences; short p26; Buf *indices; };
struct R { char p0[124]; Skin *skin; Bone **bones; unsigned bone_count; char p136[148]; int count; unsigned flags; };
struct Sink { void *vt; };
inline unsigned Bytes(const unsigned &n) { return n * 12; }
inline bool IsA(Type *t, Type *want) {
  while (t != want) { Type *n = t->parent; if (t == n) return false; t = n; }
  return true;
}
inline Skin *AsSkin(Skin *s) { return (s && IsA(s->vt->type(s), (Type *)skin_type_80363654)) ? s : 0; }
extern "C" int bind_position_array_skinned_80169094(Sink *sink, Mesh *mesh) {
  R *self = sink ? (R *)((char *)sink - 4) : 0;
  Buf *b = mesh->buffer; unsigned n = b->count; unsigned char *d = b->data;
  if (n != 0) {
    Buf *c = *(Buf *volatile *)&mesh->buffer; c->Sync(d, Bytes(n));
    if (self->skin) {
      Skin *s = AsSkin(self->skin);
      if (s) {
        void *ind = s->indices->data, *wei = s->weights->data;
        void *t = w3d_cc17b_temp_alloc_8016a21c(self, Bytes(n));
        float **mats = (float **)__builtin_alloca(self->bone_count * 64);
        for (unsigned i = 0; i < self->bone_count; i++) mats[i] = (float *)((char *)self->bones[i] + 48);
        f8c_skin_801a1460(d, s->influences, wei, ind, mats, t, n, 12, 12);
        w3d_auto_8016805c(global_804b1884);
        DCFlushRange(t, Bytes(n));
        GXSetArray(9, t, 12);
        self->flags |= 1; self->count++;
      } else {
        void *wei = self->skin->weights->data;
        void *t = w3d_cc17b_temp_alloc_8016a21c(self, Bytes(n));
        std::vector<float *> mats(self->bone_count);
        for (unsigned i = 0; i < self->bone_count; i++) mats[i] = (float *)((char *)self->bones[i] + 48);
        f13b_skin_801a1250(d, self->bone_count, wei, &mats[0], t, n);
        w3d_auto_8016805c(global_804b1884);
        DCFlushRange(t, Bytes(n));
        GXSetArray(9, t, 12);
        self->flags |= 1; self->count++;
      }
    } else {
      GXSetArray(9, d, 12);
      self->flags |= 1; self->count++;
    }
  }
  return 0;
}
