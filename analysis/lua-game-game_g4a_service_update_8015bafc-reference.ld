/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(g4a_service_update_8015bafc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
elapsed_801fe4d8 = 0x801fe4d8;
ticks_801fe508 = 0x801fe508;
toggle_8015ba30 = 0x8015ba30;
SECTIONS {
  .text.g4a_service_update_8015bafc 0x8015bafc : { *(.text.g4a_service_update_8015bafc) }
  .rodata 0x803a4310 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
