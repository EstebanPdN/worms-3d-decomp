// Variant trials for 0x801dbd34 (and sibling 0x801dc254).
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
    void (*apply)(cc39d_Registry *, cc39d_Element *, const cc39d_Record *);
    void *unknown0a0;
    void (*apply_other)(cc39d_Registry *, cc39d_Element *, const cc39d_Record *);
};
struct cc39d_Registry { cc39d_RegistryVtable *vtable; unsigned char unknown04[32]; cc39d_ElementArray elements; };
extern "C" int cc39d_records_a(cc39d_Registry *self, const cc39d_Record *records) {
    cc39d_Element *element = 0;
    unsigned int index = 0;
    while (records[index].key) {
        bool found = false;
        for (unsigned int i = 0; i < self->elements.size(); i++) {
            element = self->elements[i];
            if (element->id == records[index].id) { found = true; break; }
        }
        if (!found) self->vtable->create(self, records[index].id);
        else { self->vtable->apply(self, element, &records[index]); index++; }
    }
    return 0;
}
extern "C" int cc39d_records_b(cc39d_Registry *self, const cc39d_Record *records) {
    cc39d_Element *element = 0;
    const cc39d_Record *record = records;
    while (record->key) {
        bool found = false;
        for (unsigned int i = 0; i < self->elements.size(); i++) {
            element = self->elements[i];
            if (element->id == record->id) { found = true; break; }
        }
        if (!found) self->vtable->create(self, record->id);
        else { self->vtable->apply(self, element, record); record++; }
    }
    return 0;
}
extern "C" int cc39d_records_c(cc39d_Registry *self, const cc39d_Record *records) {
    cc39d_Element *element = 0;
    for (unsigned int index = 0; records[index].key; ) {
        bool found = false;
        for (unsigned int i = 0; i < self->elements.count; i++) {
            element = self->elements.items[i];
            if (element->id == records[index].id) { found = true; break; }
        }
        if (!found) self->vtable->create(self, records[index].id);
        else self->vtable->apply(self, element, &records[index++]);
    }
    return 0;
}
