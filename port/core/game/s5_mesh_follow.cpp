#include "w3d_ptr.h"
#line 1 "s5_mesh_follow.cpp"
/* Copies a resolved owner's position to a mesh and optional handle member. */
extern "C" {
struct S5FollowVec { float x,y,z; };
struct S5FollowMesh;
struct S5FollowVtable { Ptr32<void (void)> reserved[19]; Ptr32<void (Ptr32<S5FollowMesh>, Ptr32<S5FollowVec>, int)> set_position; };
struct S5FollowMesh { Ptr32<S5FollowVtable> vtable; };
struct S5FollowOwner { unsigned char reserved[28]; S5FollowVec position; };
struct S5FollowState { unsigned char reserved[28]; int owner; Ptr32<S5FollowMesh> mesh; S5FollowVec position; Ptr32<void> handle; };
Ptr32<S5FollowOwner> w3d_owner_resolve_80164fc8(int);
void w3d_handle_member_query_801265ec(Ptr32<void>,Ptr32<S5FollowVec>);
void w3d_mesh_follow_owner_800d56bc(Ptr32<S5FollowState> state)
{
    state->position=w3d_owner_resolve_80164fc8(state->owner)->position;
    state->mesh->vtable->set_position(state->mesh,&state->position,0);
    if(state->handle) w3d_handle_member_query_801265ec(state->handle,&state->position);
}
}


