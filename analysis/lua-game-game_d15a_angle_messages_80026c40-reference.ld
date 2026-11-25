/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d15a_angle_messages_80026c40)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_d15a_angle_apply_8002709c = 0x8002709c;
w3d_d15a_angle_forward_80027388 = 0x80027388;
w3d_d15a_angle_initialize_80026e74 = 0x80026e74;
w3d_d15a_angle_limits_800272b0 = 0x800272b0;
w3d_d15a_angle_notify_80027328 = 0x80027328;
w3d_d15a_base_messages_8015fb34 = 0x8015fb34;
w3d_d15a_channel_value_80342a74 = 0x80342a74;
w3d_d15a_half_pi_8036cae8 = 0x8036cae8;
w3d_d15a_message_query_800a8334 = 0x800a8334;
w3d_d15a_minus_half_pi_8036cae4 = 0x8036cae4;
w3d_d15a_value_get_80178df0 = 0x80178df0;
w3d_d15a_value_set_80178dfc = 0x80178dfc;
w3d_message_id_equals_cache = 0x8015f65c;
SECTIONS {
  .text.w3d_d15a_angle_messages_80026c40 0x80026c40 : { *(.text.w3d_d15a_angle_messages_80026c40) }
  .sdata 0x804acb1c (NOLOAD) : {
    . = 0x0; w3d_d15a_msg_first_on_804acb1c = .;
    . = 0x8; w3d_d15a_msg_first_off_804acb24 = .;
    . = 0x10; w3d_d15a_msg_second_on_804acb2c = .;
    . = 0x18; w3d_d15a_msg_second_off_804acb34 = .;
    . = 0x20; w3d_d15a_msg_query_804acb3c = .;
    . = 0x40; w3d_d15a_msg_save_804acb5c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
