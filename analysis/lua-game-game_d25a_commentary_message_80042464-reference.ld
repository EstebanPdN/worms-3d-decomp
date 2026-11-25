/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d25a_commentary_message_80042464)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6String = 0x803426b8;
__6StringPCc = 0x8020bb54;
w3d_base_handler_8015fb34 = 0x8015fb34;
w3d_commentary_play_80043134 = 0x80043134;
w3d_hud_reset_80047e94 = 0x80047e94;
w3d_hud_start_80043470 = 0x80043470;
w3d_identity_80343744 = 0x80343744;
w3d_int_property_800fc230 = 0x800fc230;
w3d_message_equals_8015f620 = 0x8015f620;
w3d_message_text_8010a8fc = 0x8010a8fc;
w3d_message_worm_800a830c = 0x800a830c;
w3d_object_string_80179170 = 0x80179170;
w3d_on_80044244 = 0x80044244;
w3d_on_80044410 = 0x80044410;
w3d_on_800446f4 = 0x800446f4;
w3d_on_80044994 = 0x80044994;
w3d_on_80044a80 = 0x80044a80;
w3d_on_80044bc0 = 0x80044bc0;
w3d_on_80044ef8 = 0x80044ef8;
w3d_on_800450a4 = 0x800450a4;
w3d_on_8004527c = 0x8004527c;
w3d_on_80045cb4 = 0x80045cb4;
w3d_on_80046290 = 0x80046290;
w3d_on_80046408 = 0x80046408;
w3d_on_80046764 = 0x80046764;
w3d_on_800468dc = 0x800468dc;
w3d_on_80047b6c = 0x80047b6c;
w3d_on_80047d50 = 0x80047d50;
w3d_on_80047fcc = 0x80047fcc;
w3d_on_80048110 = 0x80048110;
w3d_on_death_800455bc = 0x800455bc;
w3d_panel_80041d28 = 0x80041d28;
w3d_string_80374da8 = 0x80374da8;
w3d_string_80374dc0 = 0x80374dc0;
w3d_string_append_8020bf2c = 0x8020bf2c;
w3d_string_assign_8020bd38 = 0x8020bd38;
w3d_string_finish_8020c5c4 = 0x8020c5c4;
w3d_string_header_80341884 = 0x80341884;
w3d_string_init_8020c5c0 = 0x8020c5c0;
w3d_string_property_800fc2b0 = 0x800fc2b0;
w3d_string_release_80341588 = 0x80341588;
w3d_string_release_header_8020bb2c = 0x8020bb2c;
SECTIONS {
  .text.w3d_d25a_commentary_message_80042464 0x80042464 : { *(.text.w3d_d25a_commentary_message_80042464) }
  .sdata 0x804ad1e0 (NOLOAD) : {
    . = 0x0; w3d_message_804ad1e0 = .;
    . = 0x8; w3d_message_804ad1e8 = .;
    . = 0x10; w3d_message_804ad1f0 = .;
    . = 0x18; w3d_message_804ad1f8 = .;
    . = 0x20; w3d_message_804ad200 = .;
    . = 0x28; w3d_message_804ad208 = .;
    . = 0x30; w3d_message_804ad210 = .;
    . = 0x38; w3d_message_804ad218 = .;
    . = 0x40; w3d_message_804ad220 = .;
    . = 0x48; w3d_message_804ad228 = .;
    . = 0x50; w3d_message_804ad230 = .;
    . = 0x58; w3d_message_804ad238 = .;
    . = 0x60; w3d_message_804ad240 = .;
    . = 0x68; w3d_message_804ad248 = .;
    . = 0x70; w3d_message_804ad250 = .;
    . = 0x78; w3d_message_804ad258 = .;
    . = 0x80; w3d_message_804ad260 = .;
    . = 0x88; w3d_message_804ad268 = .;
    . = 0x90; w3d_message_804ad270 = .;
    . = 0x98; w3d_message_804ad278 = .;
    . = 0xa0; w3d_message_804ad280 = .;
    . = 0xa8; w3d_message_804ad288 = .;
    . = 0xb0; w3d_message_804ad290 = .;
    . = 0xb8; w3d_message_804ad298 = .;
    . = 0xc0; w3d_message_804ad2a0 = .;
    . = 0xc8; w3d_message_804ad2a8 = .;
    . = 0xd0; w3d_message_804ad2b0 = .;
    . = 0xd8; w3d_message_804ad2b8 = .;
    . = 0xe0; w3d_message_804ad2c0 = .;
    . = 0xe8; w3d_message_804ad2c8 = .;
    . = 0x45a8; w3d_game_state_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
