/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d25b_inventory_reset_8008b80c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_._19Descriptor_80178474 = 0x80178474;
__6String = 0x803426b8;
w3d_as_inventory_80179598 = 0x80179598;
w3d_identity_80341584 = 0x80341584;
w3d_resource_property_800fc1b0 = 0x800fc1b0;
w3d_string_8037de84 = 0x8037de84;
w3d_string_8037de98 = 0x8037de98;
w3d_string_finish_8020c5c4 = 0x8020c5c4;
w3d_string_format_8020c510 = 0x8020c510;
w3d_string_release_80341588 = 0x80341588;
SECTIONS {
  .text.w3d_d25b_inventory_reset_8008b80c 0x8008b80c : { *(.text.w3d_d25b_inventory_reset_8008b80c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
