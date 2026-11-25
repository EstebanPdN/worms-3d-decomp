/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_grid_render_layers_8010d8a4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
memset = 0x802eefe0;
w3d_auto_8010cbcc = 0x8010cbcc;
w3d_auto_8010cc3c = 0x8010cc3c;
w3d_auto_8010d7c4 = 0x8010d7c4;
w3d_auto_8010d834 = 0x8010d834;
w3d_grid_contour_8010b894 = 0x8010b894;
w3d_grid_contour_8010bb1c = 0x8010bb1c;
w3d_obj_8044c6ec = 0x8044c6ec;
w3d_obj_8044c86c = 0x8044c86c;
SECTIONS {
  .text.w3d_grid_render_layers_8010d8a4 0x8010d8a4 : { *(.text.w3d_grid_render_layers_8010d8a4) }
  .sdata 0x804af2ac (NOLOAD) : {
    . = 0x0; w3d_obj_804af2ac = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
