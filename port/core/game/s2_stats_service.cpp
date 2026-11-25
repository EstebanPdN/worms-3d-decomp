#include "w3d_ptr.h"
#line 1 "s2_stats_service.cpp"
/* Statistics text substitution, counters, and a small service lifecycle. */
extern "C" {
struct S2StatsString;
void w3d_string_default(Ptr32<S2StatsString>);
void w3d_string_from_text(Ptr32<S2StatsString>, Ptr32<const char>);
void w3d_string_base_init(Ptr32<S2StatsString>);
void w3d_string_base_finish(Ptr32<S2StatsString>);
void w3d_string_release(Ptr32<S2StatsString>);
Ptr32<unsigned short> w3d_string_header(Ptr32<S2StatsString>);
void w3d_string_release_header(Ptr32<unsigned short>);
void w3d_string_append(Ptr32<S2StatsString>, Ptr32<const char>);
void w3d_string_assign(Ptr32<S2StatsString>, Ptr32<const char>);
void w3d_fn_8020c048(Ptr32<S2StatsString>, Ptr32<S2StatsString>, int);
Ptr32<char> strstr(Ptr32<const char>, Ptr32<const char>);
struct S2StatsString { Ptr32<char> text; unsigned int storage; };
struct S2StatsAutoString : S2StatsString {
    S2StatsAutoString() { w3d_string_default(this); }
    S2StatsAutoString(Ptr32<const char> w3d_p) : S2StatsAutoString((const char *)w3d_p.get()) {}
 S2StatsAutoString(const char *value) { w3d_string_from_text(this, value); }
    S2StatsAutoString(const S2StatsString &other) {
        w3d_string_base_init(this); text = other.text; (*w3d_string_header(this))++;
    }
    ~S2StatsAutoString() { w3d_string_base_finish(this); w3d_string_release(this); }
};
struct S2Stats { unsigned char pad00[84]; unsigned int counts[8]; unsigned int unknown116; int blocked; };
struct S2StatsWorm { unsigned char pad00[213]; unsigned char team; };
struct S2StatsKey { Ptr32<const char> text; };
int w3d_fn_800fc2b0(Ptr32<S2StatsKey>, Ptr32<Ptr32<const char>>);
void w3d_fn_800fc1f0(Ptr32<S2StatsKey>, Ptr32<int>);
Ptr32<S2StatsWorm> w3d_fn_800fc6dc(int);
void w3d_fn_801096f0(Ptr32<S2Stats>, Ptr32<S2StatsString>, Ptr32<const char>, Ptr32<const char>);
void w3d_fn_8010a01c(Ptr32<S2Stats>, Ptr32<const char>);
void w3d_fn_800fc550(Ptr32<S2StatsKey>, Ptr32<const char>);
struct S2StatsVirtual { Ptr32<Ptr32<void (Ptr32<S2StatsVirtual>)>> vtable; };
struct S2StatsService { Ptr32<void> vtable; unsigned char pad04[24]; Ptr32<S2StatsVirtual> resource; };
int w3d_ctor_801628b0(Ptr32<S2StatsService>);
void w3d_service_destroy_801628ec(Ptr32<S2StatsService>, int);
int w3d_auto_8016293c(Ptr32<S2StatsService>, Ptr32<unsigned short>);
void w3d_empty_8010a850(Ptr32<S2StatsService>);
extern unsigned char w3d_obj_804107b8[];
extern const char w3d_str_80399c1c[], w3d_str_80399c5c[], w3d_str_80399c64[], w3d_str_80399c74[], w3d_str_80399c78[];
extern const char w3d_str_80399c88[], w3d_str_80399c8c[], w3d_str_80399c98[], w3d_str_80399c9c[], w3d_str_80399cd8[];
extern const char w3d_str_80399cfc[], w3d_str_80399d1c[];

#if 0 /* 3 attempts including a prototype compile error; string address setup differs */
void w3d_stats_format_source_80109604(S2Stats *self)
{
    const char *source = 0;
    S2StatsKey key;
    key.text = w3d_str_80399c1c;
    if (w3d_fn_800fc2b0(&key, &source) >= 0) {
        S2StatsString text;
        w3d_string_from_text(&text, source);
        S2StatsString *cleanup = &text;
        w3d_fn_801096f0(self, &text, w3d_str_80399c5c, w3d_str_80399c64);
        w3d_fn_801096f0(self, &text, w3d_str_80399c74, w3d_str_80399c78);
        w3d_fn_801096f0(self, &text, w3d_str_80399c88, w3d_str_80399c8c);
        w3d_fn_801096f0(self, &text, w3d_str_80399c98, w3d_str_80399c9c);
        w3d_fn_8010a01c(self, text.text);
        w3d_string_base_finish(cleanup);
        w3d_string_release(cleanup);
    }
}
#endif


#if 0 /* 3 attempts including a prototype compile error; string temporary setup differs */
void w3d_stats_replace_text_801099a4(S2Stats *unused, S2StatsString *text, const char *search, const char *replacement)
{
    S2StatsString output;
    w3d_string_default(&output);
    S2StatsString *cleanup = &output;
    { S2StatsAutoString find(search);
    unsigned short length = ((unsigned short *)find.text)[-2];
    S2StatsAutoString replace(replacement);
    char *match = strstr(text->text, find.text);
    while (match) {
        w3d_fn_8020c048(&output, text, match - text->text);
        w3d_string_append(&output, replace.text);
        w3d_string_append(&output, match + length);
        ((unsigned short *)output.text)[-3]++;
        unsigned short *header = (unsigned short *)text->text - 3;
        if (--*header == 0) w3d_string_release_header(header);
        text->text = output.text;
        match = strstr(text->text, find.text);
    }
    }
    w3d_string_base_finish(cleanup);
    w3d_string_release(cleanup);
}
#endif


void w3d_stats_clear_counts_80109ae4(Ptr32<S2Stats> self)
{
    self->counts[1] = 0;
    self->counts[0] = 0;
    self->counts[3] = 0;
    self->counts[2] = 0;
    self->counts[4] = 0;
    self->counts[7] = 0;
    self->counts[6] = 0;
    self->counts[5] = 0;
}


#if 0 /* 3 attempts including a prototype compile error; two local setup instructions differ */
void w3d_stats_count_target_80109b1c(S2Stats *self, int target)
{
    if (!self->blocked) {
        int active = self->blocked;
        S2StatsKey key;
        key.text = w3d_str_80399cd8;
        w3d_fn_800fc1f0(&key, &active);
        if (active >= 0) {
            unsigned char team = w3d_fn_800fc6dc(active)->team;
            if (team == w3d_fn_800fc6dc(target)->team) self->counts[1]++;
            else self->counts[0]++;
        }
    }
}
#endif


#if 0 /* 3 attempts including a prototype compile error; string temporary register allocation differs */
void w3d_fn_8010a01c(S2Stats *unused, const char *line)
{
    S2StatsString text;
    w3d_string_default(&text);
    S2StatsString *cleanup = &text;
    const char *value;
    S2StatsKey key;
    key.text = w3d_str_80399cfc;
    w3d_fn_800fc2b0(&key, &value);
    w3d_string_assign(&text, value);
    { S2StatsAutoString copy(text); }
    w3d_string_append(&text, line);
    w3d_string_append(&text, w3d_str_80399d1c);
    S2StatsKey output;
    output.text = w3d_str_80399cfc;
    w3d_fn_800fc550(&output, text.text);
    w3d_string_base_finish(cleanup);
    w3d_string_release(cleanup);
}
#endif


Ptr32<S2StatsService> w3d_small_service_construct_8010a740(Ptr32<S2StatsService> self)
{
    struct { unsigned int first, second; } scratch;
    w3d_ctor_801628b0(self);
    self->resource = 0;
    self->vtable = w3d_obj_804107b8;
    return self;
}


void w3d_small_service_destroy_8010a784(Ptr32<S2StatsService> self, int flags)
{
    self->vtable = w3d_obj_804107b8;
    if (self->resource) self->resource->vtable[4](self->resource);
    w3d_service_destroy_801628ec(self, flags);
}


int w3d_small_service_dispatch_8010a7e4(Ptr32<S2StatsService> self, Ptr32<unsigned short> message)
{
    if (*message == 64) {
        if (w3d_auto_8016293c(self, message) >= 0) {
            w3d_empty_8010a850(self);
            return 0;
        }
        return 0x80004005;
    }
    return w3d_auto_8016293c(self, message);
}

}


