/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d27a_free_camera_input_8002cb6c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
s19_active_team_value_80020834 = 0x80020834;
w3d_auto_80178df0 = 0x80178df0;
w3d_camera_8002c840 = 0x8002c840;
w3d_cx9c_cosf_802e86d4 = 0x802e86d4;
w3d_cx9c_sinf_802e88ac = 0x802e88ac;
SECTIONS {
  .text.w3d_d27a_free_camera_input_8002cb6c 0x8002cb6c : { *(.text.w3d_d27a_free_camera_input_8002cb6c) }
  .rodata 0x80372948 : { *(.rodata) }
  .sdata 0x804b1760 (NOLOAD) : {
    . = 0x0; g_team_804b1760 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
