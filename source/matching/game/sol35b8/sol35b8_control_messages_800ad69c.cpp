// Inferred native GC32 views and names, not recovered original class names.
// Three vectors occupy +4/+16/+28; a snapshot of the second is at +156.
// 8015a6b8 forwards r3/r4 into its +72 table/+24 virtual callback. Keep the
// actual input pointer across the copies; cc31a 8002d3e4 and cx8a 800d308c
// independently preserve this same boundary. The complete API/return type
// remains unknown; this unit ignores the result. Each string-message helper
// returns its input pointer in r3, which is passed directly to post-current.
// Native live compatible objects, arena allocation and callback effects are
// external obligations. No portable, runtime or whole-program claim.
namespace sol35b8_control_messages {
struct Vec3 {float x,y,z;};
struct Control {unsigned u0;Vec3 a,b,c;char u40[116];Vec3 saved;};
struct Cache {unsigned words[2];};
typedef char Vec3_size[(sizeof(Vec3)==12)?1:-1];
typedef char Control_size[(sizeof(Control)==168)?1:-1];
typedef char Cache_size[(sizeof(Cache)==8)?1:-1];
extern "C" {
void sol35b8_control_query_8015a6b8(Control*,const Control*);
void *sol35b8_control_allocate_801613f0(void*,unsigned);
unsigned sol35b8_control_id_8015f5a0(Cache*,int);
void *sol35b8_control_string_8010a8e0(void*,unsigned short,const char*);
int sol35b8_control_post_8016239c(void*);
extern void *sol35b8_control_arena_804b1754;
extern Cache sol35b8_control_cache_804ae3c8,sol35b8_control_cache_804ae3d0;
extern const char sol35b8_control_text_8038200c[],sol35b8_control_text_80382018[],sol35b8_control_text_80382028[],sol35b8_control_text_80382040[],sol35b8_control_text_80382050[],sol35b8_control_text_8038205c[],sol35b8_control_text_80382068[];
}
extern "C" void sol35b8_control_messages_800ad69c(Control*s,const Control*input) {
 s->a=input->a;s->b=input->b;s->c=input->c;s->saved=s->b;
 sol35b8_control_query_8015a6b8(s,input);
 {void*message=sol35b8_control_allocate_801613f0(sol35b8_control_arena_804b1754,12);
 sol35b8_control_post_8016239c(sol35b8_control_string_8010a8e0(message,sol35b8_control_id_8015f5a0(&sol35b8_control_cache_804ae3c8,1),sol35b8_control_text_8038200c));}
 {void*message=sol35b8_control_allocate_801613f0(sol35b8_control_arena_804b1754,12);
 sol35b8_control_post_8016239c(sol35b8_control_string_8010a8e0(message,sol35b8_control_id_8015f5a0(&sol35b8_control_cache_804ae3d0,1),sol35b8_control_text_80382018));}
 {void*message=sol35b8_control_allocate_801613f0(sol35b8_control_arena_804b1754,12);
 sol35b8_control_post_8016239c(sol35b8_control_string_8010a8e0(message,sol35b8_control_id_8015f5a0(&sol35b8_control_cache_804ae3d0,1),sol35b8_control_text_80382028));}
 {void*message=sol35b8_control_allocate_801613f0(sol35b8_control_arena_804b1754,12);
 sol35b8_control_post_8016239c(sol35b8_control_string_8010a8e0(message,sol35b8_control_id_8015f5a0(&sol35b8_control_cache_804ae3d0,1),sol35b8_control_text_80382040));}
 {void*message=sol35b8_control_allocate_801613f0(sol35b8_control_arena_804b1754,12);
 sol35b8_control_post_8016239c(sol35b8_control_string_8010a8e0(message,sol35b8_control_id_8015f5a0(&sol35b8_control_cache_804ae3d0,1),sol35b8_control_text_80382050));}
 {void*message=sol35b8_control_allocate_801613f0(sol35b8_control_arena_804b1754,12);
 sol35b8_control_post_8016239c(sol35b8_control_string_8010a8e0(message,sol35b8_control_id_8015f5a0(&sol35b8_control_cache_804ae3d0,1),sol35b8_control_text_8038205c));}
 {void*message=sol35b8_control_allocate_801613f0(sol35b8_control_arena_804b1754,12);
 sol35b8_control_post_8016239c(sol35b8_control_string_8010a8e0(message,sol35b8_control_id_8015f5a0(&sol35b8_control_cache_804ae3d0,1),sol35b8_control_text_80382068));}
}
}
