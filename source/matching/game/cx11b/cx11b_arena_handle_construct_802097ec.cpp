// Observed PPC32 arena record stride fifty-six, minimum +36, flags byte +48; handle arena +0/flags +4.
struct Arena {unsigned char opaque[36];int minimum;unsigned char pad[8];unsigned char flags;unsigned char tail[7];};struct Handle {Arena *arena;unsigned char flags;};extern unsigned int count_804b18f8;extern Arena arenas_804a91f8[];
extern "C" void init_80209160(Arena *,const char *);extern "C" void flags_802097e4(Arena *,int);extern "C" void *registry_80209a70();extern "C" void register_80209bc8(void *,Handle *);
extern "C" Handle *w3d_cx11b_arena_handle_construct_802097ec(Handle *self,const char *name,int minimum,int flags){Arena *arena=&arenas_804a91f8[count_804b18f8];count_804b18f8=count_804b18f8+1;self->arena=arena;init_80209160(self->arena,name);self->flags=255;if(minimum>self->arena->minimum)self->arena->minimum=minimum;if(flags)flags_802097e4(self->arena,flags);register_80209bc8(registry_80209a70(),self);self->arena->flags=self->flags;return self;}


