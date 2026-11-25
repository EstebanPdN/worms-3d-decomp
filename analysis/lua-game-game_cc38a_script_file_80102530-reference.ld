/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc38a_script_file_80102530)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__21cc38a_Stream_80207fec = 0x80207fec;
__21cc38a_String_803426b8 = 0x803426b8;
cc38a_allocate_801fe0b8 = 0x801fe0b8;
cc38a_append_8020bf2c = 0x8020bf2c;
cc38a_assign_8020bd38 = 0x8020bd38;
cc38a_close_8020810c = 0x8020810c;
cc38a_execute_80102660 = 0x80102660;
cc38a_finish_8020c5c4 = 0x8020c5c4;
cc38a_free_801fe160 = 0x801fe160;
cc38a_lua_80398e48 = 0x80398e48;
cc38a_lub_80398e50 = 0x80398e50;
cc38a_open_802080a0 = 0x802080a0;
cc38a_read_80208298 = 0x80208298;
cc38a_release_80341588 = 0x80341588;
cc38a_stat_802081c8 = 0x802081c8;
cc38a_stream_finish_8020803c = 0x8020803c;
SECTIONS {
  .text.cc38a_script_file_80102530 0x80102530 : { *(.text.cc38a_script_file_80102530) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
