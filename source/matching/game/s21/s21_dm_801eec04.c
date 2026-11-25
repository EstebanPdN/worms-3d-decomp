// desc: Appears to be a destructor body that releases every shared string of the counted array at offset 32, installs the base vtable and destroys the embedded node.
// desc: Appears to be a destructor body that releases every shared string of the counted array at offset 32, installs the base vtable and destroys the embedded node.
struct S21Object { void *vtable; char node[20]; int count; char pad[4]; char *strings[1]; };
extern char lbl_80417670[];
extern char lbl_80411ac0[];
extern void fn_8020bb2c(void *);
extern void fn_80210990(void *, int);
void w3d_s21_destroy_801eec04(struct S21Object *self)
{
    int count = self->count;
    char **strings = self->strings;
    char **text;
    int remaining;
    self->vtable = lbl_80417670;
    if (count > 0) {
        text = strings;
        remaining = count;
        do {
            unsigned short *header = (unsigned short *)(*text - 6);
            unsigned short left;
            text++;
            left = --*header;
            if (left == 0)
                fn_8020bb2c(header);
        } while (--remaining);
    }
    self->vtable = lbl_80411ac0;
    fn_80210990(self->node, 0);
}
