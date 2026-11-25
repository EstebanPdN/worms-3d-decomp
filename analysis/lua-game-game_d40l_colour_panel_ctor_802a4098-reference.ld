/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d40l_colour_panel_ctor_802a4098)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8015fef0 = 0x8015fef0;
fn_802afb20 = 0x802afb20;
fn_803426b8 = 0x803426b8;
vt_8041c470 = 0x8041c470;
vt_8041c4c0 = 0x8041c4c0;
SECTIONS {
  .text.d40l_colour_panel_ctor_802a4098 0x802a4098 : { *(.text.d40l_colour_panel_ctor_802a4098) }
  .rodata 0x803d5ffc : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
