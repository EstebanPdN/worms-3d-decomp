/* Inferred chunk cursor. PPC32: entries +0, current chunk +4,
 * relative offset +8, absolute offset +12. Entries are four bytes with
 * an unsigned 16-bit chunk length at +2. Coordinates use x+y*1024+z*32.
 */
struct Cx9cChunk {unsigned short tag,length;};
struct Cx9cChunkCursor {Cx9cChunk *chunks;int index,relative,absolute;};
extern "C" void w3d_cx9c_chunk_cursor_80343bc0(Cx9cChunkCursor *self,int x,int y,int z)
{
    int offset=x+y*1024+z*32;
    self->relative+=offset;
    self->absolute+=offset;
    if(self->relative<0){
        do {--self->index;self->relative+=self->chunks[self->index].length;}while(self->relative<0);
    }else{
        while(self->relative>=self->chunks[self->index].length){
            self->relative-=self->chunks[self->index].length;
            ++self->index;
        }
    }
}
