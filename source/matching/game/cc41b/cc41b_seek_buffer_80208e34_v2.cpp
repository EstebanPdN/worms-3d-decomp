// Original 0x80208e34. Partial stream cursor view, unsigned wrapped offsets and bounds.
// Reports old position before validating origin or range, including failed seeks.
struct cc41b_SeekBuffer { unsigned char unknown[28]; unsigned position,limit; unsigned size(){return limit;} unsigned fromEnd(unsigned delta){return limit+delta;} };
extern "C" unsigned cc41b_seek_buffer_80208e34(cc41b_SeekBuffer *self,unsigned offset,int origin,unsigned *old) {
 if(old)*old=self->position;
 unsigned limit;
 switch(origin) {
 case 0:limit=self->limit;break;
 case 2:offset=self->fromEnd(offset);limit=self->size();break;
 case 1:offset=offset+self->position;limit=self->limit;break;
 default:return 0x90000002;
 }
 if(offset>limit)return 0x90000003;
 self->position=offset;return 0;
}
