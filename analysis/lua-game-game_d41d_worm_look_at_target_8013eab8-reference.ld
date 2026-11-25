/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d41d_worm_look_at_target_8013eab8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
angle_8013b898 = 0x8013b898;
apply_8013c21c = 0x8013c21c;
control_801817e0 = 0x801817e0;
engine_80165254 = 0x80165254;
facing_8013b3b8 = 0x8013b3b8;
in_range_8013b5bc = 0x8013b5bc;
line_8039edfc = 0x8039edfc;
lookup_80164fc8 = 0x80164fc8;
mood_8013ef50 = 0x8013ef50;
play_801359ec = 0x801359ec;
playing_80181ccc = 0x80181ccc;
rand_80162c20 = 0x80162c20;
reset_8013c54c = 0x8013c54c;
speak_8013bd0c = 0x8013bd0c;
turn_8013b948 = 0x8013b948;
SECTIONS {
  .text.w3d_d41d_worm_look_at_target_8013eab8 0x8013eab8 : { *(.text.w3d_d41d_worm_look_at_target_8013eab8) }
  .rodata 0x8039fd04 : { *(.rodata) }
  .sdata 0x804ab100 (NOLOAD) : {
    . = 0x0; i_804ab100 = .;
    . = 0x1ac; a_804ab2ac = .;
    . = 0x1b0; f_804ab2b0 = .;
    . = 0x1cc; b_804ab2cc = .;
    . = 0x1d0; c_804ab2d0 = .;
    . = 0x1d4; d_804ab2d4 = .;
    . = 0x1e4; e_804ab2e4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
