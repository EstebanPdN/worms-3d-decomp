/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d40l_choice_panel_ctor_802a7f9c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8015fef0 = 0x8015fef0;
fn_802afb20 = 0x802afb20;
fn_803426b8 = 0x803426b8;
memset = 0x802eefe0;
vt_8041c500 = 0x8041c500;
vt_8041c550 = 0x8041c550;
SECTIONS {
  .text.d40l_choice_panel_ctor_802a7f9c 0x802a7f9c : { *(.text.d40l_choice_panel_ctor_802a7f9c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
