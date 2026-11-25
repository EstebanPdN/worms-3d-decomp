/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_char_to_lower)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_actor_member_delete_backend = 0x801fe1f8;
w3d_char_class_803db449 = 0x803db449;
w3d_operator_delete_80015264 = 0x80015264;
w3d_service_request_802f06c8 = 0x802f06c8;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_release = 0x80341588;
SECTIONS {
  .text.w3d_char_to_lower 0x80341260 : { *(.text.w3d_char_to_lower) }
  .text.w3d_service_request_8034127c 0x8034127c : { *(.text.w3d_service_request_8034127c) }
  .text.w3d_empty_80341348 0x80341348 : { *(.text.w3d_empty_80341348) }
  .text.w3d_vector_clear_8034134c 0x8034134c : { *(.text.w3d_vector_clear_8034134c) }
  .text.w3d_range_limits_reset 0x8034141c : { *(.text.w3d_range_limits_reset) }
  .text.w3d_empty_80341448 0x80341448 : { *(.text.w3d_empty_80341448) }
  .text.w3d_empty_8034144c 0x8034144c : { *(.text.w3d_empty_8034144c) }
  .text.w3d_vector_destroy_virtual16 0x80341450 : { *(.text.w3d_vector_destroy_virtual16) }
  .text.w3d_vector_destroy_virtual12 0x803414b4 : { *(.text.w3d_vector_destroy_virtual12) }
  .text.w3d_vector_destroy_named 0x80341518 : { *(.text.w3d_vector_destroy_named) }
  .text.w3d_empty_80341584 0x80341584 : { *(.text.w3d_empty_80341584) }
  .sdata 0x804ac570 (NOLOAD) : {
    . = 0x0; w3d_service_holder_804ac570 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
