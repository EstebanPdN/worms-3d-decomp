/* Worms 3D GameCube PAL 0x80064384. Selects the energy bar team: when the team colour at +60 of the team record differs from the stored one, stores the team and colour, fills the +36 text with the team name and opaque black, reloads the bar texture HUD.TeamEnergy{P,G,B,R,Y,C} into +28, relays it, and updates the layout and vectors. Field and type names are inferred from the original instructions; strings and globals are external views of original data. */
struct String {
    char *text;
    String(const char *);
    ~String();
    String(const String &);
};
extern "C" void string_finish_8020c5c4(String *);
extern "C" void string_release_80341588(String *);
inline String::~String() {
    string_finish_8020c5c4(this);
    string_release_80341588(this);
}
struct Rgba {
    unsigned char r, g, b, a;
    Rgba(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha) { r = red; g = green; b = blue; a = alpha; }
};
struct Team { char u[60]; unsigned char colour; };
struct Text;
struct Label { char *text; };
struct Bar { struct V { void *u[22]; void (*set88)(Bar *, void *); } *vtable; };
struct Object;
struct Self {
    char u0[28];
    Bar *bar;        /* +28 */
    char u32[4];
    Object *font;    /* +36 */
    char u40[8];
    int team;        /* +48 */
    int colour;      /* +52 */
    char u56[36];
    void *arg92;     /* +92 */
};
extern "C" Team *team_800fc7f8(int);
extern "C" Text *as_text_80343580(Object *);
extern "C" void * name_800fd3e4(Label *, int, ...);
extern "C" int fill_text_8018d35c(Text *, Label *);
extern "C" int fill_values_8018d434(Text *, Rgba *);
extern "C" int load_8015adf4(const String *, Bar **, unsigned char);
extern "C" void layout_80064a80(Self *);
extern "C" void update_800642ac(Self *);
extern "C" void update_80064198(Self *);
extern const char s_80379d40[], s_80379d00[], s_80379d50[], s_80379d60[], s_80379d70[], s_80379d80[];
#define LOAD(name) { String n(name); load_8015adf4(&n, &self->bar, 255); } break;
extern "C" void w3d_d24g_energy_bar_set_team_80064384(Self *self, int team)
{
    int colour = team_800fc7f8(team)->colour;
    if (colour != self->colour) {
        self->team = team;
        self->colour = colour;
        Text *text = as_text_80343580(self->font);
        Rgba c(0, 0, 0, 255);
        Label label;
        name_800fd3e4(&label, self->team);
        fill_text_8018d35c(text, &label);
        fill_values_8018d434(text, &c);
        switch (self->colour) {
        case 5: LOAD(s_80379d40)
        case 2: LOAD(s_80379d00)
        case 1: LOAD(s_80379d50)
        case 0: LOAD(s_80379d60)
        case 3: LOAD(s_80379d70)
        case 4: LOAD(s_80379d80)
        }
        layout_80064a80(self);
        self->bar->vtable->set88(self->bar, self->arg92);
        update_800642ac(self);
        update_80064198(self);
    }
}
