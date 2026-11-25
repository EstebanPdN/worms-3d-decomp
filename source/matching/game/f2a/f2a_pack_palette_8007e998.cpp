// Original entry 0x8007e998; palette and color-channel naming is inferred.
// Unused three-float object preserves observed frame reservation.
struct Header {unsigned unused;unsigned short kind;char p[18];unsigned count;unsigned short refs;char pad[2];unsigned char bytes[1];};
struct Array {Header *h;};struct Input{char p[48];Array a;};struct Output {char p[372];unsigned short*dest;};
extern "C" unsigned char *fn_801ef048(Array*,unsigned,int,int);
inline unsigned char *read(Array*a,unsigned count){Header*h=a->h;if(h->kind==1){++h->refs;return h->bytes;}return fn_801ef048(a,count,1,2);}
extern "C" {
int w3d_f2a_pack_palette_8007e998(Output *self,Input *in){struct Frame{float x,y,z;Frame(){}} reservation;unsigned char*src=read(&in->a,in->a.h->count);for(int i=0;i<256;++i){unsigned char *pixel=src+i;unsigned value=(pixel[2]&0xf0)|(((src[i]&0xf0)<<8)|((pixel[1]&0xf0)<<4));self->dest[i]=value;src+=2;}return 0;}}
