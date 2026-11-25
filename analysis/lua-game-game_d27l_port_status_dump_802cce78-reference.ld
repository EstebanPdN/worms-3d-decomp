/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27l_port_status_dump_802cce78)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__3Str = 0x803426b8;
connected_80473724 = 0x80473724;
fn_8020c510 = 0x8020c510;
fn_8020c5c4 = 0x8020c5c4;
fn_802cc0ac = 0x802cc0ac;
fn_802cd128 = 0x802cd128;
fn_802cd220 = 0x802cd220;
fn_80341588 = 0x80341588;
header_80403f7c = 0x80403f7c;
names_804a9d38 = 0x804a9d38;
s_803d9460 = 0x803d9460;
s_803d948c = 0x803d948c;
s_803d94ac = 0x803d94ac;
s_803d94b8 = 0x803d94b8;
SECTIONS {
  .text.d27l_port_status_dump_802cce78 0x802cce78 : { *(.text.d27l_port_status_dump_802cce78) }
  .sdata 0x804abcc0 (NOLOAD) : {
    . = 0x0; footer_804abcc0 = .;
    . = 0x24; active_804abce4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
