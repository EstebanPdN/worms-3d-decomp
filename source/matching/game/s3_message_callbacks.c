/* Cached-message comparisons and intrusive callback registration. */
typedef struct Cache {union {unsigned int flags;struct {short id,pad;} parts;} state;const char *name;} Cache;
typedef struct TextCache {Cache base;char *text;} TextCache;
typedef struct Member {int encoded;unsigned int target;} Member;
typedef struct Callback Callback;
struct Callback {Callback *next,*previous;void *owner,*object,*value;Member member;};
typedef struct CallbackOwner {unsigned char pad00[24];Callback *head;} CallbackOwner;
extern void w3d_cached_message_base_init(Cache *);
extern short w3d_cached_message_id(Cache *,int);
extern void w3d_string_assign(char **,const char *),w3d_string_release_header(void *);
extern void * w3d_string_default(char **);
extern char *w3d_empty_804b06a0[];
extern const Member w3d_member_803a45c4[];
Cache *w3d_message_cache_construct(Cache *cache)
{
 cache->state.parts.id=-1;cache->name=0;cache->state.flags&=0xffff7fff;
 w3d_cached_message_base_init(cache);return cache;
}
int w3d_message_cache_equals(Cache *cache,int id){return id==w3d_cached_message_id(cache,1);}
int w3d_message_id_equals_cache(int id,Cache *cache){return id==w3d_cached_message_id(cache,1);}
void w3d_text_cache_assign(TextCache *cache,const char *text);
TextCache *w3d_text_cache_construct(TextCache *cache,const char *text)
{
 w3d_message_cache_construct(&cache->base);w3d_string_default(&cache->text);w3d_text_cache_assign(cache,text);return cache;
}
void w3d_text_cache_assign(TextCache *cache,const char *text)
{
 if(text==0){
 char *old;unsigned short refs;
 char *empty;unsigned short *header;
 cache->base.name=text;empty=*w3d_empty_804b06a0;(*(unsigned short*)(empty-6))++;
 old=cache->text;header=(unsigned short*)(old-6);
 if(--*header==0)w3d_string_release_header(header);
 cache->text=*w3d_empty_804b06a0;
 }else {w3d_string_assign(&cache->text,text);cache->base.name=cache->text;}
 cache->base.state.flags&=0xffff7fff;
}
void w3d_callback_link(Callback *callback,Callback **head,void *object,void *owner,void *value,const Member *member)
{
 Member copy=*member;
 callback->next=*head;if(*head)(*head)->previous=callback;
 callback->object=object;callback->owner=owner;callback->value=value;
 {Callback *first=*head;callback->previous=0;callback->next=first;}*head=callback;callback->member=copy;
}
#if 0 /* Member-descriptor stack copy and argument register allocation differ after four attempts. */
int w3d_callback_register(CallbackOwner *owner,void *object,Callback *callback,void *value,const Member *member)
{
 unsigned int copy[2];unsigned int target=member->target;int encoded=member->encoded;
 if((short)encoded){copy[0]=encoded;copy[1]=target;w3d_callback_link(callback,&owner->head,object,owner,value,(Member *)copy);}
 else {copy[0]=w3d_member_803a45c4->encoded;copy[1]=w3d_member_803a45c4->target;w3d_callback_link(callback,&owner->head,object,owner,value,(Member *)copy);}
 return 0;
}
#endif

int w3d_callback_dispatch(CallbackOwner *owner,void *message)
{
 Callback *callback=owner->head;int result=0;
 while(callback){
 int (*method)(void *,void *);short index=((short*)&callback->member)[1];void *object;
 if(index>=0){
 void *base=callback->object;
 unsigned int table=*(unsigned int*)((char*)base+((short*)&callback->member)[2]);
 method=*(int (**)(void *,void *))(table+index*4-4);object=base;
 }else {method=(int (*)(void *,void *))callback->member.target;object=callback->object;}
 result=method((char*)object+((short*)&callback->member)[0],message);
 if(result<0)break;
 callback=callback->next;
 }
 return result;
}
