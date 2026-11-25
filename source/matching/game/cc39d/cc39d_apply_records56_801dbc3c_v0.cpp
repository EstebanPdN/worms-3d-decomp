// Variant trial for 0x801dbc3c: 56-byte record member of the record-walk family.
struct cc39d_Element { unsigned char unknown00[36]; int id; };
struct cc39d_ElementArray {
    unsigned int count;
    unsigned int unknown04;
    cc39d_Element **items;
    unsigned int size() const { return count; }
    cc39d_Element *&operator[](unsigned int i) { return items[i]; }
};
struct cc39d_Record56 { int key; int unknown04; int id; unsigned char unknown0c[44]; };
struct cc39d_Registry56;
struct cc39d_Registry56Vtable {
    void *unknown000[37];
    void (*create)(cc39d_Registry56 *, int);
    void (*apply_98)(cc39d_Registry56 *, cc39d_Element *, const cc39d_Record56 *);
};
struct cc39d_Registry56 { cc39d_Registry56Vtable *vtable; unsigned char unknown04[32]; cc39d_ElementArray elements; };
extern "C" int cc39d_records56_a(cc39d_Registry56 *self, const cc39d_Record56 *records) {
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
        else { self->vtable->apply_98(self, element, &records[index]); index++; }
    }
    return 0;
}
