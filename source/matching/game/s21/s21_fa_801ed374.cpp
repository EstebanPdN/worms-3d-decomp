// desc: Appears to build a temporary string from a text and pass it to a bound member-function pointer called on the target object, returning zero.
struct S21Text;
extern void fn_8020c5c4(S21Text *);
extern void fn_80341588(S21Text *);
struct S21Text {
    char *data;
    S21Text(const char *source);
    ~S21Text() { fn_8020c5c4(this); fn_80341588(this); }
};
typedef void (*S21Function)(void *, S21Text *);
struct S21Method { short delta; short index; union { S21Function function; short vtable_offset; } u; };
struct S21Binding { char reserved[20]; S21Method write; };
extern "C" int w3d_s21_write_text_801ed374(S21Binding *binding, const char *text, char *target)
{
    S21Function function;
    char *self;
    if (binding->write.index >= 0)
        function = *(S21Function *)(*(int *)(target + binding->write.u.vtable_offset) + binding->write.index * 4 - 4);
    else
        function = binding->write.u.function;
    self = target + binding->write.delta;
    {
        S21Text temporary(text);
        function(self, &temporary);
    }
    return 0;
}
