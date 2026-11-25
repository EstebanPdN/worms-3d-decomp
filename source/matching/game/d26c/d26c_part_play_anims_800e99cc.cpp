// d26c: 0x800e99cc. Start a part's two named animations: stop the current one when the first name is set, then play
// each name that is not empty. Names are inferred; String is one word; 0x80181640 uses the admitted cc21b prototype.
struct StringHeader { unsigned short refs; };
struct String {
    char *text;
    String(const String &);
    ~String();
};
extern "C" void string_init_8020c5c0(String *);
extern "C" StringHeader *string_header_80341884(String *);
extern "C" void string_finish_8020c5c4(String *);
extern "C" void string_release_80341588(String *);
inline String::String(const String &o) {
    string_init_8020c5c0(this);
    text = o.text;
    string_header_80341884(this)->refs++;
}
inline String::~String() {
    string_finish_8020c5c4(this);
    string_release_80341588(this);
}
extern "C" int strcmp(const char *, const char *);
inline bool operator!=(const String &a, const char *b) { return strcmp(a.text, b) != 0; }
struct Desc { char u0[196]; String b; char u200[84]; String a; };
struct Mesh;
struct Part {
    char u0[28];
    void *h28;
    Mesh *mesh;
    char u36[120];
    int state;
    char u160[28];
    int anim;
};
extern "C" void *empty_80341584(void *);
extern "C" Desc *desc_801797b4(void *);
extern "C" int check_8018179c(Mesh *, int, int);
extern "C" int play_80181640(Mesh *, const char *, int *, float, float, int, float);
extern char empty_text_8038b1f8[];
extern "C" void d26c_part_play_anims_800e99cc(Part *self) {
    Desc *d = desc_801797b4(empty_80341584(self->h28));
    if (self->state == 1) self->state = 2;
    String a(d->a);
    String b(d->b);
    if (self->anim != -1 && a != empty_text_8038b1f8) check_8018179c(self->mesh, self->anim, 0);
    if (a != empty_text_8038b1f8) {
        int out;
        play_80181640(self->mesh, a.text, &out, 1.0f, -1.0f, 0, 0.0f);
    }
    if (b != empty_text_8038b1f8) {
        play_80181640(self->mesh, b.text, &self->anim, 1.0f, -1.0f, 0, 0.0f);
        check_8018179c(self->mesh, self->anim, 1);
    }
}
