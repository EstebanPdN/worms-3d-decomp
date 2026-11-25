/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d25d_worm_turn_towards_8013b948)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
atan2_802e7e5c = 0x802e7e5c;
cos_802e86d4 = 0x802e86d4;
delta_8013aa10 = 0x8013aa10;
play_801359ec = 0x801359ec;
sin_802e88ac = 0x802e88ac;
SECTIONS {
  .text.d25d_worm_turn_towards_8013b948 0x8013b948 : { *(.text.d25d_worm_turn_towards_8013b948) }
  .rodata 0x8039f80c : { *(.rodata) }
  .sdata 0x804ab19c (NOLOAD) : {
    . = 0x0; right_804ab19c = .;
    . = 0x4; left_804ab1a0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
