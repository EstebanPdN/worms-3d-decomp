// desc: Appears to release a global singleton through a virtual slot, clear the global pointer and return zero.
struct S21Singleton;
struct S21SingletonMethods { void (*reserved[4])(void); void (*release)(struct S21Singleton *); };
struct S21Singleton { struct S21SingletonMethods *methods; };
extern struct S21Singleton *lbl_804b063c;
int w3d_s21_release_singleton_802002fc(void)
{
    if (lbl_804b063c)
        lbl_804b063c->methods->release(lbl_804b063c);
    lbl_804b063c = 0;
    return 0;
}
