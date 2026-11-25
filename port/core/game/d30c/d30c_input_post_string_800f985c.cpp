#include "w3d_ptr.h"
#line 1 "d30c_input_post_string_800f985c.cpp"
// d30c: 0x800f985c. Queues a string input record: pushes it on the menu queue (+156) when the service is in menu mode, otherwise on the game queue (+60), then processes it. Names are inferred.
#include "d25c_input_queue.h"
extern "C" Ptr32<void> string_default_803426b8(Ptr32<void>);
struct PostString {
    Ptr32<char> text;
    PostString() { string_default_803426b8(this); }
    PostString(const PostString &o) {
        w3d_string_base_init(this);
        text = o.text;
        ++*w3d_string_header(this);
    }
    ~PostString() {
        w3d_string_base_finish(this);
        w3d_string_release(this);
    }
    PostString &operator=(const PostString &o) {
        ++*(Ptr32<unsigned short>)(o.text - 6);
        Ptr32<unsigned short> header = (Ptr32<unsigned short>)(text - 6);
        if (--*header == 0) w3d_string_release_header(header);
        text = o.text;
        return *this;
    }
};
struct PostBase {
    unsigned short id;
    int value;
    PostBase(unsigned short i, int v) : id(i), value(v) { W3D_SET_VPTR(this->w3d_vptr_PostBase, w3d_vt___vt_8PostBase, "__vt_8PostBase"); }
    void w3d_r_fire() __asm__(W3D_SYM("_ZN8PostBase4fireEv"));
 __attribute__((always_inline)) inline void fire() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_PostBase, 2))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_PostBase; };
struct PostRecord : PostBase {
    PostString name __attribute__((aligned(__alignof__(PostBase))));
    PostRecord(unsigned short i, const PostString &n, int v) : PostBase(i, v) { W3D_SET_VPTR(this->PostBase::w3d_vptr_PostBase, w3d_vt___vt_10PostRecord, "__vt_10PostRecord");  name = n; }
    void w3d_r_fire() __asm__(W3D_SYM("_ZN10PostRecord4fireEv"));
 __attribute__((always_inline)) inline void fire() { this->PostBase::fire(); } };
struct Input {
    unsigned char u0[60];
    D24fVector<PostRecord> game;
    unsigned char u76[80];
    D24fVector<PostRecord> menu;
    unsigned char u172[256];
    int in_menu;
};
extern Ptr32<Input> input_804aaf48;
extern "C" void process_800f9db8(Ptr32<Input>, Ptr32<const PostRecord>);
extern "C" void d30c_input_post_string_800f985c(unsigned short id, const PostString &name, int value) {
    PostRecord r(id, name, value);
    if (input_804aaf48->in_menu) input_804aaf48->menu.push_back(r);
    else input_804aaf48->game.push_back(r);
    process_800f9db8(input_804aaf48, &r);
}


