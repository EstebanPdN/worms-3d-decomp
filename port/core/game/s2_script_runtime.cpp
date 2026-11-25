#include "w3d_ptr.h"
#line 1 "s2_script_runtime.cpp"
/* Script debugger and error reporting; layouts follow observed accesses. */
extern "C" {
struct S2Runtime { unsigned char pad00[40]; Ptr32<void> document; unsigned char pad2c[24]; Ptr32<void> lua; unsigned int unknown48; char line[256]; };
struct S2RuntimeString { Ptr32<char> text; unsigned int storage; };
struct S2LuaDebug { unsigned char pad00[16]; Ptr32<const char> source; int currentLine; unsigned char pad18[72]; };
struct S2RuntimeVirtual { Ptr32<Ptr32<void (Ptr32<S2RuntimeVirtual>, int)>> vtable; };
extern Ptr32<S2RuntimeVirtual> w3d_obj_804ab438; extern Ptr32<S2RuntimeVirtual> w3d_obj_804aaa04;
Ptr32<S2Runtime> w3d_script_service_from_lua(Ptr32<void>);
void w3d_fn_80101e08(Ptr32<S2Runtime>, Ptr32<S2LuaDebug>);
void w3d_fn_80100bbc(Ptr32<S2Runtime>);
void w3d_fn_801022ec(Ptr32<S2Runtime>, Ptr32<const char>);
int w3d_fn_801020b0(Ptr32<S2Runtime>);
void w3d_script_log(Ptr32<S2Runtime>, Ptr32<const char>, int);
void w3d_script_output_hook(Ptr32<S2Runtime>, Ptr32<const char>);
Ptr32<void> w3d_string_default(Ptr32<S2RuntimeString>);
void w3d_string_from_text(Ptr32<S2RuntimeString>, Ptr32<const char>);
void w3d_string_format(Ptr32<S2RuntimeString>, Ptr32<const char>, ...);
void w3d_string_base_init(Ptr32<S2RuntimeString>);
void w3d_string_base_finish(Ptr32<S2RuntimeString>);
void w3d_string_release(Ptr32<S2RuntimeString>);
Ptr32<unsigned short> w3d_string_header(Ptr32<S2RuntimeString>);
void w3d_string_append(Ptr32<S2RuntimeString>, Ptr32<const char>);
int lua_getstack(Ptr32<void>, int, Ptr32<S2LuaDebug>);
void lua_getinfo(Ptr32<void>, Ptr32<const char>, Ptr32<S2LuaDebug>);
Ptr32<const char> lua_tostring(Ptr32<void>, int);
void lua_settop(Ptr32<void>, int);
void lua_pushnil(Ptr32<void>);
int lua_type(Ptr32<void>, int);
int lua_next(Ptr32<void>, int);
int w3d_fn_80102a34(Ptr32<S2Runtime>, Ptr32<const char>, Ptr32<Ptr32<void>>);
int w3d_fn_801029c8(Ptr32<S2Runtime>, Ptr32<const char>, int, Ptr32<int>);
int w3d_get_80102734(Ptr32<S2Runtime>);
void w3d_script_set_run_state(Ptr32<S2Runtime>, int);
int w3d_script_source_line(Ptr32<S2Runtime>, Ptr32<const char>, int, Ptr32<char>);
Ptr32<void> w3d_fn_801613f0(Ptr32<void>, int);
Ptr32<void> w3d_message_string_init(Ptr32<void>, unsigned short, Ptr32<const char>);
void w3d_message_post_current(Ptr32<void>);
int w3d_cached_message_id(Ptr32<void>, int);
extern Ptr32<void> w3d_obj_804b1754;
extern unsigned int w3d_obj_804af164;
extern const char w3d_str_80398da4[], w3d_str_80398da8[], w3d_str_80398dbc[];
extern const char w3d_str_80398dd8[], w3d_str_80398de4[], w3d_str_80398de8[], w3d_str_80398e08[], w3d_str_80398e2c[];

void w3d_script_debug_hook_80101dd4(Ptr32<void> lua, Ptr32<S2LuaDebug> event)
{
    struct { unsigned int first, second; } scratch;
    w3d_fn_80101e08(w3d_script_service_from_lua(lua), event);
}


void w3d_fn_80101e08(Ptr32<S2Runtime> self, Ptr32<S2LuaDebug> event)
{
    struct { S2RuntimeString text; Ptr32<void> document; int breakpoint; } local;
    lua_getstack(self->lua, 0, event);
    lua_getinfo(self->lua, w3d_str_80398da4, event);
    local.document = 0;
    if (w3d_fn_80102a34(self, event->source, &local.document)) {
        int line = event->currentLine;
        int index = line - 1;
        if (w3d_fn_801029c8(self, event->source, index, &local.breakpoint) < 0) {
            w3d_fn_801022ec(self, w3d_str_80398da8);
        } else if (w3d_get_80102734(self) == 0 || local.breakpoint) {
            w3d_script_set_run_state(self, 2);
            Ptr32<char> buffer = self->line;
            w3d_string_default(&local.text);
            w3d_script_source_line(self, event->source, index, buffer);
            w3d_string_format(&local.text, w3d_str_80398dbc, w3d::VA(event->source), line, w3d::VA(buffer));
            w3d_script_log(self, local.text.text, 9);
            w3d_fn_801020b0(self);
            while (w3d_get_80102734(self) == 2) {
                w3d_obj_804ab438->vtable[8](w3d_obj_804ab438, 0);
                w3d_obj_804aaa04->vtable[8](w3d_obj_804aaa04, 0);
                w3d_fn_80100bbc(self);
            }
            Ptr32<S2RuntimeString> text = &local.text;
            w3d_string_base_finish(text);
            w3d_string_release(text);
        }
    }
}


int w3d_script_lua_error_80102028(Ptr32<S2Runtime> self)
{
    struct { unsigned int first, second; } scratch;
    Ptr32<const char> text = lua_tostring(self->lua, -1);
    lua_settop(self->lua, -2);
    w3d_script_log(self, text, 1);
    w3d_script_output_hook(self, text);
    return 0;
}


#if 0 /* 3 attempts; string temporary allocation and loop hoisting differ */
int w3d_fn_801020b0(S2Runtime *self)
{
    struct { S2RuntimeString name, value, output, prefix, temporary; } local;
    S2RuntimeString *value = &local.value;
    w3d_script_log(self, w3d_str_80398dd8, 9);
    S2RuntimeString *temporary = &local.temporary;
    lua_pushnil(self->lua);
    goto advance;
 next: {
        if (lua_type(self->lua, -1) != 6) {
            const char *key = lua_tostring(self->lua, -2);
            w3d_string_from_text(&local.name, key);
            S2RuntimeString *name = &local.name;
            if (*local.name.text != '_') {
                w3d_string_from_text(value, lua_tostring(self->lua, -1));
                w3d_string_base_init(temporary);
                local.temporary.text = local.name.text;
                (*w3d_string_header(temporary))++;
                w3d_string_append(temporary, w3d_str_80398de4);
                w3d_string_base_init(&local.prefix);
                local.prefix.text = local.temporary.text;
                (*w3d_string_header(&local.prefix))++;
                w3d_string_base_finish(temporary);
                w3d_string_release(temporary);
                w3d_string_base_init(temporary);
                local.temporary.text = local.prefix.text;
                (*w3d_string_header(temporary))++;
                w3d_string_append(temporary, local.value.text);
                w3d_string_base_init(&local.output);
                local.output.text = local.temporary.text;
                (*w3d_string_header(&local.output))++;
                w3d_string_base_finish(temporary);
                w3d_string_release(temporary);
                w3d_string_base_finish(&local.prefix);
                w3d_string_release(&local.prefix);
                w3d_script_log(self, local.output.text, 9);
                w3d_string_base_finish(&local.output);
                w3d_string_release(&local.output);
                w3d_string_base_finish(value);
                w3d_string_release(value);
            }
            w3d_string_base_finish(name);
            w3d_string_release(name);
        }
        lua_settop(self->lua, -2);
    }
 advance:
    if (lua_next(self->lua, -10001)) goto next;
    lua_settop(self->lua, -2);
    return 0;
}
#endif


#if 0 /* 8 attempts including a compile error; saved-register allocation differs */
void w3d_fn_801022ec(S2Runtime *self, const char *error)
{
    struct { S2RuntimeString text; S2LuaDebug event; S2RuntimeString frame; } local;
    w3d_string_default(&local.text);
    w3d_string_format(&local.text, w3d_str_80398de8, error);
    S2RuntimeString *text = &local.text;
    w3d_script_log(self, local.text.text, 1);
    w3d_script_output_hook(self, local.text.text);
    void *message = w3d_fn_801613f0(w3d_obj_804b1754, 12);
    w3d_message_post_current(w3d_message_string_init(message, (unsigned short)w3d_cached_message_id(&w3d_obj_804af164, 1), w3d_str_80398e08));
    w3d_script_set_run_state(self, 2);
    if (self->lua) {
        int level = 0;
        message = &local.event;
        goto search;
    next:
            lua_getinfo(self->lua, w3d_str_80398da4, (S2LuaDebug *)message);
            if (local.event.currentLine == -1) goto increment;
            {
                message = self->line;
                char *buffer = (char *)message;
                S2RuntimeString *frame = &local.frame;
                w3d_string_default(frame);
                w3d_script_source_line(self, local.event.source, local.event.currentLine - 1, buffer);
                w3d_string_format(frame, w3d_str_80398e2c, local.event.source, local.event.currentLine, buffer);
                w3d_script_log(self, local.frame.text, 1);
                w3d_script_output_hook(self, local.frame.text);
                w3d_string_base_finish(frame);
                w3d_string_release(frame);
                goto done;
            }
    increment:
        level++;
    search:
        if (lua_getstack(self->lua, level, (S2LuaDebug *)message)) goto next;
    done:;
    }
    w3d_string_base_finish(text);
    w3d_string_release(text);
}
#endif

}


