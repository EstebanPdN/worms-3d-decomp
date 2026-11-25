/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d23a_worm_aim_start_80026e74)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6StringPCc = 0x8020bb54;
w3d_cached_message_id_8015f5a0 = 0x8015f5a0;
w3d_identity_80342a74 = 0x80342a74;
w3d_resource_property_800fc1b0 = 0x800fc1b0;
w3d_string_8036caec = 0x8036caec;
w3d_string_8036cb04 = 0x8036cb04;
w3d_string_8036cb14 = 0x8036cb14;
w3d_string_8036cb28 = 0x8036cb28;
w3d_string_8036cb3c = 0x8036cb3c;
w3d_string_finish_8020c5c4 = 0x8020c5c4;
w3d_string_release_80341588 = 0x80341588;
w3d_subscribe_80162024 = 0x80162024;
w3d_watch_property_800fd62c = 0x800fd62c;
w3d_worm_aim_on_index_8002732c = 0x8002732c;
w3d_worm_aim_update_8002709c = 0x8002709c;
SECTIONS {
  .text.w3d_d23a_worm_aim_start_80026e74 0x80026e74 : { *(.text.w3d_d23a_worm_aim_start_80026e74) }
  .sdata 0x804acb1c (NOLOAD) : {
    . = 0x0; w3d_message_804acb1c = .;
    . = 0x8; w3d_message_804acb24 = .;
    . = 0x10; w3d_message_804acb2c = .;
    . = 0x18; w3d_message_804acb34 = .;
    . = 0x20; w3d_message_804acb3c = .;
    . = 0x38; w3d_message_804acb54 = .;
    . = 0x40; w3d_message_804acb5c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
