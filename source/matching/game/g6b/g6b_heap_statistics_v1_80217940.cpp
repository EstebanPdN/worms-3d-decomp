// External runtime heap metadata. None of these views is locally constructed.
typedef unsigned int Word;
struct Segment;
struct Block { Segment *segment; Word size; };
struct Segment {
    void *owner;
    Segment *next;
    char *allocation;
    Word reservedBytes;
    char *end;
    Word available;
    Block *freeBlock;
};
struct FreeLink { FreeLink *next; };
struct HeapState {
    Word flags, alignment, fixedSize;
    Segment *segments;
    FreeLink *freeList;
};
struct HeapOwner { char unknown00[48]; HeapState *state; };
struct Statistics {
    int allocatedCount, freeCount;
    Word allocatedBytes, freeBytes, largestAllocated, largestFree;
    int segmentCount;
    Word segmentBytes;
};
typedef void (*Visitor)(HeapOwner *, void *, Word, int);
extern "C" int g6b_heap_statistics_80217940(HeapOwner *owner, Statistics *out, Visitor visit) {
    HeapState *state = owner->state;
    if (!out) return -1;
    Word flags = state->flags;
    if (flags & 1) goto guarded;
    if (flags & 0x2000) return -1;
    state->flags = flags | 0x2000;
guarded:
    out->freeCount = 0;
    out->allocatedCount = 0;
    out->largestFree = 0;
    out->largestAllocated = 0;
    out->freeBytes = 0;
    out->allocatedBytes = 0;
    out->segmentCount = 0;
    out->segmentBytes = 0;
    Word extent;
    // The original defines extent only in applicable fixed/segment modes.
    if (state->flags & 0x100) goto segments;
    if (state->flags & 0x80) {
        extent = state->fixedSize;
        if (extent) {
            FreeLink *link = state->freeList;
            extent = (extent + 7) & ~7U;
            while (link) {
                if (visit) visit(owner,link,extent,1);
                ++out->freeCount;
                link = link->next;
            }
        }
    }
segments:
    for (Segment *segment = state->segments; segment; segment=segment->next) {
        char *cursor = (char *)segment + 32;
        ++out->segmentCount;
        out->segmentBytes += segment->reservedBytes;
        char *end = segment->end - 8;
        if (state->flags & 0x640) {
            while (cursor < end) {
                Word markedSize = ((Block *)cursor)->size;
                extent = markedSize & ~7U;
                if ((markedSize & 5) != 1) {
                    if (extent > out->largestFree) out->largestFree = extent;
                    out->freeBytes += extent;
                    ++out->freeCount;
                    if (visit) visit(owner,cursor,extent,1);
                } else {
                    char *payload = cursor + 8;
                    if (state->flags & 0x200) {
                        extent = *(Word *)(cursor+12);
                        payload = cursor + 24;
                    } else if (state->flags & 0x400) extent = *(Word *)(extent+cursor+4);
                    if (extent > out->largestAllocated) out->largestAllocated = extent;
                    if (visit) visit(owner,payload,extent,0);
                    out->allocatedBytes += extent;
                    ++out->allocatedCount;
                }
                cursor += (((Block *)cursor)->size & ~7U) + 8;
            }
        } else if (state->flags & 0x100) {
            extent = segment->freeBlock ? segment->freeBlock->size+8 : 0;
            if (extent) { out->freeBytes += extent; ++out->freeCount; }
            extent = (end-cursor)-extent;
            if (extent) { out->allocatedBytes += extent; ++out->allocatedCount; }
        } else if ((state->flags & 0x80) && extent) {
            out->allocatedCount += (Word)(end-cursor)/extent;
        }
    }
    if ((state->flags & 0x80) && extent) {
        out->allocatedCount -= out->freeCount;
        if (out->allocatedCount > 0) {
            Word fixedSize = state->fixedSize;
            out->largestAllocated = fixedSize;
            out->allocatedBytes = fixedSize * out->allocatedCount;
        }
        if (out->freeCount > 0) {
            Word fixedSize = state->fixedSize;
            out->largestFree = fixedSize;
            out->freeBytes = fixedSize * out->freeCount;
        }
    }
    state->flags &= ~0x2000;
    return 0;
}
