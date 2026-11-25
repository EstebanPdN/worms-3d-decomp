/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k8a_detail_set_release_800b8e50)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_fn_800600d4 = 0x800600d4;
w3d_memcpy_802eee50 = 0x802eee50;
SECTIONS {
  .text.w3d_k8a_detail_set_release_800b8e50 0x800b8e50 : { *(.text.w3d_k8a_detail_set_release_800b8e50) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
