/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s4_mouse_message)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_8015fb34 = 0x8015fb34;
w3d_empty_802852c0 = 0x802852c0;
w3d_input_position_800a79f8 = 0x800a79f8;
w3d_message_matches_8015f65c = 0x8015f65c;
w3d_mouse_clamp_802852c4 = 0x802852c4;
w3d_mouse_setup_80285168 = 0x80285168;
w3d_value_range_get_80069a50 = 0x80069a50;
SECTIONS {
  .text.w3d_s4_mouse_message 0x80284e80 : { *(.text.w3d_s4_mouse_message) }
  .sdata 0x804aac54 (NOLOAD) : {
    . = 0x0; w3d_input_804aac54 = .;
    . = 0xf64; w3d_mouse_busy_804abbb8 = .;
    . = 0x5f38; w3d_cache_804b0b8c = .;
    . = 0x5f40; w3d_cache_804b0b94 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
