/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d29f_border_view_setup_8028a784)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d10b_rebuild_layout_802b3d04 = 0x802b3d04;
d25f_node_scene_setup_8028a900 = 0x8028a900;
fn_80164514 = 0x80164514;
lbl_803cfb54 = 0x803cfb54;
lbl_803cfb68 = 0x803cfb68;
lbl_8041c660 = 0x8041c660;
w3d_auto_80178df0 = 0x80178df0;
w3d_auto_802b30c0 = 0x802b30c0;
w3d_auto_802b310c = 0x802b310c;
w3d_constructor_lookup_name = 0x800fc1b0;
w3d_cx12b_child_view_initialize_802b3c5c = 0x802b3c5c;
w3d_empty_80342a74 = 0x80342a74;
w3d_s10_service_forward_8020b680 = 0x8020b680;
w3d_set_triple_802b3020 = 0x802b3020;
SECTIONS {
  .text.d29f_border_view_setup_8028a784 0x8028a784 : { *(.text.d29f_border_view_setup_8028a784) }
  .sdata 0x804abb60 (NOLOAD) : {
    . = 0x0; lbl_804abb60 = .;
    . = 0x5c2c; lbl_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
