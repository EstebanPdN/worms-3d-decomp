// d16c: 0x8011b010 (376 bytes). Load the HUD text assets: look up the
// "FE.Font" service and hold it for the call, scale it by (-1, 0), load the
// "FE.Font" text resource into the font slot (+28, retained; the previous one
// is released), load the green text backing (+32) and attach the font.
// The float literals form this function's constant pool at 0x8039aea4.
// 0x8015adf4 forwards the resource manager's virtual load result, so it is
// declared with a status return.
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
struct d16c_Object;
struct d16c_ObjectVtable {
    void *unknown00[3];
    void (*retain)(d16c_Object *);       // +12
    void (*release)(d16c_Object *);      // +16
};
struct d16c_Object { d16c_ObjectVtable *vtable; };
// Retaining reference (one pointer); released when it goes out of scope.
struct d16c_Ref {
    d16c_Object *value;
    ~d16c_Ref() { if (value) value->vtable->release(value); }
};
struct d16c_HudText {
    unsigned char unknown00[28];
    d16c_Object *font;                   // +28
    d16c_Object *backing;                // +32
};
extern "C" int d16c_handle_load_8015adf4(const d16c_String_8020bb54 *, d16c_Object **, unsigned char);
extern "C" d16c_Object *d16c_service_lookup_8015ae3c(const d16c_String_8020bb54 *);
extern "C" d16c_Object *d16c_as_font_8034435c(d16c_Object *);
extern "C" d16c_Object *d16c_as_text_80343580(d16c_Object *);
extern "C" void d16c_font_set_scale_8018bb28(d16c_Object *, float, float);
extern "C" int d16c_text_set_font_8018dfa0(d16c_Object *, int);
extern const char d16c_font_name_8039ae88[];       // "FE.Font"
extern const char d16c_backing_green_8039ae90[];   // "Text.Backing.Green"

extern "C" void d16c_hud_text_load_8011b010(d16c_HudText *self) {
    d16c_Ref font;
    {
        d16c_String_8020bb54 name(d16c_font_name_8039ae88);
        font.value = d16c_as_font_8034435c(d16c_service_lookup_8015ae3c(&name));
        if (font.value) font.value->vtable->retain(font.value);
    }
    d16c_font_set_scale_8018bb28(font.value, -1.0f, 0.0f);
    {
        d16c_String_8020bb54 name(d16c_font_name_8039ae88);
        d16c_Ref loaded;
        loaded.value = 0;
        d16c_handle_load_8015adf4(&name, &loaded.value, 18);
        d16c_Object *text = d16c_as_text_80343580(loaded.value);
        if (text) text->vtable->retain(text);
        if (self->font) self->font->vtable->release(self->font);
        self->font = text;
    }
    {
        d16c_String_8020bb54 name(d16c_backing_green_8039ae90);
        d16c_handle_load_8015adf4(&name, &self->backing, 17);
    }
    d16c_text_set_font_8018dfa0(self->font, 1);
}
