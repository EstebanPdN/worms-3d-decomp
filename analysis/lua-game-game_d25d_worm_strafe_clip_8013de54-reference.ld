/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d25d_worm_strafe_clip_8013de54)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__3Pos = 0x80343740;
construct_801f7538 = 0x801f7538;
control_801817e0 = 0x801817e0;
index_query_800fc6dc = 0x800fc6dc;
play_801359ec = 0x801359ec;
SECTIONS {
  .text.d25d_worm_strafe_clip_8013de54 0x8013de54 : { *(.text.d25d_worm_strafe_clip_8013de54) }
  .rodata 0x8039fbd0 : { *(.rodata) }
  .sdata 0x804ab100 (NOLOAD) : {
    . = 0x0; idle_804ab100 = .;
    . = 0x2a0; back_804ab3a0 = .;
    . = 0x2a4; front_804ab3a4 = .;
    . = 0x2a8; right_804ab3a8 = .;
    . = 0x2ac; left_804ab3ac = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
