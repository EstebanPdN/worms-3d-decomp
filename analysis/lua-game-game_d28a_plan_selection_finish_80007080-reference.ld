/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d28a_plan_selection_finish_80007080)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
g_pending_804a84d8 = 0x804a84d8;
g_plans_804a8518 = 0x804a8518;
s19_slot_matches_global_80015400 = 0x80015400;
w3d_ai_planner_set_state = 0x800068a8;
w3d_ai_select_team = 0x80007b44;
w3d_auto_800153dc = 0x800153dc;
w3d_command_create_18 = 0x800092bc;
w3d_command_create_19 = 0x80009404;
w3d_cx7p_planner_reset_800066e0 = 0x800066e0;
SECTIONS {
  .text.w3d_d28a_plan_selection_finish_80007080 0x80007080 : { *(.text.w3d_d28a_plan_selection_finish_80007080) }
  .rodata 0x80369518 : { *(.rodata) }
  .sdata 0x804aa598 (NOLOAD) : {
    . = 0x0; g_busy_804aa598 = .;
    . = 0x128; g_worm_804aa6c0 = .;
    . = 0x12c; g_chooser_804aa6c4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
