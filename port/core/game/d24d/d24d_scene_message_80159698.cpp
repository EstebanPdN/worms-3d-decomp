#include "w3d_ptr.h"
#line 1 "d24d_scene_message_80159698.cpp"
// d24d: 0x80159698 (736 bytes). Scene message handler. Message 64 runs the base handler
// (0x8015fb34) and, on success, the scene start 0x801599ec (else 0x80004005); 66 stops
// the scene. Other ids are matched against cached ids (0x8015f65c): one carrying the
// text "WormMoving", or any of four others, resets (0x80159978); another, while enabled
// (+64), posts the announcements (kind 51 once, guarded by +72, then five plain ones);
// three more set or clear +64 and +68. All but the handled cases end in the base
// handler. The string has one word (no second word needed).
struct d24d_String {
    Ptr32<char> text;
    template <class W3dU> d24d_String(Ptr32<W3dU> w3d_p) : d24d_String((const char *)w3d_p.get()) {}
 d24d_String(const char *);
    ~d24d_String();
};
extern "C" void d24d_string_finish_8020c5c4(Ptr32<d24d_String>);
extern "C" void d24d_string_release_80341588(Ptr32<d24d_String>);
inline d24d_String::~d24d_String() { d24d_string_finish_8020c5c4(this); d24d_string_release_80341588(this); }
struct d24d_Msg { unsigned short id; };
struct d24d_Plain { unsigned short id; Ptr32<void> data; };
struct d24d_Scene {
    unsigned char unknown00[64];
    int enabled;                         // +64
    int started;                         // +68
    int announced;                       // +72
};
extern Ptr32<void> d24d_arena_804b1754;
extern char d24d_message_vtable_8040db38[];
extern "C" int strcmp(Ptr32<const char>, Ptr32<const char>);
extern "C" int d24d_scene_base_8015fb34(Ptr32<d24d_Scene>, Ptr32<d24d_Msg>);
extern "C" void d24d_scene_start_801599ec(Ptr32<d24d_Scene>);
extern "C" void d24d_scene_stop_80159c24(Ptr32<d24d_Scene>);
extern "C" int d24d_message_is_8015f65c(unsigned, Ptr32<int>);
extern "C" Ptr32<const char> d24d_message_text_8010a8fc(Ptr32<d24d_Msg>);
extern "C" void d24d_scene_reset_80159978(Ptr32<d24d_Scene>);
extern "C" Ptr32<void> d24d_arena_alloc_801613f0(Ptr32<void>, int);
extern "C" unsigned d24d_message_id_8015f5a0(Ptr32<int>, int);
extern "C" Ptr32<void> d24d_kind_message_80125fdc(Ptr32<void>, unsigned short, int);
extern "C" int d24d_message_post_8016239c(Ptr32<void>);
extern const char d24d_text_803a3fe4[];
inline bool d24d_same(Ptr32<const char> a, Ptr32<const char> b) { return strcmp(a, b) == 0; }
extern int d24d_key_804aff88;
extern int d24d_key_804affd0;
extern int d24d_key_804affb8;
extern int d24d_key_804affd8;
extern int d24d_key_804affe0;
extern int d24d_key_804aff90;
extern int d24d_key_804b0000;
extern int d24d_key_804afff8;
extern int d24d_key_804affe8;
extern int d24d_key_804b0010;
extern int d24d_key_804aff98;
extern int d24d_key_804b0008;
extern int d24d_key_804affb0;
extern int d24d_key_804affa0;
extern int d24d_key_804affa8;

extern "C" int d24d_scene_message_80159698(Ptr32<d24d_Scene> self, Ptr32<d24d_Msg> msg) {
    unsigned id = msg->id;
    switch (id) {
    case 64:
        if (d24d_scene_base_8015fb34(self, msg) >= 0) {
            d24d_scene_start_801599ec(self);
            return 0;
        }
        return 0x80004005;
    case 66:
        d24d_scene_stop_80159c24(self);
        break;
    default:
    if (d24d_message_is_8015f65c(id, &d24d_key_804aff88)) {
        const d24d_String &text = d24d_String(d24d_message_text_8010a8fc(msg));
        if (d24d_same(text.text, d24d_text_803a3fe4)) d24d_scene_reset_80159978(self);
    }
    if (d24d_message_is_8015f65c(id, &d24d_key_804affd0) || d24d_message_is_8015f65c(id, &d24d_key_804affb8) || d24d_message_is_8015f65c(id, &d24d_key_804affd8) || d24d_message_is_8015f65c(id, &d24d_key_804affe0))
        d24d_scene_reset_80159978(self);
    if (d24d_message_is_8015f65c(id, &d24d_key_804aff90) && self->enabled) {
        if (!self->announced) {
            self->announced = 1;
            Ptr32<void> m = d24d_arena_alloc_801613f0(d24d_arena_804b1754, 12);
            d24d_message_post_8016239c(d24d_kind_message_80125fdc(m, d24d_message_id_8015f5a0(&d24d_key_804b0000, 1), 51));
        }
        {
            Ptr32<d24d_Plain> m = (Ptr32<d24d_Plain>)d24d_arena_alloc_801613f0(d24d_arena_804b1754, 8);
            m->id = d24d_message_id_8015f5a0(&d24d_key_804afff8, 1);
            m->data = d24d_message_vtable_8040db38;
            d24d_message_post_8016239c(m);
        }
        {
            Ptr32<d24d_Plain> m = (Ptr32<d24d_Plain>)d24d_arena_alloc_801613f0(d24d_arena_804b1754, 8);
            m->id = d24d_message_id_8015f5a0(&d24d_key_804affe8, 1);
            m->data = d24d_message_vtable_8040db38;
            d24d_message_post_8016239c(m);
        }
        {
            Ptr32<d24d_Plain> m = (Ptr32<d24d_Plain>)d24d_arena_alloc_801613f0(d24d_arena_804b1754, 8);
            m->id = d24d_message_id_8015f5a0(&d24d_key_804b0010, 1);
            m->data = d24d_message_vtable_8040db38;
            d24d_message_post_8016239c(m);
        }
        {
            Ptr32<d24d_Plain> m = (Ptr32<d24d_Plain>)d24d_arena_alloc_801613f0(d24d_arena_804b1754, 8);
            m->id = d24d_message_id_8015f5a0(&d24d_key_804aff98, 1);
            m->data = d24d_message_vtable_8040db38;
            d24d_message_post_8016239c(m);
        }
        {
            Ptr32<d24d_Plain> m = (Ptr32<d24d_Plain>)d24d_arena_alloc_801613f0(d24d_arena_804b1754, 8);
            m->id = d24d_message_id_8015f5a0(&d24d_key_804b0008, 1);
            m->data = d24d_message_vtable_8040db38;
            d24d_message_post_8016239c(m);
        }
    }
    if (d24d_message_is_8015f65c(id, &d24d_key_804affb0)) { self->started = 1; self->enabled = 1; }
    if (d24d_message_is_8015f65c(id, &d24d_key_804affa0)) self->enabled = 1;
    if (d24d_message_is_8015f65c(id, &d24d_key_804affa8)) self->enabled = 0;
    }
    return d24d_scene_base_8015fb34(self, msg);
}


