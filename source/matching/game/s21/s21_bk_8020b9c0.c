// desc: Appears to release a second global singleton through a virtual slot, clear the global pointer and return zero.
struct S21Singleton;
struct S21SingletonMethods { void (*reserved[4])(void); void (*release)(struct S21Singleton *); };
struct S21Singleton { struct S21SingletonMethods *methods; };
extern struct S21Singleton *lbl_804b0698;
int w3d_s21_release_singleton_b_8020b9c0(void)
{
    if (lbl_804b0698)
        lbl_804b0698->methods->release(lbl_804b0698);
    lbl_804b0698 = 0;
    return 0;
}
