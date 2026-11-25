/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24a_worm_hud_start_80023944)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6StringPCc = 0x8020bb54;
w3d_cached_message_id_8015f5a0 = 0x8015f5a0;
w3d_handle_load_8015adf4 = 0x8015adf4;
w3d_hud_apply_800246e4 = 0x800246e4;
w3d_hud_layout_80024448 = 0x80024448;
w3d_hud_offset_800244d4 = 0x800244d4;
w3d_hud_refresh_80024844 = 0x80024844;
w3d_identity_80341584 = 0x80341584;
w3d_identity_803426b4 = 0x803426b4;
w3d_identity_80342a78 = 0x80342a78;
w3d_identity_80342fa4 = 0x80342fa4;
w3d_resource_property_800fc1b0 = 0x800fc1b0;
w3d_string_8036c59c = 0x8036c59c;
w3d_string_8036c5b0 = 0x8036c5b0;
w3d_string_8036c5c4 = 0x8036c5c4;
w3d_string_8036c5cc = 0x8036c5cc;
w3d_string_8036c5dc = 0x8036c5dc;
w3d_string_8036c5e4 = 0x8036c5e4;
w3d_string_8036c5f4 = 0x8036c5f4;
w3d_string_8036c608 = 0x8036c608;
w3d_string_8036c624 = 0x8036c624;
w3d_string_8036c644 = 0x8036c644;
w3d_string_8036c660 = 0x8036c660;
w3d_string_8036c67c = 0x8036c67c;
w3d_string_8036c698 = 0x8036c698;
w3d_string_8036c6b4 = 0x8036c6b4;
w3d_string_8036c6d0 = 0x8036c6d0;
w3d_string_8036c6ec = 0x8036c6ec;
w3d_string_8036c70c = 0x8036c70c;
w3d_string_8036c718 = 0x8036c718;
w3d_string_8036c72c = 0x8036c72c;
w3d_string_finish_8020c5c4 = 0x8020c5c4;
w3d_string_release_80341588 = 0x80341588;
w3d_subscribe_80162024 = 0x80162024;
SECTIONS {
  .text.w3d_d24a_worm_hud_start_80023944 0x80023944 : { *(.text.w3d_d24a_worm_hud_start_80023944) }
  .sdata 0x804aca54 (NOLOAD) : {
    . = 0x0; w3d_message_804aca54 = .;
    . = 0x8; w3d_message_804aca5c = .;
    . = 0x10; w3d_message_804aca64 = .;
    . = 0x18; w3d_message_804aca6c = .;
    . = 0x20; w3d_message_804aca74 = .;
    . = 0x28; w3d_message_804aca7c = .;
    . = 0x30; w3d_message_804aca84 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
