// desc: Appears to recurse through a first-child pointer, then call the function pointer at offset 12 and return its negative status or zero.
struct S21Node { struct S21Node *first; char pad[8]; int (*callback)(); };
int w3d_s21_run_callbacks_80200ca4(struct S21Node *node)
{
    if (!node)
        return 0;
    if (node->first)
        w3d_s21_run_callbacks_80200ca4(node->first);
    if (node->callback) {
        int status = node->callback();
        if (status < 0)
            return status;
    }
    return 0;
}
