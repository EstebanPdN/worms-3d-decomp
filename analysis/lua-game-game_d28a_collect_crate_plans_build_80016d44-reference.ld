/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d28a_collect_crate_plans_build_80016d44)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_80015960 = 0x80015960;
__8CostBase = 0x80006360;
_vt.12CollectCrate = 0x8040d958;
s19_lookup_slot_8008c360 = 0x8008c360;
strcmp = 0x802ef234;
w3d_actor_member_delete_backend = 0x801fe1f8;
w3d_ai_push_plan_b = 0x80007514;
w3d_auto_8001523c = 0x8001523c;
w3d_auto_80015540 = 0x80015540;
w3d_center_8041d3a0 = 0x8041d3a0;
w3d_handle_storage_release = 0x802134fc;
w3d_player_list_team_count_8008c34c = 0x8008c34c;
SECTIONS {
  .text.w3d_d28a_collect_crate_plans_build_80016d44 0x80016d44 : { *(.text.w3d_d28a_collect_crate_plans_build_80016d44) }
  .rodata 0x8036a6e4 : { *(.rodata) }
  .sdata 0x804aa594 (NOLOAD) : {
    . = 0x0; w3d_flag_804aa594 = .;
    . = 0x144; w3d_settings_804aa6d8 = .;
    . = 0x148; w3d_game_804aa6dc = .;
    . = 0x14c; w3d_busy_804aa6e0 = .;
    . = 0x5b8; w3d_players_804aab4c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
