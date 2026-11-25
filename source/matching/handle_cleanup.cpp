/* Reconstructed native slot/free-handle cleanup, original entry 8003f8e8.
 * Reference proof and bounded behavior are recorded separately. */
typedef unsigned int HandleSize;
typedef unsigned short HandleValue;
struct HandleResource;
struct HandleResourceMethods {
    void *unknown_00[22];
    void (*cleanup)(HandleResource *, int);
};
struct HandleResource { HandleResourceMethods *methods; };
struct HandleSlot {
    unsigned char unknown_00[0x14];
    unsigned int active;
    unsigned int unknown_18;
    HandleResource *resource;
};
struct HandleVector { unsigned char *begin, *end, *limit; };
struct HandleTable {
    HandleSlot *slots;
    unsigned char unknown_04[12];
};
extern "C" {
extern HandleTable w3d_handle_table;
extern HandleVector w3d_free_handles;
void *w3d_handle_storage_allocate(HandleSize);
void w3d_handle_storage_release(void *);
/* Native declaration is variadic: the original call clears the FP vararg bit. */
void *w3d_handle_copy_memory(void *, const void *, HandleSize, ...);
}

template<class T> inline const T &handle_max(const T &first, const T &second)
{ return first < second ? second : first; }
template<class T> inline const T &handle_min(const T &first, const T &second)
{ return second < first ? second : first; }

inline void handle_push(HandleVector *v, const HandleValue &value)
{
    if (v->end == v->limit) {
        HandleSize used = v->end - v->begin;
        HandleSize bytes = 2 * handle_max((int)(used + 1), (int)(used + (used >> 1)));
        unsigned char *replacement = (unsigned char *)w3d_handle_storage_allocate(bytes);
        if (v->begin) {
            w3d_handle_copy_memory(replacement, v->begin, handle_min(bytes, used));
            w3d_handle_storage_release(v->begin);
        }
        v->begin = replacement;
        v->end = replacement + used;
        v->limit = replacement + bytes;
    }
    *(HandleValue *)v->end = value;
    v->end += sizeof(HandleValue);
}

inline HandleSlot &handle_slot(HandleSlot *base, unsigned int i) { return *(base + i); }

extern "C" void w3d_actor_handle_cleanup_backend(unsigned int handle)
{
    HandleValue recycled = (HandleValue)handle;
    handle_slot(w3d_handle_table.slots, handle).active = 0;
    HandleResource *resource = handle_slot(w3d_handle_table.slots, handle).resource;
    if (resource)
        resource->methods->cleanup(resource, 0);
    handle_push(&w3d_free_handles, recycled);
}
