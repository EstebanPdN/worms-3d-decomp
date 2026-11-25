#include "w3d_ptr.h"
#line 1 "f9b_random_decay_80036b08.cpp"
// Sixteen frame bytes have unknown original purpose; no payload is read from them.
struct F9RandomVec{float x,y,z;};struct F9RandomSource{float strength;int start,duration;};struct F9RandomContext{char p[52];int ticks;};
extern const float bias_80373cc8[],one_80373cd8[];
extern "C" Ptr32<F9RandomContext> context_80165254();extern "C" unsigned random_80162ba8();
extern "C" void f9b_random_decay_80036b08(Ptr32<F9RandomSource> s,Ptr32<F9RandomVec> out){int elapsed=context_80165254()->ticks-s->start;out->x=(float)(random_80162ba8()%3)+-1.0f;out->y=(float)(random_80162ba8()%3)+-1.0f;out->z=(float)(random_80162ba8()%3)+-1.0f;float strength=s->strength;if(s->duration>0)strength*=1.0f-(float)elapsed/(float)s->duration;out->x*=strength;out->y*=strength;out->z*=strength;}


