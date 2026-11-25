// Inferred GC32 tagged-value layout, supported by the native constructor.
namespace sol35d9_open_stream {
struct Interface;
typedef void (*VirtualCall)(Interface *);
struct Interface { VirtualCall *vtable; };
struct Tagged {
 VirtualCall *vtable;
 unsigned short references, tag;
 unsigned tag_value;
 unsigned pair_first,pair_second;
 Interface *held;
};
extern "C" Tagged *fn_80207fec(Tagged *);
extern "C" unsigned fn_80207f8c(Tagged *);
extern "C" int fn_802080a0(Tagged *,void *,int);
extern "C" void fn_8020803c(Tagged *,int);
extern "C" Interface *fn_8020fcb4(const void *);
extern "C" unsigned lbl_80365808;
extern "C" int fn_801f8754(Interface *,Interface *);
struct ScopedTagged : Tagged {
 ScopedTagged() {fn_80207fec(this); fn_80207f8c(this);}
 ~ScopedTagged() {fn_8020803c(this,2);}
};
typedef char TaggedSize[(sizeof(Tagged)==24)?1:-1];
}
extern "C" int sol35d9_open_stream_801f7dc4(void *unused,void *input,
 sol35d9_open_stream::Interface **output) {
 using namespace sol35d9_open_stream;
 *output=0;
 ScopedTagged value;
 int result=fn_802080a0(&value,input,1);
 if(result>=0) {
  Interface *stream=fn_8020fcb4(&lbl_80365808);
  stream->vtable[3](stream);
  result=fn_801f8754(stream,value.held);
  if(result>=0) {*output=stream;return 0;}
  stream->vtable[4](stream);
 }
 return result;
}
