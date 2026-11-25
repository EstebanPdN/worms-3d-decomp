/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27d_worm_aim_blend_8013e130)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
blend_8013e340 = 0x8013e340;
fade_80181884 = 0x80181884;
index_query_800fc6dc = 0x800fc6dc;
level_80178df0 = 0x80178df0;
SECTIONS {
  .text.d27d_worm_aim_blend_8013e130 0x8013e130 : { *(.text.d27d_worm_aim_blend_8013e130) }
  .rodata 0x8039fbe4 : { *(.rodata) }
  .sdata 0x804ab3b4 (NOLOAD) : {
    . = 0x0; yawClip_804ab3b4 = .;
    . = 0x4; pitchClip_804ab3b8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
