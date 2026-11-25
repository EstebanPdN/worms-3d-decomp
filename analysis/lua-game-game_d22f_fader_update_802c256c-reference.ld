/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d22f_fader_update_802c256c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_active_resource_clear_802c4380 = 0x802c4380;
w3d_auto_8015fd1c = 0x8015fd1c;
w3d_auto_80178d1c = 0x80178d1c;
w3d_mesh_set_colour_80173df0 = 0x80173df0;
w3d_panel_set_frame_80173f88 = 0x80173f88;
SECTIONS {
  .text.d22f_fader_update_802c256c 0x802c256c : { *(.text.d22f_fader_update_802c256c) }
  .rodata 0x803d8594 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
