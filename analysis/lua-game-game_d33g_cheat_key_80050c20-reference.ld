/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d33g_cheat_key_80050c20)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6StringPCc = 0x8020bb54;
__6StringPCcii = 0x8020bbec;
names_803fcce0 = 0x803fcce0;
refresh_8004fe48 = 0x8004fe48;
s_80378128 = 0x80378128;
s_80378130 = 0x80378130;
s_80378138 = 0x80378138;
strchr = 0x802ef198;
string_append_8020bf2c = 0x8020bf2c;
string_finish_8020c5c4 = 0x8020c5c4;
string_header_80341884 = 0x80341884;
string_init_8020c5c0 = 0x8020c5c0;
string_release_80341588 = 0x80341588;
string_upper_8020c2e8 = 0x8020c2e8;
unlock_800fd440 = 0x800fd440;
SECTIONS {
  .text.w3d_d33g_cheat_key_80050c20 0x80050c20 : { *(.text.w3d_d33g_cheat_key_80050c20) }
  .sdata 0x804aa9fc (NOLOAD) : {
    . = 0x0; alphabet_804aa9fc = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
