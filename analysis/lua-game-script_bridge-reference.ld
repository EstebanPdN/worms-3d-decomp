/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_script_service_from_lua)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lua_gettable = 0x802ce264;
lua_pushstring = 0x802cdfd4;
lua_settop = 0x802cd808;
lua_tostring = 0x802cdd04;
lua_touserdata = 0x802cde08;
w3d_script_cancel_timer = 0x80102cc4;
w3d_script_close_container = 0x80103254;
w3d_script_copy_container = 0x8010336c;
w3d_script_edit_container = 0x80102dfc;
w3d_script_get_data = 0x801016ec;
w3d_script_globals = 0x801020b0;
w3d_script_print = 0x80103ecc;
w3d_script_query_container = 0x80103090;
w3d_script_report_error = 0x801022ec;
w3d_script_send_float_message = 0x80101218;
w3d_script_send_int_message = 0x801013b0;
w3d_script_send_message = 0x8010109c;
w3d_script_send_string_message = 0x80101550;
w3d_script_set_data = 0x80101b00;
w3d_script_start_timer = 0x80102b2c;
SECTIONS {
  .text.w3d_script_service_from_lua 0x80101018 : { *(.text.w3d_script_service_from_lua) }
  .text.w3d_lua_SendMessage 0x80101078 : { *(.text.w3d_lua_SendMessage) }
  .text.w3d_lua_SendFloatMessage 0x801011f4 : { *(.text.w3d_lua_SendFloatMessage) }
  .text.w3d_lua_SendIntMessage 0x8010138c : { *(.text.w3d_lua_SendIntMessage) }
  .text.w3d_lua_SendStringMessage 0x8010152c : { *(.text.w3d_lua_SendStringMessage) }
  .text.w3d_lua_GetData 0x801016c8 : { *(.text.w3d_lua_GetData) }
  .text.w3d_lua_SetData 0x80101adc : { *(.text.w3d_lua_SetData) }
  .text.w3d_lua_panic 0x80101f90 : { *(.text.w3d_lua_panic) }
  .text.w3d_script_panic 0x80101fb4 : { *(.text.w3d_script_panic) }
  .text.w3d_lua_globals 0x8010208c : { *(.text.w3d_lua_globals) }
  .text.w3d_lua_StartTimer 0x80102b08 : { *(.text.w3d_lua_StartTimer) }
  .text.w3d_lua_CancelTimer 0x80102ca0 : { *(.text.w3d_lua_CancelTimer) }
  .text.w3d_lua_EditContainer 0x80102dd8 : { *(.text.w3d_lua_EditContainer) }
  .text.w3d_lua_QueryContainer 0x8010306c : { *(.text.w3d_lua_QueryContainer) }
  .text.w3d_lua_CloseContainer 0x80103230 : { *(.text.w3d_lua_CloseContainer) }
  .text.w3d_lua_CopyContainer 0x80103348 : { *(.text.w3d_lua_CopyContainer) }
  .text.w3d_lua_Print 0x80103ea8 : { *(.text.w3d_lua_Print) }
  .rodata 0x803988b0 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
