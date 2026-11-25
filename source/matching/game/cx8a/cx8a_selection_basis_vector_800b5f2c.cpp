// Inferred basis multiplication. Owner basis pointer +4; basis columns +0xc0,+0xcc,+0xd8.
struct Cx8aVec3 { float x,y,z; };
struct Cx8aBasis { unsigned char unknown00[0xc0];Cx8aVec3 right,up,forward; };
struct Cx8aBasisOwner { void *unknown00; Cx8aBasis *basis; };
extern Cx8aVec3 selection_direction_8043ade4[];
extern "C" void w3d_cx8a_selection_basis_vector_800b5f2c(Cx8aBasisOwner *owner,Cx8aVec3 *out) {
 Cx8aBasis *b=owner->basis;Cx8aVec3 *v=selection_direction_8043ade4;Cx8aVec3 *right=&b->right,*up=&b->up,*forward=&b->forward;
 out->x=(v->x*right->x+v->y*up->x)+v->z*forward->x;
 out->y=(v->x*right->y+v->y*up->y)+v->z*forward->y;
 out->z=(v->x*right->z+v->y*up->z)+v->z*forward->z;
}
