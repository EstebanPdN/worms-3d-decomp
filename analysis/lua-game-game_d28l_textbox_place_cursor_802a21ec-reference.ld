/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d28l_textbox_place_cursor_802a21ec)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
aligns_80401c50 = 0x80401c50;
fn_80173df0 = 0x80173df0;
fn_8018c8bc = 0x8018c8bc;
fn_8018c938 = 0x8018c938;
fn_802a2524 = 0x802a2524;
fn_802b1880 = 0x802b1880;
SECTIONS {
  .text.d28l_textbox_place_cursor_802a21ec 0x802a21ec : { *(.text.d28l_textbox_place_cursor_802a21ec) }
  .rodata 0x803d1f8c : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
