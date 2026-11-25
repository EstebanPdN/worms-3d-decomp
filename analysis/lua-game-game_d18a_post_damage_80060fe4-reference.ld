/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d18a_post_damage_80060fe4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d18a_apply_point_800eca14 = 0x800eca14;
d18a_body_state_801797b4 = 0x801797b4;
d18a_damage_message_800666b4 = 0x800666b4;
d18a_forward_point_800e5ca4 = 0x800e5ca4;
d18a_handle_cast_80341584 = 0x80341584;
d18a_handle_float_80178df0 = 0x80178df0;
d18a_message_alloc_801613f0 = 0x801613f0;
d18a_post_current_8016239c = 0x8016239c;
d18a_update_800eb6e4 = 0x800eb6e4;
SECTIONS {
  .text.w3d_d18a_post_damage_80060fe4 0x80060fe4 : { *(.text.w3d_d18a_post_damage_80060fe4) }
  .rodata 0x80379294 : { *(.rodata) }
  .sdata 0x804b1754 (NOLOAD) : {
    . = 0x0; d18a_queue_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
