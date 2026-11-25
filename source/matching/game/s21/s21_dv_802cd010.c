// desc: Appears to shut down a sixteen-entry table of handles when the subsystem is enabled and initialized: it releases every nonzero entry and clears the initialized flag.
extern int lbl_804abce4;
extern int lbl_804abce8;
extern int lbl_80473764[];
extern void fn_802cce78(void *);
void w3d_s21_shutdown_handles_802cd010(void)
{
    if (lbl_804abce4 && lbl_804abce8) {
        int *handle = lbl_80473764;
        int *last = handle + 15;
        do {
            int value = *handle;
            handle++;
            if (value)
                fn_802cce78(value);
        } while (handle <= last);
        lbl_804abce8 = 0;
    }
}
