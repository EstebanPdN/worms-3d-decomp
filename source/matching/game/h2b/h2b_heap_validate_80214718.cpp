// Partial external heap views, never instantiated locally.
struct SegmentView {unsigned unknown;SegmentView* next;unsigned unknown8[2];unsigned char* end;};
struct HeapView {unsigned flags;unsigned unknown[2];SegmentView* segments;};
struct HeapOwnerView;
struct HeapCallbacks {unsigned unknown;void (*error)(HeapOwnerView*,int,unsigned char*);};
struct HeapOwnerView {unsigned unknown[11];HeapCallbacks* callbacks;HeapView* heap;};
struct BlockHeader {SegmentView* segment;unsigned flags;};
extern "C" int h2b_heap_validate_80214718(HeapOwnerView *owner,unsigned char *address) {
    HeapView *heap=owner->heap;
    unsigned flags=heap->flags;
    unsigned exact=flags&1;
    if(!exact) {
        exact=flags&0x4000;
        heap->flags=flags&~0x4000;
        if(!exact) {
            if(flags&0x2000) return -1;
            heap->flags|=0x2000;
        }
    }
    int result=-1;
    SegmentView *segment=heap->segments;
    unsigned char *begin,*end;
    for(;segment;segment=segment->next) {
        begin=(unsigned char*)segment+32;
        end=segment->end-8;
        if(address>begin && address<end) break;
    }
    if(exact && !(heap->flags&1)) {
        BlockHeader *header=(BlockHeader*)(address-8);
        if(segment && header->segment==segment && (header->flags&1) && !(header->flags&4)) result=0;
        if(result!=0) {
            HeapCallbacks *callbacks=owner->callbacks;
            if(callbacks->error) callbacks->error(owner,3,address);
        }
    } else if(segment) {
        while(begin<end) {
            BlockHeader *header=(BlockHeader*)begin;
            unsigned char *payload=begin+8;
            unsigned size=header->flags&~7;
            if(address>=payload && address<payload+size) {
                result=address-payload;
                if((header->flags&5)!=1) result=-1;
                break;
            }
            begin+=size+8;
        }
    }
    if(!exact) heap->flags&=~0x2000;
    return result;
}
