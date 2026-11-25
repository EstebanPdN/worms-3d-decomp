// Inferred console editing operation and observed four-byte string lifetime.
struct SharedString;
extern "C" void sol35e6a_default_803426b8(SharedString *);
extern "C" void sol35e6a_finish_8020c5c4(SharedString *);
extern "C" void sol35e6a_release_80341588(SharedString *);
struct SharedString {
 char *text;
 SharedString();
 ~SharedString() { sol35e6a_finish_8020c5c4(this); sol35e6a_release_80341588(this); }
};
extern "C" void sol35e6a_flag_8027a934(void *,unsigned);
extern "C" void sol35e6a_request_802cd220(SharedString *);
extern "C" void sol35e6a_clear_802cd128(SharedString *);
extern "C" void sol35e6a_append_802cbf2c(SharedString *,const char *,unsigned);
extern "C" void sol35e6a_sink_clear_802cd2e0(void *,unsigned);
extern "C" void sol35e6a_sink_write_802cbdf8(void *,const char *,unsigned);
extern const char *sol35e6a_lines_804012fc[];
#define FIELD(p,T,o) (*reinterpret_cast<T *>(static_cast<char *>(p)+(o)))
inline void release(void *p) {
 if (p) {
  typedef void (*Release)(void *);
  Release *table=FIELD(p,Release *,0);
  table[4](p);
 }
}
extern "C" void sol35e6a_console_edit_80271420_v2(void *self) {
 sol35e6a_flag_8027a934(self,1);
 SharedString text;
 sol35e6a_request_802cd220(&text);
 sol35e6a_clear_802cd128(&text);
 FIELD(self,unsigned,36)=0;
 const char **line=sol35e6a_lines_804012fc;
 while (*line) {
  sol35e6a_append_802cbf2c(&text,*line,7);
  ++line;
 }
 sol35e6a_sink_clear_802cd2e0(FIELD(self,void *,32),0);
 sol35e6a_sink_write_802cbdf8(FIELD(self,void *,32),text.text,9);
 release(FIELD(self,void *,88));
 FIELD(self,void *,88)=0;
 release(FIELD(self,void *,92));
 FIELD(self,void *,92)=0;
}
typedef char StringSize[sizeof(SharedString)==4?1:-1];
