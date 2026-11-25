/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k8a_name_grid_destroy_800b9598)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_base_destroy_8015ff2c = 0x8015ff2c;
w3d_handle_storage_release = 0x802134fc;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_release = 0x80341588;
w3d_vtable_8040f7d8 = 0x8040f7d8;
SECTIONS {
  .text.w3d_k8a_name_grid_destroy_800b9598 0x800b9598 : { *(.text.w3d_k8a_name_grid_destroy_800b9598) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
