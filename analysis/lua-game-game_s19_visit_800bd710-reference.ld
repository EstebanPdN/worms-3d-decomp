/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_refresh_marked_800bd710)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_800b53d8 = 0x800b53d8;
FUN_800bcdec = 0x800bcdec;
lbl_8043bb64 = 0x8043bb64;
SECTIONS {
  .text.s19_refresh_marked_800bd710 0x800bd710 : { *(.text.s19_refresh_marked_800bd710) }
  .rodata 0x80382cf4 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
