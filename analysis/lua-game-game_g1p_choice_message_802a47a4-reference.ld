/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(g1p_choice_message_802a47a4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8015f65c = 0x8015f65c;
fn_8015fb34 = 0x8015fb34;
fn_802a4cbc = 0x802a4cbc;
fn_802a4f98 = 0x802a4f98;
fn_802a6e3c = 0x802a6e3c;
fn_802a6ee4 = 0x802a6ee4;
fn_802a7980 = 0x802a7980;
fn_802a7998 = 0x802a7998;
fn_802aff9c = 0x802aff9c;
fn_802b1258 = 0x802b1258;
fn_802b22b0 = 0x802b22b0;
fn_802b264c = 0x802b264c;
SECTIONS {
  .text.g1p_choice_message_802a47a4 0x802a47a4 : { *(.text.g1p_choice_message_802a47a4) }
  .sdata 0x804abb48 (NOLOAD) : {
    . = 0x0; global_804abb48 = .;
    . = 0x5380; cache_804b0ec8 = .;
    . = 0x5388; cache_804b0ed0 = .;
    . = 0x5390; cache_804b0ed8 = .;
    . = 0x5398; cache_804b0ee0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
