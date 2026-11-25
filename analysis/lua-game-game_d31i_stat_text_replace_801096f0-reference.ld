/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d31i_stat_text_replace_801096f0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6StringPCc = 0x8020bb54;
atoi = 0x802ed89c;
read_text_800fc2b0 = 0x800fc2b0;
replace_all_801099a4 = 0x801099a4;
s_80399c5c = 0x80399c5c;
s_80399c88 = 0x80399c88;
s_80399c98 = 0x80399c98;
s_80399cc8 = 0x80399cc8;
s_80399cd0 = 0x80399cd0;
s_80399cd4 = 0x80399cd4;
strcmp = 0x802ef234;
string_append_8020bf2c = 0x8020bf2c;
string_assign_8020bd38 = 0x8020bd38;
string_finish_8020c5c4 = 0x8020c5c4;
string_format_8020c510 = 0x8020c510;
string_header_80341884 = 0x80341884;
string_init_8020c5c0 = 0x8020c5c0;
string_release_8020bb2c = 0x8020bb2c;
string_release_80341588 = 0x80341588;
SECTIONS {
  .text.d31i_stat_text_replace_801096f0 0x801096f0 : { *(.text.d31i_stat_text_replace_801096f0) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
