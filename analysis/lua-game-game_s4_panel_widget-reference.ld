/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s4_panel_destroy)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_base_destroy_8015ff2c = 0x8015ff2c;
w3d_control_destroy_802afc40 = 0x802afc40;
w3d_control_reset_802b0fec = 0x802b0fec;
w3d_label_destroy_8025e0c4 = 0x8025e0c4;
w3d_vtable_8041c3e0 = 0x8041c3e0;
w3d_vtable_8041c430 = 0x8041c430;
SECTIONS {
  .text.w3d_s4_panel_destroy 0x802a2eb8 : { *(.text.w3d_s4_panel_destroy) }
  .text.w3d_s4_panel_reset 0x802a30b0 : { *(.text.w3d_s4_panel_reset) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
