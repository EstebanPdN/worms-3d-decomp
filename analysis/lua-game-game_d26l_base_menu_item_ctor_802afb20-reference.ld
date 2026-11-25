/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d26l_base_menu_item_ctor_802afb20)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__3Str = 0x803426b8;
fn_800fc1b0 = 0x800fc1b0;
fn_802aff04 = 0x802aff04;
vt_8041c610 = 0x8041c610;
SECTIONS {
  .text.d26l_base_menu_item_ctor_802afb20 0x802afb20 : { *(.text.d26l_base_menu_item_ctor_802afb20) }
  .rodata 0x803d79a4 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
