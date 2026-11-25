/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d30a_collect_named_80015960)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__builtin_delete = 0x801fe1f8;
__builtin_new = 0x801fe1d8;
g_groups_8043bb64 = 0x8043bb64;
memcpy_802eee50 = 0x802eee50;
strcmp = 0x802ef234;
w3d_handle_storage_allocate = 0x80212fd4;
w3d_handle_storage_release = 0x802134fc;
SECTIONS {
  .text.w3d_d30a_collect_named_80015960 0x80015960 : { *(.text.w3d_d30a_collect_named_80015960) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
