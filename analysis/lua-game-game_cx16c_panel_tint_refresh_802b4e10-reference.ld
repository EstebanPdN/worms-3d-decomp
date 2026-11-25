/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx16c_panel_tint_refresh_802b4e10)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cx16c_color_view_8034357c = 0x8034357c;
cx16c_refresh_802b4d58 = 0x802b4d58;
cx16c_set_color_80173df0 = 0x80173df0;
SECTIONS {
  .text.w3d_cx16c_panel_tint_refresh_802b4e10 0x802b4e10 : { *(.text.w3d_cx16c_panel_tint_refresh_802b4e10) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
