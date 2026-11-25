// desc: Appears to construct an object on a base constructor with its own vtable, a type code of 23 and an embedded shared string copied from a global default string.
inline void *operator new(unsigned int, void *place) { return place; }
extern void fn_8020c5c0(void *);
extern unsigned short *fn_80341884(void *);
extern char *lbl_804b06a0[];
struct S21Text {
    char *data;
    S21Text(char *source) { fn_8020c5c0(this); data = source; ++*fn_80341884(this); }
};
struct S21Root { virtual void method(); };
struct S21Base : S21Root {
    S21Base();
    char pad[16];
};
struct S21Object : S21Base {
    int type;
    S21Text text;
    S21Object() : type(23), text(lbl_804b06a0[0]) { }
    virtual void method();
};
extern "C" S21Object *w3d_s21_construct_8024f174(S21Object *self)
{
    return new (self) S21Object;
}
