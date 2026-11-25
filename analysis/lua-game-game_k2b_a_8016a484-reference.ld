/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k2b_set_blend_mode_8016a484)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_gx_set_mode_8030ba64 = 0x8030ba64;
w3d_table_803a552c = 0x803a552c;
SECTIONS {
  .text.w3d_k2b_set_blend_mode_8016a484 0x8016a484 : { *(.text.w3d_k2b_set_blend_mode_8016a484) }
  .sdata 0x804ab51c (NOLOAD) : {
    . = 0x0; w3d_global_804ab51c = .;
    . = 0x4; w3d_global_804ab520 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
