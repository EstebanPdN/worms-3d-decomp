/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k2b_run_main_loop_8015ba70)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_8015ce28 = 0x8015ce28;
w3d_clock_ticks_801fe45c = 0x801fe45c;
w3d_history_tick = 0x8015ce60;
w3d_obj_80455170 = 0x80455170;
SECTIONS {
  .text.w3d_k2b_run_main_loop_8015ba70 0x8015ba70 : { *(.text.w3d_k2b_run_main_loop_8015ba70) }
  .sdata 0x804b0054 (NOLOAD) : {
    . = 0x0; w3d_global_804b0054 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
