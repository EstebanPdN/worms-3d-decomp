#include "w3d_ptr.h"
#line 1 "d21a_level_load_8006d610.cpp"
/* Level start-up loader (0x8006d610): reads the "Game.NextLevel" property,
 * looks the named level record up and returns 0 when it is unknown.
 * Otherwise it publishes the record's land file and current script as
 * properties, posts the two string messages for the +64 and +52 texts, posts
 * the particle-file message when the record has one, publishes the particle
 * override file and (when present) the land materials, copies the record's
 * fog range into the global fog settings and reads Fog.MinRange,
 * Fog.MaxRange and Fog.Colour into locals that are not used afterwards.
 * Returns 1. Field and type names are inferred from the original
 * instructions. The property names are external views of the original
 * .rodata; the unit owns no data.
 *
 * Before the particle-file message and the land-materials property, the
 * original copies the record string into a by-value String temporary and
 * destroys it again without using it (inline copy 0x8020c5c0/0x80341884,
 * then 0x8020c5c4/0x80341588): a by-value argument of a debug helper whose
 * body is empty in this build.
 *
 * The fog range destination is a two-float structure: as a structure member
 * store, GCC keeps each record load after the previous store, as in the
 * original. */
struct String {
    Ptr32<char> text;
    String(const String &other);
    ~String();
    unsigned Length() const { return ((Ptr32<unsigned short>)text)[-2]; }
};
extern "C" void w3d_string_base_init_8020c5c0(Ptr32<String>);
extern "C" Ptr32<unsigned short> w3d_string_header_80341884(Ptr32<String>);
extern "C" void w3d_string_base_finish_8020c5c4(Ptr32<String>);
extern "C" void w3d_string_release_80341588(Ptr32<String>);
inline String::String(const String &other) {
    w3d_string_base_init_8020c5c0(this);
    text = other.text;
    ++*w3d_string_header_80341884(this);
}
inline String::~String() {
    w3d_string_base_finish_8020c5c4(this);
    w3d_string_release_80341588(this);
}
/* Debug note taking its text by value; the body is empty in this build. */
inline void DebugNote(String) {}

struct PropertyKey { Ptr32<const char> name; };
struct LevelRecord {
    char unknown00[20];
    float fogFar;            /* +20 */
    float fogNear;           /* +24 */
    char unknown1c[20];
    String particleFile;     /* +48 */
    String text52;           /* +52, posted with message 0x804ad764 */
    String landFile;         /* +56 */
    String landMaterials;    /* +60 */
    String text64;           /* +64, posted with message 0x804ad75c */
    String currentScript;    /* +68 */
};
struct Message;
struct MessageCache { unsigned short id; unsigned char unknown[6]; };
struct FogRange { float nearRange; float farRange; };

extern "C" int w3d_string_property_800fc2b0(Ptr32<PropertyKey>, Ptr32<Ptr32<const char>>);
extern "C" int w3d_level_lookup_800fc330(Ptr32<PropertyKey>, Ptr32<Ptr32<LevelRecord>>);
extern "C" int w3d_string_property_write_800fc550(Ptr32<PropertyKey>, Ptr32<const char>);
extern "C" int w3d_float_property_800fc270(Ptr32<PropertyKey>, Ptr32<float>);
extern "C" int w3d_colour_property_800fc370(Ptr32<PropertyKey>, Ptr32<void>);
extern "C" Ptr32<Message> w3d_arena_alloc_801613f0(Ptr32<void>, int);
extern "C" int w3d_cached_message_id_8015f5a0(Ptr32<MessageCache>, int);
extern "C" Ptr32<Message> w3d_message_string_init_8010a8e0(Ptr32<Message>, unsigned short, Ptr32<const char>);
extern "C" int w3d_message_post_8016239c(Ptr32<Message>);
extern Ptr32<void> w3d_message_arena_804b1754;
extern MessageCache w3d_message_804ad75c, w3d_message_804ad764, w3d_message_804ad774;
extern FogRange w3d_fog_range_804aa78c;
extern "C" const char *w3d_mapa_um_tierra(const char *level);       /* port, v26 */
extern "C" const char *w3d_mapa_um_materiales(const char *level);   /* port, v26 */
extern "C" const char *w3d_mapa_um_tema(const char *level);         /* port, v27: tema y hora del mapa de UM */
extern "C" const char *w3d_mapa_um_hora(const char *level);
extern "C" char w3d_string_8037bb64[]; /* "Game.NextLevel" */
extern "C" char w3d_string_8037c0d4[]; /* "Land.File" */
extern "C" char w3d_string_8037c0e0[]; /* "GameLogic.CurrentScript" */
extern "C" char w3d_string_8037c110[]; /* "Particle.OverrideFile" */
extern "C" char w3d_string_8037bbbc[]; /* "Land.Materials" */
extern "C" char w3d_string_8037c178[]; /* "Fog.MinRange" */
extern "C" char w3d_string_8037c188[]; /* "Fog.MaxRange" */
extern "C" char w3d_string_8037c198[]; /* "Fog.Colour" */

