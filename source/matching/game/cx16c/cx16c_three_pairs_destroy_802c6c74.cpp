
// Observed held interfaces release through slot +16; semantic class names are inferred.
#define CX16C_FIELD(p,T,o) (*(T*)((char*)(p)+(o)))
struct Cx16cHeld { void *held; ~Cx16cHeld() { if(held) ((void(*)(void*))(*(void**)(*(char**)held+16)))(held); } };
extern "C" void cx16c_context_destroy_802afc40(void*,int);
extern "C" void cx16c_base_destroy_8015ff2c(void*,int);

extern const void *cx16c_table_8041c960[];
extern "C" void cx16c_text_finish_8020c5c4(void*);
extern "C" void cx16c_text_release_80341588(void*);
struct Cx16cText { const char *data; ~Cx16cText() { cx16c_text_finish_8020c5c4(this);cx16c_text_release_80341588(this); } };
struct Cx16cThreePairs {
 const void *table;char reserved[24];Cx16cHeld field28;char gap32[8];
 Cx16cHeld first[2],second[2],third[2],field64;char gap68[24];
 Cx16cHeld field92;char gap96[4];Cx16cText text;
 ~Cx16cThreePairs() {}
};
extern "C" void w3d_cx16c_three_pairs_destroy_802c6c74(void *self,int flags) {
 Cx16cThreePairs *owner=(Cx16cThreePairs*)self;
 owner->table=cx16c_table_8041c960;
 owner->~Cx16cThreePairs();
 cx16c_base_destroy_8015ff2c(self,flags);
}
