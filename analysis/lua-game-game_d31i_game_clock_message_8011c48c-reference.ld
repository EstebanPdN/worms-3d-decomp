/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d31i_game_clock_message_8011c48c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
a_8011d6d8 = 0x8011d6d8;
a_8011d7d8 = 0x8011d7d8;
arena_801613f0 = 0x801613f0;
b_8011d6fc = 0x8011d6fc;
b_8011d78c = 0x8011d78c;
base_8015fb34 = 0x8015fb34;
c_8011d720 = 0x8011d720;
c_8011d804 = 0x8011d804;
clear_8011d6a4 = 0x8011d6a4;
d_8011d744 = 0x8011d744;
d_8011d850 = 0x8011d850;
e_8011d768 = 0x8011d768;
e_8011d89c = 0x8011d89c;
eq_8015f620 = 0x8015f620;
init_8011cb5c = 0x8011cb5c;
inner_80178c48 = 0x80178c48;
message_id_8015f5a0 = 0x8015f5a0;
post_8016239c = 0x8016239c;
tick_8011d470 = 0x8011d470;
vt_8040db38 = 0x8040db38;
SECTIONS {
  .text.d31i_game_clock_message_8011c48c 0x8011c48c : { *(.text.d31i_game_clock_message_8011c48c) }
  .sdata 0x804abac0 (NOLOAD) : {
    . = 0x0; flag_804abac0 = .;
    . = 0x38f8; id_804af3b8 = .;
    . = 0x3900; id_804af3c0 = .;
    . = 0x3908; id_804af3c8 = .;
    . = 0x3910; id_804af3d0 = .;
    . = 0x3920; id_804af3e0 = .;
    . = 0x3928; id_804af3e8 = .;
    . = 0x3938; id_804af3f8 = .;
    . = 0x3940; id_804af400 = .;
    . = 0x3948; id_804af408 = .;
    . = 0x3950; id_804af410 = .;
    . = 0x3958; id_804af418 = .;
    . = 0x3960; id_804af420 = .;
    . = 0x3968; id_804af428 = .;
    . = 0x3970; id_804af430 = .;
    . = 0x3978; id_804af438 = .;
    . = 0x3980; id_804af440 = .;
    . = 0x3988; id_804af448 = .;
    . = 0x3990; id_804af450 = .;
    . = 0x3998; id_804af458 = .;
    . = 0x39a0; id_804af460 = .;
    . = 0x39a8; id_804af468 = .;
    . = 0x5c94; arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
