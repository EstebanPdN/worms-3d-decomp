/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d33b_water_shade_80087628)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_80178df0 = 0x80178df0;
w3d_empty_80342a74 = 0x80342a74;
SECTIONS {
  .text.d33b_water_shade_80087628 0x80087628 : { *(.text.d33b_water_shade_80087628) }
  .rodata 0x8037d0e0 : { *(.rodata) }
  .sdata 0x804b17e0 (NOLOAD) : {
    . = 0x0; w3d_world_804b17e0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
