// Variant trials for 0x801dbd34: inner search loop forms.
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
extern "C" int cc39d_records_d(cc39d_Registry *self, const cc39d_Record *records) {
    cc39d_Element *element = 0;
    unsigned int index = 0;
    while (records[index].key) {
        bool found = false;
        unsigned int i = 0;
        while (i < self->elements.size()) {
            element = self->elements[i];
            if (element->id == records[index].id) { found = true; break; }
            i++;
        }
        if (!found) self->vtable->create(self, records[index].id);
        else { self->vtable->apply(self, element, &records[index]); index++; }
    }
    return 0;
}
extern "C" int cc39d_records_e(cc39d_Registry *self, const cc39d_Record *records) {
    cc39d_Element *element = 0;
    unsigned int index = 0;
    while (records[index].key) {
        bool found = false;
        for (unsigned int i = 0; i < self->elements.size(); i++) {
            element = self->elements[i];
            if (element->id != records[index].id) continue;
            found = true;
            break;
        }
        if (!found) self->vtable->create(self, records[index].id);
        else { self->vtable->apply(self, element, &records[index]); index++; }
    }
    return 0;
}
extern "C" int cc39d_records_f(cc39d_Registry *self, const cc39d_Record *records) {
    cc39d_Element *element = 0;
    unsigned int index = 0;
    while (records[index].key) {
        bool found = false;
        unsigned int i = 0;
        if (i < self->elements.size()) do {
            element = self->elements[i];
            if (element->id == records[index].id) { found = true; break; }
        } while (++i < self->elements.size());
        if (!found) self->vtable->create(self, records[index].id);
        else { self->vtable->apply(self, element, &records[index]); index++; }
    }
    return 0;
}
extern "C" int cc39d_records_g(cc39d_Registry *self, const cc39d_Record *records) {
    cc39d_Element *element = 0;
    unsigned int index = 0;
    while (records[index].key) {
        bool found = false;
        for (unsigned int i = 0; i < self->elements.size(); i++) {
            element = self->elements[i];
            if (element->id == records[index].id) { found = true; goto done; }
        }
    done:
        if (!found) self->vtable->create(self, records[index].id);
        else { self->vtable->apply(self, element, &records[index]); index++; }
    }
    return 0;
}
extern "C" int cc39d_records_h(cc39d_Registry *self, const cc39d_Record *records) {
    cc39d_Element *element = 0;
    unsigned int index = 0;
    while (records[index].key) {
        bool found = false;
        for (unsigned int i = 0; i < self->elements.size() && !found; i++) {
            element = self->elements[i];
            if (element->id == records[index].id) found = true;
        }
        if (!found) self->vtable->create(self, records[index].id);
        else { self->vtable->apply(self, element, &records[index]); index++; }
    }
    return 0;
}
extern "C" int cc39d_records_i(cc39d_Registry *self, const cc39d_Record *records) {
    cc39d_Element *element = 0;
    unsigned int index = 0;
    while (records[index].key) {
        bool found = false;
        for (unsigned int i = 0; i < self->elements.size(); i++)
            if ((element = self->elements[i])->id == records[index].id) { found = true; break; }
        if (found) { self->vtable->apply(self, element, &records[index]); index++; }
        else self->vtable->create(self, records[index].id);
    }
    return 0;
}
