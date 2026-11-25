/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24d_acquire_message_80162024)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d24d_class_a_80361860 = 0x80361860;
d24d_class_b_803617d0 = 0x803617d0;
d24d_class_c_803618f0 = 0x803618f0;
d24d_free_pool_80455244 = 0x80455244;
d24d_storage_allocate_80212fd4 = 0x80212fd4;
d24d_storage_release_802134fc = 0x802134fc;
memcpy = 0x802eee50;
SECTIONS {
  .text.d24d_acquire_message_80162024 0x80162024 : { *(.text.d24d_acquire_message_80162024) }
  .sdata 0x804ab4b0 (NOLOAD) : {
    . = 0x0; d24d_lists_c_804ab4b0 = .;
    . = 0x4; d24d_lists_a_804ab4b4 = .;
    . = 0x8; d24d_lists_b_804ab4b8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
