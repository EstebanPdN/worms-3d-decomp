/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d41a_stand_plan_spawn_8000b8f8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__13Base_80006360 = 0x80006360;
__vt_13Plan_8040d668 = 0x8040d668;
__vt_13Plan_8040d6d8 = 0x8040d6d8;
__vt_13Plan_8040d710 = 0x8040d710;
__vt_13Plan_8040d748 = 0x8040d748;
__vt_13Plan_8040d7b8 = 0x8040d7b8;
cc25a_planner_clear_neighborhood_80019ea0 = 0x80019ea0;
queue_build_80009674 = 0x80009674;
w3d_ai_push_plan_b = 0x80007514;
w3d_auto_8001523c = 0x8001523c;
w3d_center_8041d3a0 = 0x8041d3a0;
w3d_cx12a_sample_grid_8001e224 = 0x8001e224;
w3d_d41a_best_stand_80019b34 = 0x80019b34;
w3d_fn_802e8094 = 0x802e8094;
w3d_libm_forward_802e83cc = 0x802e83cc;
w3d_move_queue_release = 0x800033d8;
SECTIONS {
  .text.w3d_d41a_stand_plan_spawn_8000b8f8 0x8000b8f8 : { *(.text.w3d_d41a_stand_plan_spawn_8000b8f8) }
  .rodata 0x80369c9c : { *(.rodata) }
  .sdata 0x804aa594 (NOLOAD) : {
    . = 0x0; g_fallback_804aa594 = .;
    . = 0x144; g_settings_804aa6d8 = .;
    . = 0x148; g_on_804aa6dc = .;
    . = 0x14c; g_off_804aa6e0 = .;
    . = 0x1bc; g_list_804aa750 = .;
    . = 0x71c4; w3d_grid_804b1758 = .;
    . = 0x71c8; g_status_804b175c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
