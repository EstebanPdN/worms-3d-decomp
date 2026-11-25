/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_sound_emitter_vary_volume_801e1308)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_f32_803b04e8 = 0x803b04e8;
w3d_f32_803b04ec = 0x803b04ec;
w3d_f32_803b04f0 = 0x803b04f0;
w3d_rand_802ee7dc = 0x802ee7dc;
SECTIONS {
  .text.w3d_sound_emitter_vary_volume_801e1308 0x801e1308 : { *(.text.w3d_sound_emitter_vary_volume_801e1308) }
  .rodata 0x803b04e0 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
