/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d30a_grid_refresh_regions_8001ef50)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc26a_grid_mark_8001f4f4 = 0x8001f4f4;
cc26a_grid_refresh_8001f904 = 0x8001f904;
memcpy_802eee50 = 0x802eee50;
s19_lookup_slot_8008c548 = 0x8008c548;
w3d_auto_80015264 = 0x80015264;
w3d_auto_800153dc = 0x800153dc;
w3d_auto_80015588 = 0x80015588;
w3d_auto_800fc330 = 0x800fc330;
w3d_player_list_weapon_count_8008c534 = 0x8008c534;
w3d_register_8001f394 = 0x8001f394;
w3d_settings_803eb658 = 0x803eb658;
SECTIONS {
  .text.w3d_d30a_grid_refresh_regions_8001ef50 0x8001ef50 : { *(.text.w3d_d30a_grid_refresh_regions_8001ef50) }
  .rodata 0x8036b8a0 : { *(.rodata) }
  .sdata 0x804aa754 (NOLOAD) : {
    . = 0x0; w3d_marks_804aa754 = .;
    . = 0x3f8; w3d_players_804aab4c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
