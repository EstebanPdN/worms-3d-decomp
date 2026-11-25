// Appears to build a chain of tree entries from a delimited path: each token is parsed
// into an origin, wrapped in a new entry linked to its parent, and the last entry is
// reported through the output pointer.
struct K8aString { char *text; };
struct K8aWords3 { int a, b, c; };
struct K8aEntry
{
    char pad0[4];
    K8aString name;          // +4
    K8aWords3 origin;        // +8
    K8aEntry *parent;        // +20
    K8aEntry *child;         // +24
};
extern "C" void w3d_entry_origin_parse_800b0530(void *self, const char *token, K8aWords3 *origin);
extern "C" void *w3d_heap_allocate(void *pool, int size);
extern "C" K8aEntry *k4a_entry_construct_800afdd4(void *self);
extern "C" void w3d_string_assign(K8aString *string, const char *text);
extern "C" char *strtok(char *text, const char *delimiters);
extern unsigned int w3d_heap_804b0044;
extern char *w3d_delimiters_804aacb8;
extern "C" K8aEntry *w3d_k8a_entry_tree_parse_800b0474(void *self, K8aEntry *parent, char *token, K8aEntry **last)
{
    K8aEntry *result;
    if (token)
    {
        K8aWords3 origin;
        w3d_entry_origin_parse_800b0530(self, token, &origin);
        K8aEntry *entry = k4a_entry_construct_800afdd4(w3d_heap_allocate(&w3d_heap_804b0044, 28));
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
