/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx12a_accumulate_limit_800ac03c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
one_80381c44 = 0x80381c44;
read_80178df0 = 0x80178df0;
SECTIONS {
  .text.w3d_cx12a_accumulate_limit_800ac03c 0x800ac03c : { *(.text.w3d_cx12a_accumulate_limit_800ac03c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
