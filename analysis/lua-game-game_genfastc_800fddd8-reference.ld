/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_init_fade_800fddd8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80173df0 = 0x80173df0;
fn_80178f54 = 0x80178f54;
fn_80322838 = 0x80322838;
fn_80322898 = 0x80322898;
lbl_803b0734 = 0x803b0734;
lbl_803b0738 = 0x803b0738;
lbl_803b073c = 0x803b073c;
lbl_803b0740 = 0x803b0740;
lbl_803b0744 = 0x803b0744;
lbl_803b0748 = 0x803b0748;
lbl_803b074c = 0x803b074c;
SECTIONS {
  .text.w3d_init_fade_800fddd8 0x800fddd8 : { *(.text.w3d_init_fade_800fddd8) }
  .text.w3d_set_voice_pan_801e58b0 0x801e58b0 : { *(.text.w3d_set_voice_pan_801e58b0) }
  .text.w3d_set_voice_pan_801e5908 0x801e5908 : { *(.text.w3d_set_voice_pan_801e5908) }
  .text.w3d_set_voice_pitch_801e5960 0x801e5960 : { *(.text.w3d_set_voice_pitch_801e5960) }
  .text.w3d_update_tint_8026b2c4 0x8026b2c4 : { *(.text.w3d_update_tint_8026b2c4) }
  .text.w3d_update_tint_802a0d44 0x802a0d44 : { *(.text.w3d_update_tint_802a0d44) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
