/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d25g_camera_follow_800645b8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
refresh_80064198 = 0x80064198;
show_800649e8 = 0x800649e8;
value_80178df0 = 0x80178df0;
vector_80178ec4 = 0x80178ec4;
SECTIONS {
  .text.w3d_d25g_camera_follow_800645b8 0x800645b8 : { *(.text.w3d_d25g_camera_follow_800645b8) }
  .rodata 0x80379da0 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
