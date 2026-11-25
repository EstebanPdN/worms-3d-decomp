/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d28d_worm_idle_think_8013aa58)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
angle_8013b898 = 0x8013b898;
apply_8013c21c = 0x8013c21c;
facing_8013b3b8 = 0x8013b3b8;
get_803426b4 = 0x803426b4;
idle_8013a158 = 0x8013a158;
in_range_8013b5bc = 0x8013b5bc;
play_801359ec = 0x801359ec;
query_800fc6dc = 0x800fc6dc;
rand_80162c20 = 0x80162c20;
stop_800e5bb8 = 0x800e5bb8;
target_80178c48 = 0x80178c48;
turn_8013b948 = 0x8013b948;
visible_8013b91c = 0x8013b91c;
SECTIONS {
  .text.d28d_worm_idle_think_8013aa58 0x8013aa58 : { *(.text.d28d_worm_idle_think_8013aa58) }
  .rodata 0x8039f798 : { *(.rodata) }
  .sdata 0x804ab100 (NOLOAD) : {
    . = 0x0; b_804ab100 = .;
    . = 0x6c; a_804ab16c = .;
    . = 0x1a4; e_804ab2a4 = .;
    . = 0x1a8; f_804ab2a8 = .;
    . = 0x1d0; c_804ab2d0 = .;
    . = 0x1d8; d_804ab2d8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
