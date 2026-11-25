/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d43p_hud_build_backing_8011a5c8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_empty_8034380c = 0x8034380c;
w3d_fn_8018920c = 0x8018920c;
w3d_fn_80189450 = 0x80189450;
w3d_fn_80189518 = 0x80189518;
w3d_fn_8018963c = 0x8018963c;
w3d_fn_80189828 = 0x80189828;
w3d_fn_80189884 = 0x80189884;
w3d_fn_801898e0 = 0x801898e0;
SECTIONS {
  .text.w3d_d43p_hud_build_backing_8011a5c8 0x8011a5c8 : { *(.text.w3d_d43p_hud_build_backing_8011a5c8) }
  .rodata 0x8039add0 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
