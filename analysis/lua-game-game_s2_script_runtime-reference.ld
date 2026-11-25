/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_script_debug_hook_80101dd4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lua_getinfo = 0x802cef54;
lua_getstack = 0x802ceb88;
lua_settop = 0x802cd808;
lua_tostring = 0x802cdd04;
w3d_fn_80100bbc = 0x80100bbc;
w3d_fn_801020b0 = 0x801020b0;
w3d_fn_801022ec = 0x801022ec;
w3d_fn_801029c8 = 0x801029c8;
w3d_fn_80102a34 = 0x80102a34;
w3d_get_80102734 = 0x80102734;
w3d_script_log = 0x801022b0;
w3d_script_output_hook = 0x801022e8;
w3d_script_service_from_lua = 0x80101018;
w3d_script_set_run_state = 0x8010272c;
w3d_script_source_line = 0x80102890;
w3d_str_80398da4 = 0x80398da4;
w3d_str_80398da8 = 0x80398da8;
w3d_str_80398dbc = 0x80398dbc;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_default = 0x803426b8;
w3d_string_format = 0x8020c510;
w3d_string_release = 0x80341588;
SECTIONS {
  .text.w3d_script_debug_hook_80101dd4 0x80101dd4 : { *(.text.w3d_script_debug_hook_80101dd4) }
  .text.w3d_fn_80101e08 0x80101e08 : { *(.text.w3d_fn_80101e08) }
  .text.w3d_script_lua_error_80102028 0x80102028 : { *(.text.w3d_script_lua_error_80102028) }
  .sdata 0x804aaa04 (NOLOAD) : {
    . = 0x0; w3d_obj_804aaa04 = .;
    . = 0xa34; w3d_obj_804ab438 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
