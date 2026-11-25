/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_fn_80064c6c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_empty_80343580 = 0x80343580;
w3d_fn_80064d20 = 0x80064d20;
w3d_fn_800fd3e4 = 0x800fd3e4;
w3d_fn_8018d35c = 0x8018d35c;
SECTIONS {
  .text.w3d_fn_80064c6c 0x80064c6c : { *(.text.w3d_fn_80064c6c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
