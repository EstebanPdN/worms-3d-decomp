/* Observed: the three-word vector supplied by the caller is copied into the
   fixed global at 0x8043add8, two state words and the counter pair are then
   written, and a global service pointer, when non-null, is handed to the
   marked-entry visitor at 0x800bd794. */
struct E14aVec3 {
 int x;
 int y;
 int z;
};
extern "C" {
extern E14aVec3 lbl_8043add8;
extern int lbl_804b1784;
extern int lbl_804b1810;
extern int lbl_804b1764;
extern int lbl_804b1814;
extern void *lbl_804b17e0;
void s19_visit_marked_800bd794(void *self);
void w3d_e14a_begin_marked_region_800b11dc(const E14aVec3 *position,int id) {
 lbl_804b1810=0;
 lbl_804b1784=0;
 lbl_8043add8=*position;
 lbl_804b1764=id+1;
 lbl_804b1814=id;
 if(lbl_804b17e0) s19_visit_marked_800bd794(lbl_804b17e0);
}
}
