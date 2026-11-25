/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d26c_find_named_item_800d7318)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6StringPCc = 0x8020bb54;
groups_8043bb64 = 0x8043bb64;
memcpy = 0x802eee50;
storage_alloc_80212fd4 = 0x80212fd4;
storage_free_802134fc = 0x802134fc;
strcmp = 0x802ef234;
string_finish_8020c5c4 = 0x8020c5c4;
string_release_80341588 = 0x80341588;
SECTIONS {
  .text.d26c_find_named_item_800d7318 0x800d7318 : { *(.text.d26c_find_named_item_800d7318) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
