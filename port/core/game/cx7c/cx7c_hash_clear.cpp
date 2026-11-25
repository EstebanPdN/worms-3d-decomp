#include "w3d_ptr.h"
#line 1 "cx7c_hash_clear.cpp"
/* Inferred hash-table clear, original 0x8035c81c. Bucket vector is
 * begin/end at +4/+8; count at +24. Each 12-byte node starts with next.
 * Its value has trivial destruction; original null checks are retained.
 */
extern "C" void cx7c_deallocate_802134fc(Ptr32<void>);
struct Cx7cClearNode {Ptr32<Cx7cClearNode> next;unsigned int value[2];};
struct Cx7cClearBuckets {
    Ptr32<Ptr32<Cx7cClearNode>> begin; Ptr32<Ptr32<Cx7cClearNode>> end; Ptr32<Ptr32<Cx7cClearNode>> capacity;
    unsigned int size() const {return end-begin;}
    Ptr32<Cx7cClearNode> & at(unsigned int index) {return *(Ptr32<Ptr32<Cx7cClearNode>>)((Ptr32<char>)begin+(index<<2));}
};
struct Cx7cClearTable {unsigned int unknown_00;Cx7cClearBuckets buckets;unsigned int unknown_10[2],count;};
extern "C" void w3d_cx7c_hash_clear_8035c81c(Ptr32<Cx7cClearTable> self)
{
    for (unsigned int bucket=0;bucket<self->buckets.size();++bucket) {
        Ptr32<Cx7cClearNode> node=self->buckets.at(bucket);
        while (node) {
            Ptr32<Cx7cClearNode> next=node->next;
            if (node) cx7c_deallocate_802134fc(node);
            node=next;
        }
        self->buckets.at(bucket)=0;
    }
    self->count=0;
}


