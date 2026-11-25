#include "w3d_ptr.h"
#line 1 "s2_application_services_r3.cpp"
/* Application startup, shutdown and language/audio settings. */
extern "C" {
struct Object { Ptr32<Ptr32<void>> vtable; };
struct Key { Ptr32<const char> name; };
struct Text { Ptr32<char> text; };
struct Application { Ptr32<void> vtable;char unknown04[92];Ptr32<Object> service; Ptr32<Object> language;char unknown68[8];Ptr32<Object> audio;char unknown74[8];Ptr32<Object> refs[6];Text first;int unknown98;Text second,third;int unknowna4,unknowna8,state,count,unknownb4;float fraction;unsigned int flags; };
struct Context {char unknown00[48];int value;};
struct Mode {char unknown00[28];Ptr32<Object> display; Ptr32<Object> property;};
Ptr32<void> w3d_auto_801ffea8(Ptr32<void>);
void w3d_fn_80347324(Ptr32<void>,Ptr32<const char>,...);
int w3d_fn_8015ad40(Ptr32<void>, Ptr32<void>);
void w3d_application_trace_801266d0();
void w3d_fn_801fcc48(int);
Ptr32<void> w3d_application_construct_80126bfc(Ptr32<Application>);
void w3d_application_destroy_80126d1c(Ptr32<Application>,int);
void w3d_auto_80207ca4(Ptr32<const char>);
void w3d_fn_8015bf74(Ptr32<Application>,Ptr32<const char>,int,int,int);
void w3d_fn_8015ba70(Ptr32<Application>);
void w3d_fn_8015c118(Ptr32<Application>);
void w3d_empty_80128084(Ptr32<Application>);
void w3d_string_base_finish(Ptr32<Text>);
void w3d_string_release(Ptr32<Text>);
void w3d_fn_8015c540(Ptr32<Application>,int);
void w3d_fn_802cc58c(Ptr32<void>);
Ptr32<Context> w3d_engine_get_context();
void w3d_auto_8015fd1c(Ptr32<void>);
Ptr32<void> w3d_auto_80164f88(Ptr32<Object>);
void w3d_fn_800fbf64(Ptr32<void>);
void w3d_fn_8015c880(Ptr32<Application>);
void w3d_fn_800fc230(Ptr32<Key>,Ptr32<unsigned int>);
void w3d_fn_80127ba0(Ptr32<Application>,unsigned int);
void w3d_fn_800fc270(Ptr32<Key>,Ptr32<float>);
Ptr32<Object> w3d_constructor_native_cast(Ptr32<Object>);
int w3d_auto_80178d1c(Ptr32<Object>);
void w3d_constant_8015fb2c(Ptr32<Mode>,Ptr32<void>);
extern char w3d_obj_803625c0[],w3d_obj_80361f88[],w3d_obj_80366938[],w3d_obj_803656dc[],w3d_obj_8036567c[],w3d_obj_8036564c[],w3d_obj_803655bc[],w3d_obj_80410c48[];
extern int w3d_obj_804b0640;
extern Ptr32<Application> w3d_obj_804b1788;
extern Ptr32<void> w3d_obj_804aaf88; extern Ptr32<void> w3d_obj_804ab004; extern Ptr32<void> w3d_obj_804aaabc; extern Ptr32<void> w3d_obj_804aaba4; extern Ptr32<void> w3d_obj_804aadcc;
extern const char w3d_str_8039bbe8[],w3d_str_8039bbfc[],w3d_str_8039bc00[],w3d_str_8039bc10[],w3d_str_8039bc1c[],w3d_str_8039bc28[],w3d_str_8039bc2c[],w3d_str_8039bd5c[],w3d_str_8039c8fc[],w3d_str_8039c914[],w3d_str_8039c928[];
extern const float w3d_f32_8039c93c[],w3d_f32_8039c940[];
inline void clear(Ptr32<Object> &slot,Ptr32<Object> replacement) { if(slot) ((Ptr32<void (Ptr32<Object>)>)slot->vtable[4])(slot);slot=replacement; }
void w3d_application_trace_801266d0() {
    w3d_fn_80347324(&w3d_obj_804b0640,w3d_str_8039bbe8,w3d::VA(w3d_auto_801ffea8(w3d_obj_803625c0)));
    w3d_fn_80347324(&w3d_obj_804b0640,w3d_str_8039bbe8,w3d::VA(w3d_auto_801ffea8(w3d_obj_80361f88)));
    w3d_fn_80347324(&w3d_obj_804b0640,w3d_str_8039bbfc,w3d::VA(w3d_auto_801ffea8(w3d_obj_80366938)));
    w3d_fn_80347324(&w3d_obj_804b0640,w3d_str_8039bc00,w3d::VA(w3d_fn_8015ad40));
    w3d_fn_80347324(&w3d_obj_804b0640,w3d_str_8039bbfc,w3d::VA(w3d_auto_801ffea8(w3d_obj_803656dc)));
    w3d_fn_80347324(&w3d_obj_804b0640,w3d_str_8039bbfc,w3d::VA(w3d_auto_801ffea8(w3d_obj_8036567c)));
    w3d_fn_80347324(&w3d_obj_804b0640,w3d_str_8039bbfc,w3d::VA(w3d_auto_801ffea8(w3d_obj_8036564c)));
    w3d_fn_80347324(&w3d_obj_804b0640,w3d_str_8039bbfc,w3d::VA(w3d_auto_801ffea8(w3d_obj_803655bc)));
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
void w3d_application_destroy_80126d1c(Ptr32<Application> self,int flags) {
    self->vtable=w3d_obj_80410c48;
    Ptr32<Text> third=&self->third;
    w3d_empty_80128084(self);
    Ptr32<Text> second=&self->second;
    w3d_obj_804b1788=0;
    Ptr32<Text> first=&self->first;
    w3d_string_base_finish(third);w3d_string_release(third);
    w3d_string_base_finish(second);w3d_string_release(second);
    w3d_string_base_finish(first);w3d_string_release(first);
    if(self->refs[5]) ((Ptr32<void (Ptr32<Object>)>)self->refs[5]->vtable[4])(self->refs[5]);
    if(self->refs[4]) ((Ptr32<void (Ptr32<Object>)>)self->refs[4]->vtable[4])(self->refs[4]);
    if(self->refs[3]) ((Ptr32<void (Ptr32<Object>)>)self->refs[3]->vtable[4])(self->refs[3]);
    if(self->refs[2]) ((Ptr32<void (Ptr32<Object>)>)self->refs[2]->vtable[4])(self->refs[2]);
    if(self->refs[1]) ((Ptr32<void (Ptr32<Object>)>)self->refs[1]->vtable[4])(self->refs[1]);
    if(self->refs[0]) ((Ptr32<void (Ptr32<Object>)>)self->refs[0]->vtable[4])(self->refs[0]);
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


