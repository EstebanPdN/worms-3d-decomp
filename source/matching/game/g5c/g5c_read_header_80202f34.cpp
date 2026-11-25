// File header storage is external at stream+60, and the reader writes64 bytes.
struct Stream;
extern "C" void* memset(void*,int,unsigned);
extern "C" int fn_802025a8(Stream*,void*,unsigned);
extern "C" void fn_80347324(void*,const char*);
extern unsigned diagnostic_804b0640;
extern char bad_magic_803b2b54[],bad_version_803b2b60[];
inline unsigned swapWord(unsigned v) {
 return (v<<24)|((v&0xff00)<<8)|((v>>8)&0xff00)|(v>>24);
}
extern "C" int g5c_read_header_80202f34(Stream* stream) {
 unsigned* header=(unsigned*)((char*)stream+60);
 memset(header,0,64);
 int result=fn_802025a8(stream,header,64);
 if(result>=0) {
  const char* error;
  if(header[0]==0x4d4f494b) {
   unsigned a=header[2],b=header[3],c=header[4],d=header[5],e=header[6];
   unsigned f=header[7],g=header[8],h=header[9],i=header[10];
   unsigned version=swapWord(header[1]);
   header[10]=swapWord(i);
   header[2]=swapWord(a);header[3]=swapWord(b);header[4]=swapWord(c);
   header[5]=swapWord(d);header[6]=swapWord(e);header[7]=swapWord(f);
   header[8]=swapWord(g);header[9]=swapWord(h);header[1]=version;
   if(version<0x2000001)return 0;
   error=bad_version_803b2b60;
  }else error=bad_magic_803b2b54;
  fn_80347324(&diagnostic_804b0640,error);
  result=(int)0x80004005;
 }
 return result;
}
