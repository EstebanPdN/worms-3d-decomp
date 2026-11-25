struct K5bTypeTag { char pad[6]; unsigned short slot; };
struct K5bQuery {
    char head[24];
    unsigned int flags;
    char pad[8];
    struct K5bTypeTag *tag;
};
struct K5bDispatcher {
    char head[24];
    int (**handlers)(struct K5bDispatcher *, struct K5bTypeTag *);
};
struct K5bResolver {
    char head[44];
    int level;
    int forced;
};
int w3d_k5b_resolver_classify_801d5a54(struct K5bDispatcher *dispatcher, struct K5bQuery *query)
{
    struct K5bResolver *self = dispatcher ? (struct K5bResolver *)((char *)dispatcher - 4) : 0;
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
