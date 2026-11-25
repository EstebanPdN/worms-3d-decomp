#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_cz_801f8d6c.c"
// desc: Appears to find an entry by name in the object's array of 64-byte records, comparing the name with the record's leading text, and return the record or zero.
struct S21Record { char name[64]; };
struct S21Table { char pad[32]; int count; Ptr32<struct S21Record> records; };
extern int fn_802ef074(Ptr32<const char>, Ptr32<const char>);
Ptr32<struct S21Record> w3d_s21_find_by_name_801f8d6c(Ptr32<struct S21Table> table, Ptr32<const char> name)
{
    int i = 0;
    Ptr32<struct S21Record> record = table->records;
    for (; i < table->count; i++, record++) {
        if (fn_802ef074(name, record->name) == 0)
            return record;
    }
    return 0;
}

}
