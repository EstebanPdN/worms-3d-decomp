#include "w3d_ptr.h"
#line 1 "s4_mouse_events.cpp"
extern "C" {
struct S4Vector { float x,y,z; };
struct S4Mouse { unsigned char pad[32]; S4Vector position; };
struct S4Message { unsigned short id; };
struct S4Cache { unsigned char data[8]; };
struct S4Context { unsigned char pad[188]; unsigned int flags; };
extern S4Cache w3d_cache_804b0b8c,w3d_cache_804b0b94;
extern Ptr32<S4Context> w3d_context_804b1788;
extern int w3d_mouse_busy_804abbb8;
extern Ptr32<void> w3d_input_804aac54;
int w3d_auto_8015fb34(Ptr32<void>,Ptr32<S4Message>);
void w3d_mouse_setup_80285168(Ptr32<void>);
void w3d_empty_802852c0(Ptr32<void>);
int w3d_message_matches_8015f65c(unsigned int,Ptr32<void>);
void w3d_value_range_get_80069a50(Ptr32<S4Message>,Ptr32<float>,Ptr32<float>);
void w3d_input_position_800a79f8(Ptr32<void>,float,float);
int w3d_mouse_clamp_802852c4(Ptr32<S4Mouse>);
int w3d_s4_mouse_message(Ptr32<S4Mouse> self,Ptr32<S4Message> message)
{
    switch(message->id) {
    case 64:
        if(w3d_auto_8015fb34(self,message)>=0) {
            w3d_mouse_setup_80285168(self);
            break;
        }
        return (int)0x80004005;
    case 66:
        w3d_empty_802852c0(self);
        return w3d_auto_8015fb34(self,message);
    default:
        if(w3d_message_matches_8015f65c(message->id,&w3d_cache_804b0b8c) ||
           w3d_message_matches_8015f65c(message->id,&w3d_cache_804b0b94)) {
            int busy = w3d_mouse_busy_804abbb8;
            if(!busy) {
                w3d_mouse_busy_804abbb8=1;
                w3d_value_range_get_80069a50(message,&self->position.x,&self->position.y);
                if(w3d_mouse_clamp_802852c4(self))
                    w3d_input_position_800a79f8(w3d_input_804aac54,self->position.x,self->position.y);
                w3d_mouse_busy_804abbb8=busy;
            }
        } else return w3d_auto_8015fb34(self,message);
    }
    return 0;
}
extern S4Vector w3d_bounds_min_804668d0[],w3d_bounds_max_804668dc[];
// Deferred: vector copies and reference-selection allocation differ after one attempt.
#if 0
int w3d_mouse_clamp_802852c4(S4Mouse *self)
{
    S4Vector before;
    before.x=self->position.x; before.y=self->position.y; before.z=self->position.z;
    const float *a=&self->position.x;
    if(*a<w3d_bounds_min_804668d0[0].x) a=&w3d_bounds_min_804668d0[0].x;
    const float *b=a;
    if(w3d_bounds_max_804668dc[0].x<*a) b=&w3d_bounds_max_804668dc[0].x;
    self->position.x=*b;
    a=&self->position.y;
    if(*a<w3d_bounds_min_804668d0[0].y) a=&w3d_bounds_min_804668d0[0].y;
    b=a;
    if(w3d_bounds_max_804668dc[0].y<*a) b=&w3d_bounds_max_804668dc[0].y;
    self->position.y=*b;
    a=&self->position.z;
    if(*a<w3d_bounds_min_804668d0[0].z) a=&w3d_bounds_min_804668d0[0].z;
    b=a;
    if(w3d_bounds_max_804668dc[0].z<*a) b=&w3d_bounds_max_804668dc[0].z;
    self->position.z=*b;
    int same=0;
    if(*(unsigned int *)&before.x==*(unsigned int *)&self->position.x &&
       *(unsigned int *)&before.y==*(unsigned int *)&self->position.y)
        same=*(unsigned int *)&before.z==*(unsigned int *)&self->position.z;
    return same^1;
}
#endif
}


