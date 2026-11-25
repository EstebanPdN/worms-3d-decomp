/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_fn_80066068)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_80064d88 = 0x80064d88;
w3d_auto_80178c48 = 0x80178c48;
w3d_empty_803426b4 = 0x803426b4;
w3d_fn_800645b8 = 0x800645b8;
w3d_fn_800663a8 = 0x800663a8;
w3d_fn_800fc6dc = 0x800fc6dc;
w3d_fn_80164fc8 = 0x80164fc8;
SECTIONS {
  .text.w3d_fn_80066068 0x80066068 : { *(.text.w3d_fn_80066068) }
  .text.w3d_fn_800664f8 0x800664f8 : { *(.text.w3d_fn_800664f8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
