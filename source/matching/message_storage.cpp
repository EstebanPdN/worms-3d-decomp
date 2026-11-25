/* Message storage prefix observed at801613f0; ownership/init remain pending. */
typedef unsigned int Word;
struct MessageStorage {
    unsigned char *data;
    Word cursor;
    Word capacity;
    Word boundary;
    bool before_boundary(Word position) const { return position < boundary; }
};
extern "C" void *w3d_message_allocate(MessageStorage *storage, Word requested)
{
    Word bytes = ((requested + 3u) & ~3u) + 4u;
    if (bytes > storage->capacity - storage->cursor) storage->cursor = 0;
    Word cursor = storage->cursor;
    Word *block = (Word *)(storage->data + cursor);
    /* The native routine reads boundary and performs a discarded unsigned
     * comparison. Its original checking/debug purpose is not established.
     */
    storage->before_boundary(cursor);
    storage->cursor = cursor + bytes;
    *block = bytes;
    return block + 1;
}
