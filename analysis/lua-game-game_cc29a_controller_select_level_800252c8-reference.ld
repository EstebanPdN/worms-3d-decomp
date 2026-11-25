/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc29a_controller_select_level_800252c8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc29a_alloc_801613f0 = 0x801613f0;
cc29a_base_8015fb34 = 0x8015fb34;
cc29a_current_800255e0 = 0x800255e0;
cc29a_equals_8015f65c = 0x8015f65c;
cc29a_id_8015f5a0 = 0x8015f5a0;
cc29a_post_8016239c = 0x8016239c;
cc29a_set_8002557c = 0x8002557c;
cc29a_start_8002547c = 0x8002547c;
cc29a_table_8040db38 = 0x8040db38;
SECTIONS {
  .text.cc29a_controller_select_level_800252c8 0x800252c8 : { *(.text.cc29a_controller_select_level_800252c8) }
  .sdata 0x804aca9c (NOLOAD) : {
    . = 0x0; cc29a_cache_804aca9c = .;
    . = 0x8; cc29a_cache_804acaa4 = .;
    . = 0x10; cc29a_cache_804acaac = .;
    . = 0x18; cc29a_cache_804acab4 = .;
    . = 0x20; cc29a_cache_804acabc = .;
    . = 0x28; cc29a_cache_804acac4 = .;
    . = 0x30; cc29a_cache_804acacc = .;
    . = 0x4cb8; cc29a_allocator_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
