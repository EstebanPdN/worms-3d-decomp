/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc21b_field_manager_sinit_8020797c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc21b_arena_ctor_802097ec = 0x802097ec;
cc21b_descriptor_8045ee24 = 0x8045ee24;
cc21b_descriptor_ctor_8020fbd0 = 0x8020fbd0;
cc21b_factory_80206d54 = 0x80206d54;
cc21b_name_803b2c90 = 0x803b2c90;
cc21b_name_803b2ca8 = 0x803b2ca8;
cc21b_name_803ea1f4 = 0x803ea1f4;
cc21b_vtable_80411ad8 = 0x80411ad8;
cc21b_vtable_80419598 = 0x80419598;
SECTIONS {
  .text.w3d_cc21b_field_manager_sinit_8020797c 0x8020797c : { *(.text.w3d_cc21b_field_manager_sinit_8020797c) }
  .sdata 0x804b0644 (NOLOAD) : {
    . = 0x0; cc21b_arena_804b0644 = .;
    . = 0x8; cc21b_arena_804b064c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
