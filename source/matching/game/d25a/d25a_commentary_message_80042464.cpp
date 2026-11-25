/* Commentary message handler (0x80042464): message 64 runs the base handler
 * (0x8015fb34; a negative result returns 0x80004005) and starts the HUD
 * (0x80043470). Otherwise compares the id with the cached ids (0x8015f620):
 * panel show/hide (0x80041d28, 0x80047e94, state +64), plays a named comment
 * looked up from the comment key (+124) with or without a "Comment.Delay" time
 * (an invalid id produces "** INVALID STRING ID: <id>"), plays message text when
 * game state bit 0x1000 is set, clears the queues (+72, +96), switches commentary
 * (+252) and, unless +28 is set, dispatches the remaining ids to their handlers;
 * unknown ids go to the base handler. The string queue clear is the standard
 * vector erase with a copy loop that folds away (see 0x80044638). Field and type
 * names are inferred from the original instructions. Strings and globals are external views of original
 * data; the unit owns no data. */
struct String;
extern "C" void w3d_string_init_8020c5c0(String *);
extern "C" unsigned short *w3d_string_header_80341884(String *);
extern "C" void w3d_string_finish_8020c5c4(String *);
extern "C" void w3d_string_release_80341588(String *);
extern "C" void w3d_string_release_header_8020bb2c(void *);
struct String {
    const char *text;
    String();
    String(const char *);
    String(const String &o) {
        w3d_string_init_8020c5c0(this);
        text = o.text;
        ++*w3d_string_header_80341884(this);
    }
    ~String() { w3d_string_finish_8020c5c4(this); w3d_string_release_80341588(this); }
    unsigned short *header() const { return (unsigned short *)(text - 6); }
    static void release(unsigned short *h) { if (--*h == 0) w3d_string_release_header_8020bb2c(h); }
    String &operator=(const String &x) {
        ++*x.header();
        release(header());
        text = x.text;
        return *this;
    }
};
extern "C" int w3d_string_append_8020bf2c(String *, const char *);
extern "C" int w3d_string_assign_8020bd38(String *, const char *);
inline String operator+(String a, const String &b)
{
    w3d_string_append_8020bf2c(&a, b.text);
    return a;
}
struct PropertyKey { const char *name; };
struct MessageCache { unsigned short id; unsigned char unknown[6]; };
struct Message { unsigned short id; };
struct Object;
inline void Distance(String *first, String *last, int &n)
{
    n += last - first;
}

inline String *CopyRange(String *first, String *last, String *result)
{
    int n = 0;
    Distance(first, last, n);
    for (; n > 0; --n) {
        *result = *first;
        ++first;
        ++result;
    }
    return result;
}

struct FalseType {};

inline void DestroyAux(String *first, String *last, const FalseType &)
{
    for (; first != last; ++first) first->~String();
}

inline void DestroyValue(String *first, String *last, String *)
{
    DestroyAux(first, last, FalseType());
}

inline void DestroyRange(String *first, String *last)
{
    DestroyValue(first, last, first);
}

inline void Distance(int *first, int *last, int &n)
{
    n += last - first;
}

inline int *CopyRange(int *first, int *last, int *result)
{
    int n = 0;
    Distance(first, last, n);
    for (; n > 0; --n) {
        *result = *first;
        ++first;
        ++result;
    }
    return result;
}

