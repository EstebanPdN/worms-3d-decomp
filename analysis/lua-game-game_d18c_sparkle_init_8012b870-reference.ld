/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d18c_sparkle_init_8012b870)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__20d18c_String_8020bb54PCc = 0x8020bb54;
d18c_engine_context_80165254 = 0x80165254;
d18c_handle_load_node_8015adf4 = 0x8015adf4;
d18c_mesh_alloc_8018920c = 0x8018920c;
d18c_mesh_colours_80189760 = 0x80189760;
d18c_mesh_flags_80189828 = 0x80189828;
d18c_mesh_uvs_8018963c = 0x8018963c;
d18c_random_8015ff5c = 0x8015ff5c;
d18c_read_int_800fc1b0 = 0x800fc1b0;
d18c_string_finish_8020c5c4 = 0x8020c5c4;
d18c_string_release_80341588 = 0x80341588;
d18c_water_level_8039d348 = 0x8039d348;
d18c_water_sparkle_8039d338 = 0x8039d338;
SECTIONS {
  .text.d18c_sparkle_init_8012b870 0x8012b870 : { *(.text.d18c_sparkle_init_8012b870) }
  .rodata 0x8039d354 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
