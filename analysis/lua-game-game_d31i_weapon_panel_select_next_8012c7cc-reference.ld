/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d31i_weapon_panel_select_next_8012c7cc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6StringPCc = 0x8020bb54;
arena_801613f0 = 0x801613f0;
attr_800fd014 = 0x800fd014;
inner_80178c48 = 0x80178c48;
message_id_8015f5a0 = 0x8015f5a0;
message_int_init_800a82f0 = 0x800a82f0;
post_8016239c = 0x8016239c;
read_uint_800fc230 = 0x800fc230;
reason_8012f0f8 = 0x8012f0f8;
row_start_8012c768 = 0x8012c768;
s_8039d9a4 = 0x8039d9a4;
s_8039d9b0 = 0x8039d9b0;
stock_800fcec8 = 0x800fcec8;
strcmp = 0x802ef234;
string_finish_8020c5c4 = 0x8020c5c4;
string_release_80341588 = 0x80341588;
team_800fc6dc = 0x800fc6dc;
weapons_803fd9e4 = 0x803fd9e4;
SECTIONS {
  .text.d31i_weapon_panel_select_next_8012c7cc 0x8012c7cc : { *(.text.d31i_weapon_panel_select_next_8012c7cc) }
  .sdata 0x804af684 (NOLOAD) : {
    . = 0x0; msg_804af684 = .;
    . = 0x20d0; arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
