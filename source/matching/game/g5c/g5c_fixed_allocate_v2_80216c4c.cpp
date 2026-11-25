// External heap, state, region and block views; none is constructed locally.
struct Heap;
typedef unsigned* (*AcquireRegion)(Heap*,unsigned,void*);
typedef void (*NotifyAllocation)(Heap*,unsigned*,unsigned*,unsigned);
extern AcquireRegion callback_80400768[];
extern NotifyAllocation callback_8040077c[];
extern "C" unsigned* g5c_fixed_allocate_80216c4c(Heap* heap,unsigned requested) {
    unsigned* pool=*(unsigned**)((char*)heap+48);
    if (!requested) return 0;
    unsigned flags=pool[0];
    unsigned direct=flags&1;
    if (!direct) {
        if ((flags&0x2000) || (pool[2] && requested!=pool[2])) return 0;
        pool[0]=flags|0x2000;
    }
    unsigned* result;
    if (!pool[2]) {
        unsigned* region=(unsigned*)pool[3];
        pool[2]=requested;
        requested=(requested+7)&~7U;
        for (;region;region=(unsigned*)region[1]) {
            result=(unsigned*)region[6];
            if (result) {
                region[6]=0;
                unsigned remaining=(result[1]&~7U)+8;
                while (remaining>=requested) {
                    result[1]=0x55555555;
                    result[0]=pool[4];
                    pool[4]=(unsigned)result;
                    result=(unsigned*)((char*)result+requested);
                    remaining-=requested;
                }
            }
        }
    }
    for (;;) {
        result=(unsigned*)pool[4];
        if (result) {pool[4]=result[0];break;}
        unsigned pageSize=pool[1];
        unsigned regionSize;
        if (pageSize&(pageSize-1)) regionSize=((pool[2]-1+pageSize)/pageSize)*pageSize;
        else regionSize=(pool[2]-1+pageSize)&~(pageSize-1);
        result=callback_80400768[0](heap,regionSize,0);
        if (!result) {
            if (pool[0]&0x1000) {pool[0]&=~0x1000U;continue;}
        } else {
            unsigned stride=(pool[2]+7)&~7U;
            unsigned* block=(unsigned*)((char*)result+stride);
            unsigned remaining=*(unsigned*)(pool[3]+16)-(unsigned)(block+2);
            while(remaining>=stride) {
                block[1]=0x55555555;
                block[0]=pool[4];
                pool[4]=(unsigned)block;
                block=(unsigned*)((char*)block+stride);
                remaining-=stride;
            }
        }
        break;
    }
    if (!direct && (pool[0]&2) && callback_8040077c[0] && result)
        callback_8040077c[0](heap,0,result,pool[2]);
    pool[0]&=~0x2000U;
    return result;
}
