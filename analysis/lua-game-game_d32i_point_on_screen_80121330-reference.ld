/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d32i_point_on_screen_80121330)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__3Pos = 0x80343740;
d18d_camera_view_matrix_8015aa04 = 0x8015aa04;
w3d_k5b_mtx34_from_801f74d0 = 0x801f74d0;
SECTIONS {
  .text.d32i_point_on_screen_80121330 0x80121330 : { *(.text.d32i_point_on_screen_80121330) }
  .rodata 0x8039b708 : { *(.rodata) }
  .sdata 0x804aa8c8 (NOLOAD) : {
    . = 0x0; scene_804aa8c8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
