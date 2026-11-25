/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_script_poll_8010045c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lua_atpanic = 0x802cd774;
lua_insert = 0x802cd8e0;
lua_pushcclosure = 0x802ce148;
lua_pushlightuserdata = 0x802ce244;
lua_pushstring = 0x802cdfd4;
lua_setgcthreshold = 0x802ce840;
lua_sethook = 0x802ceb4c;
lua_settable = 0x802ce4d8;
w3d_fn_80100c4c = 0x80100c4c;
w3d_fn_80101dd4 = 0x80101dd4;
w3d_fn_8020b680 = 0x8020b680;
w3d_fn_802cba50 = 0x802cba50;
w3d_fn_802cbb5c = 0x802cbb5c;
w3d_fn_802cbdf8 = 0x802cbdf8;
w3d_fn_802ccb40 = 0x802ccb40;
w3d_lua_CancelTimer = 0x80102ca0;
w3d_lua_CloseContainer = 0x80103230;
w3d_lua_CopyContainer = 0x80103348;
w3d_lua_EditContainer = 0x80102dd8;
w3d_lua_GetData = 0x801016c8;
w3d_lua_Print = 0x80103ea8;
w3d_lua_QueryContainer = 0x8010306c;
w3d_lua_SendFloatMessage = 0x801011f4;
w3d_lua_SendIntMessage = 0x8010138c;
w3d_lua_SendMessage = 0x80101078;
w3d_lua_SendStringMessage = 0x8010152c;
w3d_lua_SetData = 0x80101adc;
w3d_lua_StartTimer = 0x80102b08;
w3d_lua_globals = 0x8010208c;
w3d_lua_panic = 0x80101f90;
w3d_obj_80413700 = 0x80413700;
w3d_obj_80413750 = 0x80413750;
w3d_obj_80413820 = 0x80413820;
w3d_obj_80413880 = 0x80413880;
w3d_str_803987f4 = 0x803987f4;
w3d_str_80398800 = 0x80398800;
w3d_str_80398814 = 0x80398814;
w3d_str_80398824 = 0x80398824;
w3d_str_80398838 = 0x80398838;
w3d_str_80398840 = 0x80398840;
w3d_str_80398848 = 0x80398848;
w3d_str_80398850 = 0x80398850;
w3d_str_8039885c = 0x8039885c;
w3d_str_80398868 = 0x80398868;
w3d_str_80398878 = 0x80398878;
w3d_str_80398888 = 0x80398888;
w3d_str_80398898 = 0x80398898;
w3d_str_803988a8 = 0x803988a8;
w3d_str_803988b0 = 0x803988b0;
w3d_str_803988c0 = 0x803988c0;
SECTIONS {
  .text.w3d_script_poll_8010045c 0x8010045c : { *(.text.w3d_script_poll_8010045c) }
  .text.w3d_fn_80100748 0x80100748 : { *(.text.w3d_fn_80100748) }
  .text.w3d_fn_80100bbc 0x80100bbc : { *(.text.w3d_fn_80100bbc) }
  .sdata 0x804aaf88 (NOLOAD) : {
    . = 0x0; w3d_obj_804aaf88 = .;
    . = 0x6800; w3d_obj_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
