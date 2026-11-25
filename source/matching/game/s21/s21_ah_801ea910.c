// desc: Appears to be a static destruction helper that finishes two parts of a global object with the argument two.
struct S21Global { char first[12]; char second[4]; };
extern struct S21Global lbl_8045e0f8[];
extern void fn_80357230(void *, int);
extern void fn_80356ef8(void *, int);
void w3d_s21_destroy_global_801ea910(void)
{
    struct S21Global *global = lbl_8045e0f8;
    fn_80357230(global->second, 2);
    fn_80356ef8(global, 2);
}
