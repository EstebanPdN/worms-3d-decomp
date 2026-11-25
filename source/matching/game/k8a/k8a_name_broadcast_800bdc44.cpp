// Appears to send a name string to every element of every registered group: for each
// group in the global group list it passes a copy of the name to each of the group's
// elements; the by-value name parameter is destroyed on return.
extern "C" void w3d_string_base_init(void *string);
extern "C" unsigned short *w3d_string_header(void *string);
extern "C" void w3d_string_base_finish(void *string);
extern "C" void w3d_string_release(void *string);
struct K8aString
{
    char *text;
    unsigned int storage;
    K8aString(const K8aString &other)
    {
        w3d_string_base_init(this);
        text = other.text;
        ++*w3d_string_header(this);
    }
    ~K8aString() { w3d_string_base_finish(this); w3d_string_release(this); }
};
struct K8aElement;
struct K8aGroup
{
    char pad0[20];
    K8aElement **begin;      // +20
    K8aElement **end;        // +24
};
struct K8aGroupList
{
    K8aGroup **begin;
    K8aGroup **end;
};
extern K8aGroupList w3d_groups_8043bb64[];
extern "C" void w3d_auto_800608d4(K8aElement *element, K8aString name);
extern "C" void w3d_k8a_name_broadcast_800bdc44(void *self, K8aString name)
{
    K8aGroup **group = w3d_groups_8043bb64[0].begin;
    K8aGroup **groupEnd = w3d_groups_8043bb64[0].end;
    for (; group != groupEnd; ++group)
    {
        K8aElement **last = (*group)->end;
        K8aElement **first = (*group)->begin;
        for (; first != last; ++first)
            w3d_auto_800608d4(*first, name);
    }
}
