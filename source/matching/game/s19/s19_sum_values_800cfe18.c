struct S19Ent { char pad0[12]; float value; char pad16[12]; };
struct S19Owner { char pad0[28]; struct S19Ent *begin; struct S19Ent *end; };
float s19_sum_values_800cfe18(struct S19Owner *p)
{
    float sum = 0.0f;
    struct S19Ent *b = p->begin;
    unsigned n = p->end - b;
    unsigned i;
    for (i = 0; i < n; i++)
        sum += b[i].value;
    return sum;
}
