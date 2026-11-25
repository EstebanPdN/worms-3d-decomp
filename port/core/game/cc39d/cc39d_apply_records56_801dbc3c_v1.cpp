#include "w3d_ptr.h"
#line 1 "cc39d_apply_records56_801dbc3c_v1.cpp"
// Apply a zero-key-terminated array of 56-byte records to a registry's
// element pointer array (0x801dbc3c); 56-byte member of the record-walk
// family proven at 0x801dbd34/0x801dc254. Each record's id at +8 is searched
// linearly among the elements (id at element +36). A miss calls the create
// slot (+148) with the id and retries the same record; a hit calls the slot
// at +152 with the element and the record, then advances. Returns 0. The
// record index is declared before the element pointer, and the search reads
// the record id between taking the candidate and keeping it, as the
// original instruction order requires.
// Partial observed views only: vtable slots by byte offset (4-byte entries),
// element array at registry +36 (count +0, items +8), record key +0 and id
// +8, element id +36. Real class names, slot roles and sizeof are unknown.
struct cc39d_Element56 { unsigned char unknown00[36]; int id; };
struct cc39d_ElementArray56 {
    unsigned int count;
    unsigned int unknown04;
    Ptr32<Ptr32<cc39d_Element56>> items;
    unsigned int size() const { return count; }
    Ptr32<cc39d_Element56> & operator[](unsigned int i) { return items[i]; }
};
struct cc39d_Record56 { int key; int unknown04; int id; unsigned char unknown0c[44]; };
struct cc39d_Registry56;
struct cc39d_Registry56Vtable {
    Ptr32<void> unknown000[37];
    Ptr32<void (Ptr32<cc39d_Registry56>, int)> create;
    Ptr32<void (Ptr32<cc39d_Registry56>, Ptr32<cc39d_Element56>, Ptr32<const cc39d_Record56>)> apply_98;
};
struct cc39d_Registry56 { Ptr32<cc39d_Registry56Vtable> vtable; unsigned char unknown04[32]; cc39d_ElementArray56 elements; };
extern "C" int cc39d_apply_records56_801dbc3c(Ptr32<cc39d_Registry56> self, Ptr32<const cc39d_Record56> records) {
    unsigned int index = 0;
    Ptr32<cc39d_Element56> element = 0;
    while (records[index].key) {
        bool found = false;
        for (unsigned int i = 0; i < self->elements.size(); i++) {
            Ptr32<cc39d_Element56> candidate = self->elements[i];
            int id = records[index].id;
            element = candidate;
            if (element->id == id) { found = true; goto done; }
        }
    done:
        if (!found) self->vtable->create(self, records[index].id);
        else { self->vtable->apply_98(self, element, &records[index]); index++; }
    }
    return 0;
}


