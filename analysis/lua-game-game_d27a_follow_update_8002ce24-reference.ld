/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d27a_follow_update_8002ce24)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
sqrt_802e82c0 = 0x802e82c0;
w3d_auto_80178df0 = 0x80178df0;
w3d_cx9c_cosf_802e86d4 = 0x802e86d4;
w3d_cx9c_sinf_802e88ac = 0x802e88ac;
SECTIONS {
  .text.w3d_d27a_follow_update_8002ce24 0x8002ce24 : { *(.text.w3d_d27a_follow_update_8002ce24) }
  .rodata 0x80372954 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
