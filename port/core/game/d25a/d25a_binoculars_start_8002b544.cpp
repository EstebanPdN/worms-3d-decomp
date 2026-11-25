#include "w3d_ptr.h"
#line 1 "d25a_binoculars_start_8002b544.cpp"
/* Binoculars HUD start (0x8002b544): loads resource "HUD.Binoculars" into +32,
 * then sets its position (virtual +84) from the screen aspect blend of game state
 * +184: x between 320 and 360, y between 240 and 270, z 1, and shows it (virtual
 * +88). Field and type names are inferred from the original instructions. The
 * string is an external view of original data; the unit owns the literal pool at
 * 0x803725b0. */
struct String;
extern "C" void w3d_string_finish_8020c5c4(Ptr32<String>);
extern "C" void w3d_string_release_80341588(Ptr32<String>);
struct String {
    Ptr32<const char> text;
    template <class W3dU> String(Ptr32<W3dU> w3d_p) : String((const char *)w3d_p.get()) {}
 String(const char *);
    ~String() { w3d_string_finish_8020c5c4(this); w3d_string_release_80341588(this); }
};
struct Vec3 { float x, y, z; };
struct Sprite;
struct SpriteVtable {
    Ptr32<void> unknown00[21];
    Ptr32<int (Ptr32<Sprite>, Ptr32<Vec3>, int)> setPosition;  /* +84 */
    Ptr32<int (Ptr32<Sprite>, int)> setVisible;           /* +88 */
};
struct Sprite { Ptr32<SpriteVtable> vtable; };
struct BinocularsHud {
    char unknown00[32];
    Ptr32<Sprite> sprite;            /* +32 */
};
struct GameState { char unknown00[184]; float aspect; };
extern Ptr32<GameState> w3d_game_state_804b1788;
extern "C" int w3d_handle_load_8015adf4(Ptr32<const String>, Ptr32<Ptr32<Sprite>>, unsigned char);
extern "C" char w3d_string_803725a0[];

extern "C" void w3d_d25a_binoculars_start_8002b544(Ptr32<BinocularsHud> self)
{
    {
        String text(w3d_string_803725a0);
        w3d_handle_load_8015adf4(&text, &self->sprite, 255);
    }
    float aspect = w3d_game_state_804b1788->aspect;
    Vec3 v;
    float rest = 1.0f - aspect;
    v.x = aspect * 360.0f + rest * 320.0f;
    v.y = aspect * 270.0f + rest * 240.0f;
    Ptr32<Vec3> p = &v;
    p->z = 1.0f;
    Ptr32<Sprite> sprite = self->sprite;
    sprite->vtable->setPosition(sprite, p, 0);
    self->sprite->vtable->setVisible(self->sprite, 0);
}


