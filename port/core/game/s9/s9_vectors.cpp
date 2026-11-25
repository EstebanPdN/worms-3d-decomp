#include "w3d_ptr.h"
#line 1 "s9_vectors.cpp"
struct S9Vec3 { int x,y,z; };
struct S9Flags {
    char unknown[4];
    unsigned char value; char w3d_tag_rest[3];
    void mark_dirty() { value|=2; }
};
struct S9Storage {
    int unknown0;
    S9Flags flags;
    char unknown12[60];
    S9Vec3 vector72;
    S9Vec3 vector84;
    S9Vec3 vector96;
};
struct S9Inner { char unknown[48]; Ptr32<S9Storage> storage; };
struct S9VectorOwner { char unknown[120]; Ptr32<S9Inner> inner; };
extern "C" int s9_set_vector_8017b040(Ptr32<S9VectorOwner> self,Ptr32<const S9Vec3> value)
{
    Ptr32<S9Storage> data=self->inner->storage;
    data->vector96=*value;
    data->flags.mark_dirty();
    return 0;
}

extern "C" int s9_set_vector_8017b07c(Ptr32<S9VectorOwner> self,Ptr32<const S9Vec3> value)
{
    Ptr32<S9Storage> data=self->inner->storage;
    data->vector84=*value;
    data->flags.mark_dirty();
    return 0;
}

extern "C" int s9_set_vector_8017b120(Ptr32<S9VectorOwner> self,Ptr32<const S9Vec3> value)
{
    Ptr32<S9Storage> data=self->inner->storage;
    data->vector72=*value;
    data->flags.mark_dirty();
    return 0;
}


