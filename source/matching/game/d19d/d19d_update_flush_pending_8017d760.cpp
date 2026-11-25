// d19d: 0x8017d760 (200 bytes). Timed update of an object that keeps a
// list of pending items: when the object is active (flags bit 31) it marks
// itself as updating (bit 30), calls its virtual +0x44 hook, advances by
// `time` through 0x8017e49c, clears the updating bit, hands every pending
// item to its virtual +0x7c visitor, empties the pending list and runs the
// global follow-ups 0x803439d8 and 0x8019831c. Always returns 0. Built with
// -mps-float (SN paired-single mode: one reserved 8-byte slot per saved FPR).
// The pending list is a vector-like {start, finish, end_of_storage} view;
// only the fields used here are named.
template <class T> struct D19dVector {
    T *start;
    T *finish;
    T *end_of_storage;
    T *begin() { return start; }
    T *end() { return finish; }
    void clear() { finish = start; }
};
struct D19dScene;
struct D19dSceneVtbl {
    void *unknown00[17];
    void (*enter)(D19dScene *self);              /* +68 */
    void *unknown48[13];
    void (*visit)(D19dScene *self, void *item);  /* +124 */
};
struct D19dScene {
    D19dSceneVtbl *vt;
    unsigned char unknown04[16];
    unsigned int flags;                          /* +20 */
    unsigned char unknown18[9788 - 24];
    D19dVector<void *> pending;                  /* +9788 (0x263c) */
};
extern "C" {
int fn_8017e49c(D19dScene *self, float time);
int fn_803439d8(void);
void fn_8019831c(void *);
int d19d_update_flush_pending_8017d760(D19dScene *self, float time);
}
int d19d_update_flush_pending_8017d760(D19dScene *self, float time)
{
    if (!(self->flags & 0x80000000))
        return 0;
    self->flags |= 0x40000000;
    self->vt->enter(self);
    fn_8017e49c(self, time);
    self->flags &= ~0x40000000;
    for (void **it = self->pending.begin(); it != self->pending.end(); ++it)
        self->vt->visit(self, *it);
    self->pending.clear();fn_8019831c((void *)fn_803439d8());
    return 0;
}
