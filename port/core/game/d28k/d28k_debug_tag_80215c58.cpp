#include "w3d_ptr.h"
#line 1 "d28k_debug_tag_80215c58.cpp"
// Debug block tagging (Worms 3D GameCube PAL, 0x80215c58).
// On first use runs 0x802156c8. Looks the file name up in a move-to-front list (0x804b06c0),
// adding a new entry through the name allocator, stores name, line (1 when there is no
// name), size and a copy of the chunk word in the header, and fills the guards before and
// after the payload with 173. The list head is written with the old head in both insert
// paths: that is what the original does, so entries beyond the first are not kept linked.

extern "C" void fn_802156c8();
extern "C" int lbl_804aba80;
extern "C" Ptr32<char> lbl_804b06c0;
struct NameAlloc { Ptr32<Ptr32<char> (Ptr32<NameAlloc>, unsigned int)> alloc; };
extern "C" Ptr32<NameAlloc> lbl_804aba6c;
struct Table { Ptr32<void> slot[3]; Ptr32<Ptr32<char> (Ptr32<char>, Ptr32<const char>, int)> copy; };
extern "C" Table lbl_80400768[];
extern "C" unsigned int strlen(Ptr32<const char>);
extern "C" int strcmp(Ptr32<const char>, Ptr32<const char>);
extern "C" void w3d_d28k_debug_tag_80215c58(Ptr32<char> mem, unsigned int size, Ptr32<const char> file, int line) {
 if (lbl_804aba80 == 0) {
  fn_802156c8();
  lbl_804aba80 = 1;
 }
 Ptr32<char> name; Ptr32<char> prev;
 Ptr32<unsigned char> start;
 if (!file || *file == 0) { name = 0; start = (Ptr32<unsigned char>)mem - 4; }
 else {
  name = lbl_804b06c0;
  prev = 0;
  start = (Ptr32<unsigned char>)mem - 4;
  goto test;
 next:
  prev = name;
  name = *(Ptr32<Ptr32<char>>)name;
 test:
  if (name) goto compare;
  name = lbl_804aba6c->alloc(lbl_804aba6c, strlen(file) + 8);
  if (!name) goto store;
  lbl_80400768[0].copy(name + 4, file, 0);
  *(Ptr32<Ptr32<char>>)name = lbl_804b06c0;
  lbl_804b06c0 = *(Ptr32<Ptr32<char>>)name;
  goto store;
 compare:
  if (strcmp(name + 4, file)) goto next;
  if (prev) {
   Ptr32<char> follow = *(Ptr32<Ptr32<char>>)name; Ptr32<char> head = lbl_804b06c0;
   *(Ptr32<Ptr32<char>>)prev = follow;
   *(Ptr32<Ptr32<char>>)name = head;
   lbl_804b06c0 = head;
  }
 }
 store:
 *(Ptr32<Ptr32<char>>)(mem - 16) = name ? w3d::R(name + 4) : 0;
 Ptr32<char> tail = (Ptr32<char>)w3d::G((*(Ptr32<unsigned int>)(mem - 20) & ~7UL)) + (unsigned int)w3d::H(mem) - 24;
 if (name && name + 4 != 0) *(Ptr32<int>)(tail + 4) = line;
 else *(Ptr32<int>)(tail + 4) = 1;
 *(Ptr32<unsigned int>)(mem - 12) = size;
 *(Ptr32<unsigned int>)(mem - 8) = *(Ptr32<unsigned int>)(mem - 24);
 Ptr32<unsigned char> q = start;
 for (; q < (Ptr32<unsigned char>)mem; q++) *q = 173;
 Ptr32<unsigned char> lim = (Ptr32<unsigned char>)w3d::G((*(Ptr32<unsigned int>)(mem - 20) & ~7UL)) + (unsigned int)w3d::H(mem) - 20;
 for (q = (Ptr32<unsigned char>)mem + *(Ptr32<int>)(mem - 12); q < lim; q++) *q = 173;
}