struct StringVector {
    String *first, *last;
    void erase(String *from, String *to)
    {
        String *end = CopyRange(to, last, from);
        DestroyRange(end, last);
        last = end;
    }
    void clear() { erase(first, last); }
};
struct IntVector {
    int *first, *last;
    void clear() { last = first; }
};
struct Commentary {
    char unknown00[28];
    int unknown28;             /* +28 */
    char unknown32[32];
    int state;                 /* +64 */
    char unknown68[4];
    StringVector queue;        /* +72 */
    char unknown80[16];
    IntVector ids;             /* +96 */
    char unknown104[20];
    Object *commentKey;        /* +124 */
    char unknown128[124];
    int enabled;               /* +252 */
};
struct GameState { char unknown00[188]; unsigned flags; };
extern GameState *w3d_game_state_804b1788;
extern "C" int w3d_base_handler_8015fb34(Commentary *, Message *);
extern "C" void w3d_hud_start_80043470(Commentary *);
extern "C" int w3d_message_equals_8015f620(MessageCache *, unsigned short);
extern "C" void w3d_panel_80041d28(Commentary *, int);
extern "C" void w3d_hud_reset_80047e94(Commentary *);
extern "C" Object *w3d_identity_80343744(Object *);
extern "C" const String *w3d_object_string_80179170(Object *);
extern "C" int w3d_string_property_800fc2b0(PropertyKey *, const char **);
extern "C" int w3d_int_property_800fc230(PropertyKey *, int *);
extern "C" const char *w3d_message_text_8010a8fc(Message *);
extern "C" int w3d_message_worm_800a830c(Message *);
extern "C" void w3d_commentary_play_80043134(Commentary *, String, int);
extern "C" void w3d_on_death_800455bc(Commentary *, Message *);
extern "C" void w3d_on_80045cb4(Commentary *, Message *);
extern "C" void w3d_on_80044244(Commentary *, int);
extern "C" void w3d_on_80044410(Commentary *);
extern "C" void w3d_on_800446f4(Commentary *);
extern "C" void w3d_on_80044994(Commentary *, int);
extern "C" void w3d_on_80044a80(Commentary *);
extern "C" void w3d_on_80044bc0(Commentary *);
extern "C" void w3d_on_800450a4(Commentary *);
extern "C" void w3d_on_80044ef8(Commentary *);
extern "C" void w3d_on_8004527c(Commentary *);
extern "C" void w3d_on_80046290(Commentary *);
extern "C" void w3d_on_80046408(Commentary *, Message *);
extern "C" void w3d_on_80046764(Commentary *);
extern "C" void w3d_on_800468dc(Commentary *);
extern "C" void w3d_on_80047b6c(Commentary *);
extern "C" void w3d_on_80047d50(Commentary *);
extern "C" void w3d_on_80047fcc(Commentary *);
extern "C" void w3d_on_80048110(Commentary *);
extern MessageCache w3d_message_804ad2a8, w3d_message_804ad2b8, w3d_message_804ad2b0, w3d_message_804ad1e0, w3d_message_804ad1e8, w3d_message_804ad220, w3d_message_804ad228, w3d_message_804ad230, w3d_message_804ad238, w3d_message_804ad1f0, w3d_message_804ad268, w3d_message_804ad270, w3d_message_804ad1f8, w3d_message_804ad200, w3d_message_804ad208, w3d_message_804ad210, w3d_message_804ad218, w3d_message_804ad240, w3d_message_804ad248, w3d_message_804ad250, w3d_message_804ad258, w3d_message_804ad260, w3d_message_804ad278, w3d_message_804ad280, w3d_message_804ad288, w3d_message_804ad290, w3d_message_804ad298, w3d_message_804ad2a0, w3d_message_804ad2c0, w3d_message_804ad2c8;
extern "C" char w3d_string_80374da8[]; /* "** INVALID STRING ID: " */
extern "C" char w3d_string_80374dc0[]; /* comment delay property */



inline String Prefixed(const String &p, const String &n) { return p + n; }

