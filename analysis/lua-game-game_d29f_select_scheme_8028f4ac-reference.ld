/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d29f_select_scheme_8028f4ac)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_._19Descriptor_80178474 = 0x80178474;
__14Cache_8015f704PCc = 0x8015f704;
__15String_803426b8 = 0x803426b8;
f3c_propagate_tag_801ea4c8 = 0x801ea4c8;
lbl_803d0150 = 0x803d0150;
lbl_803d0164 = 0x803d0164;
lbl_803d0174 = 0x803d0174;
lbl_803d01ac = 0x803d01ac;
lbl_803d01c0 = 0x803d01c0;
lbl_80413b28 = 0x80413b28;
strcmp = 0x802ef234;
tsonnet_b33_arena_801613f0 = 0x801613f0;
w3d_auto_8015f558 = 0x8015f558;
w3d_auto_80179598 = 0x80179598;
w3d_auto_801797b4 = 0x801797b4;
w3d_cached_message_id = 0x8015f5a0;
w3d_constructor_lookup_name = 0x800fc1b0;
w3d_empty_80341584 = 0x80341584;
w3d_export_scheme_8028fb10 = 0x8028fb10;
w3d_message_post_current = 0x8016239c;
w3d_message_string_init = 0x8010a8e0;
w3d_s10_service_forward_8020b680 = 0x8020b680;
w3d_string_assign = 0x8020bd38;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_base_init = 0x8020c5c0;
w3d_string_header = 0x80341884;
w3d_string_release = 0x80341588;
SECTIONS {
  .text.d29f_select_scheme_8028f4ac 0x8028f4ac : { *(.text.d29f_select_scheme_8028f4ac) }
  .sdata 0x804b1754 (NOLOAD) : {
    . = 0x0; lbl_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
