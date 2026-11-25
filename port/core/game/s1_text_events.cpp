#include "w3d_ptr.h"
#line 1 "s1_text_events.cpp"
/* Display text events and their observed string lifetimes. */
extern "C" {
struct W3dS1Text { Ptr32<char> text; };
struct W3dS1TextHeader { unsigned short references; };
struct W3dS1TextVector { Ptr32<W3dS1Text> begin; Ptr32<W3dS1Text> end; };
struct W3dS1TextDisplay { unsigned char unknown[0x48]; W3dS1TextVector strings; };
struct W3dS1TextActor { unsigned char unknown[0x8c]; Ptr32<const char> name; };
void w3d_string_base_init(Ptr32<W3dS1Text>);
void w3d_string_base_finish(Ptr32<W3dS1Text>);
void w3d_string_release(Ptr32<W3dS1Text>);
Ptr32<W3dS1TextHeader> w3d_string_header(Ptr32<W3dS1Text>);
Ptr32<void> w3d_string_default(Ptr32<W3dS1Text>);
void w3d_string_from_text(Ptr32<W3dS1Text>,Ptr32<const char>);
void w3d_string_format(Ptr32<W3dS1Text>,Ptr32<const char>,...);
void w3d_fn_80043134(Ptr32<void>,Ptr32<W3dS1Text>,unsigned int);
void w3d_fn_800438d4(Ptr32<void>,unsigned int);
Ptr32<void> w3d_fn_800fc2b0(Ptr32<Ptr32<const char>>,Ptr32<Ptr32<const char>>);
Ptr32<W3dS1TextActor> w3d_fn_800fc6dc(int);
unsigned int w3d_auto_8015ff5c(Ptr32<void>);
extern const char w3d_str_80374f78[],w3d_str_803763c0[];
static inline void copy_text(Ptr32<W3dS1Text> dest,Ptr32<const W3dS1Text> src)
{
    w3d_string_base_init(dest);dest->text=src->text;++w3d_string_header(dest)->references;
}
static inline void finish_text(Ptr32<W3dS1Text> text) { w3d_string_base_finish(text);w3d_string_release(text); }
static inline void clear_texts(Ptr32<W3dS1TextVector> v,Ptr32<W3dS1Text> first)
{
    Ptr32<W3dS1Text> last=v->end; Ptr32<W3dS1Text> p=first;
    for(;p!=last;++p) finish_text(p);
    v->end=first;
}
#if 0 /* 0x80044638: four instruction-order differences remain. */
void w3d_fn_80044638(W3dS1TextDisplay *self,W3dS1Text *input)
{
    W3dS1Text local;
    W3dS1Text *first=self->strings.begin;
    clear_texts(&self->strings,first);
    copy_text(&local,input);
    w3d_fn_80043134(self,&local,0);
    w3d_fn_800438d4(self,0);
    finish_text(input);
}
#endif
struct W3dS1LocalText { W3dS1Text value; int unused; };
struct W3dS1ArgumentText { W3dS1Text value; int unused; };
void w3d_fn_80044994(Ptr32<void> self,Ptr32<void> message)
{
    struct { W3dS1LocalText formatted,copy; W3dS1ArgumentText argument; Ptr32<const char> key; Ptr32<const char> format; } local;
    w3d_string_default(&local.formatted.value);
    local.key=w3d_str_80374f78;
    w3d_fn_800fc2b0(&local.key,&local.format);
    Ptr32<W3dS1TextActor> actor=w3d_fn_800fc6dc((int)w3d::H(message));
    w3d_string_format(&local.formatted.value,local.format,w3d::VA(actor->name));
    copy_text(&local.copy.value,&local.formatted.value);
    copy_text(&local.argument.value,&local.copy.value);
    w3d_fn_80043134(self,&local.argument.value,0);
    finish_text(&local.copy.value);
    finish_text(&local.formatted.value);
}
#if 0 /* 0x80048110: two argument-address setup instructions remain exchanged. */
void w3d_fn_80048110(void *self)
{
    struct { W3dS1LocalText formatted; W3dS1ArgumentText argument; } local;
    const char *key,*format;
    format=0;
    w3d_string_default(&local.formatted.value);
    unsigned int random=w3d_auto_8015ff5c(self);
    w3d_string_format(&local.formatted.value,w3d_str_803763c0,random%13+1);
    key=local.formatted.value.text;
    w3d_fn_800fc2b0(&key,&format);
    w3d_string_from_text(&local.argument.value,format);
    w3d_fn_80043134(self,&local.argument.value,0);
    finish_text(&local.formatted.value);
}
#endif
}


