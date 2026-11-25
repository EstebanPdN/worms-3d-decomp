/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(k5a_fall_camera_enter_80071d28)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_80035714 = 0x80035714;
FUN_801613f0 = 0x801613f0;
s8_property_write_800fc43c = 0x800fc43c;
w3d_auto_8015fc58 = 0x8015fc58;
w3d_auto_801797b4 = 0x801797b4;
w3d_cached_message_id = 0x8015f5a0;
w3d_empty_80341584 = 0x80341584;
w3d_engine_get_context = 0x80165254;
w3d_f32_8037caf4 = 0x8037caf4;
w3d_message_post_current = 0x8016239c;
w3d_message_string_init = 0x8010a8e0;
w3d_string_8037ca78 = 0x8037ca78;
w3d_string_8037cad4 = 0x8037cad4;
w3d_string_8037caec = 0x8037caec;
w3d_vtable_8040db38 = 0x8040db38;
SECTIONS {
  .text.k5a_fall_camera_enter_80071d28 0x80071d28 : { *(.text.k5a_fall_camera_enter_80071d28) }
  .sdata 0x804aa8c8 (NOLOAD) : {
    . = 0x0; w3d_camera_set_804aa8c8 = .;
    . = 0x306c; w3d_message_804ad934 = .;
    . = 0x3074; w3d_message_804ad93c = .;
    . = 0x6e8c; w3d_message_pool_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
