struct K5aString;
extern "C" void * w3d_string_from_text(K5aString *string, const char *text);
extern "C" void w3d_string_base_finish(K5aString *string);
extern "C" void w3d_string_release(K5aString *string);
struct K5aString {
    char *text;
    int unused;
    K5aString() {}
    ~K5aString() { w3d_string_base_finish(this); w3d_string_release(this); }
};
struct K5aDispatcher { char pad0[180]; int immediate; };
struct K5aEngineContext { char pad0[52]; int tick; };
extern "C" void *w3d_message_pool_804b1754;
extern "C" void *FUN_801613f0(void *pool, int size);
extern "C" void *w3d_message_string_init(void *storage, int id, const char *text);
extern "C" int w3d_message_post_current(void *message);
extern "C" K5aEngineContext *w3d_engine_get_context();
extern "C" int FUN_800f985c(int id, K5aString *text, int due);

extern "C" void k5a_message_text_send_800a7b24(K5aDispatcher *self, int id, const char *text)
{
    if (self->immediate != 0)
    {
        w3d_message_post_current(w3d_message_string_init(FUN_801613f0(w3d_message_pool_804b1754, 12), id, text));
    }
    else
    {
        K5aString string;
        w3d_string_from_text(&string, text);
        FUN_800f985c(id, &string, w3d_engine_get_context()->tick + 10);
    }
}
