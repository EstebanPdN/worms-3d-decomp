/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(g1p_choice_tick_802a49d0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802a62bc = 0x802a62bc;
fn_802a64a8 = 0x802a64a8;
fn_802a6878 = 0x802a6878;
fn_802a6ce8 = 0x802a6ce8;
fn_802a75ec = 0x802a75ec;
fn_802a77a4 = 0x802a77a4;
fn_802b0668 = 0x802b0668;
SECTIONS {
  .text.g1p_choice_tick_802a49d0 0x802a49d0 : { *(.text.g1p_choice_tick_802a49d0) }
  .rodata 0x803d6004 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
