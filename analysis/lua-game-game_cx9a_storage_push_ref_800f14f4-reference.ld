/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx9a_storage_push_ref_800f14f4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
storage_allocate_80212fd4 = 0x80212fd4;
storage_copy_802eee50 = 0x802eee50;
storage_release_802134fc = 0x802134fc;
SECTIONS {
  .text.w3d_cx9a_storage_push_ref_800f14f4 0x800f14f4 : { *(.text.w3d_cx9a_storage_push_ref_800f14f4) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
