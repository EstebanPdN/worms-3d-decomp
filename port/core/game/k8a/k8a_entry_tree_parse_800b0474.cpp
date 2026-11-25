#include "w3d_ptr.h"
#line 1 "k8a_entry_tree_parse_800b0474.cpp"
// Appears to build a chain of tree entries from a delimited path: each token is parsed
// into an origin, wrapped in a new entry linked to its parent, and the last entry is
// reported through the output pointer.
struct K8aString { Ptr32<char> text; };
struct K8aWords3 { int a, b, c; };
struct K8aEntry
{
    char pad0[4];
    K8aString name;          // +4
    K8aWords3 origin;        // +8
    Ptr32<K8aEntry> parent;        // +20
    Ptr32<K8aEntry> child;         // +24
};
extern "C" void w3d_entry_origin_parse_800b0530(Ptr32<void> self, Ptr32<const char> token, Ptr32<K8aWords3> origin);
extern "C" Ptr32<void> w3d_heap_allocate(Ptr32<void> pool, int size);
extern "C" Ptr32<K8aEntry> k4a_entry_construct_800afdd4(Ptr32<void> self);
extern "C" void w3d_string_assign(Ptr32<K8aString> string, Ptr32<const char> text);
extern "C" Ptr32<char> strtok(Ptr32<char> text, Ptr32<const char> delimiters);
extern unsigned int w3d_heap_804b0044;
extern Ptr32<char> w3d_delimiters_804aacb8;
extern "C" Ptr32<K8aEntry> w3d_k8a_entry_tree_parse_800b0474(Ptr32<void> self, Ptr32<K8aEntry> parent, Ptr32<char> token, Ptr32<Ptr32<K8aEntry>> last)
{
    Ptr32<K8aEntry> result;
    if (token)
    {
        K8aWords3 origin;
        w3d_entry_origin_parse_800b0530(self, token, &origin);
        Ptr32<K8aEntry> entry = k4a_entry_construct_800afdd4(w3d_heap_allocate(&w3d_heap_804b0044, 28));
        w3d_string_assign(&entry->name, token);
        entry->origin = origin;
        entry->parent = parent;
        entry->child = w3d_k8a_entry_tree_parse_800b0474(self, entry, strtok(0, w3d_delimiters_804aacb8), last);
        result = entry;
    }
    else
    {
        *last = parent;
        result = 0;
    }
    return result;
}


