// desc: Appears to follow a chain of fields from the engine context and return a nested value, or zero when the object has no link or the chain condition word is zero.
struct S21Leaf { char pad[24]; int value; };
struct S21Mid { char pad[24]; struct S21Leaf *leaf; };
struct S21Top { char pad[24]; int condition; char pad1[4]; struct S21Mid *mid; };
struct S21Engine { char pad[32]; struct S21Top *top; };
struct S21Object { char pad[28]; int link; };
extern void * fn_80341584(int);
extern struct S21Engine *fn_801797b4(void *);
int w3d_s21_nested_value_802bc71c(struct S21Object *self)
{
    int link = self->link;
    if (link == 0)
        return 0;
    {
        struct S21Top *top = fn_801797b4(fn_80341584(link))->top;
        if (top->condition == 0)
            return 0;
        return top->mid->leaf->value;
    }
}
