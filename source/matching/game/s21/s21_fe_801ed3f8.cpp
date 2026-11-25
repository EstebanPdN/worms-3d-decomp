// desc: Appears to read a value through a bound member-function pointer on the target and write it to a stream through virtual slot 8 together with the binding's first word.
typedef int (*S21Getter)(void *);
struct S21Method { short delta; short index; union { S21Getter function; short vtable_offset; } u; };
struct S21Stream;
struct S21StreamMethods { void (*reserved[8])(void); int (*write)(S21Stream *, int, int); };
struct S21Stream { S21StreamMethods *methods; };
struct S21Binding { int *key; char reserved[8]; S21Method get; };
extern "C" int w3d_s21_write_value_801ed3f8(S21Binding *binding, S21Stream *stream, char *target)
{
    S21StreamMethods *methods = stream->methods;
    S21Getter function;
    int value;
    if (binding->get.index >= 0)
        function = *(S21Getter *)(*(int *)(target + binding->get.u.vtable_offset) + binding->get.index * 4 - 4);
    else
        function = binding->get.u.function;
    value = function(target + binding->get.delta);
    return methods->write(stream, value, *binding->key);
}
