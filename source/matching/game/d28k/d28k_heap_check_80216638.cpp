// Debug heap check (Worms 3D GameCube PAL, 0x80216638).
// Returns -1 unless the heap has checks enabled (flag 512). Walks every chunk of every
// block; for an in-use chunk it counts a non-positive tail counter as bad, then scans the
// guard bytes (value 173) before and after the payload. A damaged guard is reported
// through 0x8021573c, the tail counter is negated and the chunk counts as bad.

struct Node { Node *back; unsigned long size; };
struct Hdr { char pad[20]; char guard[4]; };
struct Block { int a; Block *next; int c; int d; char *high; };
struct Heap { unsigned long flags; int b,c; Block *blocks; };
struct Arena { char pad[48]; Heap *heap; };
extern "C" int fn_8021573c(Arena *, char *, int, void *, int, int);
#define TAIL(u) ((char *)(*(unsigned long *)((u) - 20) & ~7UL) + (unsigned long)(u))
extern "C" int w3d_d28k_heap_check_80216638(Arena *self) {
 Heap *h = self->heap;
 if ((h->flags & 512) == 0) return -1;
 int bad = 0;
 Block *b = h->blocks;
 while (b) {
  char *end = b->high - 8;
  Node *p = (Node *)((char *)b + 32);
  while ((char *)p < end) {
   if ((p->size & 5) == 1) {
    char *user = (char *)p + 24;
    if (*(int *)(TAIL(user) - 20) <= 0) bad++;
    else {
     char *c = ((Hdr *)p)->guard, *lim;
     int *q;
     for (; c < user; c++) if (*(unsigned char *)c != 173) goto corrupt;
     lim = TAIL(user) - 20;
     c = user + *(int *)(user - 12);
     if (c < lim) do {
      if (*(unsigned char *)c != 173) {
      corrupt:
       fn_8021573c(self, user, c - user, 0, 0, 0);
       q = (int *)(TAIL(user) - 24);
       if (q[1] > 0) q[1] = -q[1];
       bad++;
       break;
      }
      c++;
     } while (c < lim);
    }
   }
   p = (Node *)((char *)p + ((p->size & ~7UL) + 8));
  }
  b = b->next;
 }
 return bad;
}
