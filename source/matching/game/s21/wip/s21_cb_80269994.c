// desc: Appears to run a virtual slot of the object returned by a helper for the second argument when its field at offset 496 is zero, then return zero.
struct S21Target;
struct S21TargetMethods { void (*reserved[4])(void); void (*run)(struct S21Target *); };
struct S21Target { struct S21TargetMethods *methods; };
struct S21Context { char pad[496]; int disabled; };
extern struct S21Target *fn_8026b3f0(struct S21Context *);
int w3d_s21_run_if_enabled_80269994(void *self, struct S21Context *context)
{
    if (context->disabled == 0) {
        struct S21Target *target = fn_8026b3f0(context);
        if (target)
            target->methods->run(target);
    }
    return 0;
}
