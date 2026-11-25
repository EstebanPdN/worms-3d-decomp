#include "w3d_ptr.h"
#line 1 "s5_rope_runtime.cpp"
/* Rope handle draining and scale adjustment. */
extern "C" {
struct S5RopeHandle { unsigned char reserved[16]; };
struct S5RopeRuntime { unsigned char reserved00[40]; int state; unsigned char reserved44[200]; Ptr32<void> clock; unsigned char reserved248[20]; float scale; unsigned char reserved272[36]; S5RopeHandle handle; };
void w3d_handle_member_query_801262c0(Ptr32<S5RopeHandle>, Ptr32<void>);
void w3d_handle_member_call_80126334(Ptr32<S5RopeHandle>);
int w3d_handle_clock_801264fc(Ptr32<S5RopeHandle>);
void w3d_handle_member_query_80126524(Ptr32<S5RopeHandle>);
float w3d_auto_80178df0(Ptr32<void>);
int w3d_rope_drain_handle_800d0058(Ptr32<S5RopeRuntime> rope, Ptr32<void> arg_r4)
{
    int count=0;
    w3d_handle_member_query_801262c0(&rope->handle, arg_r4);
    w3d_handle_member_call_80126334(&rope->handle);
    if (w3d_handle_clock_801264fc(&rope->handle)!=65535)
        do { ++count; } while (w3d_handle_clock_801264fc(&rope->handle)!=65535);
    w3d_handle_member_query_80126524(&rope->handle);
    if(count>1) { rope->state=1;return 1; }
    return 0;
}
void w3d_rope_rescale_800d1628(Ptr32<S5RopeRuntime> rope,float numerator,float denominator)
{
    struct { float reserved[6]; } unused;
    float scaled=w3d_auto_80178df0(rope->clock)*rope->scale*numerator;
    scaled/=w3d_auto_80178df0(rope->clock)*denominator;
    rope->scale=scaled;
}
}


