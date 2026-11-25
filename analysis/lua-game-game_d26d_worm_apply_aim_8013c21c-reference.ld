/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d26d_worm_apply_aim_8013c21c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
blend_80181814 = 0x80181814;
play_801359ec = 0x801359ec;
playing_80181ccc = 0x80181ccc;
rand_80162c20 = 0x80162c20;
SECTIONS {
  .text.d26d_worm_apply_aim_8013c21c 0x8013c21c : { *(.text.d26d_worm_apply_aim_8013c21c) }
  .rodata 0x8039f8c4 : { *(.rodata) }
  .sdata 0x804ab16c (NOLOAD) : {
    . = 0x0; aimIdle_804ab16c = .;
    . = 0xd8; aimAlt_804ab244 = .;
    . = 0x1b0; blendYaw_804ab31c = .;
    . = 0x1b4; blendPitch_804ab320 = .;
    . = 0x21c; a0_804ab388 = .;
    . = 0x220; a1_804ab38c = .;
    . = 0x224; a2_804ab390 = .;
    . = 0x228; b0_804ab394 = .;
    . = 0x22c; b1_804ab398 = .;
    . = 0x230; b2_804ab39c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
