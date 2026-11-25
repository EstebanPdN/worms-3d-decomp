#if 0 /* Excluded: constructor inlining and register allocation differ after two attempts. */
/* Observed input-binding record allocation and vector growth. */
extern "C" {
struct W3dS1Binding { unsigned int word[8]; };
struct W3dS1BindingVector { char *begin;W3dS1Binding **end;char *limit; };
struct W3dS1InputMap { char unknown[36];W3dS1BindingVector bindings; };
extern unsigned int w3d_heap_804ae280;
extern const char w3d_str_803788e0[],w3d_str_803788f4[];
W3dS1Binding *w3d_heap_allocate(void *,unsigned int);
void w3d_cached_message_name_init(void *,const char *);
char *w3d_handle_storage_allocate(unsigned int);
void w3d_handle_storage_release(void *);
void *memcpy(void *,const void *,unsigned int,...);
static inline const int &max_binding(const int &a,const int &b) { return a<b?b:a; }
static inline const unsigned int &min_binding(const unsigned int &a,const unsigned int &b) { return a>b?b:a; }
static inline void append_binding(W3dS1BindingVector *v,W3dS1Binding *const &item)
{
    int next,grown;
    unsigned int bytes,used;
    if((char *)v->end==v->limit) {
        used=(char *)v->end-v->begin;
        next=used+1;
        grown=used+(used>>1);
        bytes=max_binding(next,grown)*4;
        char *storage=w3d_handle_storage_allocate(bytes);
        if(v->begin) {
            memcpy(storage,v->begin,min_binding(bytes,used));
            w3d_handle_storage_release(v->begin);
        }
        v->begin=storage;
        v->end=(W3dS1Binding **)(storage+used);
        v->limit=storage+bytes;
    }
    *v->end=item;
    v->end++;
}
void w3d_fn_80058804(void *unused,W3dS1InputMap *map)
{
    W3dS1Binding *pressed=w3d_heap_allocate(&w3d_heap_804ae280,32);
    w3d_cached_message_name_init(&pressed->word[1],w3d_str_803788e0);
    pressed->word[5]=8;pressed->word[6]=1;pressed->word[3]=2;pressed->word[7]=0;pressed->word[4]=0;
    append_binding(&map->bindings,pressed);
    W3dS1Binding *released=w3d_heap_allocate(&w3d_heap_804ae280,32);
    w3d_cached_message_name_init(&released->word[1],w3d_str_803788f4);
    released->word[5]=8;released->word[3]=2;released->word[7]=0;released->word[4]=0;released->word[6]=0;
    append_binding(&map->bindings,released);
}
}
#endif
