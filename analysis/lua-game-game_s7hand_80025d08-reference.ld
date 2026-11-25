/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_80025d08)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8015FEF0 = 0x8015fef0;
lbl_8040DFC8 = 0x8040dfc8;
SECTIONS {
  .text.w3d_auto_80025d08 0x80025d08 : { *(.text.w3d_auto_80025d08) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
