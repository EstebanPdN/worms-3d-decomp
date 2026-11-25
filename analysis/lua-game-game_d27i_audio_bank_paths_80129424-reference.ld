/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27i_audio_bank_paths_80129424)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
String_addc_8020bf2c = 0x8020bf2c;
String_addch_8020c00c = 0x8020c00c;
String_left_8020c0fc = 0x8020c0fc;
String_set_8020bd38 = 0x8020bd38;
__15String_803426b8 = 0x803426b8;
s_8039c944 = 0x8039c944;
s_8039c94c = 0x8039c94c;
s_8039c988 = 0x8039c988;
str_finish_8020c5c4 = 0x8020c5c4;
str_free_8020bb2c = 0x8020bb2c;
str_release_80341588 = 0x80341588;
strlen_802ef9c0 = 0x802ef9c0;
strstr_802efd14 = 0x802efd14;
SECTIONS {
  .text.d27i_audio_bank_paths_80129424 0x80129424 : { *(.text.d27i_audio_bank_paths_80129424) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; game_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
