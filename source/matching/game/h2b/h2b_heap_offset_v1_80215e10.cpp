// External heap/segment/block views. No local objects of these types.
struct SegmentView {unsigned unknown; SegmentView *next; unsigned unknown8[2]; unsigned char *end;};
struct HeapView {unsigned flags; unsigned unknown[2]; SegmentView *segments;};
struct HeapOwnerView {unsigned unknown[12]; HeapView *heap;};
struct BlockView {unsigned previous,size_flags; unsigned unknown8,payload_bytes;};
extern "C" int h2b_heap_offset_v1_80215e10(HeapOwnerView *owner,unsigned char *address) {
    HeapView *heap=owner->heap;
    int result=-1;
    unsigned flags=heap->flags;
    unsigned exact=flags&0x4000;
    heap->flags=flags&~0x4000;
    if((!exact && (flags&0x2000)) || !address) return -1;
    done:
    if(!exact) heap->flags|=0x2000;
    SegmentView *segment=heap->segments;
    unsigned char *begin,*end;
    for(;segment;segment=segment->next) {
        begin=(unsigned char*)segment+32;
        end=segment->end-8;
        if(address>begin && address<end) break;
    }
    if(segment) {
        if(exact) {
            if(*(SegmentView**)(address-8)==segment) {
                result=-2;
                if((*(unsigned*)(address-20)&5)==1) result=0;
            }
            test_block: if(begin<end) goto next_block;
        } else {
            goto test_block;
            next_block: {
                BlockView *block=(BlockView*)begin;
                unsigned char *data=begin+8;
                unsigned size=block->size_flags;
                if(address>=data && address<data+size) {
                    if((size&5)==1) {
                        unsigned char *payload=begin+24;
                        if(address>=payload && address<payload+*(unsigned*)(payload-12))
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
