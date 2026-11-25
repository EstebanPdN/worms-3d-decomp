/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx13a_follow_target_800383d8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
read_80178df0 = 0x80178df0;
read_80178ec4 = 0x80178ec4;
threshold_80373fb8 = 0x80373fb8;
SECTIONS {
  .text.w3d_cx13a_follow_target_800383d8 0x800383d8 : { *(.text.w3d_cx13a_follow_target_800383d8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
