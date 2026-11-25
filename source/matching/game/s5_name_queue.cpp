/* Queue of fixed 33-byte names, backed by byte-counted storage. */
extern "C" {
struct S5QueuedName { char text[33]; S5QueuedName(); void assign(const char *); };
struct S5NameRange { S5QueuedName *begin,*end; unsigned char *capacity; };
struct S5NameQueue { unsigned unknown; S5NameRange names; };
void w3d_digits_fill_zero(S5QueuedName *);
S5QueuedName *strncpy(S5QueuedName *,const char *,unsigned);
void *w3d_handle_storage_allocate(unsigned);
void w3d_handle_storage_release(void *);
void *memcpy(void *,const void *,unsigned,...);
void w3d_string_assign(void *,const char *);
inline S5QueuedName::S5QueuedName() { w3d_digits_fill_zero(this); }
inline void S5QueuedName::assign(const char *value) { strncpy(this,value,33); }
static inline const int &s5_name_max(const int &left,const int &right) { return left<right?right:left; }
static inline const unsigned &s5_name_min(const unsigned &left,const unsigned &right) { return left>right?right:left; }
static inline void s5_name_reserve(S5NameRange *range)
{
    unsigned used=(char*)range->end-(char*)range->begin;
    int minimum=used+1;
    int grown=used+(used>>1);
    unsigned bytes=s5_name_max(minimum,grown)*33;
    S5QueuedName *replacement=(S5QueuedName*)w3d_handle_storage_allocate(bytes);
    if (range->begin) {
        memcpy(replacement,range->begin,s5_name_min(bytes,used));
        w3d_handle_storage_release(range->begin);
    }
    range->begin=replacement;
    range->end=(S5QueuedName*)((char*)replacement+used);
    range->capacity=(unsigned char*)replacement+bytes;
}
static inline void s5_name_push(S5NameRange *range,const S5QueuedName &name)
{
    if ((unsigned char*)range->end==range->capacity) s5_name_reserve(range);
    *range->end=name;
    ++range->end;
}
int w3d_name_queue_append_800c467c(S5NameQueue *queue,const char *text)
{
    S5QueuedName name;
    name.assign(text);
    s5_name_push(&queue->names,name);
    return 0;
}
void *memmove(void *,const void *,unsigned);
static inline void s5_name_insert(S5NameRange *range,S5QueuedName *at,const S5QueuedName &name)
{
    if ((unsigned char*)range->end==range->capacity) {
        int index=at-range->begin;
        s5_name_reserve(range);
        at=range->begin+index;
    }
    if (at==range->end) {
        *at=name;
        ++range->end;
    } else {
        S5QueuedName copy=name;
        memmove(at+1,at,(char*)range->end-(char*)at);
        ++range->end;
        *at=copy;
    }
}
/* 0x800c47f8: reserve setup and begin-pointer scheduling differ after one attempt. */
#if 0
int w3d_name_queue_prepend_800c47f8(S5NameQueue *queue,const char *text)
{
    S5QueuedName name;
    name.assign(text);
    s5_name_insert(&queue->names,queue->names.begin,name);
    return 0;
}
#endif
/* 0x800c4a7c: memcpy byte-count expression remains one instruction short after five attempts. */
#if 0
int w3d_name_queue_pop_800c4a7c(S5NameQueue *queue,void *output)
{
    S5NameRange *range=&queue->names;
    if (range->begin==range->end) return 0x80004005;
    w3d_string_assign(output,range->begin->text);
    S5QueuedName *at=range->begin;
    S5QueuedName *next=at+1;
    if (next!=range->end) ((void (*)(void *,void *,unsigned,...))memcpy)(at,next,(char*)range->end-(char*)next);
    --range->end;
    return 0;
}

#endif
}
