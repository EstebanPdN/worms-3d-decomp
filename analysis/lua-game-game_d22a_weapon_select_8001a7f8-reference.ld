/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d22a_weapon_select_8001a7f8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6StringPCc = 0x8020bb54;
w3d_camera_8041e780 = 0x8041e780;
w3d_camera_set_eye_80118230 = 0x80118230;
w3d_camera_set_target_80118288 = 0x80118288;
w3d_eye_vector_8041e844 = 0x8041e844;
w3d_float_property_800fc270 = 0x800fc270;
w3d_set_eye_vector_8001a770 = 0x8001a770;
w3d_set_weapon_index_8001a758 = 0x8001a758;
w3d_string_8036af64 = 0x8036af64;
w3d_string_8036af74 = 0x8036af74;
w3d_string_8036af7c = 0x8036af7c;
w3d_string_base_finish_8020c5c4 = 0x8020c5c4;
w3d_string_release_80341588 = 0x80341588;
w3d_weapon_lookup_800fc330 = 0x800fc330;
w3d_weapon_names_803eb63c = 0x803eb63c;
w3d_wind_vector_8001a9a0 = 0x8001a9a0;
w3d_zero_8036af94 = 0x8036af94;
SECTIONS {
  .text.w3d_d22a_weapon_select_8001a7f8 0x8001a7f8 : { *(.text.w3d_d22a_weapon_select_8001a7f8) }
  .sdata 0x804aa778 (NOLOAD) : {
    . = 0x0; w3d_weapon_state_804aa778 = .;
    . = 0x6ff8; w3d_weapon_range_804b1770 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
