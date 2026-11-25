// External heap/segment/block views. No local objects of these types.
struct SegmentView {unsigned unknown; SegmentView *next; unsigned unknown8[2]; unsigned char *end;};
struct HeapView {unsigned flags; unsigned unknown[2]; SegmentView *segments;};
struct HeapOwnerView {unsigned unknown[12]; HeapView *heap;};
struct BlockView {unsigned previous,size_flags; unsigned unknown8,payload_bytes;};
extern "C" int h2b_heap_offset_80215e10(HeapOwnerView *owner,unsigned char *address) {
    HeapView *heap=owner->heap;
    int result=-1;
    unsigned flags=heap->flags;
    bool scan=(flags&0x4000)==0;
    heap->flags=flags&~0x4000;
    if((scan && (flags&0x2000)) || !address) return -1;
    if(scan) heap->flags|=0x2000;
    SegmentView *segment=heap->segments;
    unsigned char *begin,*end;
    for(;segment;segment=segment->next) {
        begin=(unsigned char*)segment+32;
        end=segment->end-8;
        if(address>begin && address<end) break;
    }
    if(segment) {
        if(!scan) {
            if(*(SegmentView**)(address-8)==segment) {
                result=-2;
                if((*(unsigned*)(address-20)&5)==1) result=0;
            }
        } else {
            while(begin<end) {
                BlockView *block=(BlockView*)begin;
                unsigned char *data=begin+8;
                unsigned size=block->size_flags;
                if(address>=data && address<data+size) {
                    if((size&5)==1) {
                        unsigned char *payload=begin+24;
                        if(address>=payload && address<payload+block->payload_bytes)
                            result=address-payload;
                    }
                    break;
                }
                begin+=(size&~7)+8;
            }
        }
    }
    if(scan) heap->flags&=~0x2000;
    return result;
}
