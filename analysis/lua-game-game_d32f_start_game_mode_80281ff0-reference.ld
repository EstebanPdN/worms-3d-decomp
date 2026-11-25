/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d32f_start_game_mode_80281ff0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_._13Base_8015f558 = 0x8015f558;
_._19Descriptor_80178474 = 0x80178474;
__14Cache_8015f704PCc = 0x8015f704;
__15String_803426b8 = 0x803426b8;
__15String_803426b8PCc = 0x8020bb54;
fn_80162ba8 = 0x80162ba8;
fn_80162c20 = 0x80162c20;
fn_80178c54 = 0x80178c54;
fn_801fe45c = 0x801fe45c;
fn_80280370 = 0x80280370;
fn_802847cc = 0x802847cc;
lbl_803ce988 = 0x803ce988;
lbl_803ce9dc = 0x803ce9dc;
lbl_803ce9f0 = 0x803ce9f0;
lbl_803cea04 = 0x803cea04;
lbl_803cea68 = 0x803cea68;
lbl_803ceac8 = 0x803ceac8;
lbl_803cec64 = 0x803cec64;
lbl_803cf0b0 = 0x803cf0b0;
lbl_803cf0bc = 0x803cf0bc;
lbl_803cf0cc = 0x803cf0cc;
lbl_803cf0d8 = 0x803cf0d8;
lbl_803cf0e8 = 0x803cf0e8;
lbl_803cf0fc = 0x803cf0fc;
lbl_803cf110 = 0x803cf110;
lbl_803cf11c = 0x803cf11c;
lbl_803cf124 = 0x803cf124;
lbl_803cf134 = 0x803cf134;
lbl_803cf13c = 0x803cf13c;
lbl_803cf148 = 0x803cf148;
lbl_803cf15c = 0x803cf15c;
lbl_803cf16c = 0x803cf16c;
lbl_803cf180 = 0x803cf180;
lbl_803cf190 = 0x803cf190;
lbl_803cf198 = 0x803cf198;
lbl_803cf1a8 = 0x803cf1a8;
lbl_803cf1b8 = 0x803cf1b8;
lbl_803cf1c8 = 0x803cf1c8;
lbl_803cf1d0 = 0x803cf1d0;
lbl_803cf1d4 = 0x803cf1d4;
lbl_803cf1d8 = 0x803cf1d8;
lbl_803cf1dc = 0x803cf1dc;
lbl_803cf1e8 = 0x803cf1e8;
lbl_803cf1f8 = 0x803cf1f8;
lbl_803cf204 = 0x803cf204;
lbl_803cf218 = 0x803cf218;
lbl_803cf21c = 0x803cf21c;
lbl_803cf224 = 0x803cf224;
lbl_803cf22c = 0x803cf22c;
lbl_803cf238 = 0x803cf238;
lbl_803cf240 = 0x803cf240;
lbl_803cf248 = 0x803cf248;
lbl_803cf250 = 0x803cf250;
lbl_803cf260 = 0x803cf260;
lbl_803cf270 = 0x803cf270;
lbl_803cf280 = 0x803cf280;
lbl_803cf28c = 0x803cf28c;
lbl_803cf29c = 0x803cf29c;
lbl_803cf2a0 = 0x803cf2a0;
lbl_803cf2b0 = 0x803cf2b0;
s8_property_read_800fc550 = 0x800fc550;
s8_property_write_800fc43c = 0x800fc43c;
sol35e2_choose_string_8027befc = 0x8027befc;
strcmp = 0x802ef234;
tsonnet_b33_arena_801613f0 = 0x801613f0;
w3d_auto_800fc2b0 = 0x800fc2b0;
w3d_auto_80179598 = 0x80179598;
w3d_auto_801797b4 = 0x801797b4;
w3d_cached_message_id = 0x8015f5a0;
w3d_constructor_lookup_name = 0x800fc1b0;
w3d_d24z_strcasecmp_802ef074 = 0x802ef074;
w3d_empty_80341584 = 0x80341584;
w3d_empty_803426b4 = 0x803426b4;
w3d_message_int_init_800a82f0 = 0x800a82f0;
w3d_message_post_current = 0x8016239c;
w3d_message_string_init = 0x8010a8e0;
w3d_r25b_category_count_8027be7c = 0x8027be7c;
w3d_string_assign = 0x8020bd38;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_format = 0x8020c510;
w3d_string_release = 0x80341588;
w3d_string_release_header = 0x8020bb2c;
SECTIONS {
  .text.d32f_start_game_mode_80281ff0 0x80281ff0 : { *(.text.d32f_start_game_mode_80281ff0) }
  .sdata 0x804abbac (NOLOAD) : {
    . = 0x0; lbl_804abbac = .;
    . = 0x4; lbl_804abbb0 = .;
    . = 0x5ba8; lbl_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
