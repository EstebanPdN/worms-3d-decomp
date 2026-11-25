/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d26l_panel_ctor_b_802b5524)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8015fef0 = 0x8015fef0;
fn_802afb20 = 0x802afb20;
vt_8041c740 = 0x8041c740;
vt_8041c790 = 0x8041c790;
SECTIONS {
  .text.d26l_panel_ctor_b_802b5524 0x802b5524 : { *(.text.d26l_panel_ctor_b_802b5524) }
  .rodata 0x803d7f34 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
