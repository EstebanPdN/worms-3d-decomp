/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k8b_pool_size_8017e030)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_80170b10 = 0x80170b10;
w3d_auto_80174520 = 0x80174520;
w3d_auto_8017f524 = 0x8017f524;
w3d_auto_8018774c = 0x8018774c;
w3d_auto_8018a7e4 = 0x8018a7e4;
w3d_null_pool_size = 0x801829bc;
w3d_pset_pool_size = 0x80183eb4;
SECTIONS {
  .text.w3d_k8b_pool_size_8017e030 0x8017e030 : { *(.text.w3d_k8b_pool_size_8017e030) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
