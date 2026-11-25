/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_entity_class_destroy)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_callback_dispatch = 0x8015fc84;
w3d_entity_class_base_destroy_8020fc60 = 0x8020fc60;
w3d_input_handler_80160b7c = 0x80160b7c;
w3d_input_handler_80160cd8 = 0x80160cd8;
w3d_input_handler_80160da8 = 0x80160da8;
w3d_lookup_8020b680 = 0x8020b680;
w3d_message_allocate_801613f0 = 0x801613f0;
w3d_object_80418200 = 0x80418200;
w3d_type_8040db38 = 0x8040db38;
w3d_vtable_80411608 = 0x80411608;
w3d_vtable_80411630 = 0x80411630;
SECTIONS {
  .text.w3d_entity_class_destroy 0x80160080 : { *(.text.w3d_entity_class_destroy) }
  .text.w3d_input_owner_initialize 0x80160430 : { *(.text.w3d_input_owner_initialize) }
  .text.w3d_input_owner_poll 0x8016051c : { *(.text.w3d_input_owner_poll) }
  .text.w3d_input_key_press 0x80160558 : { *(.text.w3d_input_key_press) }
  .text.w3d_input_key_release 0x801605c0 : { *(.text.w3d_input_key_release) }
  .text.w3d_input_button_press 0x80160628 : { *(.text.w3d_input_button_press) }
  .text.w3d_input_button_release 0x80160698 : { *(.text.w3d_input_button_release) }
  .sdata 0x804b1754 (NOLOAD) : {
    . = 0x0; w3d_arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
