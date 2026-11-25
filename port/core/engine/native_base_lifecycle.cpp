#include "w3d_ptr.h"
#line 1 "native_base_lifecycle.cpp"
/* Two complete original reference-ABI cleanup bodies. Types and names inferred. */
namespace w3d_reference_base_construction {
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
struct Prefix {u16 refs,unknown; union {u32 value; volatile u8 bytes[4];} mode; u32 left,right;};
struct Base {Ptr32<void> table; Prefix prefix; u32 nested; u32 flags,tail;};
extern "C" {
extern u8 w3d_ref_base_root_table[],w3d_ref_base_table[];
struct HeaderView {u16 refs,length,capacity;};
extern HeaderView nested_pool;
extern u32 nested_skip;
extern void nested_pre(Ptr32<void>);
extern u32 nested_get(Ptr32<void>);
extern Ptr32<u16> nested_counter(Ptr32<void>);
extern void w3d_original_8020c5c4(Ptr32<void>);
extern void w3d_original_80341588(Ptr32<void>);
extern void w3d_original_80210990(Ptr32<Prefix>,u32);
extern void w3d_original_801fe1f8_for_base(Ptr32<void>);
extern void w3d_original_8017eaa0(Ptr32<Base>);
extern void w3d_original_8017f198_for_base(Ptr32<Base>,u32);
void w3d_base_destroy(Ptr32<Base> p,u32 flags) {
 p->table=w3d_ref_base_table;Ptr32<u32> n=&p->nested;
 w3d_original_8020c5c4(n);w3d_original_80341588(n);
 p->table=w3d_ref_base_root_table;w3d_original_80210990(&p->prefix,0);
 if(flags&1)w3d_original_801fe1f8_for_base(p);
}
u32 w3d_state_release_reference(Ptr32<Base> p) {
 u16 n=--p->prefix.refs;
 if(n==0){w3d_original_8017eaa0(p);if(p)w3d_original_8017f198_for_base(p,3);}
 return n;
}
}
typedef char prefix_size[(sizeof(Prefix)==16)?1:-1];
typedef char base_size[(sizeof(Base)==32)?1:-1];

typedef char header_size[(sizeof(HeaderView)==6)?1:-1];
} // namespace w3d_reference_base_construction


