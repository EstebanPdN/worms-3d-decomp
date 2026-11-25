/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24g_game_start_8006cecc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6StringPCc = 0x8020bb54;
arena_alloc_801613f0 = 0x801613f0;
create_80164514 = 0x80164514;
debug_print_802fb7ac = 0x802fb7ac;
destroy_owned_80178474 = 0x80178474;
message_id_8015f5a0 = 0x8015f5a0;
message_post_8016239c = 0x8016239c;
message_string_8010a8e0 = 0x8010a8e0;
names_add_800c4b00 = 0x800c4b00;
names_freeze_800c4de8 = 0x800c4de8;
on_round_8006ce8c = 0x8006ce8c;
parts_8006e124 = 0x8006e124;
prepare_8006df98 = 0x8006df98;
read_800fc230 = 0x800fc230;
s_8037baa4 = 0x8037baa4;
s_8037bb14 = 0x8037bb14;
s_8037be30 = 0x8037be30;
s_8037c044 = 0x8037c044;
s_8037c05c = 0x8037c05c;
s_8037c070 = 0x8037c070;
s_8037c078 = 0x8037c078;
slot_800fc948 = 0x800fc948;
string_finish_8020c5c4 = 0x8020c5c4;
string_release_80341588 = 0x80341588;
t_8040daf8 = 0x8040daf8;
t_8040dff8 = 0x8040dff8;
t_8040e278 = 0x8040e278;
t_8040e578 = 0x8040e578;
t_8040f110 = 0x8040f110;
t_8040f240 = 0x8040f240;
t_8040f4d8 = 0x8040f4d8;
t_8040f598 = 0x8040f598;
t_8040f898 = 0x8040f898;
t_8040fa18 = 0x8040fa18;
t_804100a8 = 0x804100a8;
t_804105e8 = 0x804105e8;
t_80410768 = 0x80410768;
t_80410898 = 0x80410898;
t_80410a60 = 0x80410a60;
t_80410df0 = 0x80410df0;
t_80410f30 = 0x80410f30;
t_8041bbb0 = 0x8041bbb0;
t_8041c1a0 = 0x8041c1a0;
type_8020b680 = 0x8020b680;
vt_8040db38 = 0x8040db38;
watch_800fd62c = 0x800fd62c;
write_int_800fc3b0 = 0x800fc3b0;
write_string_800fc550 = 0x800fc550;
SECTIONS {
  .text.w3d_d24g_game_start_8006cecc 0x8006cecc : { *(.text.w3d_d24g_game_start_8006cecc) }
  .sdata 0x804aaac4 (NOLOAD) : {
    . = 0x0; games_804aaac4 = .;
    . = 0x2c88; msg_804ad74c = .;
    . = 0x2d88; msg_804ad84c = .;
    . = 0x6c90; arena_804b1754 = .;
    . = 0x6cc8; service_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
