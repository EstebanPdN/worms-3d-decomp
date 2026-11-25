/* Lua message handlers. Layouts record observed fields only. */
extern "C" {
struct S2MessageScript { unsigned char pad00[68]; void *lua; };
struct S2MessageString { char *text; unsigned int storage; };
struct S2MessageId { unsigned short value; unsigned char unknown[6]; };
struct S2Message { unsigned short id; unsigned short unknown; void *vtable; };
int lua_gettop(void *);
void lua_settop(void *, int);
int lua_isstring(void *, int);
int lua_isnumber(void *, int);
const char *lua_tostring(void *, int);
float lua_tonumber(void *, int);
void w3d_fn_801022ec(S2MessageScript *, const char *);
void * w3d_string_from_text(S2MessageString *, const char *);
void * w3d_string_default(S2MessageString *);
void w3d_string_format(S2MessageString *, const char *, ...);
void w3d_string_base_finish(S2MessageString *);
void w3d_string_release(S2MessageString *);
int w3d_message_find_id(const char *, S2MessageId *);
S2Message *w3d_fn_801613f0(void *, int);
int w3d_message_post_current(S2Message *);
S2Message *w3d_message_float_init(S2Message *, unsigned short, float);
S2Message *w3d_message_int_init(S2Message *, unsigned short, int);
S2Message *w3d_message_string_init(S2Message *, unsigned short, const char *);
extern void *w3d_obj_804b1754;
extern unsigned char w3d_obj_8040db38[];
extern const char w3d_str_80398a08[], w3d_str_80398a40[], w3d_str_80398a6c[];
extern const char w3d_str_80398a90[], w3d_str_80398ad0[];
extern const char w3d_str_80398b00[], w3d_str_80398b3c[];
extern const char w3d_str_80398b6c[], w3d_str_80398bac[];

int w3d_script_send_plain_8010109c(S2MessageScript *self)
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
    const char *argument = lua_tostring(self->lua, -1);
    w3d_string_from_text(&local.name, argument);
    S2MessageString *name = &local.name;
    if (w3d_message_find_id(local.name.text, &local.id) >= 0) {
        S2Message *message = w3d_fn_801613f0(w3d_obj_804b1754, 8);
        unsigned short value = local.id.value;
        message->vtable = w3d_obj_8040db38;
        message->id = value;
        w3d_message_post_current(message);
        lua_settop(self->lua, -2);
    } else {
        w3d_string_default(&local.error);
        w3d_string_format(&local.error, w3d_str_80398a6c, local.name.text);
        w3d_fn_801022ec(self, local.error.text);
        lua_settop(self->lua, -2);
        w3d_string_base_finish(&local.error);
        w3d_string_release(&local.error);
    }
    w3d_string_base_finish(name);
    w3d_string_release(name);
    return 0;
}


int w3d_script_send_float_80101218(S2MessageScript *self)
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
    const char *argument = lua_tostring(self->lua, -2);
    w3d_string_from_text(&local.name, argument);
    S2MessageString *name = &local.name;
    if (w3d_message_find_id(local.name.text, &local.id) >= 0) {
        S2Message *message = w3d_fn_801613f0(w3d_obj_804b1754, 12);
        unsigned short value = local.id.value;
        w3d_message_post_current(w3d_message_float_init(message, value, lua_tonumber(self->lua, -1)));
        lua_settop(self->lua, -3);
    } else {
        w3d_string_default(&local.error);
        w3d_string_format(&local.error, w3d_str_80398a6c, local.name.text);
        w3d_fn_801022ec(self, local.error.text);
        lua_settop(self->lua, -3);
        w3d_string_base_finish(&local.error);
        w3d_string_release(&local.error);
    }
    w3d_string_base_finish(name);
    w3d_string_release(name);
    return 0;
}


int w3d_script_send_int_801013b0(S2MessageScript *self)
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
    const char *argument = lua_tostring(self->lua, -2);
    w3d_string_from_text(&local.name, argument);
    S2MessageString *name = &local.name;
    if (w3d_message_find_id(local.name.text, &local.id) >= 0) {
        S2Message *message = w3d_fn_801613f0(w3d_obj_804b1754, 12);
        unsigned short value = local.id.value;
        w3d_message_post_current(w3d_message_int_init(message, value, (int)lua_tonumber(self->lua, -1)));
        lua_settop(self->lua, -3);
    } else {
        w3d_string_default(&local.error);
        w3d_string_format(&local.error, w3d_str_80398a6c, local.name.text);
        w3d_fn_801022ec(self, local.error.text);
        lua_settop(self->lua, -3);
        w3d_string_base_finish(&local.error);
        w3d_string_release(&local.error);
    }
    w3d_string_base_finish(name);
    w3d_string_release(name);
    return 0;
}


int w3d_script_send_string_80101550(S2MessageScript *self)
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
    const char *argument = lua_tostring(self->lua, -2);
    w3d_string_from_text(&local.name, argument);
    S2MessageString *name = &local.name;
    if (w3d_message_find_id(local.name.text, &local.id) >= 0) {
        S2Message *message = w3d_fn_801613f0(w3d_obj_804b1754, 12);
        unsigned short value = local.id.value;
        w3d_message_post_current(w3d_message_string_init(message, value, lua_tostring(self->lua, -1)));
        lua_settop(self->lua, -3);
    } else {
        w3d_string_default(&local.error);
        w3d_string_format(&local.error, w3d_str_80398a6c, local.name.text);
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
