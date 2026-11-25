/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_8003ba00)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8015FEF0 = 0x8015fef0;
lbl_8040E758 = 0x8040e758;
lbl_804105B8 = 0x804105b8;
SECTIONS {
  .text.w3d_auto_8003ba00 0x8003ba00 : { *(.text.w3d_auto_8003ba00) }
  .text.w3d_auto_800fe8f4 0x800fe8f4 : { *(.text.w3d_auto_800fe8f4) }
  .text.w3d_auto_8034cc0c 0x8034cc0c : { *(.text.w3d_auto_8034cc0c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
