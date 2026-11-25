/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d22a_weapon_physics_8003e030)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_cached_message_id_8015f5a0 = 0x8015f5a0;
w3d_identity_80342a74 = 0x80342a74;
w3d_resource_property_800fc1b0 = 0x800fc1b0;
w3d_string_80374628 = 0x80374628;
w3d_string_80374630 = 0x80374630;
w3d_string_80374648 = 0x80374648;
w3d_subscribe_80162024 = 0x80162024;
SECTIONS {
  .text.w3d_d22a_weapon_physics_8003e030 0x8003e030 : { *(.text.w3d_d22a_weapon_physics_8003e030) }
  .sdata 0x804ad1b4 (NOLOAD) : {
    . = 0x0; w3d_message_804ad1b4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
