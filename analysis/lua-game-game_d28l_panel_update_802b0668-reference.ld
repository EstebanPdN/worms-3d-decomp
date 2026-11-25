/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d28l_panel_update_802b0668)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80181ccc = 0x80181ccc;
fn_80181d00 = 0x80181d00;
fn_802b1cec = 0x802b1cec;
fn_802b2164 = 0x802b2164;
fn_802b22e4 = 0x802b22e4;
fn_802b24bc = 0x802b24bc;
fn_80343584 = 0x80343584;
SECTIONS {
  .text.d28l_panel_update_802b0668 0x802b0668 : { *(.text.d28l_panel_update_802b0668) }
  .rodata 0x803d79c4 : { *(.rodata) }
  .sdata 0x804abb5c (NOLOAD) : {
    . = 0x0; current_804abb5c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
