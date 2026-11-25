/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_dispatch_labels_802ab24c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8020c5c0 = 0x8020c5c0;
fn_802aa71c = 0x802aa71c;
fn_80341884 = 0x80341884;
table_803d6b7c = 0x803d6b7c;
table_803d6bd0 = 0x803d6bd0;
table_803d6c24 = 0x803d6c24;
SECTIONS {
  .text.w3d_dispatch_labels_802ab24c 0x802ab24c : { *(.text.w3d_dispatch_labels_802ab24c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
