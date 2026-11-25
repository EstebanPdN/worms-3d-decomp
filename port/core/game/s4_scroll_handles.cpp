#include "w3d_ptr.h"
#line 1 "s4_scroll_handles.cpp"
/* Observed scroll-interface ownership and forwarding operations. */
extern "C" {
struct ScrollObject { Ptr32<Ptr32<void (Ptr32<ScrollObject>)>> vtable; char pad04[32]; Ptr32<char> name; };
struct ScrollRef { Ptr32<ScrollObject> object; int reserved; };
struct ScrollString { Ptr32<char> text; int reserved; };
void w3d_string_from_text(Ptr32<ScrollString>, Ptr32<const char>);
void w3d_handle_set_name(Ptr32<ScrollString>, Ptr32<ScrollRef>, int);
Ptr32<ScrollObject> w3d_empty_8034bf4c(Ptr32<ScrollObject>);
void w3d_string_base_finish(Ptr32<ScrollString>);
void w3d_string_release(Ptr32<ScrollString>);
void w3d_scroll_remove_80287c88(Ptr32<void>, Ptr32<ScrollObject>);
void w3d_actor_member_delete_backend(Ptr32<void>);
Ptr32<ScrollObject> w3d_create_8020b680(Ptr32<const void>);
void w3d_string_release_header(Ptr32<void>);
void w3d_attach_scroll_80174820(Ptr32<void>, Ptr32<ScrollObject>);
extern Ptr32<void> w3d_global_804abbc8;
extern const char w3d_str_803d06f4[];
extern const unsigned char w3d_descriptor_804144e8[];
#if 0 /* Argument setup order differs in four instruction words. */
ScrollRef *w3d_s4_scroll_handle_construct(ScrollRef *self, const char *text, int mode)
{
    struct { ScrollString name; ScrollRef found; } local;
    self->object = 0;
    w3d_string_from_text(&local.name, text);
    register ScrollString *namePtr = &local.name;
    local.found.object = 0;
    w3d_handle_set_name(namePtr, &local.found, mode);
    ScrollObject *object = w3d_empty_8034bf4c(local.found.object);
    if (object) object->vtable[3](object);
    if (self->object) self->object->vtable[4](self->object);
    self->object = object;
    if (local.found.object) local.found.object->vtable[4](local.found.object);
    w3d_string_base_finish(namePtr);
    w3d_string_release(namePtr);
    return self;
}
#endif
void w3d_s4_scroll_handle_destroy(Ptr32<ScrollRef> self, int flags)
{
    w3d_scroll_remove_80287c88(w3d_global_804abbc8, self->object);
    if (self->object) self->object->vtable[4](self->object);
    if (flags & 1) w3d_actor_member_delete_backend(self);
}
#if 0 /* String-address and argument setup order differ in two instruction words. */
int w3d_s4_scroll_attach_border(void *owner)
{
    struct { ScrollRef ref; ScrollString text; } local;
    local.ref.object = w3d_create_8020b680(w3d_descriptor_804144e8);
    if (local.ref.object) local.ref.object->vtable[3](local.ref.object);
    ScrollObject *object = local.ref.object;
    register const char *rootName = w3d_str_803d06f4;
    w3d_string_from_text(&local.text, rootName);
    ++*(unsigned short *)(local.text.text - 6);
    char *old = object->name;
    unsigned short *header = (unsigned short *)(old - 6);
    unsigned int remaining = *(unsigned short *)(old - 6) - 1;
    *(unsigned short *)(old - 6) = remaining;
    if (!(unsigned short)remaining) w3d_string_release_header(header);
    object->name = local.text.text;
    w3d_string_base_finish(&local.text);
    w3d_string_release(&local.text);
    w3d_attach_scroll_80174820(owner, local.ref.object);
    if (local.ref.object) local.ref.object->vtable[4](local.ref.object);
    return 0;
}
#endif
void w3d_s4_scroll_set_child(Ptr32<ScrollRef> self, Ptr32<void> child)
{
    Ptr32<ScrollObject> object = self->object;
    ((Ptr32<void (Ptr32<ScrollObject>, Ptr32<void>, int)>)object->vtable[19])(object, child, 0);
}
void w3d_s4_scroll_bind_to(Ptr32<ScrollRef> self, Ptr32<ScrollObject> target)
{
    ((Ptr32<void (Ptr32<ScrollObject>, Ptr32<ScrollObject>, int)>)target->vtable[23])(target, self->object, 0);
}
void w3d_s4_scroll_refresh(Ptr32<ScrollRef> self)
{
    Ptr32<ScrollObject> object = self->object;
    object->vtable[22](object);
}
}


