/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d30i_command_line_parse_801280b4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
args_8015c3ec = 0x8015c3ec;
assert_80206a00 = 0x80206a00;
at_8015b410 = 0x8015b410;
atof = 0x802ed878;
atoi = 0x802ed89c;
count_8015b424 = 0x8015b424;
get_801fcd6c = 0x801fcd6c;
n_8039bf6c = 0x8039bf6c;
n_8039bf80 = 0x8039bf80;
n_8039bf98 = 0x8039bf98;
n_8039bfc0 = 0x8039bfc0;
n_8039bff0 = 0x8039bff0;
n_8039c018 = 0x8039c018;
n_8039c060 = 0x8039c060;
n_8039c07c = 0x8039c07c;
n_8039c098 = 0x8039c098;
n_8039c0b4 = 0x8039c0b4;
n_8039c0c8 = 0x8039c0c8;
n_8039c0d8 = 0x8039c0d8;
n_8039c114 = 0x8039c114;
n_8039c130 = 0x8039c130;
n_8039c154 = 0x8039c154;
n_8039c170 = 0x8039c170;
n_8039c190 = 0x8039c190;
n_8039c1b0 = 0x8039c1b0;
n_8039c1d4 = 0x8039c1d4;
n_8039c1e8 = 0x8039c1e8;
n_8039c204 = 0x8039c204;
n_8039c20c = 0x8039c20c;
n_8039c230 = 0x8039c230;
n_8039c250 = 0x8039c250;
n_8039c29c = 0x8039c29c;
n_8039c2c4 = 0x8039c2c4;
n_8039c2f0 = 0x8039c2f0;
n_8039c308 = 0x8039c308;
n_8039c334 = 0x8039c334;
n_8039c380 = 0x8039c380;
n_8039c3a0 = 0x8039c3a0;
n_8039c3c0 = 0x8039c3c0;
n_8039c3e4 = 0x8039c3e4;
n_8039c414 = 0x8039c414;
n_8039c444 = 0x8039c444;
n_8039c474 = 0x8039c474;
n_8039c49c = 0x8039c49c;
n_8039c4ac = 0x8039c4ac;
n_8039c4c4 = 0x8039c4c4;
n_8039c4f0 = 0x8039c4f0;
n_8039c510 = 0x8039c510;
n_8039c528 = 0x8039c528;
n_8039c554 = 0x8039c554;
n_8039c580 = 0x8039c580;
n_8039c5ac = 0x8039c5ac;
n_8039c5d8 = 0x8039c5d8;
n_8039c600 = 0x8039c600;
n_8039c62c = 0x8039c62c;
n_8039c648 = 0x8039c648;
n_8039c674 = 0x8039c674;
n_8039c6cc = 0x8039c6cc;
n_8039c700 = 0x8039c700;
set_801fcc48 = 0x801fcc48;
strcmp = 0x802ef234;
string_finish_8020c5c4 = 0x8020c5c4;
string_header_80341884 = 0x80341884;
string_init_8020c5c0 = 0x8020c5c0;
string_release_8020bb2c = 0x8020bb2c;
string_release_80341588 = 0x80341588;
upper_8020c2e8 = 0x8020c2e8;
SECTIONS {
  .text.d30i_command_line_parse_801280b4 0x801280b4 : { *(.text.d30i_command_line_parse_801280b4) }
  .sdata 0x804aa79c (NOLOAD) : {
    . = 0x0; ai_804aa79c = .;
    . = 0x4; ai_804aa7a0 = .;
    . = 0xbc; music_804aa858 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
