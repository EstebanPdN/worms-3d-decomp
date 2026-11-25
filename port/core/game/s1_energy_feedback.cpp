#include "w3d_ptr.h"
#line 1 "s1_energy_feedback.cpp"
/* Team-energy text feedback, blink timing, and selected flag setup. */
extern "C" {
struct W3dS1FeedbackVec {float x,y,z;};
struct W3dS1FeedbackColor {signed char r,g,b,a;};
struct W3dS1FeedbackRef;
struct W3dS1FeedbackTable {Ptr32<void (void)> unused[19];Ptr32<void (Ptr32<W3dS1FeedbackRef>, Ptr32<W3dS1FeedbackVec>, int)> position;Ptr32<void (void)> unused20;Ptr32<void (Ptr32<W3dS1FeedbackRef>, Ptr32<W3dS1FeedbackVec>, int)> scale;};
struct W3dS1FeedbackRef {Ptr32<W3dS1FeedbackTable> vtable;};
struct W3dS1Feedback {char unknown[28];Ptr32<W3dS1FeedbackRef> bar; Ptr32<W3dS1FeedbackRef> flag; Ptr32<W3dS1FeedbackRef> text;char unknown28[8];unsigned int team;char unknown34[8];W3dS1FeedbackVec position;char unknown48[16];unsigned int blinking;char unknown5c[8];unsigned int last;char unknown68[24];Ptr32<void> xscale; Ptr32<void> yscale;};
struct W3dS1FeedbackString {Ptr32<const char> text;int unknown;};
struct W3dS1FeedbackContext {char unknown[52];unsigned int tick;};
extern const char w3d_str_80379de4[];
extern const float w3d_f32_80379df4[];
Ptr32<void> w3d_empty_80343580(Ptr32<void>);
Ptr32<void> w3d_empty_8034357c(Ptr32<void>);
Ptr32<void> w3d_fn_800fd3e4(Ptr32<W3dS1FeedbackColor>,unsigned int,...);
int w3d_fn_8018d35c(Ptr32<void>,Ptr32<W3dS1FeedbackColor>);
void w3d_fn_80064384(Ptr32<W3dS1Feedback>,unsigned int);
Ptr32<W3dS1FeedbackContext> w3d_engine_get_context(void);
void w3d_fn_80064d20(Ptr32<W3dS1Feedback>);
int w3d_fn_802ed89c(Ptr32<const char>);
void w3d_string_from_text(Ptr32<void>,Ptr32<const char>);
void w3d_handle_set_name(Ptr32<void>,Ptr32<void>,unsigned int);
void w3d_string_base_finish(Ptr32<void>);
void w3d_string_release(Ptr32<void>);
void w3d_fn_80173f88(Ptr32<void>,Ptr32<unsigned char>);
float w3d_auto_80178df0(Ptr32<void>);
void w3d_fn_80064c6c(Ptr32<W3dS1Feedback> self,unsigned int now)
{
    struct {W3dS1FeedbackColor team,white;} local;
    if(!self->blinking)w3d_fn_80064d20(self);
    else if(now>self->last+500) {
        self->last=now;
        Ptr32<void> text=w3d_empty_80343580(self->text);
        w3d_fn_800fd3e4(&local.team,self->team);w3d_fn_8018d35c(text,&local.team);
    } else if(now>self->last+250) {
        local.white.r=-1;
        Ptr32<W3dS1FeedbackColor> white=&local.white;
        white->g=-1;white->b=-1;white->a=-1;
        w3d_fn_8018d35c(w3d_empty_80343580(self->text),white);
    }
}
static inline void feedback_color(Ptr32<W3dS1FeedbackColor> color,Ptr32<void> text) {w3d_fn_8018d35c(text,color);}
#if 0 /* Excluded: two argument setup instructions remain exchanged after three attempts. */
void w3d_fn_80064d20(W3dS1Feedback *self)
{
    W3dS1FeedbackColor color;
    w3d_fn_80064384(self,self->team);
    void *text=w3d_empty_80343580(self->text);
    w3d_fn_800fd3e4(&color,self->team);feedback_color(&color,text);
    self->last=w3d_engine_get_context()->tick;
}
#endif
#if 0 /* Excluded: local pointer caching and aggregate store scheduling differ after three attempts. */
void w3d_fn_80064dcc(W3dS1Feedback *self,const char *selector)
{
    struct {W3dS1FeedbackString name;unsigned char index;char pad[7];W3dS1FeedbackVec scale;int tail;} local;
    if(selector && *selector) {
        W3dS1FeedbackString *name=&local.name;
        int index=w3d_fn_802ed89c(selector);
        W3dS1FeedbackVec *scale=&local.scale;
        w3d_string_from_text(&local.name,w3d_str_80379de4);
        w3d_handle_set_name(&local.name,&self->flag,255);
        w3d_string_base_finish(name);w3d_string_release(name);
        self->flag->vtable->position(self->flag,&self->position,0);
        void *flag=w3d_empty_8034357c(self->flag);
        local.index=index;w3d_fn_80173f88(flag,&local.index);
        scale->y=w3d_f32_80379df4[0];scale->x=w3d_f32_80379df4[0];scale->z=w3d_f32_80379df4[0];
        scale->x=w3d_auto_80178df0(self->xscale);scale->y=w3d_auto_80178df0(self->yscale);
        self->flag->vtable->scale(self->flag,scale,0);
    }
}
#endif
}


