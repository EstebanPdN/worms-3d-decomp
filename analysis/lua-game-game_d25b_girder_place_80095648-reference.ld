/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d25b_girder_place_80095648)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__7Text128PCce = 0x803434d4;
s19_fire_once_8002ad9c = 0x8002ad9c;
s19_handle_cast_query_80096564 = 0x80096564;
s9_update_value_80178c54 = 0x80178c54;
s9_update_value_80178d28 = 0x80178d28;
w3d_arena_alloc_801613f0 = 0x801613f0;
w3d_auto_8002ae70 = 0x8002ae70;
w3d_auto_800fc330 = 0x800fc330;
w3d_cached_message_id_8015f5a0 = 0x8015f5a0;
w3d_cast_80342a78 = 0x80342a78;
w3d_empty_800959cc = 0x800959cc;
w3d_empty_80342fa4 = 0x80342fa4;
w3d_forward_global6_800fdc80 = 0x800fdc80;
w3d_message_post_8016239c = 0x8016239c;
w3d_obj_8040db38 = 0x8040db38;
w3d_particle_vector_message_80108154 = 0x80108154;
w3d_set_vector_80178fa4 = 0x80178fa4;
w3d_string_8037eb50 = 0x8037eb50;
w3d_string_8037eb68 = 0x8037eb68;
w3d_string_8037eb80 = 0x8037eb80;
w3d_string_8037eb90 = 0x8037eb90;
SECTIONS {
  .text.w3d_d25b_girder_place_80095648 0x80095648 : { *(.text.w3d_d25b_girder_place_80095648) }
  .rodata 0x8037eba0 : { *(.rodata) }
  .sdata 0x804adf08 (NOLOAD) : {
    . = 0x0; w3d_message_804adf08 = .;
    . = 0x8; w3d_message_804adf10 = .;
    . = 0x20; w3d_message_804adf28 = .;
    . = 0x384c; w3d_message_arena_804b1754 = .;
    . = 0x3880; w3d_owner_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
