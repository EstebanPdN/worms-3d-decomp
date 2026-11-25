/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d40l_button_layout_802bd8cc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80178df0 = 0x80178df0;
fn_802bd354 = 0x802bd354;
fn_802bf81c = 0x802bf81c;
fn_802bfc64 = 0x802bfc64;
SECTIONS {
  .text.d40l_button_layout_802bd8cc 0x802bd8cc : { *(.text.d40l_button_layout_802bd8cc) }
  .rodata 0x803d8398 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
