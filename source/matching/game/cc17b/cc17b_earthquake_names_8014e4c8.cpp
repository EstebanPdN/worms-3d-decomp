/* Four observed property-name temporaries are independent four-byte handles.
   Offsets and property strings are original evidence; subsystem role is inferred. */
struct Cc17bEarthquakeSettings { char pad[816]; unsigned minimum,maximum; char pad2[304]; unsigned random_integer,random_float; };
extern "C" {
extern char name_803a16c0[],name_803a16e0[],name_803a1700[],name_803a1714[];
int fn_800fc270(const char **,unsigned *);
int fn_800fc1b0(const char **,unsigned *);
void w3d_cc17b_earthquake_names_8014e4c8(Cc17bEarthquakeSettings *self) {
 const char *minimum=name_803a16c0; fn_800fc270(&minimum,&self->minimum);
 const char *maximum=name_803a16e0; fn_800fc270(&maximum,&self->maximum);
 const char *integer=name_803a1700; fn_800fc1b0(&integer,&self->random_integer);
 const char *fraction=name_803a1714; fn_800fc1b0(&fraction,&self->random_float);
}
}
