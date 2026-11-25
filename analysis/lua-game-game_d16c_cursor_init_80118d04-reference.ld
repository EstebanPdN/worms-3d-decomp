/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d16c_cursor_init_80118d04)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__20d16c_String_8020bb54PCc = 0x8020bb54;
d16c_as_mesh_8034357c = 0x8034357c;
d16c_bitmap_8039aa18 = 0x8039aa18;
d16c_cached_message_id_8015f5a0 = 0x8015f5a0;
d16c_cursor_base_init_8004e0dc = 0x8004e0dc;
d16c_error_8039aa54 = 0x8039aa54;
d16c_handle_load_8015adf4 = 0x8015adf4;
d16c_intro_8039aa38 = 0x8039aa38;
d16c_loop_8039aa48 = 0x8039aa48;
d16c_mesh_8039aa00 = 0x8039aa00;
d16c_mesh_set_colour_80173df0 = 0x80173df0;
d16c_shadow_clip_8039aa7c = 0x8039aa7c;
d16c_shadow_name_8039aa64 = 0x8039aa64;
d16c_string_finish_8020c5c4 = 0x8020c5c4;
d16c_string_release_80341588 = 0x80341588;
d16c_subscribe_80162024 = 0x80162024;
d16c_target_8039aa30 = 0x8039aa30;
SECTIONS {
  .text.d16c_cursor_init_80118d04 0x80118d04 : { *(.text.d16c_cursor_init_80118d04) }
  .sdata 0x804ad424 (NOLOAD) : {
    . = 0x0; d16c_message_804ad424 = .;
    . = 0x1ef0; d16c_shadow_colour_804af314 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
