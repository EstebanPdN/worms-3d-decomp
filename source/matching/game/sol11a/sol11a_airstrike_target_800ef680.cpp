// GC32 external message and key views. Message/cache semantics are inferred.
struct Sol11aCache { unsigned flags; const char *name; };
struct Sol11aMessage { unsigned short type; void *dispatch; Sol11aMessage(Sol11aCache *); };
struct Sol11aVectorTarget { float x,y,z; };
extern void *arena_804b1754;
extern Sol11aCache cache_804aefbc,cache_804af014;
extern unsigned char dispatch_8040db38[];
extern const char has_target_8038be6c[],camera_mode_8038be80[],target_point_8038be94[],payload_target_8038beac[];
extern "C" Sol11aMessage *allocate_801613f0(void *,unsigned);
extern "C" unsigned message_id_8015f5a0(Sol11aCache *,int);
extern "C" int post_8016239c(Sol11aMessage *);
extern "C" int read_int_800fc230(const char *const *,int *);
extern "C" int read_vector_800fc2f0(const char *const *,Sol11aVectorTarget *);
extern "C" int write_vector_800fc5dc(const char *const *,const Sol11aVectorTarget *);
inline void *operator new(unsigned bytes,void *arena) { return allocate_801613f0(arena,bytes); }
inline Sol11aMessage::Sol11aMessage(Sol11aCache *cache) { type=message_id_8015f5a0(cache,1);dispatch=dispatch_8040db38; }
extern "C" int sol11a_airstrike_target_800ef680() {
 Sol11aMessage *message=new(arena_804b1754) Sol11aMessage(&cache_804aefbc);
 post_8016239c(message);
 const char *hasKey=has_target_8038be6c;
 int has;
 read_int_800fc230(&hasKey,&has);
 const char *modeKey=camera_mode_8038be80;
 int mode;
 read_int_800fc230(&modeKey,&mode);
 if(!has || mode==2)return 0;
 Sol11aVectorTarget target;
 const char *targetKey=target_point_8038be94;
 read_vector_800fc2f0(&targetKey,&target);
 const char *payloadKey=payload_target_8038beac;
 write_vector_800fc5dc(&payloadKey,&target);
 message=new(arena_804b1754) Sol11aMessage(&cache_804af014);
 post_8016239c(message);
 return 1;
}
