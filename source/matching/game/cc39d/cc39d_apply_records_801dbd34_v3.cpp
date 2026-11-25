// Variant trials for 0x801dbd34: inline find with reference out-parameter.
struct cc39d_Element { unsigned char unknown00[36]; int id; };
struct cc39d_ElementArray {
    unsigned int count;
    unsigned int unknown04;
    cc39d_Element **items;
    unsigned int size() const { return count; }
    cc39d_Element *&operator[](unsigned int i) { return items[i]; }
    cc39d_Element *const &operator[](unsigned int i) const { return items[i]; }
    bool find_l(const int &id, cc39d_Element *&element) const {
        bool found = false;
        for (unsigned int i = 0; i < count; i++) {
            element = items[i];
            if (element->id == id) { found = true; break; }
        }
        return found;
    }
    bool find_m(const int &id, cc39d_Element *&element) const {
        bool found = false;
        for (unsigned int i = 0; i < size(); i++) {
            element = (*this)[i];
            if (element->id == id) { found = true; break; }
        }
        return found;
    }
    bool find_n(int id, cc39d_Element *&element) const {
        bool found = false;
        for (unsigned int i = 0; i < count; i++) {
            element = items[i];
            if (element->id == id) { found = true; break; }
        }
        return found;
    }
    bool find_o(const int &id, cc39d_Element *&element) const {
        for (unsigned int i = 0; i < count; i++) {
            element = items[i];
            if (element->id == id) return true;
        }
        return false;
    }
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
extern "C" int cc39d_records_l(cc39d_Registry *self, const cc39d_Record *records) {
    cc39d_Element *element = 0;
    unsigned int index = 0;
    while (records[index].key) {
        if (!self->elements.find_l(records[index].id, element)) self->vtable->create(self, records[index].id);
        else { self->vtable->apply(self, element, &records[index]); index++; }
    }
    return 0;
}
extern "C" int cc39d_records_m(cc39d_Registry *self, const cc39d_Record *records) {
    cc39d_Element *element = 0;
    unsigned int index = 0;
    while (records[index].key) {
        if (!self->elements.find_m(records[index].id, element)) self->vtable->create(self, records[index].id);
        else { self->vtable->apply(self, element, &records[index]); index++; }
    }
    return 0;
}
extern "C" int cc39d_records_n(cc39d_Registry *self, const cc39d_Record *records) {
    cc39d_Element *element = 0;
    unsigned int index = 0;
    while (records[index].key) {
        if (!self->elements.find_n(records[index].id, element)) self->vtable->create(self, records[index].id);
        else { self->vtable->apply(self, element, &records[index]); index++; }
    }
    return 0;
}
extern "C" int cc39d_records_o(cc39d_Registry *self, const cc39d_Record *records) {
    cc39d_Element *element = 0;
    unsigned int index = 0;
    while (records[index].key) {
        if (!self->elements.find_o(records[index].id, element)) self->vtable->create(self, records[index].id);
        else { self->vtable->apply(self, element, &records[index]); index++; }
    }
    return 0;
}
