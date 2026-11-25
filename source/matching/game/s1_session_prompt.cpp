/* Observed press-start text resource setup. */
extern "C" {
struct W3dS1PromptVec {float x,y,z;};
struct W3dS1PromptColor {signed char r,g,b,a;};
struct W3dS1PromptFont {void (**vtable)();};
struct W3dS1PromptContext {char unknown[52];unsigned int tick;};
extern const char w3d_str_8037c4a8[],w3d_str_8037c4b0[];
extern const float w3d_f32_8037c4c0[],w3d_f32_8037c4c4[],w3d_f32_8037c4c8[],w3d_f32_8037c4cc[];
void w3d_string_from_text(void *,const char *);
void w3d_string_base_finish(void *);
void w3d_string_release(void *);
void w3d_handle_set_name(void *,void *,unsigned int);
W3dS1PromptFont *w3d_empty_80343580(void *);
void w3d_fn_800fc2b0(const char **,const char **);
void w3d_fn_8018d324(void *,int);
void w3d_auto_8018c5b0(void *,const char *);
void w3d_fn_8018d35c(void *,W3dS1PromptColor *);
W3dS1PromptContext *w3d_engine_get_context(void);
struct W3dS1PromptString {const char *text;int unknown;W3dS1PromptString(const char *s){w3d_string_from_text(this,s);}~W3dS1PromptString(){w3d_string_base_finish(this);w3d_string_release(this);}};
struct W3dS1PromptRef {W3dS1PromptFont *value;int unknown;W3dS1PromptRef():value(0){}~W3dS1PromptRef(){if(value)((void (*)(W3dS1PromptFont *))value->vtable[4])(value);}};
#if 0 /* Excluded: stack slot reuse and temporary-object scheduling differ after one attempt. */
void w3d_fn_8006ef24(unsigned int *self)
{
    {
        W3dS1PromptString name(w3d_str_8037c4a8);
        W3dS1PromptRef handle;
        w3d_handle_set_name(&name,&handle,54);
        W3dS1PromptFont *font=w3d_empty_80343580(handle.value);
        if(font)((void (*)(W3dS1PromptFont *))font->vtable[3])(font);
        W3dS1PromptFont *old=(W3dS1PromptFont *)self[64];
        if(old)((void (*)(W3dS1PromptFont *))old->vtable[4])(old);
        self[64]=(unsigned int)font;
    }
    W3dS1PromptVec position,scale;
    W3dS1PromptColor color;
    const char *key,*text;
    W3dS1PromptVec *pos=&position,*size=&scale;
    W3dS1PromptColor *tint=&color;
    pos->z=w3d_f32_8037c4c0[0];pos->y=w3d_f32_8037c4c4[0];pos->x=w3d_f32_8037c4c0[0];
    tint->r=-1;tint->a=-1;tint->g=-1;tint->b=-1;
    size->x=w3d_f32_8037c4c8[0];size->y=w3d_f32_8037c4c8[0];size->z=w3d_f32_8037c4cc[0];
    key=w3d_str_8037c4b0;text=0;w3d_fn_800fc2b0(&key,&text);
    W3dS1PromptFont *font=(W3dS1PromptFont *)self[64];
    w3d_fn_8018d324(font,0);w3d_auto_8018c5b0((void *)self[64],text);
    font=(W3dS1PromptFont *)self[64];((void (*)(W3dS1PromptFont *,W3dS1PromptVec *,int))font->vtable[19])(font,pos,0);
    font=(W3dS1PromptFont *)self[64];((void (*)(W3dS1PromptFont *,int))font->vtable[22])(font,1);
    w3d_fn_8018d35c((void *)self[64],tint);
    font=(W3dS1PromptFont *)self[64];((void (*)(W3dS1PromptFont *,W3dS1PromptVec *,int))font->vtable[21])(font,size,0);
    self[65]=w3d_engine_get_context()->tick+750;
}
#endif
}
