/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d29a_camera_shutdown_80035388)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
memcpy_802eee50 = 0x802eee50;
SECTIONS {
  .text.w3d_d29a_camera_shutdown_80035388 0x80035388 : { *(.text.w3d_d29a_camera_shutdown_80035388) }
  .sdata 0x804aa8c8 (NOLOAD) : {
    . = 0x0; g_active_804aa8c8 = .;
    . = 0x6ec0; g_engine_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
