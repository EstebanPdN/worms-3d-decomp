#include "w3d_ptr.h"
#line 1 "d28a_aim_command_create_80007eac.cpp"
// GWMP8P rev0 0x80007eac. Creates an aim command for a direction (a tiny
// upward vector when the direction equals the zero vector) and appends it to
// the current command list and the owner's storage. Class names and field
// meanings are inferred from the original instructions.
extern "C" Ptr32<unsigned char> w3d_handle_storage_allocate(unsigned int);
extern "C" void w3d_handle_storage_release(Ptr32<void>);
extern "C" Ptr32<void> memcpy(Ptr32<void>, Ptr32<const void>, ...);
extern "C" Ptr32<void> w3d_auto_8001523c(unsigned int);
inline void *operator new(__SIZE_TYPE__, void *place) { return place; }
inline const int &larger(const int &a, const int &b) { return a < b ? b : a; }
inline const unsigned int &smaller(const unsigned int &a, const unsigned int &b) { return b < a ? b : a; }
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    void Set(float a, float b, float c) { x = a; y = b; z = c; }
    bool Same(const Vec &o) const {
        Ptr32<const int> p = (Ptr32<const int>)this; Ptr32<const int> q = (Ptr32<const int>)&o;
        return p[0] == q[0] && p[1] == q[1] && p[2] == q[2];
    }
};
struct CommandBase {
    int unknown0, unknown4, unknown8, kind;
    void w3d_r_dispatch() __asm__(W3D_SYM("_ZN11CommandBase8dispatchEv"));
    CommandBase() { W3D_SET_VPTR(this->w3d_vptr_CommandBase, w3d_vt___vt_11CommandBase, "__vt_11CommandBase");  unknown4 = 0; unknown8 = 0; }
 __attribute__((always_inline)) inline void dispatch() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_CommandBase, 2))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_CommandBase; };
struct AimCommand : CommandBase {
    Vec target __attribute__((aligned(__alignof__(CommandBase))));
    void w3d_r_dispatch() __asm__(W3D_SYM("_ZN10AimCommand8dispatchEv"));
    AimCommand() { W3D_SET_VPTR(this->CommandBase::w3d_vptr_CommandBase, w3d_vt___vt_10AimCommand, "__vt_10AimCommand");  kind = 8; }
    void SetTarget(Vec v) { target = v; }
 __attribute__((always_inline)) inline void dispatch() { this->CommandBase::dispatch(); } };
struct Storage {
    Ptr32<unsigned char> begin; Ptr32<unsigned char> end; Ptr32<unsigned char> capacity;
    void push(Ptr32<CommandBase> const &value) {
        if (end == capacity) {
            unsigned int used = end - begin;
            int next = used + 1;
            int grown = used + (used >> 1);
            unsigned int allocated = larger(next, grown) * 4;
            Ptr32<unsigned char> fresh = w3d_handle_storage_allocate(allocated);
            if (begin) {
                memcpy(fresh, begin, smaller(allocated, used));
                w3d_handle_storage_release(begin);
            }
            begin = fresh; end = fresh + used; capacity = fresh + allocated;
        }
        *(Ptr32<Ptr32<CommandBase>>)end = value;
        end += 4;
    }
};
struct Member;
extern Ptr32<Storage> g_commands_804aa564;
extern Ptr32<Member> g_owner_804aa5a4;
extern Vec g_zero_8045e788[];
extern "C" void w3d_cx9a_storage_push_member_8002274c(Ptr32<Member>, Ptr32<void>);
extern "C" void w3d_d28a_aim_command_create_80007eac(Ptr32<const Vec> v)
{
    Vec p = *v;
    if (g_zero_8045e788[0].Same(p)) {
        p.Set(0.0f, 0.0001f, 0.0f);
    }
    Ptr32<AimCommand> n = new (w3d_auto_8001523c(32)) AimCommand;
    g_commands_804aa564->push(n);
    n->SetTarget(p);
    w3d_cx9a_storage_push_member_8002274c(g_owner_804aa5a4, n);
}


