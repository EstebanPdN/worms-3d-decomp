/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d42l_list_panel_update_802b5fd8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d28l_panel_update_802b0668 = 0x802b0668;
fn_802b929c = 0x802b929c;
fn_802c0064 = 0x802c0064;
s11_current_context_802b264c = 0x802b264c;
w3d_auto_80296410 = 0x80296410;
w3d_auto_802bc790 = 0x802bc790;
SECTIONS {
  .text.d42l_list_panel_update_802b5fd8 0x802b5fd8 : { *(.text.d42l_list_panel_update_802b5fd8) }
  .rodata 0x803d7f50 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
