#include "w3d_ptr.h"
#line 1 "d24g_frontend_update_8006c1b8.cpp"
/* Worms 3D GameCube PAL 0x8006c1b8. Front-end update: clears flag 0x00400000, steps 0x8006f0dc, and while the state equals the next state runs modes 0..9 (boot fade and callback, menu transitions by flag 0x02000000 and language, attract game start on timeout, return to the default menu when idle); otherwise sets flag 0x01000000. Returns 100. Field and type names are inferred from the original instructions; strings and globals are external views of original data. */
struct MessageCache { unsigned short id; unsigned char unknown[6]; };
struct Message { unsigned short id; Ptr32<const void> vtable; };
struct Key { Ptr32<const char> text; };
struct App { char u[76]; unsigned flags; };
struct Context { char u[52]; unsigned time; };
enum Mode { MODE0, MODE1, MODE2, MODE3, MODE4, MODE5, MODE6, MODE7, MODE8, MODE9, MODE10 };
struct Modes { char u0[208]; Mode state; Mode next; char u216[16]; unsigned wait; unsigned start; unsigned flags; };
extern "C" void step_8006f0dc(Ptr32<Modes>, unsigned);
extern "C" void set_mode_8006ab48(Ptr32<Modes>, int, int, int, int);
extern "C" void fade_out_80126ac0(Ptr32<App>);
extern "C" void set_byte_8015aee8(int);
extern "C" Ptr32<void> instance_80343994();
extern "C" void set_callback_801fdbb4(Ptr32<void>, Ptr32<void>);
extern "C" void finish_801ea57c();
extern "C" int language_80127b48();
extern "C" Ptr32<Context> context_80165254();
extern "C" int message_id_8015f5a0(Ptr32<MessageCache>, int);
extern "C" Ptr32<void> arena_alloc_801613f0(Ptr32<void>, int);
extern "C" int message_post_8016239c(Ptr32<void>);
extern "C" Ptr32<void> message_string_8010a8e0(Ptr32<void>, int, Ptr32<const char>);
extern "C" int select_slot_800a7e14(int, Ptr32<const char>);
extern "C" int read_800fc2b0(Ptr32<Key>, Ptr32<Ptr32<const char>>);
extern "C" Ptr32<const char> default_name_80127da4(Ptr32<App>);
extern "C" int strcmp(Ptr32<const char>, Ptr32<const char>);
extern "C" void names_clear_800c4604(Ptr32<void>);
extern "C" void callback_80069be0(Ptr32<void>);
extern Ptr32<App> app_804b1788;
extern Ptr32<void> arena_804b1754;
extern char vt_8040db38[];
extern int g_804abb5c, g_804abb48;
extern MessageCache msg_804ad86c, msg_804ad72c;
extern const char s_8037bf38[], s_8037bf44[], s_8037bf50[];
extern "C" int w3d_d24g_frontend_update_8006c1b8(Ptr32<Modes> self, unsigned time)
{
    self->flags &= ~0x00400000;
    step_8006f0dc(self, time);
    if (self->state == self->next) {
        switch (self->state) {
        case 0:
            if (time >= self->start) {
                Ptr32<App> app = app_804b1788;
                app->flags &= ~0x40000000;
                fade_out_80126ac0(app);
                set_byte_8015aee8(5);
                set_callback_801fdbb4(instance_80343994(), (Ptr32<void>)callback_80069be0);
                finish_801ea57c();
                set_mode_8006ab48(self, 1, 0, 0, 0);
            }
            break;
        case 1:
            if (!(self->flags & 0x02000000))
                set_mode_8006ab48(self, 2, 1, 0, 0);
            break;
        case 2:
            if (!(self->flags & 0x02000000)) {
                if (language_80127b48())
                    set_mode_8006ab48(self, 6, 1, 0, 1);
                else
                    set_mode_8006ab48(self, 5, 1, 0, 1);
            }
            break;
        case 3:
            set_mode_8006ab48(self, 5, 1, 1, 1);
            break;
        case 5:
            if ((int)self->flags < 0 && context_80165254()->time > self->wait) {
                self->flags |= 0x00200000;
                {
                    Ptr32<void> m = arena_alloc_801613f0(arena_804b1754, 12);
                    message_post_8016239c(message_string_8010a8e0(m, (unsigned short)message_id_8015f5a0(&msg_804ad86c, 1), s_8037bf38));
                }
                {
                    Ptr32<Message> m = (Ptr32<Message>)arena_alloc_801613f0(arena_804b1754, 8);
                    m->id = message_id_8015f5a0(&msg_804ad72c, 1);
                    m->vtable = vt_8040db38;
                    message_post_8016239c(m);
                }
                select_slot_800a7e14(7, s_8037bf44);
            }
            break;
        case 6:
            if ((int)self->flags < 0 && context_80165254()->time > self->wait && g_804abb5c == 0) {
                Key key;
                Ptr32<const char> menu;
                key.text = s_8037bf50;
                read_800fc2b0(&key, &menu);
                if (g_804abb48 == 0 && strcmp(default_name_80127da4(app_804b1788), menu) == 0) {
                    set_mode_8006ab48(self, 5, 1, 1, 1);
                    names_clear_800c4604((Ptr32<char>)self + 188);
                }
            }
            break;
        case 8:
            if (!(self->flags & 0x02000000))
                set_mode_8006ab48(self, 9, 1, 0, 0);
            break;
        case 9:
            if (!(self->flags & 0x02000000))
                set_mode_8006ab48(self, 6, 1, 0, 0);
            break;
        case 4:
        case 7:
        case 10:
            break;
        }
    } else {
        self->flags |= 0x01000000;
    }
    return 100;
}


