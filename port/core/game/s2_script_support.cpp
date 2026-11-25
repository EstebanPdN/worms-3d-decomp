#include "w3d_ptr.h"
#line 1 "s2_script_support.cpp"
/* Script document lists, loaders, and breakpoint lookup. */
extern "C" {
struct S2DocList { Ptr32<Ptr32<void>> begin; Ptr32<Ptr32<void>> end; Ptr32<Ptr32<void>> limit; };
struct S2Support { unsigned char pad00[28]; S2DocList documents; Ptr32<void> document; unsigned char pad2c[24]; Ptr32<void> lua; };
struct S2SupportString { Ptr32<char> text; unsigned int storage; };
struct S2File { unsigned char unknown[24]; };
struct S2FileSize { unsigned int bytes; unsigned int unknown[2]; };
void w3d_fn_800ffb78(Ptr32<void>, int);
Ptr32<void> memcpy(...);
void w3d_fn_80207fec(Ptr32<S2File>);
void w3d_fn_8020803c(Ptr32<S2File>, int);
int w3d_fn_802080a0(Ptr32<S2File>, Ptr32<const char>, int);
void w3d_fn_802081c8(Ptr32<S2File>, Ptr32<S2FileSize>);
void w3d_fn_80208298(Ptr32<S2File>, Ptr32<void>, unsigned int, int);
void w3d_fn_8020810c(Ptr32<S2File>);
Ptr32<void> w3d_fn_801fe0b8(unsigned int);
void w3d_temporary_release(Ptr32<void>);
void w3d_string_default(Ptr32<S2SupportString>);
void w3d_string_assign(Ptr32<S2SupportString>, Ptr32<const char>);
void w3d_string_append(Ptr32<S2SupportString>, Ptr32<const char>);
void w3d_string_format(Ptr32<S2SupportString>, Ptr32<const char>, ...);
void w3d_string_base_finish(Ptr32<S2SupportString>);
void w3d_string_release(Ptr32<S2SupportString>);
void w3d_source_document_name(Ptr32<S2SupportString>, Ptr32<void>);
int strcmp(Ptr32<const char>, Ptr32<const char>);
Ptr32<char> strcpy(Ptr32<char>, Ptr32<const char>);
Ptr32<char> strtok(Ptr32<char>, Ptr32<const char>);
void w3d_script_output_hook(Ptr32<S2Support>, Ptr32<const char>);
void w3d_fn_801022ec(Ptr32<S2Support>, Ptr32<const char>);
int luaL_loadbuffer(Ptr32<void>, Ptr32<const void>, unsigned int, Ptr32<const char>);
int lua_gettop(Ptr32<void>);
int lua_pcall(Ptr32<void>, int, int, int);
void w3d_lua_panic(Ptr32<void>);
int w3d_fn_800ffca4(Ptr32<void>, int, Ptr32<Ptr32<void>>);
void w3d_set_800ffb58(Ptr32<void>, int);
int w3d_get_800ffb60(Ptr32<void>);
int w3d_fn_80102a34(Ptr32<S2Support>, Ptr32<const char>, Ptr32<Ptr32<void>>);
int w3d_fn_80102660(Ptr32<S2Support>, Ptr32<const char>, Ptr32<const void>, unsigned int);
int w3d_fn_80102530(Ptr32<S2Support>, Ptr32<const char>);
int w3d_fn_800fd4c8(int, int);
void w3d_fn_800fc2b0(Ptr32<Ptr32<const char>>, Ptr32<Ptr32<const char>>);
extern const char w3d_str_80398e48[], w3d_str_80398e50[], w3d_str_80398e58[];
extern const char w3d_str_80398e7c[], w3d_str_80398e94[], w3d_str_80398ebc[], w3d_str_80398ec0[], w3d_str_80398ef8[];

#if 0 /* 3 attempts; compiler folds the zero-length memcpy and register allocation differs */
void w3d_script_clear_documents_80102474(S2Support *self)
{
    unsigned int i = 0;
    S2DocList *initial = &self->documents;
    if ((unsigned int)((char *)initial->end - (char *)self->documents.begin) >> 2) {
        S2DocList *list = initial;
        int offset = 0;
        do {
            void *document = *(void **)((char *)self->documents.begin + offset);
            if (document) w3d_fn_800ffb78(document, 3);
            i++;
            offset += 4;
        } while (i < (unsigned int)(((char *)list->end - (char *)self->documents.begin) >> 2));
    }
    S2DocList *range = &self->documents;
    void **begin = self->documents.begin;
    void **end = range->end;
    int bytes = (char *)end - (char *)begin;
    void *empty = 0;
    memcpy(begin, end, 0);
    range->end = (void **)((char *)range->end - bytes);
    self->document = empty;
}
#endif


#if 0 /* 3 attempts; pointer lifetimes and register allocation differ */
int w3d_fn_80102530(S2Support *self, const char *baseName)
{
    struct { S2File file; S2SupportString name; S2FileSize size; } local;
    w3d_fn_80207fec(&local.file);
    w3d_string_default(&local.name);
    w3d_string_assign(&local.name, baseName);
    w3d_string_append(&local.name, w3d_str_80398e48);
    int status;
    if (w3d_fn_802080a0(&local.file, local.name.text, 1) < 0) {
        w3d_string_assign(&local.name, baseName);
        w3d_string_append(&local.name, w3d_str_80398e50);
        status = w3d_fn_802080a0(&local.file, local.name.text, 1);
        if (status < 0) {
            w3d_string_base_finish(&local.name);
            goto release;
        }
    }
    {
        w3d_fn_802081c8(&local.file, &local.size);
        unsigned int size = local.size.bytes;
        void *buffer = w3d_fn_801fe0b8(size);
        w3d_fn_80208298(&local.file, buffer, size, 0);
        w3d_fn_8020810c(&local.file);
        status = w3d_fn_80102660(self, baseName, buffer, size);
        w3d_temporary_release(buffer);
        w3d_string_base_finish(&local.name);
    }
release:
    w3d_string_release(&local.name);
    w3d_fn_8020803c(&local.file, 2);
    return status;
}
#endif


#if 0 /* 4 attempts; four local-address setup instructions differ */
int w3d_fn_80102660(S2Support *self, const char *name, const void *data, unsigned int size)
{
    if (luaL_loadbuffer(self->lua, data, size, name)) {
        lua_gettop(self->lua);
        w3d_lua_panic(self->lua);
        struct AutoString : S2SupportString {
            AutoString() { w3d_string_default(this); }
            ~AutoString() { w3d_string_base_finish(this); w3d_string_release(this); }
        } errorText;
        w3d_string_format(&errorText, w3d_str_80398e58, name);
        w3d_fn_801022ec(self, errorText.text);
    } else {
        if (lua_pcall(self->lua, 0, 0, 0) == 0) return 0;
        w3d_lua_panic(self->lua);
    }
    return 0x80004005;
}
#endif


void w3d_script_clear_documents_80102474(Ptr32<S2Support>);
#if 0 /* 3 attempts; output temporary and status register allocation differ */
int w3d_script_load_set_8010273c(S2Support *self)
{
    struct { char names[256]; S2SupportString output; const char *key, *value; } local;
    if (w3d_fn_800fd4c8(8, 2) < 0) w3d_fn_800fd4c8(8, 1);
    local.key = w3d_str_80398e7c;
    w3d_fn_800fc2b0(&local.key, &local.value);
    w3d_script_clear_documents_80102474(self);
    int status = w3d_fn_80102530(self, w3d_str_80398e94);
    if (status < 0) return status;
    if (!local.value || !*local.value) return 0x80004005;
    strcpy(local.names, local.value);
    char *name = strtok(local.names, w3d_str_80398ebc);
    if (name) {
        do {
            w3d_string_default(&local.output);
            status = w3d_fn_80102530(self, name);
            if (status < 0) w3d_string_format(&local.output, w3d_str_80398ec0, name);
            else w3d_string_format(&local.output, w3d_str_80398ef8, name);
            w3d_script_output_hook(self, local.output.text);
            name = strtok(0, w3d_str_80398ebc);
            w3d_string_base_finish(&local.output);
            w3d_string_release(&local.output);
        } while (name);
    }
    return status;
}
#endif



#if 0 /* 3 attempts; branch layout differs */
int w3d_script_set_breakpoint_80102968(S2Support *self, int line, int enabled)
{
    struct { void *line; unsigned int unknown; } local;
    if (self->document) {
        int status = w3d_fn_800ffca4(self->document, line, &local.line);
        if (status < 0) return status;
        w3d_set_800ffb58(local.line, enabled);
        return 0;
    } else {
        return 0x80004005;
    }
}
#endif


int w3d_script_get_breakpoint_801029c8(Ptr32<S2Support> self, Ptr32<const char> name, int index, Ptr32<int> value)
{
    Ptr32<void> document;
    document = 0;
    int status = w3d_fn_80102a34(self, name, &document);
    if (status < 0) return status;
    Ptr32<void> line;
    status = w3d_fn_800ffca4(document, index, &line);
    if (status < 0) return status;
    *value = w3d_get_800ffb60(line);
    return 0;
}


#if 0 /* 3 attempts; list and string temporary register allocation differs */
int w3d_fn_80102a34(S2Support *self, const char *name, void **result)
{
    *result = 0;
    S2DocList *initial = &self->documents;
    unsigned int i = 0;
    if ((unsigned int)((char *)initial->end - (char *)self->documents.begin) >> 2) {
        S2DocList *list = &self->documents;
        int offset = 0;
        do {
            void *document = *(void **)((char *)self->documents.begin + offset);
            *result = document;
            S2SupportString text;
            w3d_source_document_name(&text, document);
            S2SupportString *temporary = &text;
            int comparison = strcmp(text.text, name);
            w3d_string_base_finish(temporary);
            w3d_string_release(temporary);
            if (!comparison) return 1;
            i++;
            offset += 4;
        } while (i < (unsigned int)(((char *)list->end - (char *)self->documents.begin) >> 2));
    }
    *result = 0;
    return 0;
}
#endif


struct S2Timer { unsigned char pad00[28]; int available; };
struct S2TimerScript { unsigned char pad00[68]; Ptr32<void> lua; unsigned char pad48[312]; Ptr32<Ptr32<S2Timer>> begin; Ptr32<Ptr32<S2Timer>> end; };
void lua_settop(Ptr32<void>, int);
int lua_isstring(Ptr32<void>, int);
int lua_isnumber(Ptr32<void>, int);
Ptr32<const char> lua_tostring(Ptr32<void>, int);
float lua_tonumber(Ptr32<void>, int);
void lua_pushnumber(Ptr32<void>, float);
unsigned int w3d_fn_8005ffc8(Ptr32<S2Timer>, Ptr32<const char>, int);
extern const char w3d_str_80398f48[], w3d_str_80398f80[], w3d_str_80398fac[];
#if 0 /* 2 attempts; timer scan strength reduction and shared error-tail layout differ */
int w3d_script_start_timer_80102b2c(S2TimerScript *self)
{
    int count = lua_gettop(self->lua);
    if (count != 2) {
        lua_settop(self->lua, ~count);
        w3d_fn_801022ec((S2Support *)self, w3d_str_80398f48);
        return 0;
    }
    if (!lua_isstring(self->lua, -2) || !lua_isnumber(self->lua, -1)) {
        w3d_fn_801022ec((S2Support *)self, w3d_str_80398f80);
    } else {
        unsigned int index = 0;
        for (; index < (unsigned int)(self->end - self->begin); index++) {
            if (self->begin[index]->available) break;
        }
        if (index < (unsigned int)(self->end - self->begin)) {
            const char *name = lua_tostring(self->lua, -2);
            int delay = (int)lua_tonumber(self->lua, -1);
            unsigned int result = w3d_fn_8005ffc8(self->begin[index], name, delay);
            lua_settop(self->lua, -3);
            lua_pushnumber(self->lua, (float)result);
            return 1;
        }
        w3d_fn_801022ec((S2Support *)self, w3d_str_80398fac);
    }
    lua_settop(self->lua, -3);
    return 0;
}
#endif


struct S2CallScript { unsigned char pad00[68]; Ptr32<void> lua; unsigned char pad48[284]; int openContainer; };
void lua_pushstring(Ptr32<void>, Ptr32<const char>);
void lua_gettable(Ptr32<void>, int);
int lua_type(Ptr32<void>, int);
extern const char w3d_str_80399394[];
Ptr32<void> lua_newuserdata(Ptr32<void>, unsigned long);
const char *w3d_test_lua_due(const char *);
int w3d_script_call_handler_801036f0(Ptr32<S2CallScript> self, Ptr32<const char> name)
{
    // W3D_TEST_LUA=<retrazos>:<trozo>: para encadenar misiones en pruebas por lotes, sin efecto si no está definida.
    if (const char *chunk = w3d_test_lua_due(&*name)) {
        unsigned long size = __builtin_strlen(chunk);
        Ptr32<char> copy = (Ptr32<char>)lua_newuserdata(self->lua, size);
        __builtin_memcpy(&*copy, chunk, size);
        if (!luaL_loadbuffer(self->lua, copy, size, copy)) lua_pcall(self->lua, 0, 0, 0);
        lua_settop(self->lua, -2);
    }
    lua_gettop(self->lua);
    lua_pushstring(self->lua, name);
    lua_gettable(self->lua, -10001);
    if (!lua_type(self->lua, -1)) lua_settop(self->lua, -2);
    else if (lua_pcall(self->lua, 0, 0, 0)) w3d_lua_panic(self->lua);
    if (self->openContainer) w3d_fn_801022ec((Ptr32<S2Support>)self, w3d_str_80399394);
    return lua_gettop(self->lua);
}

}


