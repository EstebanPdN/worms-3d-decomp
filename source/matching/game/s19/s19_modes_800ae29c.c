extern void FUN_800ae7d4(void *, int, int);

void s19_set_modes_800ae29c(void *self, int both, int one)
{
    if (both) {
        FUN_800ae7d4(self, 0, 2);
        FUN_800ae7d4(self, 1, 2);
    } else if (one) {
        FUN_800ae7d4(self, 0, 1);
        FUN_800ae7d4(self, 1, 1);
    } else {
        FUN_800ae7d4(self, 0, 0);
        FUN_800ae7d4(self, 1, 0);
    }
}
