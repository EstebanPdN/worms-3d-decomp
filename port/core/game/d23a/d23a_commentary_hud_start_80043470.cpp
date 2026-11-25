#include "w3d_ptr.h"
#line 1 "d23a_commentary_hud_start_80043470.cpp"
/* Commentary HUD start (0x80043470): creates the panel object through
 * 0x80164514 (service 0x804b178c, type 0x804109c0 resolved by 0x8020b680,
 * owner word +20) into +68, resets the HUD (0x80047e94), clears +256, reads
 * the "CommentaryPanel.Comment" and "ActiveWormIndex" properties straight
 * into +124 and +128 (0x800fc1b0), subscribes the object (0x80162024) to
 * thirty messages with handler slots +132..+248, copies the global word
 * 0x804aa978 into +92, runs 0x80041d28(self, 0) and sets +252 to 1. Field
 * and type names are inferred from the original instructions. Strings and
 * globals are external views of original data; the unit owns no data.
 *
 * The subscription takes the message id by const reference; the int result
 * of the cache lookup converts to a temporary at each call, which gets the
 * next stack slot after the two property keys (sp+16..74). */
struct Object;
struct PropertyKey { Ptr32<const char> name; };
struct MessageCache { unsigned short id; unsigned char unknown[6]; };
struct Handler { char unknown[4]; };
struct CommentaryHud {
    char unknown00[20];
    int owner;                 /* +20 */
    char unknown24[44];
    Ptr32<void> panel;               /* +68 */
    char unknown72[20];
    int mode;                  /* +92 */
    char unknown96[28];
    Ptr32<Object> comment;           /* +124 */
    Ptr32<Object> activeWormIndex;   /* +128 */
    Handler handlers[30];      /* +132 */
    int started;               /* +252 */
    int unknown256;            /* +256 */
};
extern "C" Ptr32<void> w3d_type_lookup_8020b680(Ptr32<void>);
extern "C" Ptr32<void> w3d_create_panel_80164514(Ptr32<void>, Ptr32<void>, int);
extern "C" void w3d_hud_reset_80047e94(Ptr32<CommentaryHud>);
extern "C" void w3d_commentary_select_80041d28(Ptr32<CommentaryHud>, int);
extern "C" int w3d_resource_property_800fc1b0(Ptr32<PropertyKey>, Ptr32<Ptr32<Object>>);
extern "C" int w3d_cached_message_id_8015f5a0(Ptr32<MessageCache>, int);
extern "C" int w3d_subscribe_80162024(Ptr32<CommentaryHud>, const unsigned short &, Ptr32<void>);
extern Ptr32<void> w3d_service_804b178c;
extern int w3d_mode_804aa978;
extern unsigned char w3d_type_804109c0[];
extern MessageCache w3d_message_804ad1e0,
    w3d_message_804ad1e8,
    w3d_message_804ad1f0,
    w3d_message_804ad1f8,
    w3d_message_804ad200,
    w3d_message_804ad208,
    w3d_message_804ad210,
    w3d_message_804ad218,
    w3d_message_804ad220,
    w3d_message_804ad228,
    w3d_message_804ad230,
    w3d_message_804ad238,
    w3d_message_804ad240,
    w3d_message_804ad248,
    w3d_message_804ad250,
    w3d_message_804ad258,
    w3d_message_804ad260,
    w3d_message_804ad268,
    w3d_message_804ad270,
    w3d_message_804ad278,
    w3d_message_804ad280,
    w3d_message_804ad288,
    w3d_message_804ad290,
    w3d_message_804ad298,
    w3d_message_804ad2a0,
    w3d_message_804ad2a8,
    w3d_message_804ad2b0,
    w3d_message_804ad2b8,
    w3d_message_804ad2c0,
    w3d_message_804ad2c8;
extern "C" char w3d_string_80374de0[]; /* "CommentaryPanel.Comment" */
extern "C" char w3d_string_80374df8[]; /* "ActiveWormIndex" */

inline void GetProperty(Ptr32<const char> name, Ptr32<Ptr32<Object>> out)
{
    PropertyKey key;
    key.name = name;
    w3d_resource_property_800fc1b0(&key, out);
}

extern "C" void w3d_d23a_commentary_hud_start_80043470(Ptr32<CommentaryHud> self)
{
    Ptr32<void> type = w3d_type_lookup_8020b680(w3d_type_804109c0);
    self->panel = w3d_create_panel_80164514(w3d_service_804b178c, type, self->owner);
    w3d_hud_reset_80047e94(self);
    self->unknown256 = 0;
    GetProperty(w3d_string_80374de0, &self->comment);
    GetProperty(w3d_string_80374df8, &self->activeWormIndex);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ad1e0, 1), &self->handlers[0]);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ad1e8, 1), &self->handlers[1]);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ad1f0, 1), &self->handlers[5]);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ad1f8, 1), &self->handlers[2]);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ad200, 1), &self->handlers[3]);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ad208, 1), &self->handlers[4]);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ad210, 1), &self->handlers[6]);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ad218, 1), &self->handlers[7]);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ad220, 1), &self->handlers[8]);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ad228, 1), &self->handlers[9]);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ad230, 1), &self->handlers[10]);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ad240, 1), &self->handlers[11]);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ad248, 1), &self->handlers[12]);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ad258, 1), &self->handlers[14]);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ad250, 1), &self->handlers[13]);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ad260, 1), &self->handlers[15]);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ad268, 1), &self->handlers[16]);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ad270, 1), &self->handlers[17]);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ad278, 1), &self->handlers[18]);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ad280, 1), &self->handlers[19]);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ad288, 1), &self->handlers[20]);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ad290, 1), &self->handlers[21]);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ad298, 1), &self->handlers[22]);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ad2a0, 1), &self->handlers[23]);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ad238, 1), &self->handlers[24]);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ad2a8, 1), &self->handlers[26]);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ad2b0, 1), &self->handlers[25]);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ad2b8, 1), &self->handlers[27]);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ad2c0, 1), &self->handlers[28]);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ad2c8, 1), &self->handlers[29]);
    self->mode = w3d_mode_804aa978;
    w3d_commentary_select_80041d28(self, 0);
    self->started = 1;
}


