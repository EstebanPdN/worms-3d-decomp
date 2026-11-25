// Tagged-object constructor family. Names and meanings are inferred; offsets
// are observed. The tag word at +4 packs a 24-bit pointer above an 8-bit kind
// (same layout as the static node getter 0x8020b208, which stores the kind
// byte and then inserts the pointer field with rlwimi). Storing kind and then
// clearing the pointer field reproduces the original byte reload (lbz of the
// kind byte just stored) without a volatile access.
#include "mx16oa_tagged_leaf_8020b058_base.h"

// Pair at +12: both words cleared.
struct Mx16oaTaggedPair {
    int first;
    int second;
    void clear() { second = 0; }
    Mx16oaTaggedPair() { first = 0; clear(); }
};

// Tag at +4: two halfwords, then the packed pointer/kind word.
struct Mx16oaTag {
    unsigned short a;
    unsigned short b;
    unsigned int pointer : 24;
    unsigned int kind : 8;
    Mx16oaTag(unsigned char tag) { kind = tag; pointer = 0; }
    void clear_halves() { a = 0; b = 0; }
};

// Tagged base: shares the root table (adds no virtual functions).
struct Mx16oaTagged : Mx16oaTaggedRoot {
    Mx16oaTag tag;          // +4
    Mx16oaTaggedPair pair;  // +12
    Mx16oaTagged() : tag(2) { tag.clear_halves(); }
};

// Leaf with its own table at 0x804194a0; the slot is defined elsewhere, so
// that table stays external.
struct Mx16oaTaggedLeaf : Mx16oaTagged {
    Mx16oaTaggedLeaf();
    void slot0();
};

Mx16oaTaggedLeaf::Mx16oaTaggedLeaf() {}
