/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d43l_console_channel_pump_802cb314)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_S_oom_malloc__Q24_STLt14__malloc_alloc1i0Ui = 0x803413d8;
__3StrPCc = 0x8020bb54;
a_80403f94 = 0x80403f94;
b_804a9cf8 = 0x804a9cf8;
buf_80473924 = 0x80473924;
fn_8020c5c0 = 0x8020c5c0;
fn_8020c5c4 = 0x8020c5c4;
fn_802cbdf8 = 0x802cbdf8;
fn_802cc0ac = 0x802cc0ac;
fn_802cc3d0 = 0x802cc3d0;
fn_80341588 = 0x80341588;
fn_80341884 = 0x80341884;
fn_803426b8 = 0x803426b8;
free = 0x802134fc;
in_80473724 = 0x80473724;
lines_804737a4 = 0x804737a4;
malloc = 0x80212fd4;
memchr = 0x802eed00;
memcpy = 0x802eee50;
nl_803d9178 = 0x803d9178;
out_804738a4 = 0x804738a4;
ping_80473764 = 0x80473764;
strlen = 0x802ef9c0;
SECTIONS {
  .text.d43l_console_channel_pump_802cb314 0x802cb314 : { *(.text.d43l_console_channel_pump_802cb314) }
  .sdata 0x804abcc8 (NOLOAD) : {
    . = 0x0; t_804abcc8 = .;
    . = 0x4; t_804abccc = .;
    . = 0x8; t_804abcd0 = .;
    . = 0x1c; on_804abce4 = .;
    . = 0x20; dirty_804abce8 = .;
    . = 0x24; tick_804abcec = .;
    . = 0x28; count_804abcf0 = .;
    . = 0x5c98; ping_804b1960 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
