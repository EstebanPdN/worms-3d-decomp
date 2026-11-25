/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d25f_node_scene_setup_8028a900)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__10D25fStringPCc = 0x8020bb54;
lbl_8045e788 = 0x8045e788;
w3d_handle_set_name_8015adf4 = 0x8015adf4;
w3d_string_finish_8020c5c4 = 0x8020c5c4;
w3d_string_release_80341588 = 0x80341588;
SECTIONS {
  .text.d25f_node_scene_setup_8028a900 0x8028a900 : { *(.text.d25f_node_scene_setup_8028a900) }
  .rodata 0x803cfb6c : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
