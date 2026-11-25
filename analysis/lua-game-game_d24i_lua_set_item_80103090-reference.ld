/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24i_lua_set_item_80103090)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__11d24i_StringPCc = 0x8020bb54;
d24i_as_item_80341584 = 0x80341584;
d24i_error_count_8039911c = 0x8039911c;
d24i_error_kind_803991b8 = 0x803991b8;
d24i_error_name_80399188 = 0x80399188;
d24i_error_type_80399158 = 0x80399158;
d24i_item_801797b4 = 0x801797b4;
d24i_script_error_801022ec = 0x801022ec;
d24i_setting_lookup_800fc1b0 = 0x800fc1b0;
d24i_string_finish_8020c5c4 = 0x8020c5c4;
d24i_string_release_80341588 = 0x80341588;
lua_gettop = 0x802cd7f4;
lua_isstring = 0x802cdaf4;
lua_settop = 0x802cd808;
lua_tostring = 0x802cdd04;
SECTIONS {
  .text.d24i_lua_set_item_80103090 0x80103090 : { *(.text.d24i_lua_set_item_80103090) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
