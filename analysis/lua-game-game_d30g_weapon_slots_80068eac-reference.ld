/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d30g_weapon_slots_80068eac)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6String = 0x803426b8;
__as__6StringPCc = 0x8020bd38;
s_8037a894 = 0x8037a894;
strcmp = 0x802ef234;
string_finish_8020c5c4 = 0x8020c5c4;
string_release_80341588 = 0x80341588;
string_release_header_8020bb2c = 0x8020bb2c;
SECTIONS {
  .text.w3d_d30g_weapon_slots_80068eac 0x80068eac : { *(.text.w3d_d30g_weapon_slots_80068eac) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
