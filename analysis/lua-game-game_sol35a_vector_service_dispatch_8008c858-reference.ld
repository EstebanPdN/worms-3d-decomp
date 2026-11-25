/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(sol35a_vector_service_dispatch_8008c858)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
sol35a_dispatch_80164514 = 0x80164514;
sol35a_service_8040f2c0 = 0x8040f2c0;
sol35a_service_lookup_8020b680 = 0x8020b680;
sol35a_vector_refresh_8003e1f8 = 0x8003e1f8;
SECTIONS {
  .text.sol35a_vector_service_dispatch_8008c858 0x8008c858 : { *(.text.sol35a_vector_service_dispatch_8008c858) }
  .sdata 0x804b178c (NOLOAD) : {
    . = 0x0; sol35a_context_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
