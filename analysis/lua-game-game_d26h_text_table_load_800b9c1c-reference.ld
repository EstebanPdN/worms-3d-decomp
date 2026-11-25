/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d26h_text_table_load_800b9c1c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
file_close_8020810c = 0x8020810c;
file_ctor_80207fec = 0x80207fec;
file_dtor_8020803c = 0x8020803c;
file_open_802080a0 = 0x802080a0;
file_read_80208298 = 0x80208298;
release_header_8020bb2c = 0x8020bb2c;
string_append_8020c00c = 0x8020c00c;
string_assign_8020bd38 = 0x8020bd38;
SECTIONS {
  .text.d26h_text_table_load_800b9c1c 0x800b9c1c : { *(.text.d26h_text_table_load_800b9c1c) }
  .rodata 0x803828bc : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
