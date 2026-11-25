/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx9a_storage_push_global_8001634c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
storage_allocate_80212fd4 = 0x80212fd4;
storage_copy_802eee50 = 0x802eee50;
storage_release_802134fc = 0x802134fc;
SECTIONS {
  .text.w3d_cx9a_storage_push_global_8001634c 0x8001634c : { *(.text.w3d_cx9a_storage_push_global_8001634c) }
  .sdata 0x804aa6f8 (NOLOAD) : {
    . = 0x0; storage_804aa6f8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
