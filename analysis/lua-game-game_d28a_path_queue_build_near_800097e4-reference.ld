/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d28a_path_queue_build_near_800097e4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__5Queue = 0x80003300;
cc26a_grid_build_path_8001ebe0 = 0x8001ebe0;
sqrt_802e82c0 = 0x802e82c0;
w3d_auto_8001523c = 0x8001523c;
w3d_auto_8001ece8 = 0x8001ece8;
w3d_move_queue_current_step = 0x80003e78;
SECTIONS {
  .text.w3d_d28a_path_queue_build_near_800097e4 0x800097e4 : { *(.text.w3d_d28a_path_queue_build_near_800097e4) }
  .rodata 0x80369590 : { *(.rodata) }
  .sdata 0x804aa570 (NOLOAD) : {
    . = 0x0; g_clock_804aa570 = .;
    . = 0x224; g_mode_804aa794 = .;
    . = 0x71e8; w3d_grid_804b1758 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
