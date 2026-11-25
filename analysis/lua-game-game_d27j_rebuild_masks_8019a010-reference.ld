/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27j_rebuild_masks_8019a010)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
insert_80350a78 = 0x80350a78;
insert_80350dd8 = 0x80350dd8;
release_801907d0 = 0x801907d0;
SECTIONS {
  .text.d27j_rebuild_masks_8019a010 0x8019a010 : { *(.text.d27j_rebuild_masks_8019a010) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
