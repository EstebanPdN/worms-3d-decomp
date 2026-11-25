/* Display text events and their observed string lifetimes. */
extern "C" {
struct W3dS1Text { char *text; };
struct W3dS1TextHeader { unsigned short references; };
struct W3dS1TextVector { W3dS1Text *begin,*end; };
struct W3dS1TextDisplay { unsigned char unknown[0x48]; W3dS1TextVector strings; };
struct W3dS1TextActor { unsigned char unknown[0x8c]; const char *name; };
void w3d_string_base_init(W3dS1Text *);
void w3d_string_base_finish(W3dS1Text *);
void w3d_string_release(W3dS1Text *);
W3dS1TextHeader *w3d_string_header(W3dS1Text *);
void * w3d_string_default(W3dS1Text *);
void w3d_string_from_text(W3dS1Text *,const char *);
void w3d_string_format(W3dS1Text *,const char *,...);
void w3d_fn_80043134(void *,W3dS1Text *,unsigned int);
void w3d_fn_800438d4(void *,unsigned int);
void * w3d_fn_800fc2b0(const char **,const char **);
W3dS1TextActor *w3d_fn_800fc6dc(int);
unsigned int w3d_auto_8015ff5c(void *);
extern const char w3d_str_80374f78[],w3d_str_803763c0[];
static inline void copy_text(W3dS1Text *dest,const W3dS1Text *src)
{
    w3d_string_base_init(dest);dest->text=src->text;++w3d_string_header(dest)->references;
}
static inline void finish_text(W3dS1Text *text) { w3d_string_base_finish(text);w3d_string_release(text); }
static inline void clear_texts(W3dS1TextVector *v,W3dS1Text *first)
{
    W3dS1Text *last=v->end,*p=first;
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
void w3d_fn_80044994(void *self,void *message)
{
    struct { W3dS1LocalText formatted,copy; W3dS1ArgumentText argument; const char *key,*format; } local;
    w3d_string_default(&local.formatted.value);
    local.key=w3d_str_80374f78;
    w3d_fn_800fc2b0(&local.key,&local.format);
    W3dS1TextActor *actor=w3d_fn_800fc6dc((int)message);
    w3d_string_format(&local.formatted.value,local.format,actor->name);
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
