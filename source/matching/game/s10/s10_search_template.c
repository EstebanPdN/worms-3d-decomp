typedef struct S10StringList { char reserved[28]; const char **begin; const char **end; } S10StringList;
extern int fn_802ef074(const char *, const char *);
int w3d_s10_find_string_801b4060(const S10StringList *list, const char *value)
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
