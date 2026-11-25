// Debug block tagging (Worms 3D GameCube PAL, 0x80215c58).
// On first use runs 0x802156c8. Looks the file name up in a move-to-front list (0x804b06c0),
// adding a new entry through the name allocator, stores name, line (1 when there is no
// name), size and a copy of the chunk word in the header, and fills the guards before and
// after the payload with 173. The list head is written with the old head in both insert
// paths: that is what the original does, so entries beyond the first are not kept linked.

extern "C" void fn_802156c8();
extern "C" int lbl_804aba80;
extern "C" char *lbl_804b06c0;
struct NameAlloc { char *(*alloc)(NameAlloc *, unsigned long); };
extern "C" NameAlloc *lbl_804aba6c;
struct Table { void *slot[3]; char *(*copy)(char *, const char *, int); };
extern "C" Table lbl_80400768[];
extern "C" unsigned int strlen(const char *);
extern "C" int strcmp(const char *, const char *);
extern "C" void w3d_d28k_debug_tag_80215c58(char *mem, unsigned long size, const char *file, int line) {
 if (lbl_804aba80 == 0) {
  fn_802156c8();
  lbl_804aba80 = 1;
 }
 char *name, *prev;
 unsigned char *start;
 if (!file || *file == 0) { name = 0; start = (unsigned char *)mem - 4; }
 else {
  name = lbl_804b06c0;
  prev = 0;
  start = (unsigned char *)mem - 4;
  goto test;
 next:
  prev = name;
  name = *(char **)name;
 test:
  if (name) goto compare;
  name = lbl_804aba6c->alloc(lbl_804aba6c, strlen(file) + 8);
  if (!name) goto store;
  lbl_80400768[0].copy(name + 4, file, 0);
  *(char **)name = lbl_804b06c0;
  lbl_804b06c0 = *(char **)name;
  goto store;
 compare:
  if (strcmp(name + 4, file)) goto next;
  if (prev) {
   char *follow = *(char **)name, *head = lbl_804b06c0;
   *(char **)prev = follow;
   *(char **)name = head;
   lbl_804b06c0 = head;
  }
 }
 store:
 *(char **)(mem - 16) = name ? name + 4 : 0;
 char *tail = (char *)(*(unsigned long *)(mem - 20) & ~7UL) + (unsigned long)mem - 24;
 if (name && name + 4 != 0) *(int *)(tail + 4) = line;
 else *(int *)(tail + 4) = 1;
 *(unsigned long *)(mem - 12) = size;
 *(unsigned long *)(mem - 8) = *(unsigned long *)(mem - 24);
 unsigned char *q = start;
 for (; q < (unsigned char *)mem; q++) *q = 173;
 unsigned char *lim = (unsigned char *)(*(unsigned long *)(mem - 20) & ~7UL) + (unsigned long)mem - 20;
 for (q = (unsigned char *)mem + *(int *)(mem - 12); q < lim; q++) *q = 173;
}
