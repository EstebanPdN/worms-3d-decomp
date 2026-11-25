// GWMP8P rev0 0x80007eac. Creates an aim command for a direction (a tiny
// upward vector when the direction equals the zero vector) and appends it to
// the current command list and the owner's storage. Class names and field
// meanings are inferred from the original instructions.
extern "C" unsigned char *w3d_handle_storage_allocate(unsigned int);
extern "C" void w3d_handle_storage_release(void *);
extern "C" void *memcpy(void *, const void *, ...);
extern "C" void *w3d_auto_8001523c(unsigned int);
inline void *operator new(unsigned int, void *place) { return place; }
inline const int &larger(const int &a, const int &b) { return a < b ? b : a; }
inline const unsigned int &smaller(const unsigned int &a, const unsigned int &b) { return b < a ? b : a; }
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    void Set(float a, float b, float c) { x = a; y = b; z = c; }
    bool Same(const Vec &o) const {
        const int *p = (const int *)this, *q = (const int *)&o;
        return p[0] == q[0] && p[1] == q[1] && p[2] == q[2];
    }
};
struct CommandBase {
    int unknown0, unknown4, unknown8, kind;
    virtual void dispatch();
    CommandBase() { unknown4 = 0; unknown8 = 0; }
};
struct AimCommand : CommandBase {
    Vec target;
    virtual void dispatch();
    AimCommand() { kind = 8; }
    void SetTarget(Vec v) { target = v; }
};
struct Storage {
    unsigned char *begin, *end, *capacity;
    void push(CommandBase *const &value) {
        if (end == capacity) {
            unsigned int used = end - begin;
            int next = used + 1;
            int grown = used + (used >> 1);
            unsigned int allocated = larger(next, grown) * 4;
            unsigned char *fresh = w3d_handle_storage_allocate(allocated);
            if (begin) {
                memcpy(fresh, begin, smaller(allocated, used));
                w3d_handle_storage_release(begin);
            }
            begin = fresh; end = fresh + used; capacity = fresh + allocated;
        }
        *(CommandBase **)end = value;
        end += 4;
    }
};
struct Member;
extern Storage *g_commands_804aa564;
extern Member *g_owner_804aa5a4;
extern Vec g_zero_8045e788[];
extern "C" void w3d_cx9a_storage_push_member_8002274c(Member *, void *);
extern "C" void w3d_d28a_aim_command_create_80007eac(const Vec *v)
{
    Vec p = *v;
    if (g_zero_8045e788[0].Same(p)) {
        p.Set(0.0f, 0.0001f, 0.0f);
    }
    AimCommand *n = new (w3d_auto_8001523c(32)) AimCommand;
    g_commands_804aa564->push(n);
    n->SetTarget(p);
    w3d_cx9a_storage_push_member_8002274c(g_owner_804aa5a4, n);
}
