/* String search with observed range layouts. */
typedef struct S10StringList28 { char reserved[28]; const char **begin; const char **end; } S10StringList28;
extern int fn_802ef074(const char *, const char *);
typedef struct S10StringList72 { char reserved[72]; const char **begin; const char **end; } S10StringList72;

int w3d_s10_find_string_801b4060(const S10StringList28 *list, const char *value)
{
    const char **end = list->end;
    const char **entry = list->begin;
    while (entry != end) {
        if (fn_802ef074(value, *entry) == 0)
            return entry - list->begin;
        ++entry;
    }
    return -1;
}

int w3d_s10_find_string_801b40d0(const S10StringList72 *list, const char *value)
{
    const char **end = list->end;
    const char **entry = list->begin;
    while (entry != end) {
        if (fn_802ef074(value, *entry) == 0)
            return entry - list->begin;
        ++entry;
    }
    return -1;
}
