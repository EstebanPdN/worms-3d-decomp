struct S9Vec3 { int x,y,z; };
struct S9Flags {
    char unknown[7];
    unsigned char value;
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
struct S9Inner { char unknown[48]; S9Storage *storage; };
struct S9VectorOwner { char unknown[120]; S9Inner *inner; };
extern "C" int s9_set_vector_8017b040(S9VectorOwner *self,const S9Vec3 *value)
{
    S9Storage *data=self->inner->storage;
    data->vector96=*value;
    data->flags.mark_dirty();
    return 0;
}

extern "C" int s9_set_vector_8017b07c(S9VectorOwner *self,const S9Vec3 *value)
{
    S9Storage *data=self->inner->storage;
    data->vector84=*value;
    data->flags.mark_dirty();
    return 0;
}

extern "C" int s9_set_vector_8017b120(S9VectorOwner *self,const S9Vec3 *value)
{
    S9Storage *data=self->inner->storage;
    data->vector72=*value;
    data->flags.mark_dirty();
    return 0;
}
