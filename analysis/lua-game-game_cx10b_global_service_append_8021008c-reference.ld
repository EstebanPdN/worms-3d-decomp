/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx10b_global_service_append_8021008c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
global_slots_80463be0 = 0x80463be0;
reserve_80210d54 = 0x80210d54;
SECTIONS {
  .text.w3d_cx10b_global_service_append_8021008c 0x8021008c : { *(.text.w3d_cx10b_global_service_append_8021008c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