extern "C" int w3d_d25a_commentary_message_80042464(Commentary *self, Message *message)
{
    unsigned short id = message->id;
    if (id == 64) {
        if (w3d_base_handler_8015fb34(self, message) >= 0) {
            w3d_hud_start_80043470(self);
            return 0;
        }
        return 0x80004005;
    }
    if (w3d_message_equals_8015f620(&w3d_message_804ad2a8, id)) {
        w3d_panel_80041d28(self, 1);
        w3d_hud_reset_80047e94(self);
        self->state = 4;
    }
    if (w3d_message_equals_8015f620(&w3d_message_804ad2b8, message->id)) self->state = 0;
    if (w3d_message_equals_8015f620(&w3d_message_804ad2b0, message->id)) {
        w3d_panel_80041d28(self, 0);
        w3d_hud_reset_80047e94(self);
        self->state = 4;
    }
    if (w3d_message_equals_8015f620(&w3d_message_804ad1e0, message->id)) {
        String name(*w3d_object_string_80179170(w3d_identity_80343744(self->commentKey)));
        const char *found;
        PropertyKey key;
        key.name = name.text;
        int error = w3d_string_property_800fc2b0(&key, &found);
        String text;
        if (error < 0) text = Prefixed(String(w3d_string_80374da8), name);
        else w3d_string_assign_8020bd38(&text, found);
        w3d_commentary_play_80043134(self, text, 0);
    } else if (w3d_message_equals_8015f620(&w3d_message_804ad1e8, message->id)) {
        if (w3d_game_state_804b1788->flags & 0x1000)
            w3d_commentary_play_80043134(self, String(w3d_message_text_8010a8fc(message)), 0);
    } else {
        int hit = w3d_message_equals_8015f620(&w3d_message_804ad220, message->id);
        if (hit) {
            self->queue.clear();
            self->ids.clear();
        } else if (w3d_message_equals_8015f620(&w3d_message_804ad228, message->id)) {
            self->enabled = 0;
        } else if (w3d_message_equals_8015f620(&w3d_message_804ad230, message->id)) {
            self->enabled = 1;
        } else if (w3d_message_equals_8015f620(&w3d_message_804ad238, id)) {
            String name(*w3d_object_string_80179170(w3d_identity_80343744(self->commentKey)));
            const char *found;
            PropertyKey key;
            key.name = name.text;
            int error = w3d_string_property_800fc2b0(&key, &found);
            String text;
            if (error < 0) text = Prefixed(String(w3d_string_80374da8), name);
            else w3d_string_assign_8020bd38(&text, found);
            PropertyKey delayKey;
            int delay = 1000;
            delayKey.name = w3d_string_80374dc0;
            w3d_int_property_800fc230(&delayKey, &delay);
            w3d_commentary_play_80043134(self, text, delay);
        } else if (self->unknown28 != 0) {
            goto base;
        } else if (w3d_message_equals_8015f620(&w3d_message_804ad1f0, message->id)) {
            String name(*w3d_object_string_80179170(w3d_identity_80343744(self->commentKey)));
            w3d_commentary_play_80043134(self, name, 0);
        } else
        if (w3d_message_equals_8015f620(&w3d_message_804ad268, id)) {
            w3d_on_death_800455bc(self, message);
        } else
        if (w3d_message_equals_8015f620(&w3d_message_804ad270, id)) {
            w3d_on_80045cb4(self, message);
        } else
        if (w3d_message_equals_8015f620(&w3d_message_804ad1f8, message->id)) {
            w3d_on_80044244(self, w3d_message_worm_800a830c(message));
        } else
        if (w3d_message_equals_8015f620(&w3d_message_804ad200, message->id)) {
            w3d_on_80044410(self);
        } else
        if (w3d_message_equals_8015f620(&w3d_message_804ad208, message->id) || w3d_message_equals_8015f620(&w3d_message_804ad210, message->id)) {
            w3d_on_800446f4(self);
        } else
        if (w3d_message_equals_8015f620(&w3d_message_804ad218, message->id)) {
            w3d_on_80044994(self, w3d_message_worm_800a830c(message));
        } else
        if (w3d_message_equals_8015f620(&w3d_message_804ad240, message->id)) {
            w3d_on_80044a80(self);
        } else
        if (w3d_message_equals_8015f620(&w3d_message_804ad248, message->id)) {
            w3d_on_80044bc0(self);
        } else
        if (w3d_message_equals_8015f620(&w3d_message_804ad250, message->id)) {
            w3d_on_800450a4(self);
        } else
        if (w3d_message_equals_8015f620(&w3d_message_804ad258, message->id)) {
            w3d_on_80044ef8(self);
        } else
        if (w3d_message_equals_8015f620(&w3d_message_804ad260, message->id)) {
            w3d_on_8004527c(self);
        } else
        if (w3d_message_equals_8015f620(&w3d_message_804ad278, id)) {
            w3d_on_80046290(self);
        } else
        if (w3d_message_equals_8015f620(&w3d_message_804ad280, id)) {
            w3d_on_80046408(self, message);
        } else
        if (w3d_message_equals_8015f620(&w3d_message_804ad288, id)) {
            w3d_on_80046764(self);
        } else
        if (w3d_message_equals_8015f620(&w3d_message_804ad290, id)) {
            w3d_on_800468dc(self);
        } else
        if (w3d_message_equals_8015f620(&w3d_message_804ad298, id)) {
            w3d_on_80047b6c(self);
        } else
        if (w3d_message_equals_8015f620(&w3d_message_804ad2a0, id)) {
            w3d_on_80047d50(self);
        } else
        if (w3d_message_equals_8015f620(&w3d_message_804ad2c0, id)) {
            w3d_on_80047fcc(self);
        } else
        if (!w3d_message_equals_8015f620(&w3d_message_804ad2c8, id)) {
        base:
            return w3d_base_handler_8015fb34(self, message);
        } else {
            w3d_on_80048110(self);
        }
    }
    return 0;
}
