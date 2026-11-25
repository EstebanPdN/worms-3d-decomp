/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d44s_plan_scatter_push_80017044)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__8CostBase = 0x80006360;
_vt.4Plan = 0x8040d920;
k2a_grid_position_8001f9f0 = 0x8001f9f0;
s19_random_unit_80015810 = 0x80015810;
w3d_ai_push_plan_b = 0x80007514;
w3d_auto_8001523c = 0x8001523c;
w3d_center_8041d3a0 = 0x8041d3a0;
SECTIONS {
  .text.w3d_d44s_plan_scatter_push_80017044 0x80017044 : { *(.text.w3d_d44s_plan_scatter_push_80017044) }
  .sdata 0x804aa594 (NOLOAD) : {
    . = 0x0; w3d_flag_804aa594 = .;
    . = 0x144; w3d_settings_804aa6d8 = .;
    . = 0x148; w3d_game_804aa6dc = .;
    . = 0x14c; w3d_busy_804aa6e0 = .;
    . = 0x71c4; w3d_grid_804b1758 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
