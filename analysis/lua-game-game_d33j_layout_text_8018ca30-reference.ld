/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(build__8D33jText)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8018d660 = 0x8018d660;
fn_802eee50 = 0x802eee50;
memmove = 0x802eeef4;
w3d_cc29b_fill_text_8018d35c = 0x8018d35c;
w3d_empty_8034435c = 0x8034435c;
w3d_handle_storage_allocate = 0x80212fd4;
w3d_handle_storage_release = 0x802134fc;
w3d_k5b_array_ref_lock_801ef048 = 0x801ef048;
SECTIONS {
  .text.build__8D33jText 0x8018ca30 : { *(.text.build__8D33jText) }
  .rodata 0x803a7e34 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
