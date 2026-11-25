/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d32a_crate_setup_80048a90)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6StringPCc = 0x8020bb54;
d24d_acquire_message_80162024 = 0x80162024;
s19_handle_not_minus1_80049298 = 0x80049298;
w3d_cached_message_id = 0x8015f5a0;
w3d_constructor_lookup_name = 0x800fc1b0;
w3d_d30a_crate_spawn_announce_800492cc = 0x800492cc;
w3d_empty_803426b4 = 0x803426b4;
w3d_empty_80343584 = 0x80343584;
w3d_fn_80049108 = 0x80049108;
w3d_fn_80049180 = 0x80049180;
w3d_handle_member_init_kind_8012656c = 0x8012656c;
w3d_handle_member_query_801265ec = 0x801265ec;
w3d_handle_set_name = 0x8015adf4;
w3d_heap_allocate = 0x802098d8;
w3d_light_member_attach_80126610 = 0x80126610;
w3d_s20_lookup_handle_object_80164fc8 = 0x80164fc8;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_release = 0x80341588;
SECTIONS {
  .text.w3d_d32a_crate_setup_80048a90 0x80048a90 : { *(.text.w3d_d32a_crate_setup_80048a90) }
  .rodata 0x803766d4 : { *(.rodata) }
  .sdata 0x804ad2e8 (NOLOAD) : {
    . = 0x0; g_id_804ad2e8 = .;
    . = 0x8; g_id_804ad2f0 = .;
    . = 0x28; g_id_804ad310 = .;
    . = 0x30; g_id_804ad318 = .;
    . = 0x22d4; g_heap_804af5bc = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