inline void SetStringProperty(Ptr32<const char> name, Ptr32<const char> value)
{
    PropertyKey key;
    key.name = name;
    w3d_string_property_write_800fc550(&key, value);
}

extern "C" int w3d_d21a_level_load_8006d610(void)
{
    PropertyKey levelKey;
    levelKey.name = w3d_string_8037bb64;
    PropertyKey levelName;
    w3d_string_property_800fc2b0(&levelKey, &levelName.name);
    Ptr32<LevelRecord> record;
    if (w3d_level_lookup_800fc330(&levelName, &record) < 0) return 0;
    Ptr32<LevelRecord> level = record;
    // Port (v26): partida rápida con el mapa de Ultimate Mayhem (core/native/mapa_um.cpp): su paisaje y sus materiales.
    const char *um_tierra = w3d_mapa_um_tierra(levelName.name.get());
    const char *um_materiales = w3d_mapa_um_materiales(levelName.name.get());
    const char *um_tema = w3d_mapa_um_tema(levelName.name.get());
    const char *um_hora = w3d_mapa_um_hora(levelName.name.get());
    if (um_tierra) SetStringProperty(w3d_string_8037c0d4, um_tierra);
    else SetStringProperty(w3d_string_8037c0d4, level->landFile.text);
    SetStringProperty(w3d_string_8037c0e0, level->currentScript.text);
    Ptr32<Message> message = w3d_arena_alloc_801613f0(w3d_message_arena_804b1754, 12);
    w3d_message_post_8016239c(w3d_message_string_init_8010a8e0(message,
        w3d_cached_message_id_8015f5a0(&w3d_message_804ad75c, 1), um_tema ? Ptr32<const char>(um_tema) : Ptr32<const char>(level->text64.text)));
    message = w3d_arena_alloc_801613f0(w3d_message_arena_804b1754, 12);
    w3d_message_post_8016239c(w3d_message_string_init_8010a8e0(message,
        w3d_cached_message_id_8015f5a0(&w3d_message_804ad764, 1), um_hora ? Ptr32<const char>(um_hora) : Ptr32<const char>(level->text52.text)));
    if (level->particleFile.Length()) {
        DebugNote(level->particleFile);
        message = w3d_arena_alloc_801613f0(w3d_message_arena_804b1754, 12);
        w3d_message_post_8016239c(w3d_message_string_init_8010a8e0(message,
            w3d_cached_message_id_8015f5a0(&w3d_message_804ad774, 1), level->particleFile.text));
    }
    SetStringProperty(w3d_string_8037c110, level->particleFile.text);
    if (um_materiales) SetStringProperty(w3d_string_8037bbbc, um_materiales);
    else if (level->landMaterials.Length()) {
        DebugNote(level->landMaterials);
        SetStringProperty(w3d_string_8037bbbc, level->landMaterials.text);
    }
    w3d_fog_range_804aa78c.nearRange = level->fogNear;
    w3d_fog_range_804aa78c.farRange = level->fogFar;
    PropertyKey minKey;
    minKey.name = w3d_string_8037c178;
    float minRange;
    w3d_float_property_800fc270(&minKey, &minRange);
    PropertyKey maxKey;
    maxKey.name = w3d_string_8037c188;
    float maxRange;
    w3d_float_property_800fc270(&maxKey, &maxRange);
    PropertyKey colourKey;
    colourKey.name = w3d_string_8037c198;
    unsigned colour;
    w3d_colour_property_800fc370(&colourKey, &colour);
    return 1;
}


