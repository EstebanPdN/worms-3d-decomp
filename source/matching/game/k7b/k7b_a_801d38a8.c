struct K7bString { char *text; };
struct K7bNamedItem { char pad[36]; struct K7bString name; };
struct K7bItemList { char pad[72]; struct K7bNamedItem **begin; struct K7bNamedItem **end; };
extern struct K7bString *w3d_string_append(struct K7bString *string, const char *text);
extern char lbl_803af028[];
#define K7B_STRING_LENGTH(s) (((unsigned short *)(s).text)[-2])
int w3d_k7b_item_list_join_names_801d38a8(struct K7bItemList *self, struct K7bString *out)
{
    struct K7bNamedItem **it = self->begin;
    struct K7bNamedItem **end = self->end;
    int first = 1;
    for (; it != end; it++) {
        struct K7bNamedItem *item = *it;
        if (K7B_STRING_LENGTH(item->name) != 0) {
            if (!first)
                w3d_string_append(out, lbl_803af028);
            w3d_string_append(out, item->name.text);
            first = 0;
        }
    }
    return 0;
}
