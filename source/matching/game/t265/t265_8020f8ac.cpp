struct T265Pair { unsigned first, second; };
struct T265Stack { unsigned header[4]; T265Pair entries[256]; int count; };
extern "C" void t265_pop_pair_8020f8ac(T265Stack *stack, T265Pair *out)
{
    int index = stack->count - 1;
    stack->count = index;
    T265Stack *entry = (T265Stack *)((char *)stack + index * 8);
    unsigned first = entry->entries[0].first;
    out->second = entry->entries[0].second;
    out->first = first;
}
