/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_stats_clear_counts_80109ae4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_8016293c = 0x8016293c;
w3d_ctor_801628b0 = 0x801628b0;
w3d_empty_8010a850 = 0x8010a850;
w3d_obj_804107b8 = 0x804107b8;
w3d_service_destroy_801628ec = 0x801628ec;
SECTIONS {
  .text.w3d_stats_clear_counts_80109ae4 0x80109ae4 : { *(.text.w3d_stats_clear_counts_80109ae4) }
  .text.w3d_small_service_construct_8010a740 0x8010a740 : { *(.text.w3d_small_service_construct_8010a740) }
  .text.w3d_small_service_destroy_8010a784 0x8010a784 : { *(.text.w3d_small_service_destroy_8010a784) }
  .text.w3d_small_service_dispatch_8010a7e4 0x8010a7e4 : { *(.text.w3d_small_service_dispatch_8010a7e4) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
