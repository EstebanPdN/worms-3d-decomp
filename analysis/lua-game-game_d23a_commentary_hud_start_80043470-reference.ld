/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d23a_commentary_hud_start_80043470)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_cached_message_id_8015f5a0 = 0x8015f5a0;
w3d_commentary_select_80041d28 = 0x80041d28;
w3d_create_panel_80164514 = 0x80164514;
w3d_hud_reset_80047e94 = 0x80047e94;
w3d_resource_property_800fc1b0 = 0x800fc1b0;
w3d_string_80374de0 = 0x80374de0;
w3d_string_80374df8 = 0x80374df8;
w3d_subscribe_80162024 = 0x80162024;
w3d_type_804109c0 = 0x804109c0;
w3d_type_lookup_8020b680 = 0x8020b680;
SECTIONS {
  .text.w3d_d23a_commentary_hud_start_80043470 0x80043470 : { *(.text.w3d_d23a_commentary_hud_start_80043470) }
  .sdata 0x804aa978 (NOLOAD) : {
    . = 0x0; w3d_mode_804aa978 = .;
    . = 0x2868; w3d_message_804ad1e0 = .;
    . = 0x2870; w3d_message_804ad1e8 = .;
    . = 0x2878; w3d_message_804ad1f0 = .;
    . = 0x2880; w3d_message_804ad1f8 = .;
    . = 0x2888; w3d_message_804ad200 = .;
    . = 0x2890; w3d_message_804ad208 = .;
    . = 0x2898; w3d_message_804ad210 = .;
    . = 0x28a0; w3d_message_804ad218 = .;
    . = 0x28a8; w3d_message_804ad220 = .;
    . = 0x28b0; w3d_message_804ad228 = .;
    . = 0x28b8; w3d_message_804ad230 = .;
    . = 0x28c0; w3d_message_804ad238 = .;
    . = 0x28c8; w3d_message_804ad240 = .;
    . = 0x28d0; w3d_message_804ad248 = .;
    . = 0x28d8; w3d_message_804ad250 = .;
    . = 0x28e0; w3d_message_804ad258 = .;
    . = 0x28e8; w3d_message_804ad260 = .;
    . = 0x28f0; w3d_message_804ad268 = .;
    . = 0x28f8; w3d_message_804ad270 = .;
    . = 0x2900; w3d_message_804ad278 = .;
    . = 0x2908; w3d_message_804ad280 = .;
    . = 0x2910; w3d_message_804ad288 = .;
    . = 0x2918; w3d_message_804ad290 = .;
    . = 0x2920; w3d_message_804ad298 = .;
    . = 0x2928; w3d_message_804ad2a0 = .;
    . = 0x2930; w3d_message_804ad2a8 = .;
    . = 0x2938; w3d_message_804ad2b0 = .;
    . = 0x2940; w3d_message_804ad2b8 = .;
    . = 0x2948; w3d_message_804ad2c0 = .;
    . = 0x2950; w3d_message_804ad2c8 = .;
    . = 0x6e14; w3d_service_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
