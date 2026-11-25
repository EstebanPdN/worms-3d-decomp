// d30c: 0x800f985c. Queues a string input record: pushes it on the menu queue (+156) when the service is in menu mode, otherwise on the game queue (+60), then processes it. Names are inferred.
#include "d25c_input_queue.h"
extern "C" void * string_default_803426b8(void *);
struct PostString {
    char *text;
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
        ++*(unsigned short *)(o.text - 6);
        unsigned short *header = (unsigned short *)(text - 6);
        if (--*header == 0) w3d_string_release_header(header);
        text = o.text;
        return *this;
    }
};
struct PostBase {
    unsigned short id;
    int value;
    PostBase(unsigned short i, int v) : id(i), value(v) {}
    virtual void fire();
};
struct PostRecord : PostBase {
    PostString name;
    PostRecord(unsigned short i, const PostString &n, int v) : PostBase(i, v) { name = n; }
    virtual void fire();
};
struct Input {
    unsigned char u0[60];
    D24fVector<PostRecord> game;
    unsigned char u76[80];
    D24fVector<PostRecord> menu;
    unsigned char u172[256];
    int in_menu;
};
extern Input *input_804aaf48;
extern "C" void process_800f9db8(Input *, const PostRecord *);
extern "C" void d30c_input_post_string_800f985c(unsigned short id, const PostString &name, int value) {
    PostRecord r(id, name, value);
    if (input_804aaf48->in_menu) input_804aaf48->menu.push_back(r);
    else input_804aaf48->game.push_back(r);
    process_800f9db8(input_804aaf48, &r);
}
