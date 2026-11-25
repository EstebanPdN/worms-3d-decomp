// desc: Select an index only for modes two or three, then check signed nonnegativity and pointer-range element count; names inferred.
// Observed: begin/end pointers at +0/+4 bound four-byte entries.
// Modes 0/1 leave the sentinel index -1; modes 2/3 use the supplied index.
// The vector owner and the original meaning of the mode are unresolved.
struct R24bWordRange {
    unsigned *begin;
    unsigned *end;
};
extern "C" int w3d_r24b_resolve_index_801f9fbc(
    R24bWordRange *range, int mode, int requested)
{
    int index = -1;
    switch (mode) {
    case 0:
    case 1:
        break;
    case 2:
    case 3:
        index = requested;
        break;
    default:
        return -1;
    }
    if (index >= 0 && static_cast<unsigned>(index) <
        static_cast<unsigned>(range->end - range->begin))
        return index;
    return -1;
}
