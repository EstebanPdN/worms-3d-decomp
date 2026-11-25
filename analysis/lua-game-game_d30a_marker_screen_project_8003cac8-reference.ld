/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d30a_marker_screen_project_8003cac8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
atan2_802e7e5c = 0x802e7e5c;
s19_handle_is_one_8003cf8c = 0x8003cf8c;
w3d_auto_8003ce84 = 0x8003ce84;
w3d_auto_8003cef0 = 0x8003cef0;
w3d_auto_8003cfbc = 0x8003cfbc;
w3d_k10a_camera_near_8003cfcc = 0x8003cfcc;
SECTIONS {
  .text.w3d_d30a_marker_screen_project_8003cac8 0x8003cac8 : { *(.text.w3d_d30a_marker_screen_project_8003cac8) }
  .rodata 0x8037443c : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
