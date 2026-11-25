// Original 0x80189574. Observed shared-array header fields and lock counter width.
// Partial resource/owner views; no full object sizes or data ownership are inferred.
struct cc41b_ArrayHeader { unsigned unknown0; unsigned short owners; unsigned char unknown6[18]; unsigned count; unsigned short locks; unsigned short unknown30; unsigned char data[1]; };
extern "C" void *cc41b_arrayLock_801ef048(cc41b_ArrayHeader **,unsigned,unsigned,unsigned);
struct cc41b_ChannelArray { cc41b_ArrayHeader *header;
 void *lock(unsigned count,unsigned size){cc41b_ArrayHeader *p=header;if(p->owners==1){++p->locks;return p->data;}return cc41b_arrayLock_801ef048(&header,count,size,2);}
 void *resize(unsigned count,unsigned size){cc41b_ArrayHeader *p=header;if(p->owners==1 && count==p->count){++p->locks;return p->data;}return cc41b_arrayLock_801ef048(&header,count,size,0);}
 unsigned count(){return header->count;}
};
struct cc41b_ChannelResource { unsigned char unknown[88]; cc41b_ChannelArray channel; unsigned unknown92; cc41b_ChannelArray fallback; };
struct cc41b_ChannelRoot { unsigned char unknown[48]; cc41b_ChannelResource *resource; };
struct cc41b_ChannelInstance { unsigned char unknown[168]; cc41b_ChannelRoot *root; };
extern "C" void *cc41b_lock_channel_80189574(cc41b_ChannelInstance *self) {
 cc41b_ChannelResource *resource=self->root->resource;
 unsigned count=resource->channel.count();
 void *data=resource->channel.lock(count,4);
 if(count==0){unsigned fallback=resource->fallback.count();if(fallback==0)return 0;data=resource->channel.resize(fallback,4);}
 return data;
}
