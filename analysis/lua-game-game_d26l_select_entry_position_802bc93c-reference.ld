/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d26l_select_entry_position_802bc93c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802bc71c = 0x802bc71c;
fn_802bc778 = 0x802bc778;
fn_802bc790 = 0x802bc790;
fn_802bd2bc = 0x802bd2bc;
SECTIONS {
  .text.d26l_select_entry_position_802bc93c 0x802bc93c : { *(.text.d26l_select_entry_position_802bc93c) }
  .rodata 0x803d82e0 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
