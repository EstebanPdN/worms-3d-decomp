#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s3_message_callbacks.c"
/* Cached-message comparisons and intrusive callback registration. */
typedef struct Cache {union {unsigned int flags;struct { short pad; short id; } parts;} state;Ptr32<const char> name;} Cache;
typedef struct TextCache {Cache base;Ptr32<char> text;} TextCache;
typedef struct Member {int encoded;unsigned int target;} Member;
typedef struct Callback Callback;
struct Callback {Ptr32<Callback> next; Ptr32<Callback> previous;Ptr32<void> owner; Ptr32<void> object; Ptr32<void> value;Member member;};
typedef struct CallbackOwner {unsigned char pad00[24];Ptr32<Callback> head;} CallbackOwner;
extern void w3d_cached_message_base_init(Ptr32<Cache>);
extern short w3d_cached_message_id(Ptr32<Cache>,int);
extern void w3d_string_assign(Ptr32<Ptr32<char>>,Ptr32<const char>),w3d_string_release_header(Ptr32<void>);
extern Ptr32<void> w3d_string_default(Ptr32<Ptr32<char>>);
extern Ptr32<char> w3d_empty_804b06a0[];
extern const Member w3d_member_803a45c4[];
Ptr32<Cache> w3d_message_cache_construct(Ptr32<Cache> cache)
{
 cache->state.parts.id=-1;cache->name=0;cache->state.flags&=0xffff7fff;
 w3d_cached_message_base_init(cache);return cache;
}
int w3d_message_cache_equals(Ptr32<Cache> cache,int id){return id==w3d_cached_message_id(cache,1);}
int w3d_message_id_equals_cache(int id,Ptr32<Cache> cache){return id==w3d_cached_message_id(cache,1);}
void w3d_text_cache_assign(Ptr32<TextCache> cache,Ptr32<const char> text);
Ptr32<TextCache> w3d_text_cache_construct(Ptr32<TextCache> cache,Ptr32<const char> text)
{
 w3d_message_cache_construct(&cache->base);w3d_string_default(&cache->text);w3d_text_cache_assign(cache,text);return cache;
}
void w3d_text_cache_assign(Ptr32<TextCache> cache,Ptr32<const char> text)
{
 if(text==0){
 Ptr32<char> old;unsigned short refs;
 Ptr32<char> empty;Ptr32<unsigned short> header;
 cache->base.name=text;empty=*w3d_empty_804b06a0;(*(Ptr32<unsigned short>)(empty-6))++;
 old=cache->text;header=(Ptr32<unsigned short>)(old-6);
 if(--*header==0)w3d_string_release_header(header);
 cache->text=*w3d_empty_804b06a0;
 }else {w3d_string_assign(&cache->text,text);cache->base.name=cache->text;}
 cache->base.state.flags&=0xffff7fff;
}
void w3d_callback_link(Ptr32<Callback> callback,Ptr32<Ptr32<Callback>> head,Ptr32<void> object,Ptr32<void> owner,Ptr32<void> value,Ptr32<const Member> member)
{
 Member copy=*member;
 callback->next=*head;if(*head)(*head)->previous=callback;
 callback->object=object;callback->owner=owner;callback->value=value;
 {Ptr32<Callback> first=*head;callback->previous=0;callback->next=first;}*head=callback;callback->member=copy;
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

int w3d_callback_dispatch(Ptr32<CallbackOwner> owner,Ptr32<void> message)
{
 Ptr32<Callback> callback=owner->head;int result=0;
 while(callback){
 Ptr32<int (Ptr32<void>, Ptr32<void>)> method;short index=(short)callback->member.encoded;Ptr32<void> object;
 if(index>=0){
 Ptr32<void> base=callback->object;
 unsigned int table=*(Ptr32<unsigned int>)((Ptr32<char>)base+(short)(callback->member.target>>16));
 method=*(Ptr32<Ptr32<int (Ptr32<void>, Ptr32<void>)>>)w3d::G((table+index*4-4));object=base;
 }else {method=(Ptr32<int (Ptr32<void>, Ptr32<void>)>)w3d::G(callback->member.target);object=callback->object;}
 result=method((Ptr32<char>)object+(short)(callback->member.encoded>>16),message);
 if(result<0)break;
 callback=callback->next;
 }
 return result;
}

}
