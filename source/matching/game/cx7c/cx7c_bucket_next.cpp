/* Inferred hash-table iterator increment at 0x8035c988.
 * Iterator: node +0, table +4. Node: next +0, key +4. Key: hash words
 * +0/+8, summed before unsigned modulo. Table bucket bounds: +4/+8.
 * This helper scans later buckets only; chained-node stepping is elsewhere.
 */
struct Cx7cBucketKey {unsigned int hash0,unknown_04,hash8;};
struct Cx7cBucketNode {Cx7cBucketNode *next; Cx7cBucketKey *key; unsigned int value;};
struct Cx7cBucketTable {unsigned int unknown_00; Cx7cBucketNode **begin,**end;};
struct Cx7cBucketIterator {Cx7cBucketNode *node; Cx7cBucketTable *table;};
extern "C" Cx7cBucketNode *w3d_cx7c_bucket_next_8035c988(Cx7cBucketIterator *it)
{
    Cx7cBucketNode *result=0;
    Cx7cBucketNode **begin=it->table->begin;
    unsigned int count=it->table->end-begin;
    unsigned int bucket=(it->node->key->hash0+it->node->key->hash8)%count;
    ++bucket;
    if (bucket<count) {
        Cx7cBucketNode **slot=(Cx7cBucketNode **)((bucket<<2)+(unsigned int)begin);
        do {
            result=*slot++;
            if (result) break;
        } while (++bucket<count);
    }
    return result;
}
