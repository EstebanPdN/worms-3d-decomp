/* Worm pot refresh recovered from 0x8013586c (SN ProDG g++ 2.95).
 * D15dVec3's default constructor is the original empty routine 0x80343740;
 * the 48-byte transform (nine basis words, then a position) is filled by the
 * source object's virtual slot 31. The position copy is never used afterwards,
 * as in the original. Layouts are partial observed views. */
struct D15dVec3 {
    float x, y, z;
    D15dVec3();
    D15dVec3(const D15dVec3 &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
struct D15dTransform { float basis[9]; D15dVec3 position; };
struct D15dSource;
struct D15dSourceVtable { void (*slots[31])(void); void (*read_transform)(D15dSource *, D15dTransform *); };
struct D15dSource { D15dSourceVtable *vtable; };
struct D15dPot;
struct D15dWormInfo { unsigned char pad00[140]; int text; unsigned char pad90[170 - 144]; unsigned short value; };
struct D15dContext { unsigned char pad00[56]; int paused; };
struct D15dSettings { unsigned char pad00[188]; unsigned int flags; };
struct D15dWorm {
    unsigned char pad000[52];
    unsigned char position[84 - 52];
    void *current;
    unsigned char pad058[108 - 88];
    void *flag_b;
    int worm;
    unsigned char pad074[136 - 116];
    int pot_handle;
    unsigned char pad08c[172 - 140];
    D15dSource *source;
    unsigned char pad0b0[708 - 176];
    void *show_second;
    void *show_first;
    void *flag_a;
};
extern "C" {
D15dPot *w3d_s20_lookup_handle_object_80164fc8(int);
void w3d_fn_80140b24(D15dPot *, void *);
D15dWormInfo *s8_index_query_800fc6dc(int);
void w3d_worm_pot_set_second_text(D15dPot *, int);
void w3d_set_80140d78(D15dPot *, unsigned short);
void *w3d_empty_803426b4(void *);
int w3d_auto_80178c48(void *);
int w3d_auto_80178d1c(void *);
D15dContext *w3d_engine_get_context(void);
extern D15dSettings *w3d_settings_804b1788;
extern int w3d_flag_804abab4;
void w3d_worm_pot_apply_pair(D15dPot *, int, int);
void d15d_worm_update_pot_8013586c(D15dWorm *self);
}

void d15d_worm_update_pot_8013586c(D15dWorm *self)
{
    D15dPot *pot = w3d_s20_lookup_handle_object_80164fc8(self->pot_handle);
    D15dTransform transform;
    const D15dVec3 &p = transform.position;
    self->source->vtable->read_transform(self->source, &transform);
    D15dVec3 copy(p);
    w3d_fn_80140b24(pot, self->position);
    w3d_worm_pot_set_second_text(pot, s8_index_query_800fc6dc(self->worm)->text);
    w3d_set_80140d78(pot, s8_index_query_800fc6dc(self->worm)->value);
    if (self->worm == w3d_auto_80178c48(w3d_empty_803426b4(self->current))
        || w3d_auto_80178d1c(self->flag_a) || w3d_auto_80178d1c(self->flag_b)
        || w3d_engine_get_context()->paused
        || ((w3d_settings_804b1788->flags & 4) && !w3d_flag_804abab4)) {
        w3d_worm_pot_apply_pair(pot, 0, 0);
    } else {
        w3d_worm_pot_apply_pair(pot, w3d_auto_80178d1c(self->show_first) != 0, w3d_auto_80178d1c(self->show_second) != 0);
    }
}
