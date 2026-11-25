/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d40a_ai_manager_message_800208c0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
active_team_80020834 = 0x80020834;
base_handle_8016293c = 0x8016293c;
begin_turn_80007b64 = 0x80007b64;
cast_803426b4 = 0x803426b4;
end_turn_80020b20 = 0x80020b20;
id_equals_8015f65c = 0x8015f65c;
k_8036bbdc = 0x8036bbdc;
level_end_80021050 = 0x80021050;
level_start_80020d18 = 0x80020d18;
planner_cleanup_800068b0 = 0x800068b0;
read_8002107c = 0x8002107c;
reset_dispatch_80021234 = 0x80021234;
s_default_8036bba8 = 0x8036bba8;
select_80035714 = 0x80035714;
speech_800226d0 = 0x800226d0;
start_turn_80020880 = 0x80020880;
team_entry_800fc6dc = 0x800fc6dc;
value_80178c48 = 0x80178c48;
SECTIONS {
  .text.w3d_d40a_ai_manager_message_800208c0 0x800208c0 : { *(.text.w3d_d40a_ai_manager_message_800208c0) }
  .sdata 0x804aa59c (NOLOAD) : {
    . = 0x0; g_804aa59c = .;
    . = 0x208; g_804aa7a4 = .;
    . = 0x20c; g_804aa7a8 = .;
    . = 0x32c; w3d_game_804aa8c8 = .;
    . = 0x23bc; msg_804ac958 = .;
    . = 0x23c4; msg_804ac960 = .;
    . = 0x23f4; msg_804ac990 = .;
    . = 0x23fc; msg_804ac998 = .;
    . = 0x2404; msg_804ac9a0 = .;
    . = 0x240c; msg_804ac9a8 = .;
    . = 0x2414; msg_804ac9b0 = .;
    . = 0x241c; msg_804ac9b8 = .;
    . = 0x2424; msg_804ac9c0 = .;
    . = 0x71ec; w3d_state_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
