struct K4aString;
extern "C" void * w3d_string_default(K4aString *string);
extern "C" void w3d_string_assign(K4aString *string, const char *text);
struct K4aString { char *text; };
struct K4aWords3 { int a, b, c; };
struct K4aEntry { char pad0[4]; K4aString name; K4aWords3 origin; int first; int second; };
extern "C" char w3d_str_80382314[];
extern "C" K4aWords3 w3d_origin_8045e788;
extern "C" int w3d_count_804aacac;

extern "C" K4aEntry *k4a_entry_construct_800afdd4(K4aEntry *self)
{
    w3d_string_default(&self->name);
    w3d_string_assign(&self->name, w3d_str_80382314);
    self->origin = w3d_origin_8045e788;
    self->first = 0;
    self->second = 0;
    w3d_count_804aacac = w3d_count_804aacac + 1;
    return self;
}
