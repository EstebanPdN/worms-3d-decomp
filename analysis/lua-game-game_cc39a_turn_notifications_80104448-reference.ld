/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc39a_turn_notifications_80104448)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc39a_active_803995e8 = 0x803995e8;
cc39a_allocate_801613f0 = 0x801613f0;
cc39a_firstAction_8002addc = 0x8002addc;
cc39a_id_8015f5a0 = 0x8015f5a0;
cc39a_initInt_800a82f0 = 0x800a82f0;
cc39a_post_8016239c = 0x8016239c;
cc39a_property_800fc1f0 = 0x800fc1f0;
cc39a_secondAction_8002ae70 = 0x8002ae70;
cc39a_vtable_8040db38 = 0x8040db38;
SECTIONS {
  .text.cc39a_turn_notifications_80104448 0x80104448 : { *(.text.cc39a_turn_notifications_80104448) }
  .sdata 0x804af1b0 (NOLOAD) : {
    . = 0x0; cc39a_first_804af1b0 = .;
    . = 0x10; cc39a_second_804af1c0 = .;
    . = 0x18; cc39a_worm_804af1c8 = .;
    . = 0x20; cc39a_third_804af1d0 = .;
    . = 0x25a4; cc39a_allocator_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
