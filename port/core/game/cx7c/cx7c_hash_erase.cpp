#include "w3d_ptr.h"
#line 1 "cx7c_hash_erase.cpp"
/* Inferred hash-table erase-by-iterator, original 0x8035c8c8.
 * Table begin/end at +4/+8, count +24. Node next +0, key +4.
 * Key hash is words +0/+8 summed modulo bucket count. Removal preserves
 * other chain links and frees exactly the selected node when found.
 */
extern "C" void cx7c_deallocate_802134fc(Ptr32<void>);
struct Cx7cEraseKey {unsigned int hash0,unknown_04,hash8;};
struct Cx7cEraseNode {Ptr32<Cx7cEraseNode> next;Ptr32<Cx7cEraseKey> key;unsigned int value;};
struct Cx7cEraseTable {
    unsigned int unknown_00;Ptr32<Ptr32<Cx7cEraseNode>> begin; Ptr32<Ptr32<Cx7cEraseNode>> end; Ptr32<Ptr32<Cx7cEraseNode>> capacity;
    unsigned int unknown_10[2],count;
    Ptr32<Cx7cEraseNode> & at(unsigned int bucket) {return *(Ptr32<Ptr32<Cx7cEraseNode>>)((Ptr32<char>)begin+(bucket<<2));}
};
extern "C" void w3d_cx7c_hash_erase_8035c8c8(Ptr32<Cx7cEraseTable> self,Ptr32<Cx7cEraseNode> const &iterator)
{
    Ptr32<Cx7cEraseNode> target=iterator;
    if (target) {
        unsigned int bucket=(target->key->hash0+target->key->hash8)%(unsigned int)(self->end-self->begin);
        Ptr32<Cx7cEraseNode> head=self->at(bucket);
        if (head==target) {
            self->at(bucket)=head->next;
            if (target) cx7c_deallocate_802134fc(head);
            --self->count;
        } else {
            Ptr32<Cx7cEraseNode> next=head->next;
            while (next) {
                if (next==target) {
                    head->next=next->next;
                    cx7c_deallocate_802134fc(next);
                    --self->count;
                    break;
                }
                head=next;
                next=head->next;
            }
        }
    }
}


