/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k2b_apply_cull_mode_8016c718)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_gx_prepare_8016c338 = 0x8016c338;
w3d_gx_set_cull_mode_8016a1e8 = 0x8016a1e8;
SECTIONS {
  .text.w3d_k2b_apply_cull_mode_8016c718 0x8016c718 : { *(.text.w3d_k2b_apply_cull_mode_8016c718) }
  .sdata 0x804b1884 (NOLOAD) : {
    . = 0x0; w3d_global_804b1884 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
