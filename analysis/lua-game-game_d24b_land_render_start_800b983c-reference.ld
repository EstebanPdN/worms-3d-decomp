/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24b_land_render_start_800b983c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6StringPCc = 0x8020bb54;
w3d_cached_message_id_8015f5a0 = 0x8015f5a0;
w3d_handle_load_8015adf4 = 0x8015adf4;
w3d_heap_allocate_802098d8 = 0x802098d8;
w3d_identity_8034357c = 0x8034357c;
w3d_lookup_optional_80174074 = 0x80174074;
w3d_renderer_ctor_8008fb3c = 0x8008fb3c;
w3d_resource_property_800fc1b0 = 0x800fc1b0;
w3d_string_8038285c = 0x8038285c;
w3d_string_8038286c = 0x8038286c;
w3d_string_8038287c = 0x8038287c;
w3d_string_finish_8020c5c4 = 0x8020c5c4;
w3d_string_property_800fc2b0 = 0x800fc2b0;
w3d_string_release_80341588 = 0x80341588;
w3d_subscribe_80162024 = 0x80162024;
w3d_vector_property_800fc2f0 = 0x800fc2f0;
SECTIONS {
  .text.w3d_d24b_land_render_start_800b983c 0x800b983c : { *(.text.w3d_d24b_land_render_start_800b983c) }
  .sdata 0x804aace0 (NOLOAD) : {
    . = 0x0; w3d_property_804aace0 = .;
    . = 0x3104; w3d_pool_804adde4 = .;
    . = 0x3838; w3d_message_804ae518 = .;
    . = 0x3840; w3d_message_804ae520 = .;
    . = 0x3860; w3d_message_804ae540 = .;
    . = 0x3868; w3d_setting_804ae548 = .;
    . = 0x6b1c; w3d_global_804b17fc = .;
    . = 0x6b2c; w3d_global_804b180c = .;
    . = 0x6b5c; w3d_renderer_804b183c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
