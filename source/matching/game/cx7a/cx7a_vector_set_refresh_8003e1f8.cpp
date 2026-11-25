
// The three words are copied without floating-point operations. The embedded
// member at +0x44 is then refreshed. Its concrete class is not established.
struct Cx7aWords3 { unsigned int x,y,z; };
struct Cx7aMember { unsigned char unknown[4]; };
struct Cx7aObject { unsigned char unknown00[0x1c]; Cx7aWords3 position; unsigned char unknown28[0x1c]; Cx7aMember member; };
extern "C" int refresh_801262c0(Cx7aMember *);
static inline void assign(Cx7aWords3 *to,const Cx7aWords3 *from) { unsigned int x=from->x,z=from->z,y=from->y;to->x=x;to->y=y;to->z=z; }
extern "C" void w3d_cx7a_vector_set_refresh_8003e1f8(Cx7aObject *self,const Cx7aWords3 *value) { assign(&self->position,value);refresh_801262c0(&self->member); }
