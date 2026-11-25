/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24c_input_post_20byte_800fa21c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
alloc_80212fd4 = 0x80212fd4;
alloc_fallback_803413d8 = 0x803413d8;
process_800fa670 = 0x800fa670;
record_vtable_804104d0 = 0x804104d0;
record_vtable_80410500 = 0x80410500;
release_802134fc = 0x802134fc;
SECTIONS {
  .text.d24c_input_post_20byte_800fa21c 0x800fa21c : { *(.text.d24c_input_post_20byte_800fa21c) }
  .sdata 0x804aaf48 (NOLOAD) : {
    . = 0x0; input_804aaf48 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
