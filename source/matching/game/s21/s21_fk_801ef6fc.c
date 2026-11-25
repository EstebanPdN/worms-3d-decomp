// desc: Appears to copy an interface field between two objects: it retains the interface at the source descriptor's offset in the third argument, releases the one at the target descriptor's offset and stores the new pointer.
struct S21Ref;
struct S21RefMethods { void (*reserved[3])(void); void (*retain)(struct S21Ref *); void (*release)(struct S21Ref *); };
struct S21Ref { struct S21RefMethods *methods; };
struct S21Info { char pad[4]; unsigned short offset; };
struct S21Field { struct S21Info *info; };
void w3d_s21_copy_ref_field_801ef6fc(struct S21Field *target_field, char *target, char *source, struct S21Field *source_field)
{
    struct S21Info *source_info = source_field->info;
    struct S21Info *target_info = target_field->info;
    unsigned short target_offset = target_info->offset;
    struct S21Ref *fresh = *(struct S21Ref **)(source + source_info->offset);
    struct S21Ref *old;
    fresh->methods->retain(fresh);
    old = *(struct S21Ref **)(target + target_offset);
    old->methods->release(old);
    *(struct S21Ref **)(target + target_offset) = fresh;
}
