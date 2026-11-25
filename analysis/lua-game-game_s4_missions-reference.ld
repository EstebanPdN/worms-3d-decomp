/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_mission_current_value)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
strcmp = 0x802ef234;
w3d_auto_801797b4 = 0x801797b4;
w3d_constructor_lookup_name = 0x800fc1b0;
w3d_empty_80341584 = 0x80341584;
w3d_find_mission_8027befc = 0x8027befc;
w3d_read_int_800fc230 = 0x800fc230;
w3d_str_803ceaa0 = 0x803ceaa0;
w3d_str_803ceab4 = 0x803ceab4;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_release = 0x80341588;
SECTIONS {
  .text.w3d_mission_current_value 0x80281b20 : { *(.text.w3d_mission_current_value) }
  .text.w3d_barracks_team_available 0x80281c04 : { *(.text.w3d_barracks_team_available) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
