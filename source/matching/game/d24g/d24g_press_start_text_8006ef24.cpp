/* Worms 3D GameCube PAL 0x8006ef24. Creates the press-start prompt: loads FE.Font into the +256 text with retain/release, positions it at (0, -50, 0), sets the Text.PressStart string, makes it visible and white, scales it (30, 30, 20) and hides it 750 ticks from now at +260. Field and type names are inferred from the original instructions; strings and globals are external views of original data. */
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
struct Object;
struct ObjectVtable {
    void *unknown00[3];
    void (*retain)(Object *);       // +12
    void (*release)(Object *);      // +16
};
struct Object { ObjectVtable *vtable; };
struct Ref {
    Object *value;
    ~Ref() { if (value) value->vtable->release(value); }
    Ref() {}
    Ref(const Ref &);
};
struct Vec3 { float x, y, z; Vec3() {} void set(float a, float b, float c) { x = a; y = b; z = c; } };
struct Rgba { unsigned char r, g, b, a; Rgba() {} void set(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha) { r = red; g = green; b = blue; a = alpha; } };
struct Key { const char *text; };
struct Text {
    struct V {
        void *u[19];
        void (*set_position)(Text *, Vec3 *, int);  /* +76 */
        void *u80;
        void (*set_scale)(Text *, Vec3 *, int);     /* +84 */
        void (*set_visible)(Text *, int);           /* +88 */
    } *vtable;
};
struct Context { char u[52]; int time; };
struct Self { char u0[256]; Text *text; int hideTime; };
extern "C" int load_8015adf4(const String *, Ref *, unsigned char);
extern "C" Object *as_text_80343580(Object *);
extern "C" int read_800fc2b0(Key *, int *);
extern "C" int text_style_8018d324(Text *, int);
extern "C" int text_set_8018c5b0(Text *, int);
extern "C" int fill_text_8018d35c(Text *, Rgba *);
extern "C" Context *context_80165254();
extern const char s_8037c4a8[], s_8037c4b0[];
inline void load_text(Self *self, const String &name) {
    Ref r;
    r.value = 0;
    load_8015adf4(&name, &r, 54);
    Object *o = as_text_80343580(r.value);
    if (o) o->vtable->retain(o);
    if (self->text) ((Object *)self->text)->vtable->release((Object *)self->text);
    self->text = (Text *)o;
}
extern "C" void w3d_d24g_press_start_text_8006ef24(Self *self)
{
    { String name(s_8037c4a8); load_text(self, name); }
    Vec3 position;
    Vec3 scale;
    Rgba colour;
    position.set(0.0f, -50.0f, 0.0f);
    colour.set(255, 255, 255, 255);
    scale.set(30.0f, 30.0f, 20.0f);
    Key key;
    int textId = 0;
    key.text = s_8037c4b0;
    read_800fc2b0(&key, &textId);
    text_style_8018d324(self->text, 0);
    text_set_8018c5b0(self->text, textId);
    self->text->vtable->set_position(self->text, &position, 0);
    self->text->vtable->set_visible(self->text, 1);
    fill_text_8018d35c(self->text, &colour);
    self->text->vtable->set_scale(self->text, &scale, 0);
    self->hideTime = context_80165254()->time + 750;
}
