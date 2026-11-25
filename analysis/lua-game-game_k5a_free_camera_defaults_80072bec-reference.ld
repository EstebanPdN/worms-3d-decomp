/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(k5a_free_camera_defaults_80072bec)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_800fc270 = 0x800fc270;
w3d_f32_8037cd6c = 0x8037cd6c;
w3d_f32_8037cd70 = 0x8037cd70;
w3d_f32_8037cd74 = 0x8037cd74;
w3d_f32_8037cd78 = 0x8037cd78;
w3d_f32_8037cd7c = 0x8037cd7c;
w3d_string_8037cd38 = 0x8037cd38;
w3d_string_8037cd50 = 0x8037cd50;
SECTIONS {
  .text.k5a_free_camera_defaults_80072bec 0x80072bec : { *(.text.k5a_free_camera_defaults_80072bec) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
