/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d27e_read_string_refs_80202044)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
next_802024f4 = 0x802024f4;
string_free_8020bb2c = 0x8020bb2c;
SECTIONS {
  .text.w3d_d27e_read_string_refs_80202044 0x80202044 : { *(.text.w3d_d27e_read_string_refs_80202044) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
