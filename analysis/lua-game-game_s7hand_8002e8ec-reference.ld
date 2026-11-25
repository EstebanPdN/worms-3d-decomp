/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_8002e8ec)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80161014 = 0x80161014;
lbl_8040E4B8 = 0x8040e4b8;
SECTIONS {
  .text.w3d_auto_8002e8ec 0x8002e8ec : { *(.text.w3d_auto_8002e8ec) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
