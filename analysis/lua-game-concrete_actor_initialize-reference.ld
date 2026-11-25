/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_concrete_actor_initialize)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
constructor_default_vector = 0x8045e788;
constructor_land_name = 0x803a0a6c;
constructor_optional_initialize = 0x801410f8;
w3d_actor_base_initialize = 0x80161014;
w3d_actor_handle_member_initialize = 0x80126184;
w3d_actor_handle_member_set_bounds = 0x80126278;
w3d_actor_handle_member_set_slot_word = 0x801262e4;
w3d_actor_handle_member_set_word = 0x8012632c;
w3d_actor_method_member_initialize = 0x801181bc;
w3d_actor_reset_construction_words = 0x8015286c;
w3d_concrete_actor_methods = 0x80410f00;
w3d_constructor_lookup_name = 0x800fc1b0;
w3d_constructor_native_cast = 0x80342a78;
SECTIONS {
  .text.w3d_concrete_actor_initialize 0x80141d68 : { *(.text.w3d_concrete_actor_initialize) }
  .rodata 0x803a0a80 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
