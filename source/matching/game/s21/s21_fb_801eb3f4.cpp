// desc: Appears to read an element of a described object into an output: without a position it copies a default text, otherwise it calls the target's read slot, directly when it is of kind three or via a temporary text.
struct S21Text;
extern void fn_8020c5c4(S21Text *);
extern void fn_80341588(S21Text *);
struct S21Text {
    char *data;
    S21Text();
    ~S21Text() { fn_8020c5c4(this); fn_80341588(this); }
};
struct S21Target;
struct S21TargetMethods { void (*reserved[17])(void); int (*read_text)(S21Target *, S21Text *, int, int, int); void (*reserved2[3])(void); int (*read_direct)(S21Target *, int, int, int); };
struct S21Target { S21TargetMethods *methods; };
struct S21Link { char pad[8]; int value; };
struct S21Info { char pad[4]; unsigned short offset; char pad1[2]; S21Target *target; S21Link *link; };
struct S21Object { S21Info *info; };
extern const char lbl_803b0c58[];
extern int fn_801fff60(S21Target *);
extern int fn_8020dbf8(int, const char *);
extern int fn_8020d82c(int, S21Text *);
extern "C" void w3d_s21_read_element_801eb3f4(S21Object *self, int out, int position)
{
    if (position != 0) {
        S21Info *info = self->info;
        int value = 0;
        if (info->link)
            value = info->link->value;
        int offset = position + info->offset;
        if (fn_801fff60(info->target)) {
            S21Target *target = self->info->target;
            target->methods->read_direct(target, out, offset, value);
        } else {
            S21Text text;
            S21Target *target = self->info->target;
            target->methods->read_text(target, &text, offset, 0, value);
            fn_8020d82c(out, &text);
        }
    } else {
        fn_8020dbf8(out, lbl_803b0c58);
    }
}
