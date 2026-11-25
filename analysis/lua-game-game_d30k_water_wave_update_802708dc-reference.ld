/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d30k_water_wave_update_802708dc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801ef048 = 0x801ef048;
fn_802e86d4 = 0x802e86d4;
SECTIONS {
  .text.w3d_d30k_water_wave_update_802708dc 0x802708dc : { *(.text.w3d_d30k_water_wave_update_802708dc) }
  .rodata 0x803cc030 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
