#include "w3d_ptr.h"
#line 1 "d28d_worm_attach_weapon_mesh_801394ac.cpp"
// GWMP8P rev0 0x801394ac. Attach the current weapon's model to a worm. Names
// are inferred; virtual slots are reference-ABI observations.
struct Obj { Ptr32<Ptr32<void>> vtable; };
struct String {
    Ptr32<char> text;
    String();
    String(const String &);
    ~String();
    template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((const char *)w3d_p.get()); }
 void operator=(const char *);
};
extern "C" void finish_8020c5c4(Ptr32<String>);
extern "C" void release_80341588(Ptr32<String>);
inline String::~String() { finish_8020c5c4(this); release_80341588(this); }
struct Ref {
    Ptr32<Obj> p;
    Ref() { p = 0; }
    ~Ref() { if (p) ((Ptr32<void (Ptr32<Obj>)>)p->vtable[4])(p); }
};
struct Mesh;
struct Part { struct Table { char u0[92]; Ptr32<void (Ptr32<Part>, Ptr32<Obj>, Ptr32<char>)> attach; }; Ptr32<struct Table> vt; };
struct Worm { char u0[28]; Ptr32<Part> mesh; char u20[136]; Ptr32<Obj> held; char uac[300]; float cueA; char u1dc[124]; int lights; char u25c[80]; int weapon; };
extern "C" int any_handle_8013f844(Ptr32<Worm>);
extern "C" void clear_8013e3d4(Ptr32<Worm>);
extern "C" int set_name_8015adf4(Ptr32<String>, Ptr32<Ref>, int);
extern "C" Ptr32<Obj> cast_80343584(Ptr32<Obj>);
extern "C" int set_lights_80182410(Ptr32<Obj>, int);
extern "C" void bind_8013e35c(Ptr32<Worm>);
extern "C" int play_80181640(Ptr32<Obj>, Ptr32<const char>, float, float, float, Ptr32<float>, int);
inline void load(String &s, Ref &r) { set_name_8015adf4(&s, &r, 255); }
extern Ptr32<char> nm_804ab32c; extern Ptr32<char> nA_804ab33c; extern Ptr32<char> nB_804ab340; extern Ptr32<char> nC_804ab344; extern Ptr32<char> nD_804ab348; extern Ptr32<char> nE_804ab34c; extern Ptr32<char> nF_804ab350; extern Ptr32<char> nG_804ab354; extern Ptr32<char> nH_804ab358; extern Ptr32<char> nI_804ab35c; extern Ptr32<char> nJ_804ab360; extern Ptr32<char> nK_804ab364; extern Ptr32<char> nL_804ab368; extern Ptr32<char> nM_804ab36c; extern Ptr32<char> nN_804ab370;
// Ropa de prueba (port): todo worm sin gorro de arma lleva el gorro de su equipo (w3d_hat_for_worm: el de la página
// Outfit de Crear equipo, o si no tiene, el de Developer, w3d_hat_mode; core/native/ropa_equipos.cpp) en el mismo
// HatLocator que los gorros del juego (w3d_hat_resource, en Bundles/Bundle89.xom, ver core/native/hat_militar.cpp).
extern "C" int w3d_hat_for_worm(Ptr32<Worm>);
extern "C" const char *w3d_hat_resource(int);
static const int kHatSlots = 64;
struct HatSlot { unsigned worm, hat; int kind; };
static HatSlot g_hats[kHatSlots];
static HatSlot &hat_slot(Ptr32<Worm> self) {
    unsigned w = w3d::h2g(self.get());
    HatSlot *free_slot = 0;
    for (auto &h : g_hats) { if (h.worm == w) return h; if (!h.worm && !free_slot) free_slot = &h; }
    static HatSlot spare;
    if (!free_slot) { spare = {w, 0, 0}; return spare; }
    *free_slot = {w, 0, 0};
    return *free_slot;
}
static void hat_attach(Ptr32<Worm> self) {
    const int kind = w3d_hat_for_worm(self);
    const char *resource = w3d_hat_resource(kind);
    if (!resource || !self->mesh || self->held || any_handle_8013f844(self)) return;
    String name;
    name = resource;
    Ptr32<Obj> o;
    {
        Ptr32<String> n = &name;
        Ref ref;
        set_name_8015adf4(n, &ref, 255);
        o = cast_80343584(ref.p);
        if (!o) return;
        ((Ptr32<void (Ptr32<Obj>)>)o->vtable[3])(o);
    }
    self->held = o;
    self->mesh->vt->attach(self->mesh, self->held, nm_804ab32c);
    set_lights_80182410(self->held, self->lights);
    HatSlot &s = hat_slot(self);
    s.hat = w3d::h2g(o.get()); s.kind = kind;
}
extern "C" void w3d_hat_after_clear(Ptr32<Worm> self) { if (w3d_hat_for_worm(self)) hat_attach(self); }
// Desde cada mensaje del gráfico del worm (d29d): pone, cambia o quita el gorro cuando cambia el menú Ropa.
extern "C" void w3d_hat_sync(Ptr32<Worm> self, int released) {
    HatSlot &s = hat_slot(self);
    if (released) { for (auto &h : g_hats) if (h.worm == w3d::h2g(self.get())) h = {0, 0, 0}; return; }
    unsigned held = w3d::h2g(self->held.get());
    if (s.hat && held != s.hat) { s.hat = 0; s.kind = 0; }   // el juego lo cambió (gorro de arma) o lo soltó
    const int mode = w3d_hat_for_worm(self);
    if (s.hat && s.kind != mode) { clear_8013e3d4(self); s.hat = 0; s.kind = 0; }   // otro gorro o ninguno
    if (mode && !self->held && self->mesh) hat_attach(self);
}

extern "C" void d28d_worm_attach_weapon_mesh_801394ac(Ptr32<Worm> self) {
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
        w3d_hat_after_clear(self);
        return;
    }
    {
        Ptr32<String> n = &name;
        Ref ref;
        set_name_8015adf4(n, &ref, 255);
        Ptr32<Obj> o = cast_80343584(ref.p);
        if (o) ((Ptr32<void (Ptr32<Obj>)>)o->vtable[3])(o);
        if (self->held) ((Ptr32<void (Ptr32<Obj>)>)self->held->vtable[4])(self->held);
        self->held = o;
    }
    self->mesh->vt->attach(self->mesh, self->held, nm_804ab32c);
    set_lights_80182410(self->held, self->lights);
    if (self->weapon == 44) bind_8013e35c(self);
    else if (self->weapon == 42) play_80181640(cast_80343584((Ptr32<Obj>)self->mesh), "DrawParachute", 1.0f, -1.0f, 0.0f, &self->cueA, 0);
    else if (self->weapon == 48) play_80181640(cast_80343584((Ptr32<Obj>)self->mesh), "DrawJetpack", 1.0f, -1.0f, 0.0f, &self->cueA, 0);
}


