/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24b_land_start_800bb114)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6StringPCc = 0x8020bb54;
w3d_cached_message_id_8015f5a0 = 0x8015f5a0;
w3d_handle_load_8015adf4 = 0x8015adf4;
w3d_identity_80342a74 = 0x80342a74;
w3d_identity_80342a78 = 0x80342a78;
w3d_resource_property_800fc1b0 = 0x800fc1b0;
w3d_string_80382b6c = 0x80382b6c;
w3d_string_80382b7c = 0x80382b7c;
w3d_string_80382b90 = 0x80382b90;
w3d_string_finish_8020c5c4 = 0x8020c5c4;
w3d_string_release_80341588 = 0x80341588;
w3d_subscribe_80162024 = 0x80162024;
SECTIONS {
  .text.w3d_d24b_land_start_800bb114 0x800bb114 : { *(.text.w3d_d24b_land_start_800bb114) }
  .sdata 0x804aad4c (NOLOAD) : {
    . = 0x0; w3d_property_804aad4c = .;
    . = 0x3834; w3d_message_804ae580 = .;
    . = 0x383c; w3d_message_804ae588 = .;
    . = 0x3844; w3d_message_804ae590 = .;
    . = 0x3854; w3d_message_804ae5a0 = .;
    . = 0x385c; w3d_message_804ae5a8 = .;
    . = 0x3874; w3d_message_804ae5c0 = .;
    . = 0x387c; w3d_message_804ae5c8 = .;
    . = 0x3884; w3d_message_804ae5d0 = .;
    . = 0x388c; w3d_object_804ae5d8 = .;
    . = 0x3890; w3d_object_804ae5dc = .;
    . = 0x3894; w3d_object_804ae5e0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
