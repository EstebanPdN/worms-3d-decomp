/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d17c_rain_splash_init_800f26a8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__20d17c_String_8020bb54PCc = 0x8020bb54;
d17c_as_mesh_8034380c = 0x8034380c;
d17c_engine_context_80165254 = 0x80165254;
d17c_handle_load_8015adf4 = 0x8015adf4;
d17c_mesh_alloc_8018920c = 0x8018920c;
d17c_mesh_colours_80189760 = 0x80189760;
d17c_mesh_flags_80189704 = 0x80189704;
d17c_mesh_uvs_8018963c = 0x8018963c;
d17c_rain_splash_8038c480 = 0x8038c480;
d17c_read_float_800fc270 = 0x800fc270;
d17c_string_finish_8020c5c4 = 0x8020c5c4;
d17c_string_release_80341588 = 0x80341588;
d17c_water_level_8038c494 = 0x8038c494;
memset = 0x802eefe0;
SECTIONS {
  .text.d17c_rain_splash_init_800f26a8 0x800f26a8 : { *(.text.d17c_rain_splash_init_800f26a8) }
  .rodata 0x8038c4a0 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
