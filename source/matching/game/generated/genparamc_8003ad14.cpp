/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Family template, 2026-10-22 (third session): look up a named spawn point
 * in a copy of a global vector of groups; fall back to a default position. */
#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
extern "C" void *memcpy(...);
extern "C" void *fn_80212fd4(unsigned int);
extern "C" void fn_802134fc(void *);
extern "C" int fn_802ef234(const char *, const char *);
extern "C" void fn_8020c5c4(void *);
extern "C" void fn_80341588(void *);
extern "C" void fn_8003af00(void *, const char *);
extern "C" char lbl_803742c8[];
struct W3dVec3 {
    float x, y, z;
    W3dVec3() {}
    W3dVec3(float a, float b, float c) { x = a; y = b; z = c; }
};
struct W3dPtrVector {
    void **first;
    void **last;
    void **end_of_storage;
    unsigned int size() const { return last - first; }
    void *at(unsigned int index) const { return *(void **)((char *)first + (index << 2)); }
    ~W3dPtrVector() { if (first) fn_802134fc(first); }
};
struct W3dString_8020bb54 {
    char *text;
    W3dString_8020bb54(const char *);
    ~W3dString_8020bb54() { fn_8020c5c4(this); fn_80341588(this); }
};
extern W3dPtrVector lbl_8043bb64;
extern W3dVec3 lbl_8045e788;
static inline W3dVec3 item_position(void *item)
{
    W3dVec3 &p = FIELD(item, W3dVec3, 4);
    return W3dVec3(p.x, p.y, p.z);
}
extern "C" void fn_8004a930(void *, const char *);
extern "C" char lbl_80376f30[];
extern "C" void fn_8012568c(void *, const char *);
extern "C" char lbl_8039ba80[];

extern "C" void w3d_find_spawn_point_8003ad14(void *self, const char *name)
{
    W3dPtrVector groups;
    unsigned int bytes = (char *)lbl_8043bb64.last - (char *)lbl_8043bb64.first;
    void **storage = (void **)fn_80212fd4(bytes);
    groups.first = storage;
    groups.last = (void **)((char *)storage + bytes);
    groups.end_of_storage = (void **)((char *)storage + bytes);
    memcpy(storage, lbl_8043bb64.first, bytes);
    for (unsigned int i = 0; i < groups.size(); i++) {
        W3dPtrVector &items = FIELD(groups.at(i), W3dPtrVector, 20);
        for (unsigned int j = 0; j < items.size(); j++) {
            W3dString_8020bb54 label(FIELD(items.at(j), const char *, 60));
            if (fn_802ef234(label.text, name) == 0) {
                FIELD(self, W3dVec3, 28) = item_position(items.at(j));
                return;
            }
        }
    }
    fn_8003af00(self, lbl_803742c8);
    fn_8003af00(self, name);
    FIELD(self, W3dVec3, 28) = lbl_8045e788;
}

extern "C" void w3d_find_spawn_point_8004a608(void *self, const char *name)
{
    W3dPtrVector groups;
    unsigned int bytes = (char *)lbl_8043bb64.last - (char *)lbl_8043bb64.first;
    void **storage = (void **)fn_80212fd4(bytes);
    groups.first = storage;
    groups.last = (void **)((char *)storage + bytes);
    groups.end_of_storage = (void **)((char *)storage + bytes);
    memcpy(storage, lbl_8043bb64.first, bytes);
    for (unsigned int i = 0; i < groups.size(); i++) {
        W3dPtrVector &items = FIELD(groups.at(i), W3dPtrVector, 20);
        for (unsigned int j = 0; j < items.size(); j++) {
            W3dString_8020bb54 label(FIELD(items.at(j), const char *, 60));
            if (fn_802ef234(label.text, name) == 0) {
                FIELD(self, W3dVec3, 40) = item_position(items.at(j));
                return;
            }
        }
    }
    fn_8004a930(self, lbl_80376f30);
    fn_8004a930(self, name);
    FIELD(self, W3dVec3, 40) = lbl_8045e788;
}

extern "C" void w3d_find_spawn_point_801254a0(void *self, const char *name)
{
    W3dPtrVector groups;
    unsigned int bytes = (char *)lbl_8043bb64.last - (char *)lbl_8043bb64.first;
    void **storage = (void **)fn_80212fd4(bytes);
    groups.first = storage;
    groups.last = (void **)((char *)storage + bytes);
    groups.end_of_storage = (void **)((char *)storage + bytes);
    memcpy(storage, lbl_8043bb64.first, bytes);
    for (unsigned int i = 0; i < groups.size(); i++) {
        W3dPtrVector &items = FIELD(groups.at(i), W3dPtrVector, 20);
        for (unsigned int j = 0; j < items.size(); j++) {
            W3dString_8020bb54 label(FIELD(items.at(j), const char *, 60));
            if (fn_802ef234(label.text, name) == 0) {
                FIELD(self, W3dVec3, 28) = item_position(items.at(j));
                return;
            }
        }
    }
    fn_8012568c(self, lbl_8039ba80);
    fn_8012568c(self, name);
    FIELD(self, W3dVec3, 28) = lbl_8045e788;
}
