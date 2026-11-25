/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc17c_collect_members_801e9c2c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
allocate_80212fd4 = 0x80212fd4;
copy_802eee50 = 0x802eee50;
free_802134fc = 0x802134fc;
SECTIONS {
  .text.w3d_cc17c_collect_members_801e9c2c 0x801e9c2c : { *(.text.w3d_cc17c_collect_members_801e9c2c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
