typedef struct S10PointerRange { char reserved[36]; void **begin; void **end; } S10PointerRange;
void **w3d_s10_range_data_801fb7f8(const S10PointerRange *object, int *count)
{
    *count = object->end - object->begin;
    if (*count == 0)
        return 0;
    return object->begin;
}
