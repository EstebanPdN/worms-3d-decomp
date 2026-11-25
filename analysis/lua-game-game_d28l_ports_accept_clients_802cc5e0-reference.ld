/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d28l_ports_accept_clients_802cc5e0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__3Str = 0x803426b8;
clients_80473764 = 0x80473764;
fn_8020c5c4 = 0x8020c5c4;
fn_802cbdf8 = 0x802cbdf8;
fn_802cbe9c = 0x802cbe9c;
fn_802cc01c = 0x802cc01c;
fn_802cc0ac = 0x802cc0ac;
fn_802cce78 = 0x802cce78;
fn_802cd07c = 0x802cd07c;
fn_802cd14c = 0x802cd14c;
fn_802cd2e0 = 0x802cd2e0;
fn_80341588 = 0x80341588;
lower_803d9464 = 0x803d9464;
names_804a9d38 = 0x804a9d38;
ports_80473724 = 0x80473724;
s_803d9448 = 0x803d9448;
s_803d9460 = 0x803d9460;
strchr = 0x802ef198;
upper_803d9478 = 0x803d9478;
w_80403f94 = 0x80403f94;
w_804a9cf8 = 0x804a9cf8;
SECTIONS {
  .text.d28l_ports_accept_clients_802cc5e0 0x802cc5e0 : { *(.text.d28l_ports_accept_clients_802cc5e0) }
  .sdata 0x804abcb0 (NOLOAD) : {
    . = 0x0; line_804abcb0 = .;
    . = 0x4; line_804abcb4 = .;
    . = 0x8; line_804abcb8 = .;
    . = 0xc; line_804abcbc = .;
    . = 0x28; head_804abcd8 = .;
    . = 0x2c; tail_804abcdc = .;
    . = 0x34; open_804abce4 = .;
    . = 0x38; attached_804abce8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
