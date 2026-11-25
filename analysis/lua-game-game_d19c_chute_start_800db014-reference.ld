/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d19c_chute_start_800db014)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d19c_arena_alloc_801613f0 = 0x801613f0;
d19c_cached_message_id_8015f5a0 = 0x8015f5a0;
d19c_chute_show_800dc184 = 0x800dc184;
d19c_cosine_802e86d4 = 0x802e86d4;
d19c_message_post_8016239c = 0x8016239c;
d19c_settings_read_float_800fc270 = 0x800fc270;
d19c_sine_802e88ac = 0x802e88ac;
d19c_target_message_init_800a82f0 = 0x800a82f0;
d19c_value_message_init_80125fdc = 0x80125fdc;
SECTIONS {
  .text.d19c_chute_start_800db014 0x800db014 : { *(.text.d19c_chute_start_800db014) }
  .rodata 0x80389800 : { *(.rodata) }
  .sdata 0x804aebec (NOLOAD) : {
    . = 0x0; d19c_chute_target_message_804aebec = .;
    . = 0x28; d19c_chute_open_message_804aec14 = .;
    . = 0x2b68; d19c_message_arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
