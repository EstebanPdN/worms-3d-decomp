/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc35a_controller_routes_8009723c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc35a_cast_803426b4 = 0x803426b4;
cc35a_cast_80342fa4 = 0x80342fa4;
cc35a_equal_8015f620 = 0x8015f620;
cc35a_get_8020b680 = 0x8020b680;
cc35a_handle_801190d0 = 0x801190d0;
cc35a_key_8037f508 = 0x8037f508;
cc35a_lookup_80164fc8 = 0x80164fc8;
cc35a_mode_8004eae4 = 0x8004eae4;
cc35a_read_800fc1f0 = 0x800fc1f0;
cc35a_route_80164514 = 0x80164514;
cc35a_type_8040dfb8 = 0x8040dfb8;
cc35a_type_8040e420 = 0x8040e420;
cc35a_type_8040ea30 = 0x8040ea30;
cc35a_type_8040ed70 = 0x8040ed70;
cc35a_type_8040ef18 = 0x8040ef18;
cc35a_type_804108f8 = 0x804108f8;
cc35a_value_80178c48 = 0x80178c48;
cc35a_value_80178ec4 = 0x80178ec4;
cc35a_vector_8004eb34 = 0x8004eb34;
cc35a_weapon_800fc330 = 0x800fc330;
cc35a_weapons_803eb63c = 0x803eb63c;
cc35a_worm_800fc6dc = 0x800fc6dc;
SECTIONS {
  .text.cc35a_controller_routes_8009723c 0x8009723c : { *(.text.cc35a_controller_routes_8009723c) }
  .sdata 0x804adf4c (NOLOAD) : {
    . = 0x0; cc35a_cache_804adf4c = .;
    . = 0x10; cc35a_cache_804adf5c = .;
    . = 0x18; cc35a_cache_804adf64 = .;
    . = 0x20; cc35a_cache_804adf6c = .;
    . = 0x28; cc35a_cache_804adf74 = .;
    . = 0x30; cc35a_cache_804adf7c = .;
    . = 0x38; cc35a_cache_804adf84 = .;
    . = 0x40; cc35a_cache_804adf8c = .;
    . = 0x3840; cc35a_service_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
