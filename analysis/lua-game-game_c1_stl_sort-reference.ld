/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_stl_forward_80353c78)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_fn_80353b9c = 0x80353b9c;
w3d_fn_80353d1c = 0x80353d1c;
w3d_fn_80353f70 = 0x80353f70;
w3d_fn_80354264 = 0x80354264;
w3d_fn_80354408 = 0x80354408;
w3d_fn_803546b4 = 0x803546b4;
w3d_fn_803549a8 = 0x803549a8;
w3d_fn_80354b4c = 0x80354b4c;
w3d_fn_80354df8 = 0x80354df8;
SECTIONS {
  .text.w3d_stl_forward_80353c78 0x80353c78 : { *(.text.w3d_stl_forward_80353c78) }
  .text.w3d_stl_sort_80353ff0 0x80353ff0 : { *(.text.w3d_stl_sort_80353ff0) }
  .text.w3d_stl_forward_8035434c 0x8035434c : { *(.text.w3d_stl_forward_8035434c) }
  .text.w3d_stl_sort_80354734 0x80354734 : { *(.text.w3d_stl_sort_80354734) }
  .text.w3d_stl_forward_80354a90 0x80354a90 : { *(.text.w3d_stl_forward_80354a90) }
  .text.w3d_stl_sort_80354e78 0x80354e78 : { *(.text.w3d_stl_sort_80354e78) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
