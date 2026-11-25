/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx13a_refresh_transform_800261d4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
read_80026668 = 0x80026668;
read_80026720 = 0x80026720;
SECTIONS {
  .text.w3d_cx13a_refresh_transform_800261d4 0x800261d4 : { *(.text.w3d_cx13a_refresh_transform_800261d4) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
