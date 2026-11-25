struct K8bLowMemory { char pad0[248]; unsigned int bus_clock; };
extern long long fn_80300aa0(void);
extern int lbl_804b0630;
extern unsigned long long lbl_804b0628;

unsigned int w3d_k8b_elapsed_ms_801fe45c(void)
{
    if (lbl_804b0630 == 0) {
        lbl_804b0630 = 1;
        lbl_804b0628 = fn_80300aa0();
    }
    return (unsigned long long)(fn_80300aa0() - lbl_804b0628) / (((struct K8bLowMemory *)0x80000000)->bus_clock / 4000);
}
