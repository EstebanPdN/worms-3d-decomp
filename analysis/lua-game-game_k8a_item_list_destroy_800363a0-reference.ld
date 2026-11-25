/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k8a_item_list_destroy_800363a0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_80036a94 = 0x80036a94;
w3d_handle_storage_release = 0x802134fc;
w3d_heap_release = 0x80209920;
w3d_memcpy_802eee50 = 0x802eee50;
SECTIONS {
  .text.w3d_k8a_item_list_destroy_800363a0 0x800363a0 : { *(.text.w3d_k8a_item_list_destroy_800363a0) }
  .sdata 0x804b0044 (NOLOAD) : {
    . = 0x0; w3d_heap_804b0044 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
