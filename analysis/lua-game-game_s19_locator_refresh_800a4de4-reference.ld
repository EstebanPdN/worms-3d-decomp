/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_locator_refresh_800a4de4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_800e5cf0 = 0x800e5cf0;
w3d_auto_800a4da4 = 0x800a4da4;
w3d_empty_80343584 = 0x80343584;
SECTIONS {
  .text.s19_locator_refresh_800a4de4 0x800a4de4 : { *(.text.s19_locator_refresh_800a4de4) }
  .rodata 0x80380fc8 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
