/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24l_choice_stats_802a77a4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_80366578 = 0x80366578;
w3d_cast_80341584 = 0x80341584;
w3d_lookup_800fc1b0 = 0x800fc1b0;
w3d_stats_801797b4 = 0x801797b4;
w3d_string_finish_8020c5c4 = 0x8020c5c4;
w3d_string_format_8020c510 = 0x8020c510;
w3d_string_header_80341884 = 0x80341884;
w3d_string_init_8020c5c0 = 0x8020c5c0;
w3d_string_release_80341588 = 0x80341588;
SECTIONS {
  .text.d24l_choice_stats_802a77a4 0x802a77a4 : { *(.text.d24l_choice_stats_802a77a4) }
  .rodata 0x803d6164 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
