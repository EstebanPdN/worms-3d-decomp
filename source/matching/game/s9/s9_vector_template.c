/* Vector copy and dirty-flag update through two observed owner pointers. */
#define FIELD(p,T,o) (*(T *)((char *)(p)+(o)))
typedef struct S9DirtyFlags { unsigned long long reserved:62; unsigned long long dirty:1; unsigned long long low:1; } S9DirtyFlags;
typedef struct S9Vec3 { int x,y,z; } S9Vec3;
int s9_set_vector_8017b040(void *self,const S9Vec3 *value)
{
    void *inner=FIELD(self,void *,120);
    void *data=FIELD(inner,void *,48);
    FIELD(data,S9Vec3,96)=*value;
    FIELD((char *)data+4, unsigned char volatile,7)|=2;
    return 0;
}
