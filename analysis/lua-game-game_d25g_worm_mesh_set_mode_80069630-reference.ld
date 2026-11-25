/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d25g_worm_mesh_set_mode_80069630)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
play_80181640 = 0x80181640;
start_effect_800e5cf0 = 0x800e5cf0;
stop_clip_801817e0 = 0x801817e0;
SECTIONS {
  .text.w3d_d25g_worm_mesh_set_mode_80069630 0x80069630 : { *(.text.w3d_d25g_worm_mesh_set_mode_80069630) }
  .rodata 0x8037a97c : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
