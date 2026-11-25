/* Inferred effect update shapes and property getters. */
typedef struct S9EffectOwner {char unknown0[28];int effect;char unknown32[36];int first,second;} S9EffectOwner;
extern void *fn_80343580(int);
extern int fn_8018c5b0(void *,int);
extern int fn_8018d35c(void *,int *);
extern int fn_8018d434(void *,int *);
extern int fn_8011bc28(S9EffectOwner *);
void s9_update_saved_effect_8011ad90(S9EffectOwner *self,int value)
{
    if(self->effect) {
        void *effect=fn_80343580(self->effect);
        fn_8018c5b0(effect,value);
        fn_8018d35c(effect,&self->first);
        fn_8018d434(effect,&self->second);
        fn_8011bc28(self);
    }
}
typedef struct S9RangeObject {char unknown0[84];unsigned int count;} S9RangeObject;
extern int fn_8016b488(void *,S9RangeObject *);
int s9_check_then_iterate_8016b6d8(void *self,S9RangeObject *range)
{
    int result=fn_8016b488(self,range);
    if(!result) {
        unsigned int index;
        for(index=0;index<range->count;index++) {}
        result=0;
    }
    return result;
}
typedef struct S9AxisOwner {char unknown0[144];int handle;} S9AxisOwner;
extern void *fn_80164fc8(int);
extern float fn_800ae9ac(void *);
extern float fn_800ae9b4(void *);
extern int fn_80181814(void *,int,float,float);
extern int lbl_804ab180,lbl_804ab17c;
extern float lbl_8039f6ec[];
void s9_update_axis_properties_8013a048(S9AxisOwner *self,void *context)
{
    void *object;
    int index;
    float value;
    if(self->handle==-1)return;
    object=fn_80164fc8(self->handle);
    if(!object) {self->handle=-1;return;}
    index=lbl_804ab180;
    value=fn_800ae9ac(object);
    fn_80181814(context,index,value,*lbl_8039f6ec);
    index=lbl_804ab17c;
    value=fn_800ae9b4(object);
    fn_80181814(context,index,value,*lbl_8039f6ec);
}
