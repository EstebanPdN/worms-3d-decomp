#include "w3d_ptr.h"
#line 1 "sol35a3_crate_append_8005e35c.cpp"
// Original range [0x8005e35c,0x8005e4a4), 328 instruction bytes.
// The inline empty parameter initializes real flags/spare fields across both calls.
// The pool owns the first word; this body neither reads nor initializes it.
// Explicit placement construction starts the Action and appended scalar lifetimes.
// The placement allocator has the ordinary throwing signature: valid storage is
// required, matching the original unchecked append. It does not allocate memory.
// External allocation/copy identities and byte-capacity arithmetic are preserved.
// No original C++ class or subsystem name is claimed.
// Native byte-range capacity arithmetic and cached-ID layout; meanings inferred.
inline void *operator new(__SIZE_TYPE__,void *place) { return place; }
extern "C" Ptr32<unsigned char> sol35a3_allocate_80212fd4(unsigned);
extern "C" void sol35a3_release_802134fc(Ptr32<void>);
extern "C" Ptr32<void> sol35a3_copy_802eee50(Ptr32<void>,Ptr32<const void>,...);
inline const int &larger(const int &a,const int &b) {return a<b?b:a;}
inline const unsigned &smaller(const unsigned &a,const unsigned &b) {return b<a?b:a;}
struct Storage {
    Ptr32<unsigned char> begin; Ptr32<unsigned char> end; Ptr32<unsigned char> capacity;
    void push(const unsigned &value) {
        if (end==capacity) {
            unsigned used=end-begin;
            int next=used+1;
            int grown=used+(used>>1);
            unsigned allocated=larger(next,grown)*4;
            Ptr32<unsigned char> fresh=sol35a3_allocate_80212fd4(allocated);
            if (begin) {
                sol35a3_copy_802eee50(fresh,begin,smaller(allocated,used));
                sol35a3_release_802134fc(begin);
            }
            begin=fresh;
            end=fresh+used;
            capacity=fresh+allocated;
        }
        new (end) unsigned(value);
        end+=4;
    }
};
struct CachedName {unsigned cache;Ptr32<const char> name;};
struct Action {unsigned unknown;CachedName name;unsigned mode,flags,action,enabled,spare;};
struct Owner {char unknown[36];Storage storage;};
struct Pool {unsigned head;};
extern Pool sol35a3_pool_804ae280;
extern const char sol35a3_action_name_80378edc[];
extern "C" Ptr32<void> sol35a3_pool_allocate_802098d8(Ptr32<void>,unsigned);
extern "C" Ptr32<CachedName> sol35a3_name_8015f518(Ptr32<CachedName>,Ptr32<const char>);
inline Ptr32<Action> create_action(unsigned empty) {
    Ptr32<Action> action=new (sol35a3_pool_allocate_802098d8(&sol35a3_pool_804ae280,sizeof(Action))) Action;
    sol35a3_name_8015f518(&action->name,sol35a3_action_name_80378edc);
    action->action=8;
    action->enabled=1;
    action->mode=2;
    action->flags=empty;
    action->spare=empty;
    return action;
}
extern "C" void sol35a3_crate_append_8005e35c(Ptr32<void>,Ptr32<Owner> self) {
    Ptr32<Action> action=create_action(0);
    self->storage.push((unsigned)w3d::H(action));
}

typedef char sol35a3_pointer_width[sizeof(Ptr32<void>)==4?1:-1];
typedef char sol35a3_action_size[sizeof(Action)==32?1:-1];
typedef char sol35a3_name_size[sizeof(CachedName)==8?1:-1];
typedef char sol35a3_storage_size[sizeof(Storage)==12?1:-1];


