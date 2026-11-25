/* Copies a resolved owner's position to a mesh and optional handle member. */
extern "C" {
struct S5FollowVec { float x,y,z; };
struct S5FollowMesh;
struct S5FollowVtable { void (*reserved[19])(); void (*set_position)(S5FollowMesh *,S5FollowVec *,int); };
struct S5FollowMesh { S5FollowVtable *vtable; };
struct S5FollowOwner { unsigned char reserved[28]; S5FollowVec position; };
struct S5FollowState { unsigned char reserved[28]; int owner; S5FollowMesh *mesh; S5FollowVec position; void *handle; };
S5FollowOwner *w3d_owner_resolve_80164fc8(int);
void w3d_handle_member_query_801265ec(void *,S5FollowVec *);
void w3d_mesh_follow_owner_800d56bc(S5FollowState *state)
{
    state->position=w3d_owner_resolve_80164fc8(state->owner)->position;
    state->mesh->vtable->set_position(state->mesh,&state->position,0);
    if(state->handle) w3d_handle_member_query_801265ec(state->handle,&state->position);
}
}
