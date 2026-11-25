/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d20c_roll_update_800dbc60)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_sqrt_802e82c0 = 0x802e82c0;
SECTIONS {
  .text.d20c_roll_update_800dbc60 0x800dbc60 : { *(.text.d20c_roll_update_800dbc60) }
  .rodata 0x8038987c : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
