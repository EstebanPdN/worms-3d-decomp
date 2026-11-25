/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24g_mode_message_handler_8006a418)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6StringPCc = 0x8020bb54;
apply_land_8006d854 = 0x8006d854;
arena_alloc_801613f0 = 0x801613f0;
base_handle_8016293c = 0x8016293c;
cache_equals_8015f620 = 0x8015f620;
create_ui_8006d4cc = 0x8006d4cc;
finish_8006eebc = 0x8006eebc;
id_equals_8015f65c = 0x8015f65c;
level_load_8006d610 = 0x8006d610;
message_id_8015f5a0 = 0x8015f5a0;
message_post_8016239c = 0x8016239c;
message_string_8010a8e0 = 0x8010a8e0;
movie_stop_8006be38 = 0x8006be38;
msg_int_800a830c = 0x800a830c;
msg_text_8010a8fc = 0x8010a8fc;
names_clear_800c4604 = 0x800c4604;
new_game_8006e784 = 0x8006e784;
pause_8006bf7c = 0x8006bf7c;
read_str_800fc2b0 = 0x800fc2b0;
resume_8006ac40 = 0x8006ac40;
s_8037ba54 = 0x8037ba54;
s_8037ba60 = 0x8037ba60;
s_8037baa4 = 0x8037baa4;
s_8037baf0 = 0x8037baf0;
s_8037bb04 = 0x8037bb04;
s_8037bb14 = 0x8037bb14;
s_8037bb18 = 0x8037bb18;
s_8037bb28 = 0x8037bb28;
s_8037bb38 = 0x8037bb38;
s_8037bb44 = 0x8037bb44;
s_8037bb4c = 0x8037bb4c;
s_8037bb54 = 0x8037bb54;
s_8037bb64 = 0x8037bb64;
set_mode_8006ab48 = 0x8006ab48;
start_8006c4a8 = 0x8006c4a8;
strcmp = 0x802ef234;
string_finish_8020c5c4 = 0x8020c5c4;
string_release_80341588 = 0x80341588;
t_8040e1b8 = 0x8040e1b8;
t_8040e5d8 = 0x8040e5d8;
t_8040ea90 = 0x8040ea90;
t_8040f518 = 0x8040f518;
t_8040f958 = 0x8040f958;
t_80410160 = 0x80410160;
t_80410298 = 0x80410298;
t_804107a8 = 0x804107a8;
upper_8020c2e8 = 0x8020c2e8;
vt_8040db38 = 0x8040db38;
write_bool_800fc43c = 0x800fc43c;
write_str_800fc550 = 0x800fc550;
SECTIONS {
  .text.w3d_d24g_mode_message_handler_8006a418 0x8006a418 : { *(.text.w3d_d24g_mode_message_handler_8006a418) }
  .sdata 0x804aac54 (NOLOAD) : {
    . = 0x0; other_804aac54 = .;
    . = 0x2a58; c_804ad6ac = .;
    . = 0x2a60; c_804ad6b4 = .;
    . = 0x2a68; c_804ad6bc = .;
    . = 0x2a70; c_804ad6c4 = .;
    . = 0x2a78; c_804ad6cc = .;
    . = 0x2a80; c_804ad6d4 = .;
    . = 0x2a88; c_804ad6dc = .;
    . = 0x2a90; c_804ad6e4 = .;
    . = 0x2aa0; c_804ad6f4 = .;
    . = 0x2aa8; c_804ad6fc = .;
    . = 0x2ab0; c_804ad704 = .;
    . = 0x2ab8; c_804ad70c = .;
    . = 0x2ac0; c_804ad714 = .;
    . = 0x2ac8; c_804ad71c = .;
    . = 0x2ad0; c_804ad724 = .;
    . = 0x2ad8; c_804ad72c = .;
    . = 0x2ae0; c_804ad734 = .;
    . = 0x2b08; c_804ad75c = .;
    . = 0x2b10; c_804ad764 = .;
    . = 0x2b18; c_804ad76c = .;
    . = 0x2b28; c_804ad77c = .;
    . = 0x2b40; c_804ad794 = .;
    . = 0x2b78; c_804ad7cc = .;
    . = 0x2b80; c_804ad7d4 = .;
    . = 0x2b88; c_804ad7dc = .;
    . = 0x2b90; c_804ad7e4 = .;
    . = 0x2b98; c_804ad7ec = .;
    . = 0x2bb0; c_804ad804 = .;
    . = 0x2bd8; c_804ad82c = .;
    . = 0x2c10; c_804ad864 = .;
    . = 0x6b00; arena_804b1754 = .;
    . = 0x6b34; app_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
