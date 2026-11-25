#include "w3d_ptr.h"
#line 1 "d34b_logic_message_800882b0.cpp"
// GWMP8P rev0 0x800882b0. Game logic message handler.
/* Game logic message handler (0x800882b0). */
struct MessageCache { unsigned short id; unsigned char unknown[6]; };
struct Message { unsigned short id; };
struct Object;
struct ObjectVtable {
    Ptr32<void> unknown00[3];
    Ptr32<void (Ptr32<Object>)> retain;   /* +12 */
    Ptr32<void (Ptr32<Object>)> release;  /* +16 */
};
struct Object { Ptr32<ObjectVtable> vtable; };
struct Worm { char unknown00[220]; float height; char unknown224[164]; float top; };
struct Weapon { char unknown00[55]; signed char a; signed char b; };
struct Logic { char unknown00[20]; int id; char unknown24[240]; Ptr32<void> object264; char unknown268[20]; int w288; int w292; char unknown296[68]; int w364, w368, w372; };
struct Player { char unknown00[132]; int value; };
struct PropertyKey { Ptr32<const char> name; };
struct Descriptor_80178474 {
    Ptr32<void> value;
    unsigned tag;
    Descriptor_80178474() : value(0), tag(58280) {}
    ~Descriptor_80178474();
};
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
struct Handle {
    Ptr32<Object> value;
    Handle() : value(0) {}
    Handle(const Handle &);
    ~Handle() { if (value) value->vtable->release(value); }
    void assign(Ptr32<Object> next) {
        if (next) next->vtable->retain(next);
        if (value) value->vtable->release(value);
        value = next;
    }
};
extern "C" int w3d_equals_8015f65c(unsigned short, Ptr32<MessageCache>);
extern "C" int w3d_base_8016293c(Ptr32<Logic>, Ptr32<Message>);
extern "C" int w3d_lookup_800fc1b0(Ptr32<PropertyKey>, Ptr32<Ptr32<Object>>);
extern "C" int w3d_read_text_800fc2b0(Ptr32<PropertyKey>, Ptr32<Ptr32<const char>>);
extern "C" int w3d_read_scheme_800fc330(Ptr32<PropertyKey>, Ptr32<int>);
extern "C" int w3d_read_int_800fc230(Ptr32<PropertyKey>, Ptr32<int>);
extern "C" int w3d_write_int_800fc43c(Ptr32<PropertyKey>, int);
extern "C" int w3d_write_text_800fc550(Ptr32<PropertyKey>, Ptr32<const char>);
extern "C" int w3d_write_float_800fc4c8(Ptr32<PropertyKey>, float);
extern "C" Ptr32<Object> w3d_identity_80341584(Ptr32<Object>);
extern "C" Ptr32<Worm> w3d_worm_801797b4(Ptr32<Object>);
extern "C" int w3d_land_point_8008dd54(Ptr32<Logic>, Ptr32<Vec>, Vec, float);
extern "C" void w3d_spawn_8008bc78(Ptr32<Logic>, Ptr32<Vec>);
extern "C" void w3d_spawn_8008df50(Ptr32<Logic>, Ptr32<Vec>);
extern "C" int w3d_get_8010a8fc(Ptr32<Message>);
extern "C" void w3d_point_8008bad0(Ptr32<Logic>, int, Ptr32<Vec>);
extern "C" Ptr32<void> w3d_cast_803426b4(Ptr32<void>);
extern "C" int w3d_value_80178c48(Ptr32<void>);
extern "C" Ptr32<Player> w3d_player_800fc6dc(int);
extern "C" int w3d_msg_value_80125ff8(Ptr32<Message>);
extern "C" void w3d_consume_8008aacc(Ptr32<Logic>, int);
extern "C" Ptr32<void> w3d_create_8020b680(Ptr32<void>);
extern "C" int w3d_post_80164514(Ptr32<void>, Ptr32<void>, int);
extern "C" int w3d_strcmp_802ef234(Ptr32<const char>, Ptr32<const char>);
extern "C" int w3d_load_800fd504(int, int, int);
extern "C" Ptr32<Object> w3d_as_80179598(Ptr32<Object>, Ptr32<Descriptor_80178474>);
extern "C" void w3d_apply_8025cb4c(Ptr32<Object>, int);
extern "C" int w3d_atoi_802ed89c(Ptr32<const char>);
extern "C" int w3d_prop_8025cbe0(Ptr32<Object>, int);
extern "C" void w3d_prop_8025d020(Ptr32<Object>, int, int);
extern "C" int w3d_format_80343b0c(Ptr32<char>, Ptr32<const char>, ...);
extern "C" void w3d_clear_8025ca78(Ptr32<Object>);
extern "C" int w3d_random_80162ba8();
extern "C" float w3d_random_80162bc8();
extern "C" void w3d_d2924_800d2924();
extern "C" void w3d_d26b_logic_init_80088f80(Ptr32<Logic>);
extern "C" void w3d_game_over_8008ad34(Ptr32<Logic>, Ptr32<Message>);
extern Ptr32<void> w3d_system_804b178c;
extern float w3d_height_804b1938;
extern float w3d_zero_8037d79c[];
extern float w3d_five_8037d7a0[];
extern Ptr32<const char> w3d_table_803eb63c[];
extern char w3d_type_8040ecd8[];
extern const char s_8037d1d4[], s_8037d6c8[], s_8037d6e0[], s_8037d6f8[], s_8037d714[], s_8037d730[], s_8037d774[], s_8037d788[];
extern MessageCache c_804adc94, c_804adc8c, c_804adc7c, c_804adc74, c_804adc44, c_804adc4c, c_804adc54, c_804adc6c, c_804adc64, c_804adc5c, c_804adc84, c_804adbc4, c_804adba4, c_804adc14, c_804add4c, c_804add54, c_804adbac, c_804adbe4, c_804adda4, c_804adbec, c_804adbf4, c_804adbfc, c_804adc04, c_804adc9c, c_804adcb4, c_804adcbc, c_804adcc4, c_804adc0c, c_804add24, c_804adbb4, c_804adbbc, c_804addac, c_804adce4, c_804adc1c, c_804adc24, c_804adc34, c_804adc2c, c_804adc3c, c_804adca4, c_804adcac, c_804adcfc, c_804add04, c_804add0c, c_804add14, c_804adbd4, c_804adbcc, c_804add2c, c_804add34, c_804add3c, c_804add44, c_804adccc, c_804add7c, c_804add84, c_804add94, c_804add5c;
extern "C" void f_80088f24(Ptr32<Logic>);
extern "C" void f_80089a00(Ptr32<Logic>);
extern "C" void f_80089bd4(Ptr32<Logic>);
extern "C" void f_80089eec(Ptr32<Logic>);
extern "C" void f_8008e1e0(Ptr32<Logic>);
extern "C" void f_8008a044(Ptr32<Logic>);
extern "C" void f_8008a2a0(Ptr32<Logic>);
extern "C" void f_8008cf14(Ptr32<Logic>);
extern "C" void f_8008a848(Ptr32<Logic>);
extern "C" void f_8008c6c0(Ptr32<Logic>);
extern "C" void f_8008a8b4(Ptr32<Logic>);
extern "C" void f_8008bffc(Ptr32<Logic>);
extern "C" void f_8008c280(Ptr32<Logic>);
extern "C" void f_8008c154(Ptr32<Logic>);
extern "C" void f_8008c2fc(Ptr32<Logic>);
extern "C" void f_8008c718(Ptr32<Logic>);
extern "C" void f_8008991c(Ptr32<Logic>);
extern "C" void f_8008e144(Ptr32<Logic>);
extern "C" void f_8008c3a8(Ptr32<Logic>, Ptr32<Message>);
extern "C" void f_8008c49c(Ptr32<Logic>, Ptr32<Message>);
extern "C" void f_8008c590(Ptr32<Logic>, Ptr32<Message>);
extern "C" void f_8008c628(Ptr32<Logic>, Ptr32<Message>);
extern "C" void f_8008bf28(Ptr32<Logic>, Ptr32<Message>);
extern "C" void f_8008c858(Ptr32<Logic>, Ptr32<Message>);
extern "C" void f_8008da7c(Ptr32<Logic>, Ptr32<Message>);
extern "C" void f_8008db88(Ptr32<Logic>, Ptr32<Message>);
extern "C" void f_8008e0cc(Ptr32<Logic>, Ptr32<Message>);
extern "C" void f_8008e108(Ptr32<Logic>, Ptr32<Message>);
#define KEY(s) PropertyKey key; key.name = s
extern "C" int d34b_logic_message_800882b0(Ptr32<Logic> self, Ptr32<Message> msg)
{
    unsigned short id = msg->id;
    if (id == 64) {
        if (w3d_base_8016293c(self, msg) >= 0) {
            w3d_d26b_logic_init_80088f80(self);
            return 0;
        }
        return 0x80004005;
    }
    if (w3d_equals_8015f65c(id, &c_804adc94) || w3d_equals_8015f65c(id, &c_804adc8c) || w3d_equals_8015f65c(id, &c_804adc7c) || w3d_equals_8015f65c(id, &c_804adc74) || w3d_equals_8015f65c(id, &c_804adc44) || w3d_equals_8015f65c(id, &c_804adc4c) || w3d_equals_8015f65c(id, &c_804adc54) || w3d_equals_8015f65c(id, &c_804adc6c) || w3d_equals_8015f65c(id, &c_804adc64) || w3d_equals_8015f65c(id, &c_804adc5c) || w3d_equals_8015f65c(id, &c_804adc84)) {
        w3d_game_over_8008ad34(self, msg);
    } else if (w3d_equals_8015f65c(id, &c_804adbc4)) {
        f_80088f24(self);
    } else if (w3d_equals_8015f65c(id, &c_804adba4)) {
        f_80089a00(self);
    } else if (w3d_equals_8015f65c(id, &c_804adc14)) {
        Vec point;
        w3d_point_8008bad0(self, w3d_get_8010a8fc(msg), &point);
        w3d_spawn_8008bc78(self, &point);
    } else if (w3d_equals_8015f65c(id, &c_804add4c)) {
        Handle worm;
        { KEY(s_8037d1d4); w3d_lookup_800fc1b0(&key, &worm.value); }
        Ptr32<Worm> w = w3d_worm_801797b4(w3d_identity_80341584(worm.value));
        Vec point;
        Vec from(0.0f, w->height, 0.0f);
        if (w3d_land_point_8008dd54(self, &point, from, w->top + 5.0f)) w3d_spawn_8008bc78(self, &point);
    } else if (w3d_equals_8015f65c(id, &c_804add54)) {
        Vec point;
        float h = w3d_height_804b1938;
        Vec from(0.0f, h, 0.0f);
        if (w3d_land_point_8008dd54(self, &point, from, h + 5.0f)) w3d_spawn_8008df50(self, &point);
    } else if (w3d_equals_8015f65c(id, &c_804adbac)) {
        f_80089bd4(self);
    } else if (w3d_equals_8015f65c(id, &c_804adbe4)) {
        f_80089eec(self);
    } else if (w3d_equals_8015f65c(id, &c_804adda4)) {
        f_8008e1e0(self);
    } else if (w3d_equals_8015f65c(id, &c_804adbec)) {
        f_8008a044(self);
    } else if (w3d_equals_8015f65c(id, &c_804adbf4)) {
        f_8008a2a0(self);
    } else if (w3d_equals_8015f65c(id, &c_804adbfc)) {
        f_8008cf14(self);
    } else if (w3d_equals_8015f65c(id, &c_804adc04)) {
        f_8008a848(self);
    } else if (w3d_equals_8015f65c(id, &c_804adc9c)) {
        f_8008c3a8(self, msg);
    } else if (w3d_equals_8015f65c(id, &c_804adcb4)) {
        f_8008c49c(self, msg);
    } else if (w3d_equals_8015f65c(id, &c_804adcbc)) {
        f_8008c590(self, msg);
    } else if (w3d_equals_8015f65c(id, &c_804adcc4)) {
        f_8008c628(self, msg);
    } else if (w3d_equals_8015f65c(id, &c_804adc0c)) {
        self->w288 = 0;
        self->w364 = 0;
        self->w368 = 0;
        self->w372 = 0;
        f_8008c6c0(self);
    } else if (w3d_equals_8015f65c(id, &c_804add24)) {
        self->w292 = 1;
    } else if (w3d_equals_8015f65c(id, &c_804adbb4)) {
        f_8008a8b4(self);
    } else if (w3d_equals_8015f65c(id, &c_804adbbc)) {
        w3d_consume_8008aacc(self, w3d_player_800fc6dc(w3d_value_80178c48(w3d_cast_803426b4(self->object264)))->value);
    } else if (w3d_equals_8015f65c(id, &c_804addac)) {
        w3d_consume_8008aacc(self, w3d_msg_value_80125ff8(msg));
    } else if (w3d_equals_8015f65c(id, &c_804adce4)) {
        Ptr32<void> m = w3d_create_8020b680(w3d_type_8040ecd8);
        w3d_post_80164514(w3d_system_804b178c, m, self->id);
    } else if (w3d_equals_8015f65c(id, &c_804adc1c)) {
        f_8008bf28(self, msg);
    } else if (w3d_equals_8015f65c(id, &c_804adc24)) {
        f_8008bffc(self);
    } else if (w3d_equals_8015f65c(id, &c_804adc34)) {
        f_8008c280(self);
    } else if (w3d_equals_8015f65c(id, &c_804adc2c)) {
        f_8008c154(self);
    } else if (w3d_equals_8015f65c(id, &c_804adc3c)) {
        f_8008c2fc(self);
    } else if (w3d_equals_8015f65c(id, &c_804adca4)) {
        f_8008c718(self);
    } else if (w3d_equals_8015f65c(id, &c_804adcac)) {
        f_8008c858(self, msg);
    } else if (w3d_equals_8015f65c(id, &c_804adcfc) || w3d_equals_8015f65c(id, &c_804add04)) {
        f_8008991c(self);
    } else if (w3d_equals_8015f65c(id, &c_804add0c)) {
        f_8008da7c(self, msg);
    } else if (w3d_equals_8015f65c(id, &c_804add14)) {
        f_8008db88(self, msg);
    } else if (w3d_equals_8015f65c(id, &c_804adbd4)) {
        int index;
        { KEY(s_8037d6c8); w3d_read_int_800fc230(&key, &index); }
        { KEY(s_8037d6e0); w3d_write_text_800fc550(&key, w3d_table_803eb63c[index]); }
    } else if (w3d_equals_8015f65c(id, &c_804adbcc)) {
        Ptr32<const char> text = 0;
        { KEY(s_8037d6e0); w3d_read_text_800fc2b0(&key, &text); }
        int i = 0;
        while (w3d_table_803eb63c[i] && w3d_strcmp_802ef234(w3d_table_803eb63c[i], text)) i++;
        { KEY(s_8037d6c8); w3d_write_int_800fc43c(&key, i); }
    } else if (w3d_equals_8015f65c(id, &c_804add2c)) {
        int x = w3d_get_8010a8fc(msg);
        if (w3d_load_800fd504(x, 4, 2) < 0) w3d_load_800fd504(x, 4, 1);
    } else if (w3d_equals_8015f65c(id, &c_804add34)) {
        PropertyKey k1, k2;
        int amount = 0;
        { KEY(s_8037d6f8); w3d_read_text_800fc2b0(&key, &k1.name); }
        { KEY(s_8037d714); w3d_read_text_800fc2b0(&key, &k2.name); }
        w3d_read_scheme_800fc330(&k2, &amount);
        int value = amount;
        Descriptor_80178474 desc;
        Handle held;
        { Handle tmp; w3d_lookup_800fc1b0(&k1, &tmp.value); held.assign(w3d_identity_80341584(tmp.value)); }
        Ptr32<Object> inv = w3d_as_80179598(held.value, &desc);
        amount = (int)w3d::H(inv);
        w3d_apply_8025cb4c(inv, value);
    } else if (w3d_equals_8015f65c(id, &c_804add3c)) {
        PropertyKey k1;
        Ptr32<const char> text;
        { KEY(s_8037d6f8); w3d_read_text_800fc2b0(&key, &k1.name); }
        Ptr32<Object> inv = 0;
        { KEY(s_8037d714); w3d_read_text_800fc2b0(&key, &text); }
        Descriptor_80178474 desc;
        Handle held;
        { Handle tmp; w3d_lookup_800fc1b0(&k1, &tmp.value); held.assign(w3d_identity_80341584(tmp.value)); }
        inv = w3d_as_80179598(held.value, &desc);
        int n = w3d_atoi_802ed89c(text);
        int v = w3d_prop_8025cbe0(inv, n);
        if (v != -1) w3d_prop_8025d020(inv, n, (signed char)(v + 1));
    } else if (w3d_equals_8015f65c(id, &c_804add44)) {
        Descriptor_80178474 desc;
        Handle held;
        for (int i = 0; i <= 3; i++) {
            char name[128];
            Ptr32<char> s = name;
            s[0] = 0;
            w3d_format_80343b0c(s, s_8037d730, i);
            PropertyKey key;
            key.name = s;
            { Handle tmp; w3d_lookup_800fc1b0(&key, &tmp.value); held.assign(w3d_identity_80341584(tmp.value)); }
            Ptr32<Weapon> inv = (Ptr32<Weapon>)w3d_as_80179598(held.value, &desc);
            w3d_clear_8025ca78((Ptr32<Object>)inv);
            inv->b = -1;
            inv->a = -1;
        }
    } else if (w3d_equals_8015f65c(id, &c_804adccc)) {
        unsigned short seed = w3d_random_80162ba8();
        float f = w3d_random_80162bc8();
        { KEY(s_8037d774); w3d_write_int_800fc43c(&key, seed); }
        { KEY(s_8037d788); w3d_write_float_800fc4c8(&key, f); }
    } else if (w3d_equals_8015f65c(id, &c_804add7c)) {
        f_8008e0cc(self, msg);
    } else if (w3d_equals_8015f65c(id, &c_804add84)) {
        f_8008e108(self, msg);
    } else if (w3d_equals_8015f65c(id, &c_804add94)) {
        f_8008e144(self);
    } else if (w3d_equals_8015f65c(id, &c_804add5c)) {
        w3d_d2924_800d2924();
    }
    return w3d_base_8016293c(self, msg);
}


