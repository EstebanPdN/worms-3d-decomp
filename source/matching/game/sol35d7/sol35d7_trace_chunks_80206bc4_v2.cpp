// Inferred native trace writer: at most 255 source bytes plus a local terminator.
namespace sol35d7_trace_chunks_v2 {
typedef unsigned int Size;
struct Chunk { char bytes[255]; };
struct Buffer { Chunk chunk; char zero; };
typedef char BufferSize[(sizeof(Buffer)==256)?1:-1];
extern "C" int lbl_804ab9a4;
extern "C" void fn_80217fc8(const char *);
// Original call clears CR1, consistent with this variadic native declaration.
extern "C" void *fn_802eee50(void *,const void *,Size,...);
}
static inline int write_chunks(const char *text,unsigned int count,unsigned int *written) {
 using namespace sol35d7_trace_chunks_v2;
 char out[256];
 if (lbl_804ab9a4) {
  if(written) *written=count;
  if(text[count-1]==0) fn_80217fc8(text);
  else if(count) {
   do {
    if(count>255) {
     __builtin_memcpy(out,text,255);
     out[255]=0;
     text+=255;
     count-=255;
    } else {
     fn_802eee50(out,text,count);
     out[count]=0;
     count=0;
    }
    fn_80217fc8(out);
   }while(count);
  }
 }
 return 0;
}

extern "C" int sol35d7_trace_chunks_80206bc4_v2(void *,const char *text,unsigned int count,unsigned int *written) { return write_chunks(text,count,written); }
