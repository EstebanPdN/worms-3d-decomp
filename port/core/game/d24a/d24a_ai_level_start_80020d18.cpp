#include "w3d_ptr.h"
#line 1 "d24a_ai_level_start_80020d18.cpp"
/* AI level start-up (0x80020d18): reads the "ActiveWormIndex" resource into
 * +28; when bit 0x2000000 of word +188 of the game state 0x804b1788 is set it
 * subscribes the object (0x80162024) to fifteen cached message ids with
 * handler slots +48..+108, reads "ObjectCount.Active" into +112, records the
 * type 0x8040dda8 in +116 and creates its object (0x80164514), creates an
 * object of type 0x8040dab8 into +32, loads "AIParams.CPU2" and applies its
 * value (0x801797b4) to each of the sixteen players through 0x800fcb80 and
 * 0x801ea4c8. Field and type names are inferred from the original
 * instructions. Strings and globals are external views of original data; the
 * unit owns no data. */
struct Object;
struct ObjectVtable {
    Ptr32<void> unknown00[3];
    Ptr32<void (Ptr32<Object>)> retain;   /* +12 */
    Ptr32<void (Ptr32<Object>)> release;  /* +16 */
};
struct Object { Ptr32<ObjectVtable> vtable; };
struct Ref {
    Ptr32<Object> value;
    Ref() { value = 0; }
    ~Ref() { if (value) value->vtable->release(value); }
private:
    Ref(const Ref &);
};
struct PropertyKey { Ptr32<const char> name; };
struct MessageCache { unsigned short id; unsigned char unknown[6]; };
struct String {
    Ptr32<char> text;
    String();
    ~String();
};
extern "C" void w3d_string_finish_8020c5c4(Ptr32<String>);
extern "C" void w3d_string_release_80341588(Ptr32<String>);
inline String::~String() {
    w3d_string_finish_8020c5c4(this);
    w3d_string_release_80341588(this);
}
struct Tag;
extern "C" void w3d_tag_destroy_80178474(Ptr32<Tag>, int);
struct Tag {
    unsigned a, b;
    Tag() { a = 0; b = 0xe3a8; }
    ~Tag() { w3d_tag_destroy_80178474(this, 2); }
};
struct GameState { char unknown00[188]; unsigned flags; };
struct Self {
    char unknown00[20];
    unsigned id;  /* +20 */
    char unknown24[4];
    Ptr32<Object> activeWormIndex;  /* +28 */
    Ptr32<void> created32;  /* +32 */
    char unknown36[12];
    char slot48[4];  /* +48 */
    char slot52[4];  /* +52 */
    char slot56[4];  /* +56 */
    char unknown60[4];
    char slot64[4];  /* +64 */
    char slot68[4];  /* +68 */
    char slot72[4];  /* +72 */
    char slot76[4];  /* +76 */
    char slot80[4];  /* +80 */
    char slot84[4];  /* +84 */
    char slot88[4];  /* +88 */
    char slot92[4];  /* +92 */
    char slot96[4];  /* +96 */
    char slot100[4];  /* +100 */
    char slot104[4];  /* +104 */
    char slot108[4];  /* +108 */
    Ptr32<Object> objectCountActive;  /* +112 */
    Ptr32<void> type116;  /* +116 */
};
extern "C" int w3d_resource_property_800fc1b0(Ptr32<PropertyKey>, Ptr32<Ptr32<Object>>);
extern "C" int w3d_cached_message_id_8015f5a0(Ptr32<MessageCache>, int);
extern "C" int w3d_subscribe_80162024(Ptr32<Self>, const unsigned short &, Ptr32<void>);
extern "C" Ptr32<void> w3d_type_lookup_8020b680(Ptr32<void>);
extern "C" Ptr32<void> w3d_create_80164514(Ptr32<void>, Ptr32<void>, unsigned);
extern "C" Ptr32<Object> w3d_identity_80341584(Ptr32<Object>);
extern "C" Ptr32<void> w3d_value_801797b4(Ptr32<Object>);
extern "C" Ptr32<void> w3d_player_800fcb80(unsigned, Ptr32<Tag>);
extern "C" void w3d_apply_801ea4c8(Ptr32<void>, Ptr32<void>);
extern Ptr32<GameState> w3d_game_state_804b1788;
extern Ptr32<void> w3d_service_804b178c;
extern unsigned char w3d_type_8040dda8[], w3d_type_8040dab8[];
extern MessageCache w3d_message_804ac950, w3d_message_804ac958, w3d_message_804ac960, w3d_message_804ac968, w3d_message_804ac970, w3d_message_804ac978, w3d_message_804ac980, w3d_message_804ac988, w3d_message_804ac990, w3d_message_804ac998, w3d_message_804ac9a0, w3d_message_804ac9a8, w3d_message_804ac9b0, w3d_message_804ac9b8, w3d_message_804ac9c0;
extern "C" char w3d_string_8036bcf8[]; /* "ActiveWormIndex" */
extern "C" char w3d_string_8036bd08[]; /* "ObjectCount.Active" */
extern "C" char w3d_string_8036bd1c[]; /* "AIParams.CPU2" */

inline void GetResource(Ptr32<const char> name, Ptr32<Ptr32<Object>> out)
{
    PropertyKey key;
    key.name = name;
    w3d_resource_property_800fc1b0(&key, out);
}

inline void Init(Ptr32<Self> s, Ptr32<void> t, Ptr32<void> &out) { out = t; w3d_create_80164514(w3d_service_804b178c, out, s->id); }
extern "C" void w3d_d24a_ai_level_start_80020d18(Ptr32<Self> self)
{
    GetResource(w3d_string_8036bcf8, &self->activeWormIndex);
    if (w3d_game_state_804b1788->flags & 0x2000000) {
        w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ac950, 1), self->slot48);
        w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ac958, 1), self->slot52);
        w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ac960, 1), self->slot56);
        w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ac968, 1), self->slot64);
        w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ac970, 1), self->slot68);
        w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ac978, 1), self->slot72);
        w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ac980, 1), self->slot76);
        w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ac988, 1), self->slot80);
        w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ac990, 1), self->slot84);
        w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ac998, 1), self->slot88);
        w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ac9a0, 1), self->slot92);
        w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ac9a8, 1), self->slot96);
        w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ac9b0, 1), self->slot100);
        w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ac9b8, 1), self->slot104);
        w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ac9c0, 1), self->slot108);
        GetResource(w3d_string_8036bd08, &self->objectCountActive);
        Init(self, w3d_type_lookup_8020b680(w3d_type_8040dda8), self->type116);
        Ptr32<void> second = w3d_type_lookup_8020b680(w3d_type_8040dab8);
        self->created32 = w3d_create_80164514(w3d_service_804b178c, second, self->id);
        String name;
        Ref params;
        GetResource(w3d_string_8036bd1c, &params.value);
        Ptr32<void> value = w3d_value_801797b4(w3d_identity_80341584(params.value));
        Tag tag;
        for (unsigned i = 0; i <= 15; i++)
            w3d_apply_801ea4c8(w3d_player_800fcb80(i, &tag), value);
    }
}


