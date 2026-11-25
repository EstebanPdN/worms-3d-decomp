/* Inferred hash-table clear, original 0x8035c81c. Bucket vector is
 * begin/end at +4/+8; count at +24. Each 12-byte node starts with next.
 * Its value has trivial destruction; original null checks are retained.
 */
extern "C" void cx7c_deallocate_802134fc(void *);
struct Cx7cClearNode {Cx7cClearNode *next;unsigned int value[2];};
struct Cx7cClearBuckets {
    Cx7cClearNode **begin,**end,**capacity;
    unsigned int size() const {return end-begin;}
    Cx7cClearNode *&at(unsigned int index) {return *(Cx7cClearNode **)((char *)begin+(index<<2));}
};
struct Cx7cClearTable {unsigned int unknown_00;Cx7cClearBuckets buckets;unsigned int unknown_10[2],count;};
extern "C" void w3d_cx7c_hash_clear_8035c81c(Cx7cClearTable *self)
{
    for (unsigned int bucket=0;bucket<self->buckets.size();++bucket) {
        Cx7cClearNode *node=self->buckets.at(bucket);
        while (node) {
            Cx7cClearNode *next=node->next;
            if (node) cx7c_deallocate_802134fc(node);
            node=next;
        }
        self->buckets.at(bucket)=0;
    }
    self->count=0;
}
