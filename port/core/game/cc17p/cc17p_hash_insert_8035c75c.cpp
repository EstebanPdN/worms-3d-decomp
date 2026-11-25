#include "w3d_ptr.h"
#line 1 "cc17p_hash_insert_8035c75c.cpp"
// Observed PPC32 key words, two-word payload, bucket vector, and count offset.
// Returns the payload address (the live r3 value in the original epilogue).
// Ownership and higher-level key semantics remain inferred.
// Reference pointer widths and endianness are separate from a native port layout.
struct Cc17pKey { unsigned int words[3]; };
struct Cc17pEntry { Ptr32<Cc17pKey> key; unsigned int value; };
struct Cc17pNode { Ptr32<Cc17pNode> next; Cc17pEntry entry; };
struct Cc17pHash {
    unsigned int header;
    Ptr32<Ptr32<Cc17pNode>> begin;
    Ptr32<Ptr32<Cc17pNode>> end;
    unsigned int unknown[3];
    unsigned int count;
};
extern "C" void rehash_8035c588(Ptr32<Cc17pHash>, unsigned int);
extern "C" Ptr32<void> allocate_80212fd4(unsigned int);
extern "C" Ptr32<void> fallback_803413d8(unsigned int);
extern "C" Ptr32<Cc17pEntry> w3d_cc17p_hash_insert_8035c75c(Ptr32<Cc17pHash> table, Ptr32<const Cc17pEntry> entry)
{
    rehash_8035c588(table, table->count + 1);
    unsigned int bucket = (entry->key->words[0] + entry->key->words[2]) % (table->end - table->begin);
    Ptr32<Cc17pNode> head = *(Ptr32<Ptr32<Cc17pNode>>)((Ptr32<char>)table->begin + (bucket << 2));
    Ptr32<Cc17pNode> node = (Ptr32<Cc17pNode>)allocate_80212fd4(sizeof(Cc17pNode));
    if (!node)
        node = (Ptr32<Cc17pNode>)fallback_803413d8(sizeof(Cc17pNode));
    node->next = 0;
    Ptr32<Cc17pEntry> destination = &node->entry;
    if (destination) {
        destination->key = entry->key;
        destination->value = entry->value;
    }
    node->next = head;
    *(Ptr32<Ptr32<Cc17pNode>>)((Ptr32<char>)table->begin + (bucket << 2)) = node;
    ++table->count;
    return destination;
}


