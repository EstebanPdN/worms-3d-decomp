/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_empty_80343740)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_handle_storage_release = 0x802134fc;
w3d_heap_object_base_destroy_8015a39c = 0x8015a39c;
w3d_heap_release = 0x80209920;
w3d_pair_8042df94 = 0x8042df94;
w3d_service_init_801fe300 = 0x801fe300;
w3d_text_vformat_802ed5e0 = 0x802ed5e0;
SECTIONS {
  .text.w3d_empty_80343740 0x80343740 : { *(.text.w3d_empty_80343740) }
  .text.w3d_empty_80343744 0x80343744 : { *(.text.w3d_empty_80343744) }
  .text.w3d_heap_object_destroy_80343774 0x80343774 : { *(.text.w3d_heap_object_destroy_80343774) }
  .text.w3d_empty_80343808 0x80343808 : { *(.text.w3d_empty_80343808) }
  .text.w3d_empty_8034380c 0x8034380c : { *(.text.w3d_empty_8034380c) }
  .text.w3d_registry_instance_80343810 0x80343810 : { *(.text.w3d_registry_instance_80343810) }
  .text.w3d_single_slot_init_8034384c 0x8034384c : { *(.text.w3d_single_slot_init_8034384c) }
  .text.w3d_empty_80343858 0x80343858 : { *(.text.w3d_empty_80343858) }
  .text.w3d_heap_object_destroy_8034385c 0x8034385c : { *(.text.w3d_heap_object_destroy_8034385c) }
  .text.w3d_heap_object_destroy_803438fc 0x803438fc : { *(.text.w3d_heap_object_destroy_803438fc) }
  .text.w3d_pair_instance_80343994 0x80343994 : { *(.text.w3d_pair_instance_80343994) }
  .text.w3d_pointer_pair_init_80343a48 0x80343a48 : { *(.text.w3d_pointer_pair_init_80343a48) }
  .text.w3d_heap_object_destroy_80343a5c 0x80343a5c : { *(.text.w3d_heap_object_destroy_80343a5c) }
  .text.w3d_heap_object_destroy_80343aa4 0x80343aa4 : { *(.text.w3d_heap_object_destroy_80343aa4) }
  .text.w3d_text_format_80343b0c 0x80343b0c : { *(.text.w3d_text_format_80343b0c) }
  .text.w3d_record12_at_80343bb4 0x80343bb4 : { *(.text.w3d_record12_at_80343bb4) }
  .text.w3d_heap_object_destroy_80343c7c 0x80343c7c : { *(.text.w3d_heap_object_destroy_80343c7c) }
  .text.w3d_heap_object_destroy_80343d54 0x80343d54 : { *(.text.w3d_heap_object_destroy_80343d54) }
  .text.w3d_empty_80343df4 0x80343df4 : { *(.text.w3d_empty_80343df4) }
  .text.w3d_heap_object_destroy_803441d8 0x803441d8 : { *(.text.w3d_heap_object_destroy_803441d8) }
  .text.w3d_service_instance_80344278 0x80344278 : { *(.text.w3d_service_instance_80344278) }
  .text.w3d_text_format_803442b4 0x803442b4 : { *(.text.w3d_text_format_803442b4) }
  .text.w3d_empty_8034435c 0x8034435c : { *(.text.w3d_empty_8034435c) }
  .text.w3d_digits_fill_zero 0x80344360 : { *(.text.w3d_digits_fill_zero) }
  .text.w3d_heap_object_destroy_803446e8 0x803446e8 : { *(.text.w3d_heap_object_destroy_803446e8) }
  .text.w3d_heap_object_destroy_80344750 0x80344750 : { *(.text.w3d_heap_object_destroy_80344750) }
  .text.w3d_heap_object_destroy_803447d4 0x803447d4 : { *(.text.w3d_heap_object_destroy_803447d4) }
  .text.w3d_heap_object_destroy_80344858 0x80344858 : { *(.text.w3d_heap_object_destroy_80344858) }
  .sdata 0x804ad2d4 (NOLOAD) : {
    . = 0x0; w3d_registry_804ad2d4 = .;
    . = 0x4; w3d_registry_ready_804ad2d8 = .;
    . = 0x3a0; w3d_pair_ready_804ad674 = .;
    . = 0x127c; w3d_service_804ae550 = .;
    . = 0x1280; w3d_service_ready_804ae554 = .;
    . = 0x2d70; w3d_object_heap_804b0044 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
