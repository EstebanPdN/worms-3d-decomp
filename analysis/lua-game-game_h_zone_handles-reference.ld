/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_trigger_zone_check_team_a_80125c80)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_entity_worm_80178c48 = 0x80178c48;
w3d_handle_activate_resource = 0x8003f860;
w3d_handle_call_8003fbe8 = 0x8003fbe8;
w3d_handle_call_8003fc70 = 0x8003fc70;
w3d_handle_call_8003fd54 = 0x8003fd54;
w3d_handle_create_800c07c4 = 0x800c07c4;
w3d_handle_destroy_800c1004 = 0x800c1004;
w3d_handle_query_8003fa90 = 0x8003fa90;
w3d_handle_query_8003fad8 = 0x8003fad8;
w3d_handle_query_8003fbd0 = 0x8003fbd0;
w3d_handle_query_8003ffac = 0x8003ffac;
w3d_handle_query_80041838 = 0x80041838;
w3d_handle_query_800c125c = 0x800c125c;
w3d_handle_query_800c1348 = 0x800c1348;
w3d_handle_query_800c136c = 0x800c136c;
w3d_heap_release = 0x80209920;
w3d_message_vtable_8040db38 = 0x8040db38;
w3d_worm_data_800fc6dc = 0x800fc6dc;
SECTIONS {
  .text.w3d_trigger_zone_check_team_a_80125c80 0x80125c80 : { *(.text.w3d_trigger_zone_check_team_a_80125c80) }
  .text.w3d_trigger_zone_check_team_b_80125d0c 0x80125d0c : { *(.text.w3d_trigger_zone_check_team_b_80125d0c) }
  .text.w3d_trigger_zone_trigger_now_80125d98 0x80125d98 : { *(.text.w3d_trigger_zone_trigger_now_80125d98) }
  .text.w3d_trigger_zone_filter_flags_80125e00 0x80125e00 : { *(.text.w3d_trigger_zone_filter_flags_80125e00) }
  .text.w3d_int_message_init_80125fdc 0x80125fdc : { *(.text.w3d_int_message_init_80125fdc) }
  .text.w3d_int_message_value_80125ff8 0x80125ff8 : { *(.text.w3d_int_message_value_80125ff8) }
  .text.w3d_vec_message_init_80126000 0x80126000 : { *(.text.w3d_vec_message_init_80126000) }
  .text.w3d_vec_message_value_80126034 0x80126034 : { *(.text.w3d_vec_message_value_80126034) }
  .text.w3d_bits_2_to_7_80126174 0x80126174 : { *(.text.w3d_bits_2_to_7_80126174) }
  .text.w3d_bits_10_to_15_8012617c 0x8012617c : { *(.text.w3d_bits_10_to_15_8012617c) }
  .text.w3d_handle_member_query_8012629c 0x8012629c : { *(.text.w3d_handle_member_query_8012629c) }
  .text.w3d_handle_member_query_801262c0 0x801262c0 : { *(.text.w3d_handle_member_query_801262c0) }
  .text.w3d_handle_member_query_80126308 0x80126308 : { *(.text.w3d_handle_member_query_80126308) }
  .text.w3d_handle_member_call_80126334 0x80126334 : { *(.text.w3d_handle_member_call_80126334) }
  .text.w3d_handle_member_query_80126360 0x80126360 : { *(.text.w3d_handle_member_query_80126360) }
  .text.w3d_handle_member_call_80126384 0x80126384 : { *(.text.w3d_handle_member_call_80126384) }
  .text.w3d_handle_member_call_801263bc 0x801263bc : { *(.text.w3d_handle_member_call_801263bc) }
  .text.w3d_handle_clock_801264fc 0x801264fc : { *(.text.w3d_handle_clock_801264fc) }
  .text.w3d_handle_member_query_80126524 0x80126524 : { *(.text.w3d_handle_member_query_80126524) }
  .text.w3d_handle_member_activate_80126548 0x80126548 : { *(.text.w3d_handle_member_activate_80126548) }
  .text.w3d_handle_member_init_kind_8012656c 0x8012656c : { *(.text.w3d_handle_member_init_kind_8012656c) }
  .text.w3d_handle_member_destroy_801265a4 0x801265a4 : { *(.text.w3d_handle_member_destroy_801265a4) }
  .text.w3d_handle_member_query_801265ec 0x801265ec : { *(.text.w3d_handle_member_query_801265ec) }
  .text.w3d_handle_member_query_80126688 0x80126688 : { *(.text.w3d_handle_member_query_80126688) }
  .text.w3d_handle_member_query_801266ac 0x801266ac : { *(.text.w3d_handle_member_query_801266ac) }
  .sdata 0x804af5bc (NOLOAD) : {
    . = 0x0; w3d_handle_heap_804af5bc = .;
    . = 0x21f8; w3d_clock_804b17b4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
