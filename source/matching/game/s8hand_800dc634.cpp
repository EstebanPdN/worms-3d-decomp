extern char lbl_8040fe70[];
extern "C" void fn_800dc6a8(void *,int);
struct s8_PartialObject_800dc634 {
    char pad0[112];
    void *partVtable;
    s8_PartialObject_800dc634();
};
s8_PartialObject_800dc634::s8_PartialObject_800dc634() {
    partVtable=lbl_8040fe70;
    fn_800dc6a8(this,0);
}
