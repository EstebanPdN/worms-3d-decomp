extern "C" {
struct S4Message { unsigned char base[8]; unsigned char text[8]; };
void w3d_set_value_800fc43c(const char **, int);
void w3d_message_name_8015f704(void *, const char *);
void *w3d_allocate_message_801613f0(void *, int);
int w3d_cached_message_id(void *, int);
void *w3d_message_string_init(void *, unsigned short, const char *);
void w3d_message_post_current(void *);
void w3d_string_base_finish(void *);
void w3d_string_release(void *);
void w3d_auto_8015f558(void *, int);
extern void *w3d_message_pool_804b1754;
extern const char w3d_str_803cec70[], w3d_str_803ce9a0[], w3d_str_803cec80[], w3d_str_803ceac8[];
extern const char w3d_str_803ceb40[], w3d_str_803cec94[], w3d_str_803ceca8[], w3d_str_803cecbc[];
// Register allocation differs in 11 words after six attempts.
#if 0
void w3d_frontend_select_mission_type(void *, int type)
{
    S4Message first, second;

    const char *awarded = w3d_str_803cec70;
    const char *campaign, *challenge, *tutorial;
    w3d_set_value_800fc43c(&awarded,0);
    switch(type) {
    case 0: {
        S4Message *p; unsigned char *text;
        p = &first;
        campaign = w3d_str_803ce9a0;
        w3d_set_value_800fc43c(&campaign,0);
        text = (unsigned char *)p + 8;
        w3d_message_name_8015f704(&first,w3d_str_803cec80);
        { void *m = w3d_allocate_message_801613f0(w3d_message_pool_804b1754,12);
          w3d_message_post_current(w3d_message_string_init(m,(unsigned short)w3d_cached_message_id(p,1),w3d_str_803ceb40)); }
        w3d_string_base_finish(text); w3d_string_release(text);
        w3d_auto_8015f558(p,2);
        break; }
    case 4: {
        S4Message *p; unsigned char *text;
        S4Message *q; unsigned char *text2;
        p = &first;
        challenge = w3d_str_803ce9a0;
        w3d_set_value_800fc43c(&challenge,4);
        text = (unsigned char *)p + 8;
        q = &second; text2 = (unsigned char *)q + 8;
        w3d_message_name_8015f704(&first,w3d_str_803ceac8);
        { void *m = w3d_allocate_message_801613f0(w3d_message_pool_804b1754,12);
          w3d_message_post_current(w3d_message_string_init(m,(unsigned short)w3d_cached_message_id(p,1),w3d_str_803cec94)); }
        w3d_message_name_8015f704(q,w3d_str_803ceca8);
        { void *m = w3d_allocate_message_801613f0(w3d_message_pool_804b1754,12);
          w3d_message_post_current(w3d_message_string_init(m,(unsigned short)w3d_cached_message_id(q,1),w3d_str_803ceb40)); }
        w3d_string_base_finish(text2); w3d_string_release(text2);
        w3d_auto_8015f558(q,2);
        w3d_string_base_finish(text); w3d_string_release(text);
        w3d_auto_8015f558(p,2);
        break; }
    case 3: {
        S4Message *p; unsigned char *text;
        p = &first;
        tutorial = w3d_str_803ce9a0;
        w3d_set_value_800fc43c(&tutorial,3);
        text = (unsigned char *)p + 8;
        w3d_message_name_8015f704(&first,w3d_str_803cecbc);
        { void *m = w3d_allocate_message_801613f0(w3d_message_pool_804b1754,12);
          w3d_message_post_current(w3d_message_string_init(m,(unsigned short)w3d_cached_message_id(p,1),w3d_str_803ceb40)); }
        w3d_string_base_finish(text); w3d_string_release(text);
        w3d_auto_8015f558(p,2);
        break; }
    }
}
#endif
}
