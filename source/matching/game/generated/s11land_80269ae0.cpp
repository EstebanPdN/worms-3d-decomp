/* Property-selection callback; field meanings are inferred from callers. */
struct S11LandOwner {
    char unknown00[0x1f0];
    int selected;
    void set_active(int);
};
int fn_8026C54C(S11LandOwner *);
int fn_800FC230(const char **, int *);
int fn_8026CB18(void *, int);
int fn_8026B3F0(S11LandOwner *);
extern char lbl_803CB918[];
extern "C" int s11_select_land_80269ae0(int unused, S11LandOwner *owner) {
    const char *property;
    int value;
    if (owner->selected) return 0;
    fn_8026C54C(owner);
    property = lbl_803CB918;
    fn_800FC230(&property, &value);
    fn_8026CB18((char *)owner + 0x138, value);
    owner->set_active(1);
    fn_8026B3F0(owner);
    return 0;
}
