/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d26b_scheme_load_8008cf40)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_800fc330 = 0x800fc330;
w3d_weapon_table_80431c80 = 0x80431c80;
w3d_weapon_table_80431db8 = 0x80431db8;
SECTIONS {
  .text.w3d_d26b_scheme_load_8008cf40 0x8008cf40 : { *(.text.w3d_d26b_scheme_load_8008cf40) }
  .rodata 0x8037daf4 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
