// d16c: 0x8011b188 (692 bytes). Load the HUD text backing that matches a
// team's colour (+60: 0 red, 1 blue, 2 green, 3 yellow, 4 turquoise, 5 pink,
// otherwise green) into the backing handle (+32), then rebuild it as a
// three-vertex mesh with unit scale. The float literals form this function's
// own constant pool at 0x8039af10 (1, 5, 16, 15, 0, the unsigned conversion
// bias, 10, 1/32, 0.3125).
// 0x8015adf4 forwards the resource manager's virtual load result and the mesh
// allocators return 0, so they are declared with status returns (GCC 2.95
// schedules their argument loads accordingly).

// Shared engine string; constructor and release are out of line.
struct d16c_String_8020bb54 {
 d16c_String_8020bb54(const d16c_String_8020bb54 &);
    char *text;
    d16c_String_8020bb54(const char *);
    ~d16c_String_8020bb54();
};
extern "C" void d16c_string_finish_8020c5c4(d16c_String_8020bb54 *);
extern "C" void d16c_string_release_80341588(d16c_String_8020bb54 *);
inline d16c_String_8020bb54::~d16c_String_8020bb54() {
    d16c_string_finish_8020c5c4(this);
    d16c_string_release_80341588(this);
}

struct d16c_Vec2 { float x, y; void set(float a, float b) { x = a; y = b; } };
struct d16c_Vec3 { float x, y, z;
    void set(float a, float b, float c) { x = a; y = b; z = c; } };
struct d16c_Mesh;
struct d16c_MeshVtable {
    void *unknown00[21];
    void (*scale)(d16c_Mesh *, d16c_Vec3 *, int);      // +84
};
struct d16c_Mesh { d16c_MeshVtable *vtable; };
struct d16c_Team { unsigned char unknown00[60]; unsigned char colour; };   // +60
struct d16c_HudText {
    unsigned char unknown00[32];
    void *backing;                       // +32
};

extern "C" int d16c_handle_load_8015adf4(const d16c_String_8020bb54 *, void **, unsigned char);
extern "C" d16c_Team *d16c_team_800fc7f8(unsigned);
extern "C" d16c_Mesh *d16c_handle_mesh_8034380c(void *);
extern "C" int d16c_mesh_reserve_vertices_80189450(d16c_Mesh *, int);
extern "C" int d16c_mesh_reserve_indices_8018920c(d16c_Mesh *, int);
extern "C" unsigned char *d16c_mesh_indices_80189828(d16c_Mesh *);
extern "C" d16c_Vec2 *d16c_mesh_uvs_8018963c(d16c_Mesh *);
extern "C" d16c_Vec3 *d16c_mesh_positions_80189518(d16c_Mesh *);
extern "C" d16c_Vec2 *d16c_mesh_attr_a_80189884(d16c_Mesh *);
extern "C" d16c_Vec2 *d16c_mesh_attr_b_801898e0(d16c_Mesh *);
extern const char d16c_red_8039aed4[];       // "Text.Backing.Red"
extern const char d16c_blue_8039aec0[];      // "Text.Backing.Blue"
extern const char d16c_green_8039ae90[];     // "Text.Backing.Green"
extern const char d16c_yellow_8039aee8[];    // "Text.Backing.Yellow"
extern const char d16c_turq_8039aefc[];      // "Text.Backing.Turq"
extern const char d16c_pink_8039aeac[];      // "Text.Backing.Pink"

// Pair element by byte offset (the original adds base + (index << 3)).
static inline d16c_Vec2 *d16c_pair_at(d16c_Vec2 *base, unsigned index) {
    return (d16c_Vec2 *)((char *)base + (index << 3));
}

extern "C" void d16c_hud_backing_colour_8011b188(d16c_HudText *self, unsigned team) {
    switch (d16c_team_800fc7f8(team)->colour) {
    case 5: { d16c_String_8020bb54 name(d16c_pink_8039aeac); d16c_handle_load_8015adf4(&name, &self->backing, 17); } break;
    case 2: { d16c_String_8020bb54 name(d16c_green_8039ae90); d16c_handle_load_8015adf4(&name, &self->backing, 17); } break;
    case 1: { d16c_String_8020bb54 name(d16c_blue_8039aec0); d16c_handle_load_8015adf4(&name, &self->backing, 17); } break;
    case 0: { d16c_String_8020bb54 name(d16c_red_8039aed4); d16c_handle_load_8015adf4(&name, &self->backing, 17); } break;
    case 3: { d16c_String_8020bb54 name(d16c_yellow_8039aee8); d16c_handle_load_8015adf4(&name, &self->backing, 17); } break;
    case 4: { d16c_String_8020bb54 name(d16c_turq_8039aefc); d16c_handle_load_8015adf4(&name, &self->backing, 17); } break;
    default: { d16c_String_8020bb54 name(d16c_green_8039ae90); d16c_handle_load_8015adf4(&name, &self->backing, 17); } break;
    }
    d16c_Mesh *mesh = d16c_handle_mesh_8034380c(self->backing);
    d16c_mesh_reserve_vertices_80189450(mesh, 3);
    d16c_mesh_reserve_indices_8018920c(mesh, 3);
    d16c_Vec3 scale;
    struct { float values[18]; } scratch;   // unused; the original frame reserves 72 bytes here
    d16c_Vec3 *p = &scale;
    scale.x = 1.0f;
    p->y = 1.0f;
    p->z = 1.0f;
    mesh->vtable->scale(mesh, p, 0);
    for (unsigned i = 0; i <= 2; ++i) {
        d16c_mesh_indices_80189828(mesh)[i] = i;
        d16c_pair_at(d16c_mesh_uvs_8018963c(mesh), i)->set(5.0f, 16.0f);
        d16c_mesh_positions_80189518(mesh)[i].set(15.0f, 0.0f, 0.0f);
        d16c_pair_at(d16c_mesh_attr_a_80189884(mesh), i)->set((float)i * 10.0f * 0.03125f, 0.0f);
        d16c_pair_at(d16c_mesh_attr_b_801898e0(mesh), i)->set(0.3125f, 1.0f);
    }
}
