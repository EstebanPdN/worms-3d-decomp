/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d27e_zoom_image_801d6ca8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
g3c_allocate_80213c30 = 0x80213c30;
read_column_801d6888 = 0x801d6888;
read_row_801d68e0 = 0x801d68e0;
w3d_auto_801d67e4 = 0x801d67e4;
w3d_auto_801d6850 = 0x801d6850;
w3d_cx9c_ceilf_802e85fc = 0x802e85fc;
w3d_cx9c_floorf_802e87d4 = 0x802e87d4;
w3d_handle_storage_release_802134fc = 0x802134fc;
write_pixel_801d6940 = 0x801d6940;
SECTIONS {
  .text.w3d_d27e_zoom_image_801d6ca8 0x801d6ca8 : { *(.text.w3d_d27e_zoom_image_801d6ca8) }
  .rodata 0x803af6b0 : { *(.rodata) }
  .sdata 0x804b0550 (NOLOAD) : {
    . = 0x0; contrib_804b0550 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
