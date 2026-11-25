/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d32h_land_texture_layers_800b9e58)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cast_8034357c = 0x8034357c;
key_804143e0 = 0x804143e0;
load_8015adf4 = 0x8015adf4;
lookup_80174074 = 0x80174074;
none_803828d8 = 0x803828d8;
service_8020b648 = 0x8020b648;
strcasecmp_802ef074 = 0x802ef074;
SECTIONS {
  .text.d32h_land_texture_layers_800b9e58 0x800b9e58 : { *(.text.d32h_land_texture_layers_800b9e58) }
  .sdata 0x804b183c (NOLOAD) : {
    . = 0x0; sink_804b183c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
