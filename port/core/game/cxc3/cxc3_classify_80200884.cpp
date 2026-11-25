#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "cxc3_classify_80200884.c"
/* Inferred record classification; fields describe observed GC32 offsets. */
typedef unsigned int u32;
typedef struct Cxc3Record {
    char pad[6];
    unsigned short offset;
    Ptr32<void> type;
} Cxc3Record;
typedef struct Cxc3Info {
    char pad[17];
    unsigned char count;
    char gap[10];
    Ptr32<Cxc3Record> records;
} Cxc3Info;
typedef struct Cxc3Object {
    char pad[12];
    Ptr32<Cxc3Info> info;
    char gap[4];
    u32 flags;
} Cxc3Object;
extern u32 fn_80200050(Ptr32<void>);

void cxc3_classify_80200884(Ptr32<Cxc3Object> self)
{
    if (!(self->flags & 4)) {
        Ptr32<Cxc3Record> record = self->info->records;
        int sameType = 1;
        int consecutive = 1;
        u32 count = self->info->count;
        Ptr32<void> type = record->type;
        do {
            if (!type) break;
            {
                u32 bit, flags;
                u32 i = 1;
                u32 offset = record->offset + fn_80200050(type);
                for (; i < count; i++) {
                    Ptr32<Cxc3Record> current = (Ptr32<Cxc3Record>)
                        ((Ptr32<char>)self->info->records + i * 12);
                    if (current->type != type) sameType = 0;
                    if (offset != current->offset) consecutive = 0;
                    offset += fn_80200050(type);
                }
                bit = 0;
                if (consecutive) bit = 1;
                flags = self->flags;
                if (sameType) flags |= 6;
                else flags |= 4;
                self->flags = flags | bit;
            }
        } while (0);
    }
}

}
