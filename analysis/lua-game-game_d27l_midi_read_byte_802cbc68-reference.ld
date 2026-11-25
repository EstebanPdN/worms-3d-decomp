/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27l_midi_read_byte_802cbc68)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
connected_80473724 = 0x80473724;
fn_802cb314 = 0x802cb314;
fn_802ccbfc = 0x802ccbfc;
memchr = 0x802eed00;
ports_804738a4 = 0x804738a4;
SECTIONS {
  .text.d27l_midi_read_byte_802cbc68 0x802cbc68 : { *(.text.d27l_midi_read_byte_802cbc68) }
  .sdata 0x804abce4 (NOLOAD) : {
    . = 0x0; active_804abce4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
