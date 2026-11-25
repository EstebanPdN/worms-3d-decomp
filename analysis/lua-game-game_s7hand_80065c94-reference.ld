/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_80065c94)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800649E8 = 0x800649e8;
fn_80164FC8 = 0x80164fc8;
SECTIONS {
  .text.w3d_auto_80065c94 0x80065c94 : { *(.text.w3d_auto_80065c94) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
