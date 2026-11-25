/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_light_process_queue_800c0118)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_light_queue_8043c3a0 = 0x8043c3a0;
w3d_light_range_8043c384 = 0x8043c384;
w3d_light_refresh_800c021c = 0x800c021c;
SECTIONS {
  .text.w3d_light_process_queue_800c0118 0x800c0118 : { *(.text.w3d_light_process_queue_800c0118) }
  .sdata 0x804b185c (NOLOAD) : {
    . = 0x0; w3d_light_cursor_804b185c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
