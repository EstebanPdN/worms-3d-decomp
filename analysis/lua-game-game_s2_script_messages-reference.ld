/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_script_send_plain_8010109c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lua_gettop = 0x802cd7f4;
lua_isnumber = 0x802cda9c;
lua_isstring = 0x802cdaf4;
lua_settop = 0x802cd808;
lua_tonumber = 0x802cdc5c;
lua_tostring = 0x802cdd04;
w3d_fn_801022ec = 0x801022ec;
w3d_fn_801613f0 = 0x801613f0;
w3d_message_find_id = 0x80161f54;
w3d_message_float_init = 0x80069a0c;
w3d_message_int_init = 0x800a82f0;
w3d_message_post_current = 0x8016239c;
w3d_message_string_init = 0x8010a8e0;
w3d_obj_8040db38 = 0x8040db38;
w3d_str_80398a08 = 0x80398a08;
w3d_str_80398a40 = 0x80398a40;
w3d_str_80398a6c = 0x80398a6c;
w3d_str_80398a90 = 0x80398a90;
w3d_str_80398ad0 = 0x80398ad0;
w3d_str_80398b00 = 0x80398b00;
w3d_str_80398b3c = 0x80398b3c;
w3d_str_80398b6c = 0x80398b6c;
w3d_str_80398bac = 0x80398bac;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_default = 0x803426b8;
w3d_string_format = 0x8020c510;
w3d_string_from_text = 0x8020bb54;
w3d_string_release = 0x80341588;
SECTIONS {
  .text.w3d_script_send_plain_8010109c 0x8010109c : { *(.text.w3d_script_send_plain_8010109c) }
  .text.w3d_script_send_float_80101218 0x80101218 : { *(.text.w3d_script_send_float_80101218) }
  .text.w3d_script_send_int_801013b0 0x801013b0 : { *(.text.w3d_script_send_int_801013b0) }
  .text.w3d_script_send_string_80101550 0x80101550 : { *(.text.w3d_script_send_string_80101550) }
  .sdata 0x804b1754 (NOLOAD) : {
    . = 0x0; w3d_obj_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
