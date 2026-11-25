/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d25e_find_interface_801fca00)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
memcmp = 0x802eedc0;
table_8045e890 = 0x8045e890;
SECTIONS {
  .text.w3d_d25e_find_interface_801fca00 0x801fca00 : { *(.text.w3d_d25e_find_interface_801fca00) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
