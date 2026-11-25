struct K5bMemberDesc { char pad[6]; unsigned char kind; };
struct K5bMember { struct K5bMemberDesc *desc; };
struct K5bClass {
    void **vtable;
    char pad4[16];
    struct K5bClass *parent;
    char pad24[24];
    struct K5bMember **members;
};
extern struct K5bClass lbl_80365788[];
struct K5bClass *w3d_k5b_class_find_member_kind_801e9de4(struct K5bClass *cls, int kind)
{
    while (cls != lbl_80365788) {
        int count = ((int (*)(struct K5bClass *))cls->vtable[8])(cls);
        int i;
        for (i = 0; i < count; i++) {
            if (cls->members[i]->desc->kind == kind)
                return cls;
        }
        cls = cls->parent;
    }
    return 0;
}
// desc: w3d_k5b_class_find_member_kind_801e9de4: Appears to walk a class chain up to the root at 0x80365788 and return the first class with a member whose descriptor kind byte equals the argument.
