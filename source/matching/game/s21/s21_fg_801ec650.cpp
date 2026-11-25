// desc: Appears to read a double through the stream's virtual slot 18 and pass it to a bound member-function pointer on the target object, returning the read status.
typedef int (*S21Setter)(void *, double);
struct S21Method { short delta; short index; union { S21Setter function; short vtable_offset; } u; };
struct S21Stream;
struct S21StreamMethods { void (*reserved[18])(void); int (*read)(S21Stream *, double *, int, int); };
struct S21Stream { S21StreamMethods *methods; };
struct S21Owner { char pad[8]; S21Stream *stream; };
struct S21Binding { S21Owner *owner; char reserved[20]; S21Method set; };
extern "C" int w3d_s21_read_set_double_801ec650(S21Binding *binding, int position, char *target)
{
    double value;
    S21Setter function;
    int status = binding->owner->stream->methods->read(binding->owner->stream, &value, position, 0);
    if (status >= 0) {
        if (binding->set.index >= 0)
            function = *(S21Setter *)(*(int *)(target + binding->set.u.vtable_offset) + binding->set.index * 4 - 4);
        else
            function = binding->set.u.function;
        function(target + binding->set.delta, value);
    }
    return status;
}
