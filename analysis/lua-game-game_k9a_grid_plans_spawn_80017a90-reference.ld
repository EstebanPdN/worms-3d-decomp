/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k9a_grid_plans_spawn_80017a90)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_ai_push_plan_b = 0x80007514;
w3d_auto_8001523c = 0x8001523c;
w3d_cx12a_sample_grid_8001e224 = 0x8001e224;
w3d_grid_pick_8001dd28 = 0x8001dd28;
w3d_path_cost_construct = 0x80006360;
w3d_vtable_8040d850 = 0x8040d850;
SECTIONS {
  .text.w3d_k9a_grid_plans_spawn_80017a90 0x80017a90 : { *(.text.w3d_k9a_grid_plans_spawn_80017a90) }
  .sdata 0x804aa594 (NOLOAD) : {
    . = 0x0; w3d_flag_804aa594 = .;
    . = 0x71c4; w3d_grid_804b1758 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
