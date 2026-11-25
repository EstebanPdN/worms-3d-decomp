struct K6bFieldAccessor {
    int offset;
    void *(*read)(void);
};
extern int fn_8020b460(void *field, void *value, void *context, void *extra);
void w3d_k6b_accessor_apply_8020b574(char *owner, void *context, void *extra, struct K6bFieldAccessor *accessor)
{
    char *field = owner + accessor->offset;
    fn_8020b460(field, accessor->read(), context, extra);
}
// desc: w3d_k6b_accessor_apply_8020b574: Appears to read a value through the accessor callback at +4 and pass it with the field at owner plus the accessor offset to 0x8020b460.
