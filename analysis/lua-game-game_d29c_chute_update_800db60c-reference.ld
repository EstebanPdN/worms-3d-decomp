/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d29c_chute_update_800db60c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__3Pos = 0x80343740;
acos_802e79e0 = 0x802e79e0;
arena_801613f0 = 0x801613f0;
construct_801f7538 = 0x801f7538;
heading_800dbaf4 = 0x800dbaf4;
hide_800dc20c = 0x800dc20c;
int_init_800a82f0 = 0x800a82f0;
motion_800dc244 = 0x800dc244;
msg_id_8015f5a0 = 0x8015f5a0;
post_8016239c = 0x8016239c;
roll_800dbc60 = 0x800dbc60;
sqrt_802e82c0 = 0x802e82c0;
step_800b0824 = 0x800b0824;
zero_8043ae20 = 0x8043ae20;
SECTIONS {
  .text.d29c_chute_update_800db60c 0x800db60c : { *(.text.d29c_chute_update_800db60c) }
  .rodata 0x80389854 : { *(.rodata) }
  .sdata 0x804aebec (NOLOAD) : {
    . = 0x0; msgid_804aebec = .;
    . = 0x2b68; arena_804b1754 = .;
    . = 0x2b78; time_804b1764 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
