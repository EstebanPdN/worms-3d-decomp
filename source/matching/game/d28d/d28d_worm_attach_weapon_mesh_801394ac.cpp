// GWMP8P rev0 0x801394ac. Attach the current weapon's model to a worm. Names
// are inferred; virtual slots are reference-ABI observations.
struct Obj { void **vtable; };
struct String {
    char *text;
    String();
    String(const String &);
    ~String();
    void operator=(const char *);
};
extern "C" void finish_8020c5c4(String *);
extern "C" void release_80341588(String *);
inline String::~String() { finish_8020c5c4(this); release_80341588(this); }
struct Ref {
    Obj *p;
    Ref() { p = 0; }
    ~Ref() { if (p) ((void (*)(Obj *))p->vtable[4])(p); }
};
struct Mesh;
struct Part { struct Table { char u0[92]; void (*attach)(Part *, Obj *, char *); } *vt; };
struct Worm { char u0[28]; Part *mesh; char u20[136]; Obj *held; char uac[300]; float cueA; char u1dc[124]; int lights; char u25c[80]; int weapon; };
extern "C" int any_handle_8013f844(Worm *);
extern "C" void clear_8013e3d4(Worm *);
extern "C" int set_name_8015adf4(String *, Ref *, int);
extern "C" Obj *cast_80343584(Obj *);
extern "C" int set_lights_80182410(Obj *, int);
extern "C" void bind_8013e35c(Worm *);
extern "C" int play_80181640(Obj *, const char *, float, float, float, float *, int);
inline void load(String &s, Ref &r) { set_name_8015adf4(&s, &r, 255); }
extern char *nm_804ab32c, *nA_804ab33c, *nB_804ab340, *nC_804ab344, *nD_804ab348, *nE_804ab34c, *nF_804ab350, *nG_804ab354, *nH_804ab358, *nI_804ab35c, *nJ_804ab360, *nK_804ab364, *nL_804ab368, *nM_804ab36c, *nN_804ab370;
extern "C" void d28d_worm_attach_weapon_mesh_801394ac(Worm *self) {
    String name;
    if (self->weapon != 48 && self->weapon != 41 && self->weapon != 42 && any_handle_8013f844(self)) return;
    switch ((unsigned)self->weapon) {
    case 13: name = nA_804ab33c; break;
    case 10: name = nB_804ab340; break;
    case 48: name = nC_804ab344; break;
    case 42: name = nD_804ab348; break;
    case 43: name = nF_804ab350; break;
    case 12: name = nE_804ab34c; break;
    case 39: case 40: name = nG_804ab354; break;
    case 44: name = nH_804ab358; break;
    case 52: name = nI_804ab35c; break;
    case 16: name = nJ_804ab360; break;
    case 45: name = nK_804ab364; break;
    case 17: name = nL_804ab368; break;
    case 5: name = nM_804ab36c; break;
    case 26: name = nN_804ab370; break;
    default:
        clear_8013e3d4(self);
        return;
    }
    {
        String *n = &name;
        Ref ref;
        set_name_8015adf4(n, &ref, 255);
        Obj *o = cast_80343584(ref.p);
        if (o) ((void (*)(Obj *))o->vtable[3])(o);
        if (self->held) ((void (*)(Obj *))self->held->vtable[4])(self->held);
        self->held = o;
    }
    self->mesh->vt->attach(self->mesh, self->held, nm_804ab32c);
    set_lights_80182410(self->held, self->lights);
    if (self->weapon == 44) bind_8013e35c(self);
    else if (self->weapon == 42) play_80181640(cast_80343584((Obj *)self->mesh), "DrawParachute", 1.0f, -1.0f, 0.0f, &self->cueA, 0);
    else if (self->weapon == 48) play_80181640(cast_80343584((Obj *)self->mesh), "DrawJetpack", 1.0f, -1.0f, 0.0f, &self->cueA, 0);
}
