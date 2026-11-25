/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d26i_wind_sound_update_80131338)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
sin_802e88ac = 0x802e88ac;
w3d_wind_direction_80131520 = 0x80131520;
SECTIONS {
  .text.d26i_wind_sound_update_80131338 0x80131338 : { *(.text.d26i_wind_sound_update_80131338) }
  .rodata 0x8039e1c0 : { *(.rodata) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; world_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
