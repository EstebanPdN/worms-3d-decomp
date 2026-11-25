/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f8b_choose_turn_animation_8013a8b0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
left_8039f784 = 0x8039f784;
play_801359ec = 0x801359ec;
playing_80181ccc = 0x80181ccc;
rate_8039f780 = 0x8039f780;
right_8039f788 = 0x8039f788;
zero_8039f77c = 0x8039f77c;
SECTIONS {
  .text.f8b_choose_turn_animation_8013a8b0 0x8013a8b0 : { *(.text.f8b_choose_turn_animation_8013a8b0) }
  .sdata 0x804ab19c (NOLOAD) : {
    . = 0x0; turnLeft_804ab19c = .;
    . = 0x4; turnRight_804ab1a0 = .;
    . = 0x8; walkLeft_804ab1a4 = .;
    . = 0xc; walkRight_804ab1a8 = .;
    . = 0x10; idle_804ab1ac = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
