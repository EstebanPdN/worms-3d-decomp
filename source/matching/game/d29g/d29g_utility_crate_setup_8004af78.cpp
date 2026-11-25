/* Worms 3D GameCube PAL 0x8004af78. Utility crate setup: applies scale 7, reads Crate.Contents and maps the name to kinds 39 to 58; kinds 54 to 58 take their display text from a Text.kUtility key and return, an unknown name logs and sets an error text; the rest read the utility record's text key and build the display text at +148 as the count (or the encoded glyph when -1), ' x ' and the title. Field and type names are inferred from the original instructions; strings and globals are external views of original data. */
struct Key { const char *name; };
struct WeaponRec { char u[96]; const char *name; };
struct Text { char *p; };
struct Crate { char u0[36]; int kind; char u40[68 - 40]; int count; char u72[148 - 72]; Text text; };
extern "C" {
void w3d_fn_8004b3f0(Crate *, float);
int w3d_auto_800fc2b0(Key *, const char **);
int strcmp(const char *, const char *);
void w3d_fn_8004a930(Crate *, const char *);
int w3d_auto_800fc330(const char **, WeaponRec **);
int w3d_cx13b_utf8_encode_16_8018b2b0(int, void *, char *);
int sprintf(char *, const char *, ...);
int w3d_string_assign(Text *, const char *);
int w3d_string_append(Text *, const char *);
}
extern const char *weapon_names_803eb63c[];
extern char s_contents_80376fa8[], s_int_80377024[], s_x_80377028[];
extern char s_double_damage_80377058[], s_double_turn_80377074[], s_shower_80377090[], s_spy_803770ac[];
extern char s_unrecognised_803770c4[], s_error_803770e8[];
extern "C" void w3d_d29g_utility_crate_setup_8004af78(Crate *self)
{
    w3d_fn_8004b3f0(self, 7.0f);
    Key k = {s_contents_80376fa8};
    const char *name = 0;
    w3d_auto_800fc2b0(&k, &name);
    if (strcmp(name, weapon_names_803eb63c[39]) == 0) self->kind = 39;
    else if (strcmp(name, weapon_names_803eb63c[40]) == 0) self->kind = 40;
    else if (strcmp(name, weapon_names_803eb63c[41]) == 0) self->kind = 41;
    else if (strcmp(name, weapon_names_803eb63c[42]) == 0) self->kind = 42;
    else if (strcmp(name, weapon_names_803eb63c[43]) == 0) self->kind = 43;
    else if (strcmp(name, weapon_names_803eb63c[44]) == 0) self->kind = 44;
    else if (strcmp(name, weapon_names_803eb63c[45]) == 0) self->kind = 45;
    else if (strcmp(name, weapon_names_803eb63c[46]) == 0) self->kind = 46;
    else if (strcmp(name, weapon_names_803eb63c[47]) == 0) self->kind = 47;
    else if (strcmp(name, weapon_names_803eb63c[48]) == 0) self->kind = 48;
    else if (strcmp(name, weapon_names_803eb63c[49]) == 0) self->kind = 49;
    else if (strcmp(name, weapon_names_803eb63c[50]) == 0) self->kind = 50;
    else if (strcmp(name, weapon_names_803eb63c[51]) == 0) self->kind = 51;
    else if (strcmp(name, weapon_names_803eb63c[52]) == 0) self->kind = 52;
    else if (strcmp(name, weapon_names_803eb63c[53]) == 0) self->kind = 53;
    else if (strcmp(name, weapon_names_803eb63c[54]) == 0) {
        self->kind = 54;
        Key t = {s_double_damage_80377058};
        const char *v = 0;
        w3d_auto_800fc2b0(&t, &v);
        w3d_string_assign(&self->text, v);
        return;
    }
    else if (strcmp(name, weapon_names_803eb63c[55]) == 0) {
        self->kind = 55;
        Key t = {s_double_turn_80377074};
        const char *v = 0;
        w3d_auto_800fc2b0(&t, &v);
        w3d_string_assign(&self->text, v);
        return;
    }
    else if (strcmp(name, weapon_names_803eb63c[56]) == 0) {
        self->kind = 56;
        Key t = {s_shower_80377090};
        const char *v = 0;
        w3d_auto_800fc2b0(&t, &v);
        w3d_string_assign(&self->text, v);
        return;
    }
    else if (strcmp(name, weapon_names_803eb63c[57]) == 0) {
        self->kind = 57;
        Key t = {s_spy_803770ac};
        const char *v = 0;
        w3d_auto_800fc2b0(&t, &v);
        w3d_string_assign(&self->text, v);
        return;
    }
    else if (strcmp(name, weapon_names_803eb63c[58]) == 0) {
        self->kind = 58;
        Key t = {s_spy_803770ac};
        const char *v = 0;
        w3d_auto_800fc2b0(&t, &v);
        w3d_string_assign(&self->text, v);
        return;
    }
    else {
        w3d_fn_8004a930(self, s_unrecognised_803770c4);
        w3d_fn_8004a930(self, name);
        w3d_string_assign(&self->text, s_error_803770e8);
        return;
    }
    WeaponRec *rec;
    w3d_auto_800fc330(&weapon_names_803eb63c[self->kind], &rec);
    Key tk;
    const char *title;
    tk.name = rec->name;
    title = 0;
    w3d_auto_800fc2b0(&tk, &title);
    char buf[16];
    if (self->count == -1) { char wide[4]; w3d_cx13b_utf8_encode_16_8018b2b0(190, wide, buf); }
    else sprintf(buf, s_int_80377024, self->count);
    w3d_string_assign(&self->text, buf);
    w3d_string_append(&self->text, s_x_80377028);
    w3d_string_append(&self->text, title);
}
