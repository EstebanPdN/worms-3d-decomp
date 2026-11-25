struct K4aMessageId { unsigned short value; K4aMessageId() {} };
struct K4aString;
extern "C" void * w3d_string_from_text(K4aString *string, const char *text);
extern "C" void w3d_string_base_finish(K4aString *string);
extern "C" void w3d_string_release(K4aString *string);
struct K4aString {
    char *text;
    int unused;
    K4aString() {}
    ~K4aString() { w3d_string_base_finish(this); w3d_string_release(this); }
};
struct K4aGameOver { char pad0[72]; unsigned int subs[4]; int callback_slot; };
extern "C" char w3d_str_80380d14[];
extern "C" unsigned int w3d_message_804ae18c;
extern "C" unsigned int w3d_message_804ae194;
extern "C" unsigned int w3d_message_804ae19c;
extern "C" unsigned int w3d_message_804ae1a4;
extern "C" void FUN_800a3d0c(K4aGameOver *self);
extern "C" int FUN_800a4038(void *, void *);
extern "C" unsigned short w3d_cached_message_id(void *cache, int create);
extern "C" int w3d_subscribe_80162024(void *self, K4aMessageId *id, void *slot);
extern "C" int FUN_800fd62c(K4aString *name, void (*callback)(void), void *context, void *slot);
extern "C" void s8_visibility_800a3c24(K4aGameOver *self);

extern "C" void k4a_game_over_init_800a3ac4(K4aGameOver *self)
{
    K4aMessageId id0;
    K4aMessageId id1;
    K4aMessageId id2;
    K4aMessageId id3;
    FUN_800a3d0c(self);
    id0.value = w3d_cached_message_id(&w3d_message_804ae18c, 1);
    w3d_subscribe_80162024(self, &id0, &self->subs[0]);
    id1.value = w3d_cached_message_id(&w3d_message_804ae194, 1);
    w3d_subscribe_80162024(self, &id1, &self->subs[1]);
    id2.value = w3d_cached_message_id(&w3d_message_804ae19c, 1);
    w3d_subscribe_80162024(self, &id2, &self->subs[2]);
    id3.value = w3d_cached_message_id(&w3d_message_804ae1a4, 1);
    w3d_subscribe_80162024(self, &id3, &self->subs[3]);
    {
        K4aString name;
        w3d_string_from_text(&name, w3d_str_80380d14);
        FUN_800fd62c(&name, (void (*)())FUN_800a4038, self, &self->callback_slot);
    }
    s8_visibility_800a3c24(self);
}
