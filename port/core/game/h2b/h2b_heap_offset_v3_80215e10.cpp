#include "w3d_ptr.h"
#line 1 "h2b_heap_offset_v3_80215e10.cpp"
// External heap/segment/block views. No local objects of these types.
struct SegmentView {unsigned unknown; Ptr32<SegmentView> next; unsigned unknown8[2]; Ptr32<unsigned char> end;};
struct HeapView {unsigned flags; unsigned unknown[2]; Ptr32<SegmentView> segments;};
struct HeapOwnerView {unsigned unknown[12]; Ptr32<HeapView> heap;};
struct BlockView {unsigned previous,size_flags; unsigned unknown8,payload_bytes;};
extern "C" int h2b_heap_offset_v3_80215e10(Ptr32<HeapOwnerView> owner,Ptr32<unsigned char> address) {
    Ptr32<HeapView> heap=owner->heap;
    int result=-1;
    unsigned flags=heap->flags;
    unsigned exact=flags&0x4000;
    heap->flags=flags&~0x4000;
    if((!exact && (flags&0x2000)) || !address) return -1;
    if(!exact) heap->flags|=0x2000;
    Ptr32<SegmentView> segment=heap->segments;
    Ptr32<unsigned char> begin; Ptr32<unsigned char> end;
    for(;segment;segment=segment->next) {
        begin=(Ptr32<unsigned char>)segment+32;
        end=segment->end-8;
        if(address>begin && address<end) break;
    }
    if(segment) {
        if(exact) {
            if(*(Ptr32<Ptr32<SegmentView>>)(address-8)==segment) {
                result=-2;
                if((*(Ptr32<unsigned int>)(address-20)&5)==1) result=0;
            }
        } else {
            goto test_block;
            next_block: {
                Ptr32<BlockView> block=(Ptr32<BlockView>)begin;
                Ptr32<unsigned char> payload=begin+8;
                unsigned size=block->size_flags;
                if(address>=payload && address<payload+size) {
                    if((size&5)==1) {
                        payload=begin+24;
                        if(address>=payload && address<payload+*(Ptr32<unsigned int>)(payload-12))
                            result=address-payload;
                    }
                    goto done;
                }
                begin+=(size&~7)+8;
            }
            test_block: if(begin<end) goto next_block;
        }
    }
    done:
    if(!exact) heap->flags&=~0x2000;
    return result;
}


