/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24g_mode_start_8006af38)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6String = 0x803426b8;
arena_alloc_801613f0 = 0x801613f0;
context_80165254 = 0x80165254;
create_80164514 = 0x80164514;
end_load_8006d550 = 0x8006d550;
finish_8006eebc = 0x8006eebc;
flags_8006ac90 = 0x8006ac90;
game_start_8006cecc = 0x8006cecc;
ingame_8006e004 = 0x8006e004;
load_assets_8006be14 = 0x8006be14;
main_menu_8006ba08 = 0x8006ba08;
maintain_8006e6c8 = 0x8006e6c8;
message_id_8015f5a0 = 0x8015f5a0;
message_post_8016239c = 0x8016239c;
message_string_8010a8e0 = 0x8010a8e0;
monitor_800c8120 = 0x800c8120;
pause_80069c14 = 0x80069c14;
pause_800fde38 = 0x800fde38;
pos_8045e788 = 0x8045e788;
pos_8045e7a0 = 0x8045e7a0;
pos_8045e7ac = 0x8045e7ac;
press_start_8006ef24 = 0x8006ef24;
progress_80207ca4 = 0x80207ca4;
resume_80069c54 = 0x80069c54;
round_reset_8006e6f4 = 0x8006e6f4;
s_8037bb14 = 0x8037bb14;
s_8037bbcc = 0x8037bbcc;
s_8037bbd8 = 0x8037bbd8;
s_8037bbec = 0x8037bbec;
s_8037bc20 = 0x8037bc20;
s_8037bc5c = 0x8037bc5c;
s_8037bc94 = 0x8037bc94;
s_8037bcd4 = 0x8037bcd4;
s_8037bd04 = 0x8037bd04;
s_8037bd3c = 0x8037bd3c;
s_8037bd44 = 0x8037bd44;
s_8037bd74 = 0x8037bd74;
s_8037bda4 = 0x8037bda4;
s_8037bdb4 = 0x8037bdb4;
s_8037bdec = 0x8037bdec;
s_8037be00 = 0x8037be00;
show_b53c_8006b53c = 0x8006b53c;
show_b5fc_8006b5fc = 0x8006b5fc;
show_b6bc_8006b6bc = 0x8006b6bc;
show_b77c_8006b77c = 0x8006b77c;
show_b8a0_8006b8a0 = 0x8006b8a0;
slot_table_8006bcd0 = 0x8006bcd0;
stage_80160e2c = 0x80160e2c;
step_800a7ea0 = 0x800a7ea0;
string_finish_8020c5c4 = 0x8020c5c4;
string_format_8020c510 = 0x8020c510;
string_header_80341884 = 0x80341884;
string_init_8020c5c0 = 0x8020c5c0;
string_release_80341588 = 0x80341588;
t_804100a8 = 0x804100a8;
t_80410aa0 = 0x80410aa0;
type_8020b680 = 0x8020b680;
vt_8040db38 = 0x8040db38;
SECTIONS {
  .text.w3d_d24g_mode_start_8006af38 0x8006af38 : { *(.text.w3d_d24g_mode_start_8006af38) }
  .sdata 0x804aaac0 (NOLOAD) : {
    . = 0x0; count_804aaac0 = .;
    . = 0x2c8c; msg_804ad74c = .;
    . = 0x2c94; msg_804ad754 = .;
    . = 0x2cbc; msg_804ad77c = .;
    . = 0x2cdc; msg_804ad79c = .;
    . = 0x2d54; msg_804ad814 = .;
    . = 0x6c94; arena_804b1754 = .;
    . = 0x6cc8; app_804b1788 = .;
    . = 0x6ccc; service_804b178c = .;
    . = 0x6d30; g_804b17f0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
