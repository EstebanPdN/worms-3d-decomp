/* Inferred stream layout; original instruction offsets and unsigned bounds. */
typedef unsigned int u32;
struct Cxc3Stream { char pad[28]; u32 position; u32 size; };
u32 cxc3_seek_80208e34(struct Cxc3Stream *self,u32 offset,int mode,u32 *previous)
{
    u32 size,position;
    if(previous) *previous=self->position;
    switch(mode) {
    case 0: size=self->size; position=offset; break;
    case 2: {u32 end=self->size; position=end+offset; size=end; break;}
    case 1: position=offset+self->position; size=self->size; break;
    default: return 0x90000002;
    }
    if(position>size) return 0x90000003;
    self->position=position; return 0;
}
