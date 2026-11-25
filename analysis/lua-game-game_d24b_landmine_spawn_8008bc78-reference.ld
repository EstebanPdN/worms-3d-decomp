/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24b_landmine_spawn_8008bc78)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_allocate_80212fd4 = 0x80212fd4;
w3d_as_weapon_801797b4 = 0x801797b4;
w3d_assign_interface_800eb65c = 0x800eb65c;
w3d_copy12_800eb8d0 = 0x800eb8d0;
w3d_copy_802eee50 = 0x802eee50;
w3d_float_value_80178df0 = 0x80178df0;
w3d_identity_80341584 = 0x80341584;
w3d_identity_80342a74 = 0x80342a74;
w3d_identity_80342a78 = 0x80342a78;
w3d_int_value_80178d1c = 0x80178d1c;
w3d_random_80162bc8 = 0x80162bc8;
w3d_register_80164514 = 0x80164514;
w3d_release_802134fc = 0x802134fc;
w3d_resource_property_800fc1b0 = 0x800fc1b0;
w3d_service_forward_8020b680 = 0x8020b680;
w3d_set_value_80178d28 = 0x80178d28;
w3d_string_8037d1d4 = 0x8037d1d4;
w3d_type_8040fd78 = 0x8040fd78;
SECTIONS {
  .text.w3d_d24b_landmine_spawn_8008bc78 0x8008bc78 : { *(.text.w3d_d24b_landmine_spawn_8008bc78) }
  .rodata 0x8037deb0 : { *(.rodata) }
  .sdata 0x804b178c (NOLOAD) : {
    . = 0x0; w3d_manager_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
