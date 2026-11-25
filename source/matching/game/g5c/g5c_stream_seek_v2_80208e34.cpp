// External stream position and extent at offsets28 and32.
struct Stream {unsigned char unknown[28];unsigned position,extent;};
extern "C" unsigned g5c_stream_seek_80208e34(Stream* stream,unsigned offset,int origin,unsigned* previous) {
 if(previous)*previous=stream->position;
 unsigned extent;
 switch(origin) {
 case 0:extent=stream->extent;break;
 case 2:offset=stream->extent+offset;extent=stream->extent;break;
 case 1:offset+=stream->position;extent=stream->extent;break;
 default:return 0x90000002;
 }
 if(offset>extent)return 0x90000003;
 stream->position=offset;return 0;
}
