/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_8002b828)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8002A914 = 0x8002a914;
lbl_803725F0 = 0x803725f0;
lbl_8040E3A8 = 0x8040e3a8;
SECTIONS {
  .text.w3d_auto_8002b828 0x8002b828 : { *(.text.w3d_auto_8002b828) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
