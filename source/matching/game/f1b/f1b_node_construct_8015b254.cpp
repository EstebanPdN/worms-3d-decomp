struct f1b_Owner { void *node; };
// An 8-byte initialization record; only its two words are read by the body.
struct f1b_ZeroPair {
  int first;
  int second;
};
extern "C" void *fn_801fe1d8(unsigned int size);
// Allocate a 16-byte node, clear it from a zeroed pair and publish the node
// through the owner, returning the owner.
extern "C" f1b_Owner *f1b_node_construct_8015b254(f1b_Owner *self)
{
  // Preserve the original frame reservation; the purpose of this slot is unknown.
  volatile char reserved;
  char *node = (char *)fn_801fe1d8(16);
  {
    f1b_ZeroPair zero = { 0, 0 };
    *(int *)(node + 0) = zero.first;
    *(int *)(node + 4) = zero.second;
    int *tail = (int *)(node + 8);
    tail[1] = zero.second;
  }
  *(void **)self = node;
  return self;
}
