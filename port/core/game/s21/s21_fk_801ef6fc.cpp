#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_fk_801ef6fc.c"
// desc: Appears to copy an interface field between two objects: it retains the interface at the source descriptor's offset in the third argument, releases the one at the target descriptor's offset and stores the new pointer.
struct S21Ref;
struct S21RefMethods { Ptr32<void (void)> reserved[3]; Ptr32<void (Ptr32<struct S21Ref>)> retain; Ptr32<void (Ptr32<struct S21Ref>)> release; };
struct S21Ref { Ptr32<struct S21RefMethods> methods; };
struct S21Info { char pad[4]; unsigned short offset; };
struct S21Field { Ptr32<struct S21Info> info; };
void w3d_s21_copy_ref_field_801ef6fc(Ptr32<struct S21Field> target_field, Ptr32<char> target, Ptr32<char> source, Ptr32<struct S21Field> source_field)
{
    Ptr32<struct S21Info> source_info = source_field->info;
    Ptr32<struct S21Info> target_info = target_field->info;
    unsigned short target_offset = target_info->offset;
    Ptr32<struct S21Ref> fresh = *(Ptr32<Ptr32<struct S21Ref>>)(source + source_info->offset);
    Ptr32<struct S21Ref> old;
    fresh->methods->retain(fresh);
    old = *(Ptr32<Ptr32<struct S21Ref>>)(target + target_offset);
    old->methods->release(old);
    *(Ptr32<Ptr32<struct S21Ref>>)(target + target_offset) = fresh;
}

}
