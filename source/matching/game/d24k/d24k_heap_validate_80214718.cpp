// Heap block validation (Worms 3D GameCube PAL, 0x80214718).
//
// Unless the heap flags already hold bit 0 or the one-shot bit 0x4000, takes
// the validation lock bit 0x2000 (returns -1 if it is held). Finds the segment
// containing the address. In exact mode it checks the block header (segment
// match, in-use bit set, bit 4 clear) and reports failures through the owner's
// error callback with code 3; otherwise it walks the segment's blocks and
// returns the offset into the block, or -1 for a free block. Releases the lock
// bit before returning. The callback also receives its own table in r6, which
// the original leaves loaded at the call. Views are partial.
struct SegmentView {unsigned unknown;SegmentView* next;unsigned unknown8[2];unsigned char* end;};
struct HeapView {unsigned flags;unsigned unknown[2];SegmentView* segments;};
struct HeapOwnerView;
struct HeapCallbacks {unsigned unknown;void (*error)(HeapOwnerView*,int,unsigned char*,HeapCallbacks*);};
struct HeapOwnerView {unsigned unknown[11];HeapCallbacks* callbacks;HeapView* heap;};
struct BlockHeader {SegmentView* segment;unsigned flags;};
extern "C" int w3d_d24k_heap_validate_80214718(HeapOwnerView *owner,unsigned char *address) {
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
    if(!exact) goto scan;
    if(heap->flags&1) goto scan;
    {
        begin=address-8;
        BlockHeader *header=(BlockHeader*)begin;
        if(segment && header->segment==segment && (header->flags&1) && !(header->flags&4)) result=0;
        if(result!=0) {
            HeapCallbacks *callbacks=owner->callbacks;
            if(callbacks->error) callbacks->error(owner,3,address,callbacks);
        }
    }
    goto done;
    scan: if(segment) {
        if(begin<end) do {
            BlockHeader *header=(BlockHeader*)begin;
            unsigned char *payload=begin+8;
            unsigned size=header->flags&~7;
            if(address>=payload && address<payload+size) {
                result=address-payload;
                if((header->flags&5)!=1) result=-1;
                goto done;
            }
            begin+=size+8;
        } while(begin<end);
    }
    done:
    if(!exact) heap->flags&=~0x2000;
    return result;
}
