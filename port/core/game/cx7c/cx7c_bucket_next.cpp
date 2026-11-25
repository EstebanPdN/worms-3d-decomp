#include "w3d_ptr.h"
#line 1 "cx7c_bucket_next.cpp"
/* Inferred hash-table iterator increment at 0x8035c988.
 * Iterator: node +0, table +4. Node: next +0, key +4. Key: hash words
 * +0/+8, summed before unsigned modulo. Table bucket bounds: +4/+8.
 * This helper scans later buckets only; chained-node stepping is elsewhere.
 */
struct Cx7cBucketKey {unsigned int hash0,unknown_04,hash8;};
struct Cx7cBucketNode {Ptr32<Cx7cBucketNode> next; Ptr32<Cx7cBucketKey> key; unsigned int value;};
struct Cx7cBucketTable {unsigned int unknown_00; Ptr32<Ptr32<Cx7cBucketNode>> begin; Ptr32<Ptr32<Cx7cBucketNode>> end;};
struct Cx7cBucketIterator {Ptr32<Cx7cBucketNode> node; Ptr32<Cx7cBucketTable> table;};
extern "C" Ptr32<Cx7cBucketNode> w3d_cx7c_bucket_next_8035c988(Ptr32<Cx7cBucketIterator> it)
{
    Ptr32<Cx7cBucketNode> result=0;
    Ptr32<Ptr32<Cx7cBucketNode>> begin=it->table->begin;
    unsigned int count=it->table->end-begin;
    unsigned int bucket=(it->node->key->hash0+it->node->key->hash8)%count;
    ++bucket;
    if (bucket<count) {
        Ptr32<Ptr32<Cx7cBucketNode>> slot=(Ptr32<Ptr32<Cx7cBucketNode>>)w3d::G(((bucket<<2)+(unsigned int)w3d::H(begin)));
        do {
            result=*slot++;
            if (result) break;
        } while (++bucket<count);
    }
    return result;
}


