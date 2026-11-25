// (Worms 3D GameCube PAL, 0x8020941c).
//
// Initialises a heap object: runs the empty hook, then either allocates its
// own 128-aligned arena of the requested size, with trace output around it,
// and opens the heap in it, or opens the heap over the default region. The
// open variant and mode come from flags at +20 and +40. Sets the owner on
// the opened heap, a default name, and runs the second hook. Returns 0.
// Names are inferred.

extern "C" int printf(const char *, ...);
struct Heap;
extern "C" void w3d_empty_802092c0(Heap *);
extern "C" void w3d_empty_802092c4(Heap *);
extern "C" void w3d_empty_802095d4(Heap *);
extern "C" int w3d_heap_morecore(int);
extern "C" void *w3d_aligned_allocate(unsigned, int);
struct Inner { char p[32]; Heap *owner; };
extern "C" Inner *w3d_d28k_heap_open_802168c4(void *, void *, int);
struct Heap { Inner *h; void *arena; unsigned size; int used; int pad; unsigned flags; void (*cb)(); int x28; int x32; int pad2; int x40; int ownsArena; int pad3; const char *name; };
extern char lbl_803b2f28[], lbl_803b2f3c[], lbl_803b2f60[], lbl_803b2f7c[];
extern "C" void fn_80209190(void *, void *, void *, void *);
extern int lbl_804b0670;
extern Heap *lbl_804b0684;
extern void *lbl_804aba84, *lbl_804aba88, *lbl_804aba74, *lbl_804aba7c;
extern "C" int w3d_d30e_heap_init_8020941c(Heap *self, unsigned size) {
  w3d_empty_802092c0(self);
  lbl_804b0670 = 1;
  self->used = 0;
  if (size) {
    printf(lbl_803b2f28, w3d_heap_morecore(0));
    printf(lbl_803b2f3c, size);
    void *p = w3d_aligned_allocate(size, 128);
    self->size = size;
    self->ownsArena = 1;
    self->used = 0;
    self->arena = p;
    printf(lbl_803b2f60, p);
    printf(lbl_803b2f28, w3d_heap_morecore(0));
    self->x32 = 0;
    self->cb = (void (*)())fn_80209190;
    self->x28 = 0;
    lbl_804b0684 = self;
    if (self->flags & 1) {
      if (self->flags & 2) self->h = w3d_d28k_heap_open_802168c4(&self->cb, lbl_804aba84, 5);
      else self->h = w3d_d28k_heap_open_802168c4(&self->cb, lbl_804aba84, 1);
    } else if (self->x40) self->h = w3d_d28k_heap_open_802168c4(&self->cb, lbl_804aba88, 1);
    else self->h = w3d_d28k_heap_open_802168c4(&self->cb, lbl_804aba74, 1);
    lbl_804b0684 = 0;
  } else {
    self->arena = 0;
    self->size = 0;
    if (self->x40) self->h = w3d_d28k_heap_open_802168c4(lbl_804aba7c, lbl_804aba88, 1);
    else self->h = w3d_d28k_heap_open_802168c4(lbl_804aba7c, lbl_804aba74, 1);
    self->ownsArena = 0;
  }
  w3d_empty_802092c4(self);
  self->h->owner = self;
  lbl_804b0670 = 0;
  if (!self->name) self->name = lbl_803b2f7c;
  w3d_empty_802095d4(self);
  return 0;
}
