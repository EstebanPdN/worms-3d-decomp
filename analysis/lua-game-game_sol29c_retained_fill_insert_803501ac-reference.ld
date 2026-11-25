/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(sol29c_retained_fill_insert_803501ac)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
native_array_allocate_801907a8 = 0x801907a8;
native_array_free_801907d0 = 0x801907d0;
SECTIONS {
  .text.sol29c_retained_fill_insert_803501ac 0x803501ac : { *(.text.sol29c_retained_fill_insert_803501ac) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
