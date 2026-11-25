/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d41a_bazooka_queue_build_80009f08)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
aim_search_8001aaf8 = 0x8001aaf8;
cc26a_grid_byte_cell_8001dff8 = 0x8001dff8;
cc26a_grid_select_layer_8001e328 = 0x8001e328;
cc27a_planner_set_gravity_8001aa48 = 0x8001aa48;
g_motion_8041e780 = 0x8041e780;
g_step_8041e850 = 0x8041e850;
sqrt_802e82c0 = 0x802e82c0;
w3d_ai_weapon_available = 0x80007ccc;
w3d_auto_8001523c = 0x8001523c;
w3d_d24a_turn_time_remaining_800155d0 = 0x800155d0;
w3d_d28a_method_command_append_80003558 = 0x80003558;
w3d_move_queue_construct = 0x80003300;
SECTIONS {
  .text.w3d_d41a_bazooka_queue_build_80009f08 0x80009f08 : { *(.text.w3d_d41a_bazooka_queue_build_80009f08) }
  .rodata 0x803695cc : { *(.rodata) }
  .sdata 0x804aa570 (NOLOAD) : {
    . = 0x0; g_clock_804aa570 = .;
    . = 0x16c; g_on_804aa6dc = .;
    . = 0x170; g_off_804aa6e0 = .;
    . = 0x174; g_busy_804aa6e4 = .;
    . = 0x71e8; w3d_grid_804b1758 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
