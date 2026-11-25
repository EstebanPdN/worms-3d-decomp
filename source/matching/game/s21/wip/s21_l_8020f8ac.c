// desc: Appears to pop an eight-byte entry from a counted stack into an output pair.
struct S21Pair { int first; int second; };
struct S21PairStack { char pad[16]; struct S21Pair items[256]; int count; };
void w3d_s21_pair_stack_pop_8020f8ac(struct S21PairStack *stack, struct S21Pair *out)
{
    stack->count--;
    *out = stack->items[stack->count];
}
