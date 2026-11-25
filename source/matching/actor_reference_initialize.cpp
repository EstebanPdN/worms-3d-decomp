extern "C" {
#include "actor_construction.h"
}
union FlagWord { unsigned int word; unsigned char bytes[4]; };
struct Counts { unsigned short first, second; FlagWord flags; };
struct Links { Links *next, *previous; };
/* Native layout hypothesis: counters/packed tag, then two owner links. */
struct Node { void *methods; Counts counts; Links links; unsigned int extra; ActorChildNode *children; };
typedef char native_prefix_size_matches_shared[(sizeof(Node) == sizeof(ActorBaseStorage)) ? 1 : -1];
typedef char native_counts_size[(sizeof(Counts) == 8) ? 1 : -1];
typedef char native_links_size[(sizeof(Links) == 8) ? 1 : -1];

/* FUN_8015fa40, original range [0x8015fa40, 0x8015fa94).
 * References preserve observed member address expressions under SN GCC v1.46.
 * This is a source reconstruction; the original C++ spelling is unknown. */
extern "C" ActorBaseStorage *w3d_actor_reference_initialize(ActorBaseStorage *actor) {
    Node *node = (Node *)actor;
    node->methods = (void *)w3d_actor_node_methods;
    Counts *owner = &node->counts;
    owner->flags.bytes[3] = 2;
    FlagWord &flags = owner->flags;
    flags.word = flags.bytes[3];
    node->links.next = 0;
    Links &links = node->links;
    links.previous = 0;
    owner->first = 0;
    owner->second = 0;
    node->methods = (void *)w3d_actor_reference_methods;
    node->extra = 0;
    node->children = 0;
    return actor;
}
