/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k8a_block_list_clear_8009c758)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_800e5bb8 = 0x800e5bb8;
w3d_heap_release = 0x80209920;
w3d_memcpy_802eee50 = 0x802eee50;
SECTIONS {
  .text.w3d_k8a_block_list_clear_8009c758 0x8009c758 : { *(.text.w3d_k8a_block_list_clear_8009c758) }
  .sdata 0x804aabe8 (NOLOAD) : {
    . = 0x0; w3d_global_804aabe8 = .;
    . = 0x49d4; w3d_heap_804af5bc = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
