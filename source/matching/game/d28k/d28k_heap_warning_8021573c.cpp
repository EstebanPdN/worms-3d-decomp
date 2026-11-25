// Heap warning text (Vmalloc dbwarn shape; Worms 3D GameCube PAL, 0x8021573c).
// Builds a message in a 1024-byte buffer from the error type (alloc, free, resize, corrupted
// data, alert), the region, the block, the reason, the bad byte and the recorded and detected
// file and line, then writes it through 0x802156f8.

extern "C" int abs(int);
struct Table { void *a,*b,*c; char *(*copy)(char *, const char *, int); char *(*itoa)(long, int); };
extern "C" Table lbl_80400768[];
extern "C" int lbl_804aba80;
extern "C" void fn_802156c8();
extern "C" void fn_802156f8(void *, char *, long);
extern "C" unsigned int strlen(const char *);
extern "C" const char lbl_803b36cc[], lbl_803b36d8[], lbl_803b36e4[], lbl_803b36f4[], lbl_803b3704[], lbl_803b370c[], lbl_803b3714[], lbl_803b371c[], lbl_803b3730[], lbl_803b3744[], lbl_803b3758[], lbl_803b3768[], lbl_803b3770[], lbl_803b3780[], lbl_803b378c[], lbl_803b379c[], lbl_803b37ac[], lbl_803b37b8[], lbl_803b37c8[];
#define COPY(p,s,c) (*lbl_80400768[0].copy)(p,s,c)
#define ITOA(v,b) (*lbl_80400768[0].itoa)(v,b)
extern "C" void w3d_d28k_heap_warning_8021573c(void *vm, char *data, long where, const char *file, int line, int type) {
 char buf[1024], *bufp, *endbuf;
 const char *s;
 if (!lbl_804aba80) {
  fn_802156c8();
  lbl_804aba80 = 1;
 }
 bufp = buf;
 endbuf = buf + sizeof(buf);
 if (type == 1) bufp = COPY(bufp, lbl_803b36cc, ':');
 else if (type == 2) bufp = COPY(bufp, lbl_803b36d8, ':');
 else if (type == 3) bufp = COPY(bufp, lbl_803b36e4, ':');
 else if (type == 0) bufp = COPY(bufp, lbl_803b36f4, ':');
 else if (type == 4) bufp = COPY(bufp, lbl_803b3704, ':');
 bufp = COPY(bufp, lbl_803b370c, '=');
 bufp = COPY(bufp, ITOA((long)vm, 0), ':');
 if (data) {
  bufp = COPY(bufp, lbl_803b3714, '=');
  bufp = COPY(bufp, ITOA((long)data, 0), ':');
 }
 if (!data) {
  if (where == 1) bufp = COPY(bufp, lbl_803b371c, ':');
  else bufp = COPY(bufp, lbl_803b3730, ':');
 } else if (type == 2 || type == 3) {
  if (where == 0) bufp = COPY(bufp, lbl_803b3744, ':');
  else bufp = COPY(bufp, lbl_803b3758, ':');
 } else if (type == 4) {
  bufp = COPY(bufp, lbl_803b3768, '=');
  bufp = COPY(bufp, ITOA(*(long *)(data - 12), -1), ':');
  if (where == 1) bufp = COPY(bufp, lbl_803b3770, ':');
  else if (where == 2) bufp = COPY(bufp, lbl_803b3780, ':');
  else if (where == 3) bufp = COPY(bufp, lbl_803b378c, ':');
  else if (where == 5) bufp = COPY(bufp, lbl_803b379c, ':');
 } else if (type == 0) {
  bufp = COPY(bufp, lbl_803b37ac, '=');
  bufp = COPY(bufp, ITOA(where, -1), ':');
  s = *(const char **)(data - 16);
  if (s && bufp + strlen(s) + 64 < endbuf) {
   bufp = COPY(bufp, lbl_803b37b8, '=');
   bufp = COPY(bufp, s, ',');
   bufp = COPY(bufp, ITOA(abs(*(int *)((char *)(*(unsigned long *)(data - 20) & ~7UL) + (unsigned long)data - 20)), -1), ':');
  }
 }
 if (file && file[0] && line > 0 && bufp + strlen(file) + 64 < endbuf) {
  bufp = COPY(bufp, lbl_803b37c8, '=');
  bufp = COPY(bufp, file, ',');
  bufp = COPY(bufp, ITOA(line, -1), ':');
 }
 *bufp++ = '\n';
 *bufp = 0;
 fn_802156f8(vm, buf, bufp - buf);
}
