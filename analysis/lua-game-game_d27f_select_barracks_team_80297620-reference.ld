/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27f_select_barracks_team_80297620)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_._19Descriptor_80178474 = 0x80178474;
__14Cache_8015f704PCc = 0x8015f704;
f3c_propagate_tag_801ea4c8 = 0x801ea4c8;
fn_802979b8 = 0x802979b8;
fn_80299630 = 0x80299630;
lbl_803d0940 = 0x803d0940;
lbl_803d097c = 0x803d097c;
lbl_803d09c4 = 0x803d09c4;
lbl_803d09d8 = 0x803d09d8;
lbl_803d09e0 = 0x803d09e0;
lbl_80413b28 = 0x80413b28;
strcmp = 0x802ef234;
tsonnet_b33_arena_801613f0 = 0x801613f0;
w3d_auto_8015f558 = 0x8015f558;
w3d_auto_80179598 = 0x80179598;
w3d_auto_801797b4 = 0x801797b4;
w3d_auto_80299a74 = 0x80299a74;
w3d_cached_message_id = 0x8015f5a0;
w3d_constructor_lookup_name = 0x800fc1b0;
w3d_empty_80341584 = 0x80341584;
w3d_message_post_current = 0x8016239c;
w3d_message_string_init = 0x8010a8e0;
w3d_s10_service_forward_8020b680 = 0x8020b680;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_release = 0x80341588;
SECTIONS {
  .text.d27f_select_barracks_team_80297620 0x80297620 : { *(.text.d27f_select_barracks_team_80297620) }
  .sdata 0x804b1754 (NOLOAD) : {
    . = 0x0; lbl_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
