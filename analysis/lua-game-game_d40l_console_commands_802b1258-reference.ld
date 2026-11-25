/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d40l_console_commands_802b1258)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__2IdRC3Str = 0x8015f69c;
__3Str = 0x803426b8;
__3StrPCc = 0x8020bb54;
atof = 0x802ed878;
atoi = 0x802ed89c;
fn_80069a0c = 0x80069a0c;
fn_800a82f0 = 0x800a82f0;
fn_8010a8e0 = 0x8010a8e0;
fn_8015f558 = 0x8015f558;
fn_8015f5a0 = 0x8015f5a0;
fn_801613f0 = 0x801613f0;
fn_8016239c = 0x8016239c;
fn_8020bb2c = 0x8020bb2c;
fn_8020bd38 = 0x8020bd38;
fn_8020c3a0 = 0x8020c3a0;
fn_8020c5c4 = 0x8020c5c4;
fn_80341588 = 0x80341588;
s_803d7a1c = 0x803d7a1c;
strcspn = 0x802ef380;
table_8040db38 = 0x8040db38;
SECTIONS {
  .text.d40l_console_commands_802b1258 0x802b1258 : { *(.text.d40l_console_commands_802b1258) }
  .sdata 0x804abc64 (NOLOAD) : {
    . = 0x0; separators_804abc64 = .;
    . = 0x5af0; arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
