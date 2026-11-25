/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_8002dd68)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8015FEF0 = 0x8015fef0;
lbl_8040E478 = 0x8040e478;
SECTIONS {
  .text.w3d_auto_8002dd68 0x8002dd68 : { *(.text.w3d_auto_8002dd68) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
