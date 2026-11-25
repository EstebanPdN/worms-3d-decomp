#include "w3d_ptr.h"
#line 1 "s2_script_messages.cpp"
/* Lua message handlers. Layouts record observed fields only. */
extern "C" {
struct S2MessageScript { unsigned char pad00[68]; Ptr32<void> lua; };
struct S2MessageString { Ptr32<char> text; unsigned int storage; };
struct S2MessageId { unsigned short value; unsigned char unknown[6]; };
struct S2Message { unsigned short id; unsigned short unknown; Ptr32<void> vtable; };
int lua_gettop(Ptr32<void>);
void lua_settop(Ptr32<void>, int);
int lua_isstring(Ptr32<void>, int);
int lua_isnumber(Ptr32<void>, int);
Ptr32<const char> lua_tostring(Ptr32<void>, int);
float lua_tonumber(Ptr32<void>, int);
void w3d_fn_801022ec(Ptr32<S2MessageScript>, Ptr32<const char>);
Ptr32<void> w3d_string_from_text(Ptr32<S2MessageString>, Ptr32<const char>);
Ptr32<void> w3d_string_default(Ptr32<S2MessageString>);
void w3d_string_format(Ptr32<S2MessageString>, Ptr32<const char>, ...);
void w3d_string_base_finish(Ptr32<S2MessageString>);
void w3d_string_release(Ptr32<S2MessageString>);
int w3d_message_find_id(Ptr32<const char>, Ptr32<S2MessageId>);
Ptr32<S2Message> w3d_fn_801613f0(Ptr32<void>, int);
int w3d_message_post_current(Ptr32<S2Message>);
Ptr32<S2Message> w3d_message_float_init(Ptr32<S2Message>, unsigned short, float);
Ptr32<S2Message> w3d_message_int_init(Ptr32<S2Message>, unsigned short, int);
Ptr32<S2Message> w3d_message_string_init(Ptr32<S2Message>, unsigned short, Ptr32<const char>);
extern Ptr32<void> w3d_obj_804b1754;
extern unsigned char w3d_obj_8040db38[];
extern const char w3d_str_80398a08[], w3d_str_80398a40[], w3d_str_80398a6c[];
extern const char w3d_str_80398a90[], w3d_str_80398ad0[];
extern const char w3d_str_80398b00[], w3d_str_80398b3c[];
extern const char w3d_str_80398b6c[], w3d_str_80398bac[];

int w3d_script_send_plain_8010109c(Ptr32<S2MessageScript> self)
{
    int count = lua_gettop(self->lua);
    if (count != 1) {
        w3d_fn_801022ec(self, w3d_str_80398a08);
        lua_settop(self->lua, ~count);
        return 0;
    }
    if (!lua_isstring(self->lua, -1)) {
        w3d_fn_801022ec(self, w3d_str_80398a40);
        lua_settop(self->lua, -2);
        return 0;
    }
    struct { S2MessageString name; S2MessageId id; S2MessageString error; } local;
    Ptr32<const char> argument = lua_tostring(self->lua, -1);
    w3d_string_from_text(&local.name, argument);
    Ptr32<S2MessageString> name = &local.name;
    if (w3d_message_find_id(local.name.text, &local.id) >= 0) {
        Ptr32<S2Message> message = w3d_fn_801613f0(w3d_obj_804b1754, 8);
        unsigned short value = local.id.value;
        message->vtable = w3d_obj_8040db38;
        message->id = value;
        w3d_message_post_current(message);
        lua_settop(self->lua, -2);
    } else {
        w3d_string_default(&local.error);
        w3d_string_format(&local.error, w3d_str_80398a6c, w3d::VA(local.name.text));
        w3d_fn_801022ec(self, local.error.text);
        lua_settop(self->lua, -2);
        w3d_string_base_finish(&local.error);
        w3d_string_release(&local.error);
    }
    w3d_string_base_finish(name);
    w3d_string_release(name);
    return 0;
}


int w3d_script_send_float_80101218(Ptr32<S2MessageScript> self)
{
    int count = lua_gettop(self->lua);
    if (count != 2) {
        w3d_fn_801022ec(self, w3d_str_80398a90);
        lua_settop(self->lua, ~count);
        return 0;
    }
    if (!lua_isstring(self->lua, -2) || !lua_isnumber(self->lua, -1)) {
        w3d_fn_801022ec(self, w3d_str_80398ad0);
        lua_settop(self->lua, -3);
        return 0;
    }
    struct { S2MessageString name; S2MessageId id; S2MessageString error; } local;
    Ptr32<const char> argument = lua_tostring(self->lua, -2);
    w3d_string_from_text(&local.name, argument);
    Ptr32<S2MessageString> name = &local.name;
    if (w3d_message_find_id(local.name.text, &local.id) >= 0) {
        Ptr32<S2Message> message = w3d_fn_801613f0(w3d_obj_804b1754, 12);
        unsigned short value = local.id.value;
        w3d_message_post_current(w3d_message_float_init(message, value, lua_tonumber(self->lua, -1)));
        lua_settop(self->lua, -3);
    } else {
        w3d_string_default(&local.error);
        w3d_string_format(&local.error, w3d_str_80398a6c, w3d::VA(local.name.text));
        w3d_fn_801022ec(self, local.error.text);
        lua_settop(self->lua, -3);
        w3d_string_base_finish(&local.error);
        w3d_string_release(&local.error);
    }
    w3d_string_base_finish(name);
    w3d_string_release(name);
    return 0;
}


int w3d_script_send_int_801013b0(Ptr32<S2MessageScript> self)
{
    int count = lua_gettop(self->lua);
    if (count != 2) {
        w3d_fn_801022ec(self, w3d_str_80398b00);
        lua_settop(self->lua, -3);
        return 0;
    }
    if (!lua_isstring(self->lua, -2) || !lua_isnumber(self->lua, -1)) {
        w3d_fn_801022ec(self, w3d_str_80398b3c);
        lua_settop(self->lua, -3);
        return 0;
    }
    struct { S2MessageString name; S2MessageId id; S2MessageString error; } local;
    Ptr32<const char> argument = lua_tostring(self->lua, -2);
    w3d_string_from_text(&local.name, argument);
    Ptr32<S2MessageString> name = &local.name;
    if (w3d_message_find_id(local.name.text, &local.id) >= 0) {
        Ptr32<S2Message> message = w3d_fn_801613f0(w3d_obj_804b1754, 12);
        unsigned short value = local.id.value;
        w3d_message_post_current(w3d_message_int_init(message, value, (int)lua_tonumber(self->lua, -1)));
        lua_settop(self->lua, -3);
    } else {
        w3d_string_default(&local.error);
        w3d_string_format(&local.error, w3d_str_80398a6c, w3d::VA(local.name.text));
        w3d_fn_801022ec(self, local.error.text);
        lua_settop(self->lua, -3);
        w3d_string_base_finish(&local.error);
        w3d_string_release(&local.error);
    }
    w3d_string_base_finish(name);
    w3d_string_release(name);
    return 0;
}


int w3d_script_send_string_80101550(Ptr32<S2MessageScript> self)
{
    int count = lua_gettop(self->lua);
    if (count != 2) {
        w3d_fn_801022ec(self, w3d_str_80398b6c);
        lua_settop(self->lua, ~count);
        return 0;
    }
    if (!lua_isstring(self->lua, -2) || !lua_isstring(self->lua, -1)) {
        w3d_fn_801022ec(self, w3d_str_80398bac);
        lua_settop(self->lua, -3);
        return 0;
    }
    struct { S2MessageString name; S2MessageId id; S2MessageString error; } local;
    Ptr32<const char> argument = lua_tostring(self->lua, -2);
    w3d_string_from_text(&local.name, argument);
    Ptr32<S2MessageString> name = &local.name;
    if (w3d_message_find_id(local.name.text, &local.id) >= 0) {
        Ptr32<S2Message> message = w3d_fn_801613f0(w3d_obj_804b1754, 12);
        unsigned short value = local.id.value;
        w3d_message_post_current(w3d_message_string_init(message, value, lua_tostring(self->lua, -1)));
        lua_settop(self->lua, -3);
    } else {
        w3d_string_default(&local.error);
        w3d_string_format(&local.error, w3d_str_80398a6c, w3d::VA(local.name.text));
        w3d_fn_801022ec(self, local.error.text);
        lua_settop(self->lua, -3);
        w3d_string_base_finish(&local.error);
        w3d_string_release(&local.error);
    }
    w3d_string_base_finish(name);
    w3d_string_release(name);
    return 0;
}

}


