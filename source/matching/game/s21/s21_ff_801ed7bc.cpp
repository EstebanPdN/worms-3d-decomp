// desc: Appears to convert a float to an integer and call a bound member-function pointer of the target object with it, returning the call's result.
typedef int (*S21Function)(void *, int);
struct S21Method { short delta; short index; union { S21Function function; short vtable_offset; } u; };
struct S21Binding { char reserved[20]; S21Method set; };
extern "C" int w3d_s21_set_int_801ed7bc(S21Binding *binding, char *target, int unused, const float *value)
{
    S21Function function;
    if (binding->set.index >= 0)
        function = *(S21Function *)(*(int *)(target + binding->set.u.vtable_offset) + binding->set.index * 4 - 4);
    else
        function = binding->set.u.function;
    return function(target + binding->set.delta, (int)*value);
}
