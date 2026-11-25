/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d26l_panel_ctor_8029dd4c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8015fef0 = 0x8015fef0;
fn_802109dc = 0x802109dc;
fn_802afb20 = 0x802afb20;
vt_8041c2b0 = 0x8041c2b0;
vt_8041c300 = 0x8041c300;
SECTIONS {
  .text.d26l_panel_ctor_8029dd4c 0x8029dd4c : { *(.text.d26l_panel_ctor_8029dd4c) }
  .rodata 0x803d1cf8 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
