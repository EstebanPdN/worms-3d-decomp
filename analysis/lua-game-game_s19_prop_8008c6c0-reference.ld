/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_low_gravity_8008c6c0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_800fc4c8 = 0x800fc4c8;
w3d_auto_800fc270 = 0x800fc270;
SECTIONS {
  .text.s19_low_gravity_8008c6c0 0x8008c6c0 : { *(.text.s19_low_gravity_8008c6c0) }
  .rodata 0x8037dfdc : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
