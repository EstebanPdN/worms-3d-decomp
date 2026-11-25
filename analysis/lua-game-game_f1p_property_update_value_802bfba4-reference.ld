/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_property_update_value_802bfba4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80178d1c = 0x80178d1c;
fn_802bfc64 = 0x802bfc64;
value_803d8418 = 0x803d8418;
SECTIONS {
  .text.w3d_property_update_value_802bfba4 0x802bfba4 : { *(.text.w3d_property_update_value_802bfba4) }
  .rodata 0x803d8420 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
