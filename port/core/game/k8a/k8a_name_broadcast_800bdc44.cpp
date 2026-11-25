#include "w3d_ptr.h"
#line 1 "k8a_name_broadcast_800bdc44.cpp"
// Appears to send a name string to every element of every registered group: for each
// group in the global group list it passes a copy of the name to each of the group's
// elements; the by-value name parameter is destroyed on return.
extern "C" void w3d_string_base_init(Ptr32<void> string);
extern "C" Ptr32<unsigned short> w3d_string_header(Ptr32<void> string);
extern "C" void w3d_string_base_finish(Ptr32<void> string);
extern "C" void w3d_string_release(Ptr32<void> string);
struct K8aString
{
    Ptr32<char> text;
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
    Ptr32<Ptr32<K8aElement>> begin;      // +20
    Ptr32<Ptr32<K8aElement>> end;        // +24
};
struct K8aGroupList
{
    Ptr32<Ptr32<K8aGroup>> begin;
    Ptr32<Ptr32<K8aGroup>> end;
};
extern K8aGroupList w3d_groups_8043bb64[];
extern "C" void w3d_auto_800608d4(Ptr32<K8aElement> element, K8aString name);
extern "C" void w3d_k8a_name_broadcast_800bdc44(Ptr32<void> self, K8aString name)
{
    Ptr32<Ptr32<K8aGroup>> group = w3d_groups_8043bb64[0].begin;
    Ptr32<Ptr32<K8aGroup>> groupEnd = w3d_groups_8043bb64[0].end;
    for (; group != groupEnd; ++group)
    {
        Ptr32<Ptr32<K8aElement>> last = (*group)->end;
        Ptr32<Ptr32<K8aElement>> first = (*group)->begin;
        for (; first != last; ++first)
            w3d_auto_800608d4(*first, name);
    }
}


