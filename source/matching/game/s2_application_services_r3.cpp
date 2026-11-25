/* Application startup, shutdown and language/audio settings. */
extern "C" {
struct Object { void **vtable; };
struct Key { const char *name; };
struct Text { char *text; };
struct Application { void *vtable;char unknown04[92];Object *service,*language;char unknown68[8];Object *audio;char unknown74[8];Object *refs[6];Text first;int unknown98;Text second,third;int unknowna4,unknowna8,state,count,unknownb4;float fraction;unsigned int flags; };
struct Context {char unknown00[48];int value;};
struct Mode {char unknown00[28];Object *display,*property;};
void *w3d_auto_801ffea8(void *);
void w3d_fn_80347324(void *,const char *,...);
int w3d_fn_8015ad40(void *, void *);
void w3d_application_trace_801266d0();
void w3d_fn_801fcc48(int);
void * w3d_application_construct_80126bfc(Application *);
void w3d_application_destroy_80126d1c(Application *,int);
void w3d_auto_80207ca4(const char *);
void w3d_fn_8015bf74(Application *,const char *,int,int,int);
void w3d_fn_8015ba70(Application *);
void w3d_fn_8015c118(Application *);
void w3d_empty_80128084(Application *);
void w3d_string_base_finish(Text *);
void w3d_string_release(Text *);
void w3d_fn_8015c540(Application *,int);
void w3d_fn_802cc58c(void *);
Context *w3d_engine_get_context();
void w3d_auto_8015fd1c(void *);
void *w3d_auto_80164f88(Object *);
void w3d_fn_800fbf64(void *);
void w3d_fn_8015c880(Application *);
void w3d_fn_800fc230(Key *,unsigned int *);
void w3d_fn_80127ba0(Application *,unsigned int);
void w3d_fn_800fc270(Key *,float *);
Object *w3d_constructor_native_cast(Object *);
int w3d_auto_80178d1c(Object *);
void w3d_constant_8015fb2c(Mode *,void *);
extern char w3d_obj_803625c0[],w3d_obj_80361f88[],w3d_obj_80366938[],w3d_obj_803656dc[],w3d_obj_8036567c[],w3d_obj_8036564c[],w3d_obj_803655bc[],w3d_obj_80410c48[];
extern int w3d_obj_804b0640;
extern Application *w3d_obj_804b1788;
extern void *w3d_obj_804aaf88,*w3d_obj_804ab004,*w3d_obj_804aaabc,*w3d_obj_804aaba4,*w3d_obj_804aadcc;
extern const char w3d_str_8039bbe8[],w3d_str_8039bbfc[],w3d_str_8039bc00[],w3d_str_8039bc10[],w3d_str_8039bc1c[],w3d_str_8039bc28[],w3d_str_8039bc2c[],w3d_str_8039bd5c[],w3d_str_8039c8fc[],w3d_str_8039c914[],w3d_str_8039c928[];
extern const float w3d_f32_8039c93c[],w3d_f32_8039c940[];
inline void clear(Object *&slot,Object *replacement) { if(slot) ((void (*)(Object *))slot->vtable[4])(slot);slot=replacement; }
void w3d_application_trace_801266d0() {
    w3d_fn_80347324(&w3d_obj_804b0640,w3d_str_8039bbe8,w3d_auto_801ffea8(w3d_obj_803625c0));
    w3d_fn_80347324(&w3d_obj_804b0640,w3d_str_8039bbe8,w3d_auto_801ffea8(w3d_obj_80361f88));
    w3d_fn_80347324(&w3d_obj_804b0640,w3d_str_8039bbfc,w3d_auto_801ffea8(w3d_obj_80366938));
    w3d_fn_80347324(&w3d_obj_804b0640,w3d_str_8039bc00,w3d_fn_8015ad40);
    w3d_fn_80347324(&w3d_obj_804b0640,w3d_str_8039bbfc,w3d_auto_801ffea8(w3d_obj_803656dc));
    w3d_fn_80347324(&w3d_obj_804b0640,w3d_str_8039bbfc,w3d_auto_801ffea8(w3d_obj_8036567c));
    w3d_fn_80347324(&w3d_obj_804b0640,w3d_str_8039bbfc,w3d_auto_801ffea8(w3d_obj_8036564c));
    w3d_fn_80347324(&w3d_obj_804b0640,w3d_str_8039bbfc,w3d_auto_801ffea8(w3d_obj_803655bc));
}
void w3d_application_entry_801267f8() {
    Application app;
    w3d_application_trace_801266d0();w3d_fn_801fcc48(22);
    w3d_application_construct_80126bfc(&app);
    w3d_auto_80207ca4(w3d_str_8039bc10);
    w3d_fn_8015bf74(&app,w3d_str_8039bc1c,0,0,0);
    w3d_auto_80207ca4(w3d_str_8039bc28);w3d_fn_8015ba70(&app);
    w3d_auto_80207ca4(w3d_str_8039bc2c);w3d_fn_8015c118(&app);
    w3d_application_destroy_80126d1c(&app,2);
}
void w3d_application_destroy_80126d1c(Application *self,int flags) {
    self->vtable=w3d_obj_80410c48;
    Text *third=&self->third;
    w3d_empty_80128084(self);
    Text *second=&self->second;
    w3d_obj_804b1788=0;
    Text *first=&self->first;
    w3d_string_base_finish(third);w3d_string_release(third);
    w3d_string_base_finish(second);w3d_string_release(second);
    w3d_string_base_finish(first);w3d_string_release(first);
    if(self->refs[5]) ((void (*)(Object *))self->refs[5]->vtable[4])(self->refs[5]);
    if(self->refs[4]) ((void (*)(Object *))self->refs[4]->vtable[4])(self->refs[4]);
    if(self->refs[3]) ((void (*)(Object *))self->refs[3]->vtable[4])(self->refs[3]);
    if(self->refs[2]) ((void (*)(Object *))self->refs[2]->vtable[4])(self->refs[2]);
    if(self->refs[1]) ((void (*)(Object *))self->refs[1]->vtable[4])(self->refs[1]);
    if(self->refs[0]) ((void (*)(Object *))self->refs[0]->vtable[4])(self->refs[0]);
    w3d_fn_8015c540(self,0);
}
#if 0 // Excluded after two attempts: null-store scheduling differs by two words in the best candidate.
void w3d_application_shutdown_80127a0c(Application *self) {
    struct {float unused[2];} scratch;
    w3d_fn_802cc58c(w3d_obj_804aaf88);
    int value=w3d_engine_get_context()->value;
    if(w3d_obj_804ab004) w3d_auto_8015fd1c(w3d_obj_804ab004);
    ((void (*)(Object *,int *))self->service->vtable[8])(self->service,&value);
    if(w3d_obj_804aaabc) w3d_auto_8015fd1c(w3d_obj_804aaabc);
    ((void (*)(Object *,int *))self->service->vtable[8])(self->service,&value);
    if(w3d_obj_804aaba4) w3d_auto_8015fd1c(w3d_obj_804aaba4);
    ((void (*)(Object *,int *))self->service->vtable[8])(self->service,&value);
    w3d_auto_8015fd1c(w3d_obj_804aadcc);
    ((void (*)(Object *,int *))self->service->vtable[8])(self->service,&value);
    if(self->refs[5]) ((void (*)(Object *))self->refs[5]->vtable[4])(self->refs[5]);
    Object *service=self->service;
    self->refs[5]=0;
    w3d_fn_800fbf64(w3d_auto_80164f88(service));
    clear(self->language,0);
    w3d_empty_80128084(self);w3d_fn_8015c880(self);
}
#endif
int w3d_application_load_language_80127b48() {
    unsigned int language=10;
    Key key;key.name=w3d_str_8039bd5c;
    w3d_fn_800fc230(&key,&language);
    if(language<=9) {w3d_fn_80127ba0(w3d_obj_804b1788,language);return 0;}
    return 1;
}
#if 0 // Excluded after two attempts: property-key setup and floating-point initialization scheduling differ.
void w3d_application_audio_factors_80129340() {
    if(w3d_obj_804b1788->audio) {
        Key distance;float distanceValue;Key doppler;float dopplerValue;Key rolloff;float rolloffValue;
        distance.name=w3d_str_8039c8fc;
        rolloffValue=w3d_f32_8039c940[0];distanceValue=w3d_f32_8039c93c[0];dopplerValue=w3d_f32_8039c940[0];
        w3d_fn_800fc270(&distance,&distanceValue);
        doppler.name=w3d_str_8039c914;w3d_fn_800fc270(&doppler,&dopplerValue);
        rolloff.name=w3d_str_8039c928;w3d_fn_800fc270(&rolloff,&rolloffValue);
        ((void (*)(Object *,float))w3d_obj_804b1788->audio->vtable[10])(w3d_obj_804b1788->audio,distanceValue);
        ((void (*)(Object *,float))w3d_obj_804b1788->audio->vtable[12])(w3d_obj_804b1788->audio,dopplerValue);
        ((void (*)(Object *,float))w3d_obj_804b1788->audio->vtable[8])(w3d_obj_804b1788->audio,rolloffValue);
    }
}
#endif
#if 0 // Excluded after two attempts: display and vtable temporary registers are exchanged.
int w3d_mode_update_visibility_8012bd08(Mode *self,void *message) {
    int mode=w3d_auto_80178d1c(w3d_constructor_native_cast(self->property));
    Object *display=self->display;
    void **vtable=display->vtable;
    int visible=1;if(mode==2) visible=0;
    ((void (*)(Object *,int))vtable[22])(display,visible);
    w3d_constant_8015fb2c(self,message);return 0;
}
#endif
}
