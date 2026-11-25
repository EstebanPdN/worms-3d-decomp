// desc: Appears to replace the global singleton pointer, retaining the new object and releasing the previous one through virtual slots.
struct S21Singleton;
struct S21SingletonMethods { void (*reserved[3])(void); void (*retain)(struct S21Singleton *); void (*release)(struct S21Singleton *); };
struct S21Singleton { struct S21SingletonMethods *methods; };
extern struct S21Singleton *lbl_804b0698;
void w3d_s21_set_singleton_8020b960(struct S21Singleton *fresh)
{
    if (fresh)
        fresh->methods->retain(fresh);
    if (lbl_804b0698)
        lbl_804b0698->methods->release(lbl_804b0698);
    lbl_804b0698 = fresh;
}
