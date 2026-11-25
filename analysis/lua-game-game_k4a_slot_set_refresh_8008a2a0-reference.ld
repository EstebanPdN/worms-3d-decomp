/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(k4a_slot_set_refresh_8008a2a0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_8008a30c = 0x8008a30c;
FUN_8008cf40 = 0x8008cf40;
SECTIONS {
  .text.k4a_slot_set_refresh_8008a2a0 0x8008a2a0 : { *(.text.k4a_slot_set_refresh_8008a2a0) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
