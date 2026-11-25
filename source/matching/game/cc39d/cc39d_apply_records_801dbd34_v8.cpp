// Apply a zero-key-terminated array of 64-byte records to a registry's
// element pointer array (0x801dbd34, sibling 0x801dc254). Each record's id
// at +8 is searched linearly among the elements (id at element +36). A miss
// calls the registry's create slot (+148) with the id and retries the same
// record; a hit calls an apply slot with the element and the record, then
// advances. Always returns 0. The element pointer persists across records.
// The search reads the record id between taking the candidate and keeping
// it, as the original instruction order requires.
// Partial observed views only: vtable slots by byte offset (4-byte entries),
// element array at registry +36 (count +0, items +8), record key +0 and id
// +8, element id +36. Real class names, slot roles and sizeof are unknown.
struct cc39d_Element { unsigned char unknown00[36]; int id; };
struct cc39d_ElementArray {
    unsigned int count;
    unsigned int unknown04;
    cc39d_Element **items;
    unsigned int size() const { return count; }
    cc39d_Element *&operator[](unsigned int i) { return items[i]; }
};
struct cc39d_Record { int key; int unknown04; int id; unsigned char unknown0c[52]; };
struct cc39d_Registry;
struct cc39d_RegistryVtable {
    void *unknown000[37];
    void (*create)(cc39d_Registry *, int);
    void *unknown098;
    void (*apply_9c)(cc39d_Registry *, cc39d_Element *, const cc39d_Record *);
    void *unknown0a0;
    void (*apply_a4)(cc39d_Registry *, cc39d_Element *, const cc39d_Record *);
};
struct cc39d_Registry { cc39d_RegistryVtable *vtable; unsigned char unknown04[32]; cc39d_ElementArray elements; };
extern "C" int cc39d_apply_records_801dbd34(cc39d_Registry *self, const cc39d_Record *records) {
    cc39d_Element *element = 0;
    unsigned int index = 0;
    while (records[index].key) {
        bool found = false;
        for (unsigned int i = 0; i < self->elements.size(); i++) {
            cc39d_Element *candidate = self->elements[i];
            int id = records[index].id;
            element = candidate;
            if (element->id == id) { found = true; goto done; }
        }
    done:
        if (!found) self->vtable->create(self, records[index].id);
        else { self->vtable->apply_9c(self, element, &records[index]); index++; }
    }
    return 0;
}
// Same walk through the apply slot at +164; the second argument is unused
// (its type is unknown; declared as a 32-bit integer).
extern "C" int cc39d_apply_records_801dc254(cc39d_Registry *self, int unused, const cc39d_Record *records) {
    cc39d_Element *element = 0;
    unsigned int index = 0;
    while (records[index].key) {
        bool found = false;
        for (unsigned int i = 0; i < self->elements.size(); i++) {
            cc39d_Element *candidate = self->elements[i];
            int id = records[index].id;
            element = candidate;
            if (element->id == id) { found = true; goto done; }
        }
    done:
        if (!found) self->vtable->create(self, records[index].id);
        else { self->vtable->apply_a4(self, element, &records[index]); index++; }
    }
    return 0;
}
