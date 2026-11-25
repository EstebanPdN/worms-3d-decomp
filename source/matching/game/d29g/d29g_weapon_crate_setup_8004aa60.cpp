/* Worms 3D GameCube PAL 0x8004aa60. Weapon crate setup: applies scale 7, reads Crate.Contents and maps the name through the 36-entry weapon name table to the kind at +36, logging and setting an error text for an unknown name; then reads the weapon record's text key and builds the display text at +148 as the count (or the encoded infinity glyph when -1), ' x ' and the title. Field and type names are inferred from the original instructions; strings and globals are external views of original data. */
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
extern char s_unrecognised_80376fe4[], s_error_80377008[], s_contents_80376fa8[], s_int_80377024[], s_x_80377028[];
extern "C" void w3d_d29g_weapon_crate_setup_8004aa60(Crate *self)
{
    w3d_fn_8004b3f0(self, 7.0f);
    Key k = {s_contents_80376fa8};
    const char *name = 0;
    w3d_auto_800fc2b0(&k, &name);
    if (strcmp(name, weapon_names_803eb63c[0]) == 0) self->kind = 0;
    else if (strcmp(name, weapon_names_803eb63c[1]) == 0) self->kind = 1;
    else if (strcmp(name, weapon_names_803eb63c[2]) == 0) self->kind = 2;
    else if (strcmp(name, weapon_names_803eb63c[3]) == 0) self->kind = 3;
    else if (strcmp(name, weapon_names_803eb63c[4]) == 0) self->kind = 4;
    else if (strcmp(name, weapon_names_803eb63c[5]) == 0) self->kind = 5;
    else if (strcmp(name, weapon_names_803eb63c[6]) == 0) self->kind = 6;
    else if (strcmp(name, weapon_names_803eb63c[7]) == 0) self->kind = 7;
    else if (strcmp(name, weapon_names_803eb63c[8]) == 0) self->kind = 8;
    else if (strcmp(name, weapon_names_803eb63c[9]) == 0) self->kind = 9;
    else if (strcmp(name, weapon_names_803eb63c[10]) == 0) self->kind = 10;
    else if (strcmp(name, weapon_names_803eb63c[11]) == 0) self->kind = 11;
    else if (strcmp(name, weapon_names_803eb63c[12]) == 0) self->kind = 12;
    else if (strcmp(name, weapon_names_803eb63c[13]) == 0) self->kind = 13;
    else if (strcmp(name, weapon_names_803eb63c[14]) == 0) self->kind = 14;
    else if (strcmp(name, weapon_names_803eb63c[15]) == 0) self->kind = 15;
    else if (strcmp(name, weapon_names_803eb63c[16]) == 0) self->kind = 16;
    else if (strcmp(name, weapon_names_803eb63c[17]) == 0) self->kind = 17;
    else if (strcmp(name, weapon_names_803eb63c[18]) == 0) self->kind = 18;
    else if (strcmp(name, weapon_names_803eb63c[19]) == 0) self->kind = 19;
    else if (strcmp(name, weapon_names_803eb63c[20]) == 0) self->kind = 20;
    else if (strcmp(name, weapon_names_803eb63c[21]) == 0) self->kind = 21;
    else if (strcmp(name, weapon_names_803eb63c[22]) == 0) self->kind = 22;
    else if (strcmp(name, weapon_names_803eb63c[23]) == 0) self->kind = 23;
    else if (strcmp(name, weapon_names_803eb63c[24]) == 0) self->kind = 24;
    else if (strcmp(name, weapon_names_803eb63c[25]) == 0) self->kind = 25;
    else if (strcmp(name, weapon_names_803eb63c[26]) == 0) self->kind = 26;
    else if (strcmp(name, weapon_names_803eb63c[27]) == 0) self->kind = 27;
    else if (strcmp(name, weapon_names_803eb63c[28]) == 0) self->kind = 28;
    else if (strcmp(name, weapon_names_803eb63c[29]) == 0) self->kind = 29;
    else if (strcmp(name, weapon_names_803eb63c[30]) == 0) self->kind = 30;
    else if (strcmp(name, weapon_names_803eb63c[31]) == 0) self->kind = 31;
    else if (strcmp(name, weapon_names_803eb63c[32]) == 0) self->kind = 32;
    else if (strcmp(name, weapon_names_803eb63c[33]) == 0) self->kind = 33;
    else if (strcmp(name, weapon_names_803eb63c[34]) == 0) self->kind = 34;
    else if (strcmp(name, weapon_names_803eb63c[35]) == 0) self->kind = 35;
    else {
        w3d_fn_8004a930(self, s_unrecognised_80376fe4);
        w3d_fn_8004a930(self, name);
        w3d_string_assign(&self->text, s_error_80377008);
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
