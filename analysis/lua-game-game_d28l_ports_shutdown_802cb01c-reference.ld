/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d28l_ports_shutdown_802cb01c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__3Str = 0x803426b8;
clients_80473764 = 0x80473764;
clients_804738e4 = 0x804738e4;
fn_8020c5c4 = 0x8020c5c4;
fn_802cbdf8 = 0x802cbdf8;
fn_802cc01c = 0x802cc01c;
fn_802cc0ac = 0x802cc0ac;
fn_802cd07c = 0x802cd07c;
fn_802cd0c8 = 0x802cd0c8;
fn_802cd14c = 0x802cd14c;
fn_802cd198 = 0x802cd198;
fn_80341588 = 0x80341588;
ports_80473724 = 0x80473724;
ports_804738a4 = 0x804738a4;
w_80403f94 = 0x80403f94;
w_804a9cf8 = 0x804a9cf8;
SECTIONS {
  .text.d28l_ports_shutdown_802cb01c 0x802cb01c : { *(.text.d28l_ports_shutdown_802cb01c) }
  .sdata 0x804abcb0 (NOLOAD) : {
    . = 0x0; line_804abcb0 = .;
    . = 0x4; line_804abcb4 = .;
    . = 0x8; line_804abcb8 = .;
    . = 0xc; line_804abcbc = .;
    . = 0x34; open_804abce4 = .;
    . = 0x5400; listener_804b10b0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
