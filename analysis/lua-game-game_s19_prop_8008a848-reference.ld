/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_crate_showered_8008a848)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_8008a30c = 0x8008a30c;
w3d_auto_800fc1f0 = 0x800fc1f0;
SECTIONS {
  .text.s19_crate_showered_8008a848 0x8008a848 : { *(.text.s19_crate_showered_8008a848) }
  .rodata 0x8037da08 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
