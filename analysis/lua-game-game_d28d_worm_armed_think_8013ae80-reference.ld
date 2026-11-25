/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d28d_worm_armed_think_8013ae80)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
angle_8013b898 = 0x8013b898;
apply_8013c21c = 0x8013c21c;
armed_8013e9a8 = 0x8013e9a8;
facing_8013b3b8 = 0x8013b3b8;
fire_8039f4f4 = 0x8039f4f4;
firing_8013f4dc = 0x8013f4dc;
get_803426b4 = 0x803426b4;
idle_8013a158 = 0x8013a158;
in_range_8013b5bc = 0x8013b5bc;
play_801359ec = 0x801359ec;
query_800fc6dc = 0x800fc6dc;
rand_80162c20 = 0x80162c20;
ready_8013e8f8 = 0x8013e8f8;
sqrt_802e82c0 = 0x802e82c0;
stop_800e5bb8 = 0x800e5bb8;
target_80178c48 = 0x80178c48;
turn_8013b948 = 0x8013b948;
visible_8013b91c = 0x8013b91c;
SECTIONS {
  .text.d28d_worm_armed_think_8013ae80 0x8013ae80 : { *(.text.d28d_worm_armed_think_8013ae80) }
  .rodata 0x8039f7b4 : { *(.rodata) }
  .sdata 0x804ab16c (NOLOAD) : {
    . = 0x0; a_804ab16c = .;
    . = 0x14c; g_804ab2b8 = .;
    . = 0x158; c_804ab2c4 = .;
    . = 0x15c; d_804ab2c8 = .;
    . = 0x160; e_804ab2cc = .;
    . = 0x661c; system_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
