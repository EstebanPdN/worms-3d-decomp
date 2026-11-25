/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx9c_populate_service_803488e4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cx9c_descriptor_804140d0 = 0x804140d0;
cx9c_descriptor_804163f8 = 0x804163f8;
cx9c_lookup_8020b680 = 0x8020b680;
SECTIONS {
  .text.w3d_cx9c_populate_service_803488e4 0x803488e4 : { *(.text.w3d_cx9c_populate_service_803488e4) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
