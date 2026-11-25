// External stream position and extent at offsets28 and32.
struct Stream {unsigned char unknown[28];unsigned position,extent;};
extern "C" unsigned g5c_stream_seek_80208e34(Stream* stream,unsigned offset,int origin,unsigned* previous) {
 if(previous)*previous=stream->position;
 unsigned extent;
 switch(origin) {
 case 0:extent=stream->extent;break;
 case 1:extent=stream->extent;offset+=stream->position;break;
 case 2:extent=stream->extent;offset=extent+offset;break;
 default:return 0x90000002;
 }
 if(offset<=extent){stream->position=offset;return 0;}
 return 0x90000003;
}
