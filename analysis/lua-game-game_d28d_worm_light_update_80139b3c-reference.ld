/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d28d_worm_light_update_80139b3c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
colour_80178ec4 = 0x80178ec4;
same_80342fa4 = 0x80342fa4;
test_800b0824 = 0x800b0824;
SECTIONS {
  .text.d28d_worm_light_update_80139b3c 0x80139b3c : { *(.text.d28d_worm_light_update_80139b3c) }
  .rodata 0x8039f6c0 : { *(.rodata) }
  .sdata 0x804ab3b0 (NOLOAD) : {
    . = 0x0; current_804ab3b0 = .;
    . = 0x50; colours_804ab400 = .;
    . = 0x63b4; traceFrac_804b1764 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
