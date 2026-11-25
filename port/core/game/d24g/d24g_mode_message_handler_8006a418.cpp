#include "w3d_ptr.h"
#line 1 "d24g_mode_message_handler_8006a418.cpp"
/* Worms 3D GameCube PAL 0x8006a418. Front-end message handler: on the start message runs the base handler and 0x8006c4a8; otherwise dispatches cached message ids: land theme and time of day settings, pause flags, UI creation by type, mode changes, new game reset, level selection and load, pause and movie control, relays and an activation bit; falls back to the base handler and otherwise returns 0. Field and type names are inferred from the original instructions; strings and globals are external views of original data. */
struct String;
extern "C" void string_finish_8020c5c4(Ptr32<String>);
extern "C" void string_release_80341588(Ptr32<String>);
struct String {
    Ptr32<char> text;
    template <class W3dU> String(Ptr32<W3dU> w3d_p) : String((const char *)w3d_p.get()) {}
 String(const char *);
    ~String() { string_finish_8020c5c4(this); string_release_80341588(this); }
    String(const String &);
};
struct MessageCache { unsigned short id; unsigned char unknown[6]; };
struct Message { unsigned short id; Ptr32<const void> vtable; };
struct Msg { unsigned short id; unsigned short Id() const { return id; } };
inline bool operator==(const String &a, const char *b);
struct Key { Ptr32<const char> text; };
struct App { char u0[76]; unsigned flags; char u80[108]; unsigned options; };
struct Other { char u[96]; unsigned flags; };
struct Bits { unsigned int rest:31; unsigned int active:1; };
struct Self { char u0[188]; char names[20]; int state; int mode; char u216[24]; union { unsigned flags; Bits bits; }; };
extern Ptr32<App> app_804b1788;
extern Ptr32<Other> other_804aac54;
extern Ptr32<void> arena_804b1754;
extern char vt_8040db38[];
extern unsigned char t_8040e1b8[], t_8040e5d8[], t_8040f518[], t_8040f958[], t_8040ea90[], t_80410160[], t_80410298[], t_804107a8[];
extern MessageCache c_804ad75c, c_804ad764, c_804ad82c, c_804ad734, c_804ad6ac, c_804ad6b4, c_804ad6bc, c_804ad6c4, c_804ad6cc, c_804ad6d4, c_804ad6dc, c_804ad6e4, c_804ad6f4, c_804ad7cc, c_804ad71c, c_804ad864, c_804ad724, c_804ad704, c_804ad72c, c_804ad6fc, c_804ad76c, c_804ad70c, c_804ad7e4, c_804ad7dc, c_804ad7ec, c_804ad77c, c_804ad7d4, c_804ad714, c_804ad804, c_804ad794;
extern const char s_8037ba54[], s_8037ba60[], s_8037baa4[], s_8037baf0[], s_8037bb04[], s_8037bb14[], s_8037bb18[], s_8037bb28[], s_8037bb38[], s_8037bb44[], s_8037bb4c[], s_8037bb54[], s_8037bb64[];
extern "C" int base_handle_8016293c(Ptr32<Self>, Ptr32<Msg>);
extern "C" void start_8006c4a8(Ptr32<Self>);
extern "C" int id_equals_8015f65c(int, Ptr32<MessageCache>);
extern "C" int cache_equals_8015f620(Ptr32<MessageCache>, int);
extern "C" Ptr32<const char> msg_text_8010a8fc(Ptr32<Msg>);
extern "C" void upper_8020c2e8(Ptr32<String>);
extern "C" int write_str_800fc550(Ptr32<Key>, Ptr32<const char>);
extern "C" int write_bool_800fc43c(Ptr32<Key>, int);
extern "C" int read_str_800fc2b0(Ptr32<Key>, Ptr32<Ptr32<const char>>);
extern "C" void apply_land_8006d854(Ptr32<Self>);
extern "C" void resume_8006ac40(Ptr32<Self>);
extern "C" void create_ui_8006d4cc(Ptr32<Self>, Ptr32<void>);
extern "C" void finish_8006eebc(Ptr32<Self>);
extern "C" void set_mode_8006ab48(Ptr32<Self>, int, int, int, int);
extern "C" int message_id_8015f5a0(Ptr32<MessageCache>, int);
extern "C" Ptr32<void> arena_alloc_801613f0(Ptr32<void>, int);
extern "C" int message_post_8016239c(Ptr32<void>);
extern "C" Ptr32<void> message_string_8010a8e0(Ptr32<void>, int, Ptr32<const char>);
extern "C" void new_game_8006e784(Ptr32<Self>);
extern "C" int strcmp(Ptr32<const char>, Ptr32<const char>);
extern "C" int level_load_8006d610(Ptr32<Self>);
inline bool operator==(const String &a, const char *b) { return strcmp(a.text, b) == 0; }
extern "C" void pause_8006bf7c(Ptr32<Self>);
extern "C" void movie_stop_8006be38(Ptr32<Self>);
extern "C" int msg_int_800a830c(Ptr32<Msg>);
extern "C" void names_clear_800c4604(Ptr32<void>);
#define IS(c) cache_equals_8015f620(&c, id)
#define WRITE(name, value) { Key key; key.text = name; write_str_800fc550(&key, value); }
extern "C" int w3d_d24g_mode_message_handler_8006a418(Ptr32<Self> self, Ptr32<Msg> msg)
{
    unsigned short id = msg->id;
    if (id == 64) {
        if (base_handle_8016293c(self, msg) >= 0) {
            start_8006c4a8(self);
            return 0;
        }
        return 0x80004005;
    }
    if (id_equals_8015f65c(id, &c_804ad75c)) {
        String text(msg_text_8010a8fc(msg));
        upper_8020c2e8(&text);
        WRITE(s_8037ba54, text.text)
        apply_land_8006d854(self);
    } else if (id_equals_8015f65c(msg->Id(), &c_804ad764)) {
        String text(msg_text_8010a8fc(msg));
        upper_8020c2e8(&text);
        WRITE(s_8037ba60, text.text)
        apply_land_8006d854(self);
    } else if (IS(c_804ad82c)) {
        unsigned flags = self->flags;
        if (flags & 0x20000000) {
            flags &= ~0x20000000;
            self->flags = flags;
            if (flags & 0x40000000) resume_8006ac40(self);
        } else if (flags & 0x10000000) {
            flags &= ~0x10000000;
            self->flags = flags;
        }
    } else if (IS(c_804ad734)) {
        finish_8006eebc(self);
    } else if (IS(c_804ad6ac)) {
        create_ui_8006d4cc(self, t_8040e1b8);
    } else if (IS(c_804ad6b4)) {
        create_ui_8006d4cc(self, t_8040e5d8);
    } else if (IS(c_804ad6bc)) {
        create_ui_8006d4cc(self, t_8040f518);
    } else if (IS(c_804ad6c4)) {
        create_ui_8006d4cc(self, t_8040f958);
    } else if (IS(c_804ad6cc)) {
        create_ui_8006d4cc(self, t_8040ea90);
    } else if (IS(c_804ad6d4)) {
        create_ui_8006d4cc(self, t_80410160);
    } else if (IS(c_804ad6dc)) {
        create_ui_8006d4cc(self, t_80410298);
    } else if (IS(c_804ad6e4)) {
        create_ui_8006d4cc(self, t_804107a8);
    } else if (IS(c_804ad6f4)) {
    } else if (IS(c_804ad7cc)) {
        self->flags &= ~0x02000000;
    } else if (IS(c_804ad71c) || IS(c_804ad864)) {
        finish_8006eebc(self);
    } else if (IS(c_804ad724)) {
        if (self->state == 7) {
            Ptr32<const char> movie;
            { Key key; key.text = s_8037baa4; read_str_800fc2b0(&key, &movie); }
            if (*movie && (app_804b1788->options & 64))
                set_mode_8006ab48(self, 8, 1, 1, 1);
            else
                set_mode_8006ab48(self, 9, 1, 1, 1);
        } else {
            set_mode_8006ab48(self, 6, 1, 1, 1);
        }
    } else if (IS(c_804ad704)) {
        set_mode_8006ab48(self, 6, 1, 0, 1);
    } else if (IS(c_804ad72c)) {
        { Key key; key.text = s_8037baf0; write_bool_800fc43c(&key, 0); }
        WRITE(s_8037bb04, s_8037bb14)
        WRITE(s_8037bb18, s_8037bb14)
        WRITE(s_8037bb28, s_8037bb14)
        WRITE(s_8037bb38, s_8037bb14)
        other_804aac54->flags |= 0x01000000;
        {
            Ptr32<Message> m = (Ptr32<Message>)arena_alloc_801613f0(arena_804b1754, 8);
            m->id = message_id_8015f5a0(&c_804ad804, 1);
            m->vtable = vt_8040db38;
            message_post_8016239c(m);
        }
        {
            Ptr32<void> m = arena_alloc_801613f0(arena_804b1754, 12);
            message_post_8016239c(message_string_8010a8e0(m, (unsigned short)message_id_8015f5a0(&c_804ad794, 1), s_8037bb44));
        }
        new_game_8006e784(self);
        set_mode_8006ab48(self, 7, 1, 1, 1);
    } else if (IS(c_804ad6fc)) {
        app_804b1788->flags &= 0x7fffffff;
    } else if (id_equals_8015f65c(msg->Id(), &c_804ad76c)) {
        String text(msg_text_8010a8fc(msg));
        if (text == s_8037bb4c) {
            Ptr32<const char> level;
            { Key key; key.text = s_8037bb54; read_str_800fc2b0(&key, &level); }
            WRITE(s_8037bb64, level)
        } else {
            Key key;
            key.text = s_8037bb64;
            write_str_800fc550(&key, msg_text_8010a8fc(msg));
        }
        level_load_8006d610(self);
    } else if (id_equals_8015f65c(msg->Id(), &c_804ad70c)) {
    } else if (id_equals_8015f65c(msg->Id(), &c_804ad7e4) || id_equals_8015f65c(msg->Id(), &c_804ad7dc)) {
        pause_8006bf7c(self);
    } else if (id_equals_8015f65c(msg->Id(), &c_804ad7ec)) {
        movie_stop_8006be38(self);
    } else if (id_equals_8015f65c(msg->Id(), &c_804ad77c)) {
        Ptr32<void> m = arena_alloc_801613f0(arena_804b1754, 12);
        message_post_8016239c(message_string_8010a8e0(m, (unsigned short)message_id_8015f5a0(&c_804ad734, 1), msg_text_8010a8fc(msg)));
    } else if (id_equals_8015f65c(msg->Id(), &c_804ad7d4)) {
        self->bits.active = msg_int_800a830c(msg) != 0;
    } else if (id_equals_8015f65c(msg->Id(), &c_804ad714)) {
        if ((self->flags & 0x00200000) && self->state == 7 && self->mode == 7) {
            set_mode_8006ab48(self, 6, 1, 1, 1);
            names_clear_800c4604(self->names);
        }
    } else {
        return base_handle_8016293c(self, msg);
    }
    return 0;
}


