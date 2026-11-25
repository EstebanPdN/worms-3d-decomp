/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d32a_briefing_panel_show_80030260)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_._19Descriptor_80178474 = 0x80178474;
__6StringPCc = 0x8020bb54;
g_key_80419d78 = 0x80419d78;
list_append_801ef174 = 0x801ef174;
list_begin_801ef380 = 0x801ef380;
s_80372fc0 = 0x80372fc0;
s_803730b0 = 0x803730b0;
tsonnet_b33_arena_801613f0 = 0x801613f0;
w3d_auto_80178df0 = 0x80178df0;
w3d_auto_80179598 = 0x80179598;
w3d_cached_message_id = 0x8015f5a0;
w3d_empty_80341584 = 0x80341584;
w3d_message_post_current = 0x8016239c;
w3d_message_string_init = 0x8010a8e0;
w3d_s10_service_forward_8020b680 = 0x8020b680;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_release = 0x80341588;
w3d_string_release_header = 0x8020bb2c;
SECTIONS {
  .text.w3d_d32a_briefing_panel_show_80030260 0x80030260 : { *(.text.w3d_d32a_briefing_panel_show_80030260) }
  .rodata 0x803730c8 : { *(.rodata) }
  .sdata 0x804acd54 (NOLOAD) : {
    . = 0x0; g_id_804acd54 = .;
    . = 0x4a00; g_arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
