// __DEMODiagnoseHang from the Nintendo DEMO library: read the XF and rasteriser
// counters twice, read the GP status, print it and report the likely cause of a
// graphics hang. Callees: __GXReadXfRasMetric 0x8030ce10, GXGetGPStatus
// 0x803069fc, OSReport 0x802fb7ac. GWMP8P rev0 0x801683c4.
extern "C" void fn_8030ce10(unsigned *, unsigned *, unsigned *, unsigned *);
extern "C" void fn_803069fc(unsigned char *, unsigned char *, unsigned char *, unsigned char *, unsigned char *);
extern "C" void fn_802fb7ac(const char *, ...);
extern "C" void d29j_diagnose_gp_hang_801683c4()
{
    unsigned xfTop0, xfBot0, suRdy0, r0Rdy0;
    unsigned xfTop1, xfBot1, suRdy1, r0Rdy1;
    unsigned xfTopD, xfBotD, suRdyD, r0RdyD;
    unsigned char readIdle, cmdIdle, junk;
    fn_8030ce10(&xfBot0, &xfTop0, &r0Rdy0, &suRdy0);
    fn_8030ce10(&xfBot1, &xfTop1, &r0Rdy1, &suRdy1);
    xfTopD = (xfTop1 - xfTop0) == 0;
    xfBotD = (xfBot1 - xfBot0) == 0;
    suRdyD = (suRdy1 - suRdy0) > 0;
    r0RdyD = (r0Rdy1 - r0Rdy0) > 0;
    fn_803069fc(&junk, &junk, &readIdle, &cmdIdle, &junk);
    fn_802fb7ac("GP status %d%d%d%d%d%d --> ", readIdle, cmdIdle, xfTopD, xfBotD, suRdyD, r0RdyD);
    if (!xfBotD && suRdyD) {
        fn_802fb7ac("GP hang due to XF stall bug.\n");
    } else if (!xfTopD && xfBotD && suRdyD) {
        fn_802fb7ac("GP hang due to unterminated primitive.\n");
    } else if (!cmdIdle && xfTopD && xfBotD && suRdyD) {
        fn_802fb7ac("GP hang due to illegal instruction.\n");
    } else if (readIdle && cmdIdle && xfTopD && xfBotD && suRdyD && r0RdyD) {
        fn_802fb7ac("GP appears to be not hung (waiting for input).\n");
    } else {
        fn_802fb7ac("GP is in unknown state.\n");
    }
}
