/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx9a_storage_push_member_8002274c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
storage_allocate_80212fd4 = 0x80212fd4;
storage_copy_802eee50 = 0x802eee50;
storage_release_802134fc = 0x802134fc;
SECTIONS {
  .text.w3d_cx9a_storage_push_member_8002274c 0x8002274c : { *(.text.w3d_cx9a_storage_push_member_8002274c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
