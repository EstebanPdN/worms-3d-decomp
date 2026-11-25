#include "w3d_ptr.h"
#line 1 "sol11a_airstrike_target_800ef680.cpp"
// GC32 external message and key views. Message/cache semantics are inferred.
struct Sol11aCache { unsigned flags; Ptr32<const char> name; };
struct Sol11aMessage { unsigned short type; Ptr32<void> dispatch; template <class W3dU> Sol11aMessage(Ptr32<W3dU> w3d_p) : Sol11aMessage((Sol11aCache *)w3d_p.get()) {}
 Sol11aMessage(Sol11aCache *); };
struct Sol11aVectorTarget { float x,y,z; };
extern Ptr32<void> arena_804b1754;
extern Sol11aCache cache_804aefbc,cache_804af014;
extern unsigned char dispatch_8040db38[];
extern const char has_target_8038be6c[],camera_mode_8038be80[],target_point_8038be94[],payload_target_8038beac[];
extern "C" Ptr32<Sol11aMessage> allocate_801613f0(Ptr32<void>,unsigned);
extern "C" unsigned message_id_8015f5a0(Ptr32<Sol11aCache>,int);
extern "C" int post_8016239c(Ptr32<Sol11aMessage>);
extern "C" int read_int_800fc230(Ptr32<Ptr32<const char> const>,Ptr32<int>);
extern "C" int read_vector_800fc2f0(Ptr32<Ptr32<const char> const>,Ptr32<Sol11aVectorTarget>);
extern "C" int write_vector_800fc5dc(Ptr32<Ptr32<const char> const>,Ptr32<const Sol11aVectorTarget>);
inline void *operator new(__SIZE_TYPE__ bytes,void *arena) { return allocate_801613f0(arena,bytes); }
inline Sol11aMessage::Sol11aMessage(Sol11aCache *cache) { type=message_id_8015f5a0(cache,1);dispatch=dispatch_8040db38; }
extern "C" int sol11a_airstrike_target_800ef680() {
 Ptr32<Sol11aMessage> message=new(arena_804b1754) Sol11aMessage(&cache_804aefbc);
 post_8016239c(message);
 Ptr32<const char> hasKey=has_target_8038be6c;
 int has;
 read_int_800fc230(&hasKey,&has);
 Ptr32<const char> modeKey=camera_mode_8038be80;
 int mode;
 read_int_800fc230(&modeKey,&mode);
 if(!has || mode==2)return 0;
 Sol11aVectorTarget target;
 Ptr32<const char> targetKey=target_point_8038be94;
 read_vector_800fc2f0(&targetKey,&target);
 Ptr32<const char> payloadKey=payload_target_8038beac;
 write_vector_800fc5dc(&payloadKey,&target);
 message=new(arena_804b1754) Sol11aMessage(&cache_804af014);
 post_8016239c(message);
 return 1;
}


