/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d26d_worm_jump_animation_8013bec4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__3Pos = 0x80343740;
asin_802e83ec = 0x802e83ec;
construct_801f7538 = 0x801f7538;
duration_80181d30 = 0x80181d30;
jump_time_80137d6c = 0x80137d6c;
play_801359ec = 0x801359ec;
reference_8045e788 = 0x8045e788;
spin_8039f898 = 0x8039f898;
ticks_8015fd14 = 0x8015fd14;
SECTIONS {
  .text.d26d_worm_jump_animation_8013bec4 0x8013bec4 : { *(.text.d26d_worm_jump_animation_8013bec4) }
  .rodata 0x8039f8a0 : { *(.rodata) }
  .sdata 0x804ab100 (NOLOAD) : {
    . = 0x0; nRun_804ab100 = .;
    . = 0x14; nA_804ab114 = .;
    . = 0x1c; nD_804ab11c = .;
    . = 0x24; nC_804ab124 = .;
    . = 0x30; nB_804ab130 = .;
    . = 0x278; mD_804ab378 = .;
    . = 0x27c; mC_804ab37c = .;
    . = 0x280; mA_804ab380 = .;
    . = 0x284; mB_804ab384 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
