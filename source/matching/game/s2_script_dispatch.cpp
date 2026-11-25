/* Script-service message dispatch; field names describe observed offsets. */
extern "C" {
struct S2String { char *text; unsigned int storage; };
struct S2Trigger { unsigned char pad00[4]; char *text; unsigned char pad08[8]; unsigned char message[12]; int active; };
struct S2TriggerList { S2Trigger **begin; S2Trigger **end; };
struct S2Virtual;
typedef void (*S2Method)(S2Virtual *);
struct S2Virtual { S2Method *vtable; };
struct S2Script { unsigned char pad00[40]; int enabled; S2Virtual *source; S2Virtual *dest; S2Virtual *search; S2Virtual *replace; S2Virtual *owner; S2Virtual *library; void *lua; unsigned char pad48[0x170-72]; int pending; unsigned char pad174[12]; S2TriggerList triggers; };
int w3d_auto_8016293c(S2Script *, unsigned short *);
void w3d_fn_80100490(S2Script *);
void w3d_empty_80100744(S2Script *);
int w3d_cached_message_id(void *, int);
int w3d_fn_8015f65c(unsigned short, void *);
extern unsigned int w3d_obj_804af16c;
extern unsigned int w3d_obj_804af174;
void w3d_fn_80103a5c(S2Script *);
void w3d_fn_80103c44(S2Script *);
int w3d_get_80102734(S2Script *);
void w3d_message_find_name(unsigned short, S2String *);
void w3d_string_from_text(S2String *, const char *);
void w3d_string_base_finish(S2String *);
void w3d_string_release(S2String *);
char *strcpy(char *, const char *);
void w3d_fn_801036f0(S2Script *, const char *);
#if 0 /* 1 attempt; register allocation and stack layout differ */
int w3d_script_dispatch_80100250(S2Script *self, unsigned short *message)
{
    S2String text;
    char name[256];
    S2String found;
    unsigned short id = *message;
    switch (id) {
    case 64:
        if (w3d_auto_8016293c(self, message) < 0) return 0x80004005;
        w3d_fn_80100490(self);
        return 0;
    case 66:
        if (w3d_auto_8016293c(self, message) < 0) return 0x80004005;
        w3d_empty_80100744(self);
        return 0;
    }
    S2TriggerList *list = &self->triggers;
    unsigned int i = 0;
    if (((unsigned int)((char *)list->end - (char *)self->triggers.begin) >> 2) != 0) {
        int offset = 0;
        do {
            if (id == w3d_cached_message_id((char *)*(S2Trigger **)((char *)self->triggers.begin + offset) + 16, 1)) {
                (*(S2Trigger **)((char *)self->triggers.begin + offset))->active = 1;
                w3d_string_from_text(&text, (*(S2Trigger **)((char *)self->triggers.begin + offset))->text);
                w3d_fn_801036f0(self, text.text);
                w3d_string_base_finish(&text);
                w3d_string_release(&text);
                return 0;
            }
            i++;
            offset += 4;
        } while (i < (unsigned int)(((char *)list->end - (char *)self->triggers.begin) >> 2));
    }
    if (id & 0x8000) {
        if (w3d_fn_8015f65c(id, &w3d_obj_804af16c)) w3d_fn_80103a5c(self);
        else if (w3d_fn_8015f65c(id, &w3d_obj_804af174)) w3d_fn_80103c44(self);
        else if (w3d_get_80102734(self) != 2) {
            char *cursor = name;
            w3d_message_find_name(*message, &found);
            strcpy(cursor, found.text);
            if (*cursor) {
                do {
                    if (*cursor == '.') *cursor = '_';
                    cursor++;
                } while (*cursor);
            }
            w3d_fn_801036f0(self, name);
        }
    }
    return w3d_auto_8016293c(self, message);
}
#endif

struct S2EngineFlags { unsigned char pad00[188]; unsigned int flags; };
extern S2EngineFlags *w3d_obj_804b1788;
void w3d_fn_80100bbc(S2Script *);
int w3d_script_poll_8010045c(S2Script *self)
{
    if (w3d_obj_804b1788->flags & 0x40000000) w3d_fn_80100bbc(self);
    return 20;
}


struct S2Ref { S2Virtual *value; unsigned int unused; };
void w3d_fn_801037a8(S2Script *);
void w3d_fn_8010391c(S2Script *);
struct S2Name { const char *text; };
void w3d_constructor_lookup_name(S2Name *, S2Ref *);
S2Virtual *w3d_empty_80343744(S2Virtual *);
void w3d_fn_80100748(S2Script *);
int w3d_fn_8010273c(S2Script *);
void *w3d_fn_801613f0(void *, int);
void *w3d_message_string_init(void *, unsigned short, const char *);
void w3d_message_post_current(void *);
void w3d_script_set_run_state(S2Script *, int);
int w3d_fn_802ccb00(void *);
extern void *w3d_obj_804aaf88;
extern void *w3d_obj_804b1754;
extern unsigned int w3d_obj_804af164;
extern const char w3d_str_80398770[], w3d_str_80398788[], w3d_str_8039879c[], w3d_str_803987b0[];
extern const char w3d_str_803987c8[], w3d_str_803987e8[];
#if 0 /* 5 attempts; 13 local setup words differ */
void w3d_fn_80100490(S2Script *self)
{
    S2Ref storage;
    S2Ref *temporary = &storage;
    S2Virtual *value;
    w3d_fn_801037a8(self);
    w3d_fn_8010391c(self);
    temporary->value = 0;
    S2Name sourceName;
    sourceName.text = w3d_str_80398770;
    w3d_constructor_lookup_name(&sourceName, temporary);
    value = w3d_empty_80343744(temporary->value);
    if (value) value->vtable[3](value);
    if (self->source) self->source->vtable[4](self->source);
    self->source = value;
    if (temporary->value) temporary->value->vtable[4](temporary->value);
    temporary->value = 0;
    S2Name destName;
    destName.text = w3d_str_80398788;
    w3d_constructor_lookup_name(&destName, temporary);
    value = w3d_empty_80343744(temporary->value);
    if (value) value->vtable[3](value);
    if (self->dest) self->dest->vtable[4](self->dest);
    self->dest = value;
    if (temporary->value) temporary->value->vtable[4](temporary->value);
    temporary->value = 0;
    S2Name searchName;
    searchName.text = w3d_str_8039879c;
    w3d_constructor_lookup_name(&searchName, temporary);
    value = w3d_empty_80343744(temporary->value);
    if (value) value->vtable[3](value);
    if (self->search) self->search->vtable[4](self->search);
    self->search = value;
    if (temporary->value) temporary->value->vtable[4](temporary->value);
    temporary->value = 0;
    S2Name replaceName;
    replaceName.text = w3d_str_803987b0;
    w3d_constructor_lookup_name(&replaceName, temporary);
    value = w3d_empty_80343744(temporary->value);
    if (value) value->vtable[3](value);
    if (self->replace) self->replace->vtable[4](self->replace);
    self->replace = value;
    if (temporary->value) temporary->value->vtable[4](temporary->value);
    w3d_fn_80100748(self);
    if (w3d_fn_8010273c(self) < 0) {
        void *message = w3d_fn_801613f0(w3d_obj_804b1754, 12);
        w3d_message_post_current(w3d_message_string_init(message, (unsigned short)w3d_cached_message_id(&w3d_obj_804af164, 1), w3d_str_803987c8));
    } else {
        w3d_script_set_run_state(self, 1);
        if (w3d_fn_802ccb00(w3d_obj_804aaf88)) w3d_script_set_run_state(self, 0);
        w3d_fn_801036f0(self, w3d_str_803987e8);
    }
}
#endif


S2Virtual *w3d_fn_8020b680(void *);
extern unsigned char w3d_obj_80413750[], w3d_obj_80413700[], w3d_obj_80413880[], w3d_obj_80413820[];
typedef int (*S2LuaCallback)(void *);
void lua_setgcthreshold(void *, int);
int lua_atpanic(void *, S2LuaCallback);
void lua_pushstring(void *, const char *);
void lua_pushcclosure(void *, S2LuaCallback, int);
void lua_settable(void *, int);
int lua_sethook(void *, void (*)(void *, void *), int, int);
void lua_pushlightuserdata(void *, void *);
void lua_insert(void *, int);
int w3d_lua_panic(void *);
int w3d_lua_SendMessage(void *);
int w3d_lua_SendFloatMessage(void *);
int w3d_lua_SendIntMessage(void *);
int w3d_lua_SendStringMessage(void *);
int w3d_lua_GetData(void *);
int w3d_lua_SetData(void *);
int w3d_lua_globals(void *);
int w3d_lua_StartTimer(void *);
int w3d_lua_CancelTimer(void *);
int w3d_lua_EditContainer(void *);
int w3d_lua_CloseContainer(void *);
int w3d_lua_QueryContainer(void *);
int w3d_lua_CopyContainer(void *);
int w3d_lua_Print(void *);
void w3d_fn_80101dd4(void *, void *);
extern const char w3d_str_803987f4[];
extern const char w3d_str_80398800[];
extern const char w3d_str_80398814[];
extern const char w3d_str_80398824[];
extern const char w3d_str_80398838[];
extern const char w3d_str_80398840[];
extern const char w3d_str_80398848[];
extern const char w3d_str_80398850[];
extern const char w3d_str_8039885c[];
extern const char w3d_str_80398868[];
extern const char w3d_str_80398878[];
extern const char w3d_str_80398888[];
extern const char w3d_str_80398898[];
extern const char w3d_str_803988a8[];
extern const char w3d_str_803988b0[];

void w3d_fn_80100748(S2Script *self)
{
    S2Virtual *value;
    if (self->owner) self->owner->vtable[4](self->owner);
    self->owner = 0;
    value = w3d_fn_8020b680(w3d_obj_80413750);
    if (value) value->vtable[3](value);
    if (self->owner) self->owner->vtable[4](self->owner);
    self->owner = value;
    value->vtable[6](value);
    self->lua = ((void *(*)(S2Virtual *))self->owner->vtable[9])(self->owner);
    lua_setgcthreshold(self->lua, 110000);
    ((void (*)(S2Virtual *, void *))self->owner->vtable[8])(self->owner, w3d_obj_80413700);
    ((void (*)(S2Virtual *, void *))self->owner->vtable[8])(self->owner, w3d_obj_80413880);
    value = w3d_fn_8020b680(w3d_obj_80413820);
    if (value) value->vtable[3](value);
    if (self->library) self->library->vtable[4](self->library);
    self->library = value;
    ((void (*)(S2Virtual *, S2Virtual *))self->owner->vtable[7])(self->owner, value);
    lua_atpanic(self->lua, w3d_lua_panic);
    lua_pushstring(self->lua, w3d_str_803987f4);
    lua_pushcclosure(self->lua, w3d_lua_SendMessage, 0);
    lua_settable(self->lua, -10001);
    lua_pushstring(self->lua, w3d_str_80398800);
    lua_pushcclosure(self->lua, w3d_lua_SendFloatMessage, 0);
    lua_settable(self->lua, -10001);
    lua_pushstring(self->lua, w3d_str_80398814);
    lua_pushcclosure(self->lua, w3d_lua_SendIntMessage, 0);
    lua_settable(self->lua, -10001);
    lua_pushstring(self->lua, w3d_str_80398824);
    lua_pushcclosure(self->lua, w3d_lua_SendStringMessage, 0);
    lua_settable(self->lua, -10001);
    lua_pushstring(self->lua, w3d_str_80398838);
    lua_pushcclosure(self->lua, w3d_lua_GetData, 0);
    lua_settable(self->lua, -10001);
    lua_pushstring(self->lua, w3d_str_80398840);
    lua_pushcclosure(self->lua, w3d_lua_SetData, 0);
    lua_settable(self->lua, -10001);
    lua_pushstring(self->lua, w3d_str_80398848);
    lua_pushcclosure(self->lua, w3d_lua_globals, 0);
    lua_settable(self->lua, -10001);
    lua_pushstring(self->lua, w3d_str_80398850);
    lua_pushcclosure(self->lua, w3d_lua_StartTimer, 0);
    lua_settable(self->lua, -10001);
    lua_pushstring(self->lua, w3d_str_8039885c);
    lua_pushcclosure(self->lua, w3d_lua_CancelTimer, 0);
    lua_settable(self->lua, -10001);
    lua_pushstring(self->lua, w3d_str_80398868);
    lua_pushcclosure(self->lua, w3d_lua_EditContainer, 0);
    lua_settable(self->lua, -10001);
    lua_pushstring(self->lua, w3d_str_80398878);
    lua_pushcclosure(self->lua, w3d_lua_CloseContainer, 0);
    lua_settable(self->lua, -10001);
    lua_pushstring(self->lua, w3d_str_80398888);
    lua_pushcclosure(self->lua, w3d_lua_QueryContainer, 0);
    lua_settable(self->lua, -10001);
    lua_pushstring(self->lua, w3d_str_80398898);
    lua_pushcclosure(self->lua, w3d_lua_CopyContainer, 0);
    lua_settable(self->lua, -10001);
    lua_pushstring(self->lua, w3d_str_803988a8);
    lua_pushcclosure(self->lua, w3d_lua_Print, 0);
    lua_settable(self->lua, -10001);
    if (w3d_obj_804b1788->flags & 0x40000000)
        lua_sethook(self->lua, w3d_fn_80101dd4, 4, 0);
    lua_pushlightuserdata(self->lua, self);
    lua_pushstring(self->lua, w3d_str_803988b0);
    lua_insert(self->lua, -2);
    lua_settable(self->lua, -10001);
}


int w3d_fn_802ccb40(int);
void w3d_fn_802cbdf8(int, const char *, int);
int w3d_fn_802cba50(int);
const char *w3d_fn_802cbb5c(int);
void w3d_fn_80100c4c(S2Script *, const char *);
extern const char w3d_str_803988c0[];
void w3d_fn_80100bbc(S2Script *self)
{
    if (self->enabled) {
        if (self->pending || w3d_fn_802ccb40((int)w3d_obj_804aaf88)) {
            w3d_fn_802cbdf8((int)w3d_obj_804aaf88, w3d_str_803988c0, 9);
            self->pending = 0;
        }
        if (w3d_fn_802cba50((int)w3d_obj_804aaf88))
            w3d_fn_80100c4c(self, w3d_fn_802cbb5c((int)w3d_obj_804aaf88));
    }
}

}
