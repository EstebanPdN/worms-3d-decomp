// desc: Appears to ask its embedded inner object for a related object through a virtual slot and then invoke another virtual slot on the result.
struct S21Target;
struct S21TargetMethods { void (*reserved[22])(void); void (*run)(struct S21Target *); };
struct S21Target { struct S21TargetMethods *methods; };
struct S21Inner;
struct S21InnerMethods { void (*reserved[6])(void); struct S21Target *(*get_target)(struct S21Inner *); };
struct S21Inner { struct S21InnerMethods *methods; };
struct S21Owner { char pad[20]; struct S21Inner inner; };
void w3d_s21_run_inner_target_80211f40(struct S21Owner *self)
{
    struct S21Target *target = self->inner.methods->get_target(&self->inner);
    target->methods->run(target);
}
