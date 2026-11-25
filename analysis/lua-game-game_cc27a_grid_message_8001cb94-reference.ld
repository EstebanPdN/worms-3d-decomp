/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc27a_grid_message_8001cb94)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc27a_base_8016293c = 0x8016293c;
cc27a_equal_8015f620 = 0x8015f620;
cc27a_rectangle_8001cc90 = 0x8001cc90;
cc27a_reset_8001ed98 = 0x8001ed98;
cc27a_update_8001d9ac = 0x8001d9ac;
SECTIONS {
  .text.cc27a_grid_message_8001cb94 0x8001cb94 : { *(.text.cc27a_grid_message_8001cb94) }
  .rodata 0x8036b6d0 : { *(.rodata) }
  .sdata 0x804ac93c (NOLOAD) : {
    . = 0x0; cc27a_cache_804ac93c = .;
    . = 0x8; cc27a_cache_804ac944 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
