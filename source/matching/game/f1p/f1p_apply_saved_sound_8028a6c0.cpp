// Observed saved sound mode and partial service context; roles inferred.
struct F1pSoundService{void**table;};struct F1pSoundContext{char unknown[108];F1pSoundService*service;char unknown112[68];int enabled;};extern F1pSoundContext*context_804b1788;
struct F1pSoundKey{const char*text;F1pSoundKey(const char*p):text(p){}};extern char mode_803cfb44[];
extern "C" int fn_800fc43c(F1pSoundKey*,int),fn_800fc230(F1pSoundKey*,int*);
inline void soundMode(int mode){F1pSoundService*p=context_804b1788->service;((void(*)(F1pSoundService*,int))p->table[31])(p,mode);}
extern "C" void w3d_apply_saved_sound_8028a6c0(){if(!context_804b1788->enabled){F1pSoundKey key(mode_803cfb44);fn_800fc43c(&key,0);soundMode(0);}else{int mode=0;F1pSoundKey key(mode_803cfb44);fn_800fc230(&key,&mode);if((unsigned)mode>2)mode=0;if(!mode)soundMode(0);else soundMode(mode);}}
