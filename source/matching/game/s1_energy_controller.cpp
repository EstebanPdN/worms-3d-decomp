/* Energy display event dispatch and observed transition state machine. */
extern "C" {
struct W3dS1ControllerActor {char unknown[128];int state;char unknown84[81];unsigned char team;};
struct W3dS1ControllerDisplay {char unknown[44];float current;};
struct W3dS1Controller {char unknown[28];unsigned int displays[4];void *actor;char unknown30[40];void *scale,*selected,*timeout,*suppress1,*suppress2;int state,forced,expired;unsigned int stamp;float maximum;};
extern unsigned int w3d_message_804ad558,w3d_message_804ad560,w3d_message_804ad568,w3d_message_804ad570,w3d_message_804ad578,w3d_message_804ad580,w3d_message_804ad588,w3d_message_804ad590,w3d_message_804ad598,w3d_message_804ad5a0;
extern const float w3d_f32_80379e8c[];
int w3d_auto_8015fb34(void *,unsigned short *);
int w3d_fn_8015f65c(unsigned short,void *);
void w3d_fn_800656b4(void *);
void w3d_fn_800654bc(void *);
void w3d_fn_80065ce0(void *);
void w3d_timed_state_stamp_800664c4(void *);
void w3d_fn_800664f8(W3dS1Controller *);
int w3d_auto_80178c48(void *);
unsigned int w3d_auto_80178d1c(void *);
float w3d_auto_80178df0(void *);
W3dS1ControllerActor *w3d_fn_800fc6dc(unsigned int);
void w3d_fn_80065c94(void *,int);
int w3d_fn_80066068(W3dS1Controller *);
int w3d_fn_800660d4(W3dS1Controller *);
int w3d_component_step_80065ff0(void *);
int w3d_fn_80066010(void *);
W3dS1ControllerDisplay *w3d_fn_80164fc8(unsigned int);
int w3d_fn_800645b8(void *);
int w3d_fn_80064950(void *);
void w3d_fn_800663a8(void *);
void w3d_fn_800661c4(void *);
void w3d_timed_state_set_rate_80064548(void *,float);
void *w3d_empty_803426b4(void *);
void w3d_auto_80064d88(void *,int);
#if 0 /* Excluded: two saved registers remain exchanged after three attempts. */
int w3d_fn_80065314(W3dS1Controller *self,register unsigned short *message)
{
    register int found;
    unsigned short id=*message;
    switch(id) {
    case 64:
        if(w3d_auto_8015fb34(self,message)>=0) {w3d_fn_800656b4(self);goto handled;}
        return 0x80004005;
    case 66:w3d_fn_800654bc(self);goto fallback;
    }
    {
        found=w3d_fn_8015f65c(*message,&w3d_message_804ad558);
        if(found) {w3d_fn_80065ce0(self);goto handled;}
        if(w3d_fn_8015f65c(*message,&w3d_message_804ad560)) {
            self->forced=found;w3d_timed_state_stamp_800664c4(self);w3d_fn_800664f8(self);goto handled;
        }
    }
    if(w3d_fn_8015f65c(*message,&w3d_message_804ad568)) {
        self->forced=1;w3d_fn_800664f8(self);goto handled;
    }
    if(w3d_fn_8015f65c(id,&w3d_message_804ad570) || w3d_fn_8015f65c(id,&w3d_message_804ad578)) {
        self->forced=1;goto handled;
    }
    if(w3d_fn_8015f65c(id,&w3d_message_804ad588) || w3d_fn_8015f65c(id,&w3d_message_804ad580) || w3d_fn_8015f65c(id,&w3d_message_804ad590) || w3d_fn_8015f65c(id,&w3d_message_804ad598) || w3d_fn_8015f65c(id,&w3d_message_804ad5a0)) {
        w3d_timed_state_stamp_800664c4(self);goto handled;
    }
fallback:
    return w3d_auto_8015fb34(self,message);
handled:
    return 0;
}
#endif
#if 0 /* Excluded: branchless boolean lowering and shared switch tails differ after three attempts. */
int w3d_fn_8006551c(W3dS1Controller *self,unsigned int now)
{
    int actor=w3d_auto_80178c48(self->selected);
    if(actor>=0 && w3d_fn_800fc6dc(actor)->state!=10)w3d_timed_state_stamp_800664c4(self);
    unsigned int threshold=w3d_auto_80178d1c(self->timeout)+self->stamp;
    self->expired=(bool)(now>threshold);
    if(w3d_auto_80178d1c(self->suppress1) || w3d_auto_80178d1c(self->suppress2)) {
        self->expired=0;self->forced=0;self->state=0;w3d_fn_80065c94(self,0);
    }
    int next;
    switch(self->state) {
    case 0:if(self->forced || self->expired)goto show;break;
    case 1:if(w3d_fn_80066068(self)) {next=2;goto apply;}break;
    case 2:if(w3d_fn_800660d4(self)) {next=3;goto apply;}break;
    case 3:if(w3d_component_step_80065ff0(self)) {if(self->forced || self->expired) {next=2;goto apply;}else {next=4;goto apply;}}break;
    case 4:if(w3d_fn_80066010(self)) {next=self->forced;if(next)goto show;goto apply;}break;
    }
    goto done;
show:
    next=1;
apply:
    self->state=next;
done:
    return 0;
}
#endif
int w3d_fn_80066068(W3dS1Controller *self)
{
    int complete=1;unsigned int *display=self->displays;int count=4;
    do {void *value=w3d_fn_80164fc8(*display++);if(!w3d_fn_800645b8(value))complete=0;}while(--count);
    if(complete)w3d_fn_800663a8(self);
    return complete;
}
#if 0 /* Excluded: stack layout and condition-register preservation differ after three attempts. */
int w3d_fn_800660d4(W3dS1Controller *self)
{
    float maximum=w3d_f32_80379e8c[0];int complete=1;
    unsigned int *display=self->displays;int count=4;
    do {
        W3dS1ControllerDisplay *value=w3d_fn_80164fc8(*display++);
        if(!w3d_fn_80064950(value))complete=0;
        if(value->current>maximum)maximum=value->current;
    }while(--count);
    w3d_auto_80178df0(self->scale);
    if(maximum>self->maximum) {
        float scale=w3d_auto_80178df0(self->scale)/maximum;self->maximum=maximum;
        display=self->displays;
        unsigned int *last=display+3;
        do {w3d_timed_state_set_rate_80064548(w3d_fn_80164fc8(*display++),scale);}while(display<=last);
    }
    if(complete)w3d_fn_800661c4(self);
    return complete;
}
#endif
void w3d_fn_800664f8(W3dS1Controller *self)
{
    int selected=w3d_auto_80178c48(w3d_empty_803426b4(self->actor));
    int team=selected>=0?w3d_fn_800fc6dc(selected)->team:4;
    unsigned int *display=self->displays;unsigned int index=0;
    do {
        void *value=w3d_fn_80164fc8(*display++);
        if(index==team)w3d_auto_80064d88(value,1);else w3d_auto_80064d88(value,0);
        ++index;
    }while(index<=3);
}
}
