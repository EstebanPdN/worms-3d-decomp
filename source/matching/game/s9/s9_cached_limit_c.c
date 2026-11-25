/* Local views include the stack extent observed for the reference and name objects. */
typedef struct S9LimitInterfaceC { void **vtable; } S9LimitInterfaceC;
typedef struct S9LimitRefC { S9LimitInterfaceC *pointer; int unknown; } S9LimitRefC;
typedef struct S9LimitNameC { char *text; int unknown[3]; } S9LimitNameC;
typedef struct S9LimitLocalsC { S9LimitRefC reference; S9LimitNameC name; } S9LimitLocalsC;
typedef void (*S9LimitMethodC)(S9LimitInterfaceC *);
extern S9LimitInterfaceC *lbl_804afdf8;
extern char lbl_803a1230[];
extern void fn_800fc1b0(S9LimitNameC *,S9LimitRefC *);
extern S9LimitInterfaceC *fn_80342a74(S9LimitInterfaceC *);
extern float fn_8014ca54(void *);
extern float fn_80178df0(S9LimitInterfaceC *);
int s9_compare_cached_limit_8014c89c(void *self)
{
    float angle;
    if(!lbl_804afdf8) {
        S9LimitLocalsC locals;
        S9LimitInterfaceC *value;

        locals.reference.pointer=0;
        locals.name.text=lbl_803a1230;
        fn_800fc1b0(&locals.name,&locals.reference);
        value=fn_80342a74(locals.reference.pointer);
        if(value)((S9LimitMethodC)value->vtable[3])(value);
        if(lbl_804afdf8)((S9LimitMethodC)lbl_804afdf8->vtable[4])(lbl_804afdf8);
        lbl_804afdf8=value;
        if(locals.reference.pointer)((S9LimitMethodC)locals.reference.pointer->vtable[4])(locals.reference.pointer);
    }
    angle=fn_8014ca54(self);
    return angle<=fn_80178df0(lbl_804afdf8);
}
