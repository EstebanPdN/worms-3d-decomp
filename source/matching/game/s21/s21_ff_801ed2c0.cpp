// desc: Appears to compare the strings obtained from two objects through a bound member-function pointer and report whether they are equal.
typedef char **(*S21Getter)(void *);
struct S21Method { short delta; short index; union { S21Getter function; short vtable_offset; } u; };
struct S21Binding { char reserved[12]; S21Method get; };
extern int fn_802ef234(const char *, const char *);
extern "C" int w3d_s21_equal_strings_801ed2c0(S21Binding *binding, char *first, char *second)
{
    S21Getter function;
    char **a;
    char **b;
    if (binding->get.index >= 0)
        function = *(S21Getter *)(*(int *)(first + binding->get.u.vtable_offset) + binding->get.index * 4 - 4);
    else
        function = binding->get.u.function;
    a = function(first + binding->get.delta);
    if (binding->get.index >= 0)
        function = *(S21Getter *)(*(int *)(second + binding->get.u.vtable_offset) + binding->get.index * 4 - 4);
    else
        function = binding->get.u.function;
    b = function(second + binding->get.delta);
    return fn_802ef234(*a, *b) == 0;
}
