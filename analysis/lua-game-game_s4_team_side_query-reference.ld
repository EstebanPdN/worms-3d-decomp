/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s4_team_first_unused_side)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
memset = 0x802eefe0;
w3d_auto_801797b4 = 0x801797b4;
w3d_constructor_lookup_name = 0x800fc1b0;
w3d_empty_80341584 = 0x80341584;
w3d_str_803d0bf0 = 0x803d0bf0;
SECTIONS {
  .text.w3d_s4_team_first_unused_side 0x8029cc70 : { *(.text.w3d_s4_team_first_unused_side) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
