/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24c_input_post_8byte_800f8a48)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
alloc_80212fd4 = 0x80212fd4;
alloc_fallback_803413d8 = 0x803413d8;
process_800f8dcc = 0x800f8dcc;
record_vtable_80410500 = 0x80410500;
release_802134fc = 0x802134fc;
SECTIONS {
  .text.d24c_input_post_8byte_800f8a48 0x800f8a48 : { *(.text.d24c_input_post_8byte_800f8a48) }
  .sdata 0x804aaf48 (NOLOAD) : {
    . = 0x0; input_804aaf48 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
