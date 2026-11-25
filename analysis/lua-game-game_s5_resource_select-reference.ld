/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_resource_select_800c9d98)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_resource_lookup_8020b680 = 0x8020b680;
w3d_resource_name_804144f8 = 0x804144f8;
w3d_resource_set_80174820 = 0x80174820;
SECTIONS {
  .text.w3d_resource_select_800c9d98 0x800c9d98 : { *(.text.w3d_resource_select_800c9d98) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
