/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d29a_side_step_plan_8000feb8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
k2a_grid_position_8001f9f0 = 0x8001f9f0;
sqrt_802e82c0 = 0x802e82c0;
w3d_construct_801f6034 = 0x801f6034;
w3d_d28a_command_vector_prepend_80003834 = 0x80003834;
w3d_d28a_path_queue_build_timed_80009674 = 0x80009674;
w3d_move_queue_current_step = 0x80003e78;
w3d_rotate_rows_y_801f61a0 = 0x801f61a0;
SECTIONS {
  .text.w3d_d29a_side_step_plan_8000feb8 0x8000feb8 : { *(.text.w3d_d29a_side_step_plan_8000feb8) }
  .rodata 0x8036a084 : { *(.rodata) }
  .sdata 0x804aa6dc (NOLOAD) : {
    . = 0x0; w3d_game_804aa6dc = .;
    . = 0x4; w3d_busy_804aa6e0 = .;
    . = 0x74; w3d_bodies_804aa750 = .;
    . = 0x707c; w3d_grid_804b1758 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
