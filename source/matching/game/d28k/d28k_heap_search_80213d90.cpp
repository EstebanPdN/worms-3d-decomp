// Heap tree search (Vmalloc bestsearch shape; Worms 3D GameCube PAL, 0x80213d90).
// A wanted 8-byte chunk is unlinked from its list and its segment found. Otherwise a
// top-down splay finds an exact size or the least larger chunk, promotes the next chunk of
// an equal-size list or grafts the left tree to the right, and stores the new root.

struct Node { Node *back; unsigned long size; Node *link; Node *left; Node *right; };
struct Seg { int a; Seg *next; char *addr; int b; char *high; };
struct Heap { int a,b,c; Seg *seg; int d,e; Node *root; Node *small; };
extern "C" Node *w3d_d28k_heap_search_80213d90(Heap *vd, unsigned long size, Node *wanted) {
 unsigned long s;
 Node *t, *root, *l, *r;
 Node link;
 if ((root = wanted) && size == 8) {
  Seg *seg;
  l = root->back;
  if ((r = root->link)) r->back = l;
  if (l) l->link = r;
  else vd->small = r;
  seg = vd->seg;
  if (!seg->next) root->back = (Node *)seg;
  else for (;; seg = seg->next) {
   if ((char *)root > seg->addr && (char *)root < seg->high) {
    root->back = (Node *)seg;
    break;
   }
  }
  return root;
 }
 l = r = &link;
 if ((root = vd->root)) do {
  if (size == (s = root->size)) break;
  if (size < s) {
   if ((t = root->left)) {
    if (size <= (s = t->size)) {
     root->left = t->right;
     t->right = root;
     root = t;
     if (size == s) break;
     t = root->left;
    } else {
     l->right = t;
     l = t;
     t = t->right;
    }
   }
   r->left = root;
   r = root;
  } else {
   if ((t = root->right)) {
    if (size >= (s = t->size)) {
     root->right = t->left;
     t->left = root;
     root = t;
     if (size == s) break;
     t = root->right;
    } else {
     r->left = t;
     r = t;
     t = t->left;
    }
   }
   l->right = root;
   l = root;
  }
 } while ((root = t));
 if (root) {
  l->right = root->left;
  r->left = root->right;
 } else {
  r->left = 0;
  l->right = 0;
  if ((root = link.left)) {
   while ((t = root->left)) {
    root->left = t->right;
    t->right = root;
    root = t;
   }
   link.left = root->right;
  }
 }
 if (root && (r = root->link)) {
  r->left = link.right;
  r->right = link.left;
 } else if (!(r = link.left)) r = link.right;
 else {
  while ((t = r->left)) {
   r->left = t->right;
   t->right = r;
   r = t;
  }
  r->left = link.right;
 }
 vd->root = r;
 return root;
}
