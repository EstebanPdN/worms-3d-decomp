/* Observed float field at offset 28 of the inner object. */
typedef struct S9FloatValue { char unknown0[28]; float value; } S9FloatValue;
typedef struct S9FloatOwner { void *unknown0; S9FloatValue *inner; } S9FloatOwner;
extern int fn_80178b5c(void *);
int s9_permute_80178dfc(S9FloatOwner *self,const float *value)
{
    float next=*value;
    if(self->inner->value==next)return 1;
    self->inner->value=next;
    fn_80178b5c(self);
    return 0;
}
