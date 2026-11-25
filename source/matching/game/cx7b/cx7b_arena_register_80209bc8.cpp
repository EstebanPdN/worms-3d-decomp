struct Cx7bArena { int unknown00; unsigned char index; };
struct Cx7bArenaTable { Cx7bArena *slots[256]; };
extern "C" char text_803b2fa4[];
extern "C" void fn_801fcb64(const char *,int);
extern "C" void w3d_cx7b_arena_register_80209bc8(Cx7bArenaTable *self,Cx7bArena *arena) {
 for(int i=0;i<256;++i) if(!self->slots[i]) { self->slots[i]=arena; arena->index=i; return; }
 fn_801fcb64(text_803b2fa4,0);
}
