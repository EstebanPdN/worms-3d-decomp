#include "w3d_ptr.h"
#line 1 "actor_reference_initialize.cpp"
extern "C" {
#include "actor_construction.h"
}
union FlagWord { unsigned int word; w3d::be_array<unsigned char, 4> bytes; };
struct Counts { unsigned short first, second; FlagWord flags; };
struct Links { Ptr32<Links> next; Ptr32<Links> previous; };
/* Native layout hypothesis: counters/packed tag, then two owner links. */
struct Node { Ptr32<void> methods; Counts counts; Links links; unsigned int extra; Ptr32<ActorChildNode> children; };
typedef char native_prefix_size_matches_shared[(sizeof(Node) == sizeof(ActorBaseStorage)) ? 1 : -1];
typedef char native_counts_size[(sizeof(Counts) == 8) ? 1 : -1];
typedef char native_links_size[(sizeof(Links) == 8) ? 1 : -1];

/* FUN_8015fa40, original range [0x8015fa40, 0x8015fa94).
 * References preserve observed member address expressions under SN GCC v1.46.
 * This is a source reconstruction; the original C++ spelling is unknown. */
extern "C" Ptr32<ActorBaseStorage> w3d_actor_reference_initialize(Ptr32<ActorBaseStorage> actor) {
    Ptr32<Node> node = (Ptr32<Node>)actor;
    node->methods = (Ptr32<void>)w3d_actor_node_methods;
    Ptr32<Counts> owner = &node->counts;
    owner->flags.bytes[3] = 2;
    FlagWord &flags = owner->flags;
    flags.word = flags.bytes[3];
    node->links.next = 0;
    Links &links = node->links;
    links.previous = 0;
    owner->first = 0;
    owner->second = 0;
    node->methods = (Ptr32<void>)w3d_actor_reference_methods;
    node->extra = 0;
    node->children = 0;
    return actor;
}


