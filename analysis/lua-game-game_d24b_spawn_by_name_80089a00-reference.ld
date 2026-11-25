/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24b_spawn_by_name_80089a00)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6String = 0x803426b8;
__6StringPCc = 0x8020bb54;
w3d_allocate_80212fd4 = 0x80212fd4;
w3d_copy_802eee50 = 0x802eee50;
w3d_release_802134fc = 0x802134fc;
w3d_spawn_mine_8008bc78 = 0x8008bc78;
w3d_spawn_other_8008df50 = 0x8008df50;
w3d_strcmp_802ef234 = 0x802ef234;
w3d_string_8037d888 = 0x8037d888;
w3d_string_8037d890 = 0x8037d890;
w3d_string_finish_8020c5c4 = 0x8020c5c4;
w3d_string_release_80341588 = 0x80341588;
w3d_teams_8043bb64 = 0x8043bb64;
SECTIONS {
  .text.w3d_d24b_spawn_by_name_80089a00 0x80089a00 : { *(.text.w3d_d24b_spawn_by_name_80089a00) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
