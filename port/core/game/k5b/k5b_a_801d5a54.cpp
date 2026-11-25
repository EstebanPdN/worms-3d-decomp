#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k5b_a_801d5a54.c"
struct K5bTypeTag { char pad[6]; unsigned short slot; };
struct K5bQuery {
    char head[24];
    unsigned int flags;
    char pad[8];
    Ptr32<struct K5bTypeTag> tag;
};
struct K5bDispatcher {
    char head[24];
    Ptr32<Ptr32<int (Ptr32<struct K5bDispatcher>, Ptr32<struct K5bTypeTag>)>> handlers;
};
struct K5bResolver {
    char head[44];
    int level;
    int forced;
};
int w3d_k5b_resolver_classify_801d5a54(Ptr32<struct K5bDispatcher> dispatcher, Ptr32<struct K5bQuery> query)
{
    Ptr32<struct K5bResolver> self = dispatcher ? w3d::R((Ptr32<struct K5bResolver>)((Ptr32<char>)dispatcher - 4)) : 0;
    int result;
    self->level = 0;
    result = dispatcher->handlers[query->tag->slot](dispatcher, query->tag);
    if (result >= 0) {
        if (self->forced != 0)
            query->flags = (query->flags & ~6u) | 2;
        else
            query->flags = (query->flags & ~6u) | (self->level << 1);
    }
    return result;
}
// desc: w3d_k5b_resolver_classify_801d5a54: Appears to reset the level of the outer object (base at -4), dispatch on the query tag slot and, on success, store a 2-bit mode (forced or level) in the query flags.

}
