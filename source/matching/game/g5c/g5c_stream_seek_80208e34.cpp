// External stream position and extent at offsets28 and32.
struct Stream;
extern "C" unsigned g5c_stream_seek_80208e34(Stream* stream,unsigned offset,int origin,unsigned* previous) {
 unsigned* position=(unsigned*)((char*)stream+28);
 if(previous)*previous=position[0];
 unsigned extent;
 if(origin==1){extent=position[1];offset+=position[0];}
 else if(origin<2){if(origin!=0)return 0x90000002;extent=position[1];}
 else {if(origin!=2)return 0x90000002;extent=position[1];offset=extent+offset;}
 if(offset<=extent){position[0]=offset;return 0;}
 return 0x90000003;
}
