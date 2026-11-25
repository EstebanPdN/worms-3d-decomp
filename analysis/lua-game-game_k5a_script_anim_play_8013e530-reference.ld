/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(k5a_script_anim_play_8013e530)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_801613f0 = 0x801613f0;
s8_index_query_800fc6dc = 0x800fc6dc;
w3d_auto_800fc2b0 = 0x800fc2b0;
w3d_cached_message_id = 0x8015f5a0;
w3d_f32_8039fc8c = 0x8039fc8c;
w3d_f32_8039fc90 = 0x8039fc90;
w3d_f32_8039fc94 = 0x8039fc94;
w3d_message_post_current = 0x8016239c;
w3d_message_string_init = 0x8010a8e0;
w3d_string_8039fc64 = 0x8039fc64;
w3d_string_8039fc74 = 0x8039fc74;
w3d_text_format_803434d4 = 0x803434d4;
w3d_worm_play_named_801359ec = 0x801359ec;
SECTIONS {
  .text.k5a_script_anim_play_8013e530 0x8013e530 : { *(.text.k5a_script_anim_play_8013e530) }
  .sdata 0x804af9b8 (NOLOAD) : {
    . = 0x0; w3d_message_804af9b8 = .;
    . = 0x1d9c; w3d_message_pool_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
