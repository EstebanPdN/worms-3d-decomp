/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(g4a_detail_registry_clear_800bb3a0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
copy_802eee50 = 0x802eee50;
destroy_800b12f0 = 0x800b12f0;
range_8043bb64 = 0x8043bb64;
release_800b8e50 = 0x800b8e50;
release_80209920 = 0x80209920;
SECTIONS {
  .text.g4a_detail_registry_clear_800bb3a0 0x800bb3a0 : { *(.text.g4a_detail_registry_clear_800bb3a0) }
  .sdata 0x804adde4 (NOLOAD) : {
    . = 0x0; heap_804adde4 = .;
    . = 0x3a48; block_804b182c = .;
    . = 0x3a4c; block_804b1830 = .;
    . = 0x3a50; block_804b1834 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
