#include "w3d_ptr.h"
#line 1 "f1b_node_construct_8015b254.cpp"
struct f1b_Owner { Ptr32<void> node; };
// An 8-byte initialization record; only its two words are read by the body.
struct f1b_ZeroPair {
  int first;
  int second;
};
extern "C" Ptr32<void> fn_801fe1d8(unsigned int size);
// Allocate a 16-byte node, clear it from a zeroed pair and publish the node
// through the owner, returning the owner.
extern "C" Ptr32<f1b_Owner> f1b_node_construct_8015b254(Ptr32<f1b_Owner> self)
{
  // Preserve the original frame reservation; the purpose of this slot is unknown.
  volatile char reserved;
  Ptr32<char> node = (Ptr32<char>)fn_801fe1d8(16);
  {
    f1b_ZeroPair zero = { 0, 0 };
    *(Ptr32<int>)(node + 0) = zero.first;
    *(Ptr32<int>)(node + 4) = zero.second;
    Ptr32<int> tail = (Ptr32<int>)(node + 8);
    tail[1] = zero.second;
  }
  *(Ptr32<Ptr32<void>>)self = node;
  return self;
}


