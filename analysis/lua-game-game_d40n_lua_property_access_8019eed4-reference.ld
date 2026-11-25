/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d40n_lua_property_access_8019eed4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8019e7e8 = 0x8019e7e8;
fn_8019e848 = 0x8019e848;
fn_8019e8d0 = 0x8019e8d0;
fn_8019e96c = 0x8019e96c;
fn_8019ed40 = 0x8019ed40;
fn_8019ee18 = 0x8019ee18;
luaL_checklstring = 0x802dd028;
lua_concat = 0x802ce920;
lua_equal = 0x802cdbd0;
lua_error = 0x802ce89c;
lua_getmetatable = 0x802ce3d4;
lua_isnumber = 0x802cda9c;
lua_isstring = 0x802cdaf4;
lua_isuserdata = 0x802cdb24;
lua_pushboolean = 0x802ce214;
lua_pushcclosure = 0x802ce148;
lua_pushnumber = 0x802cdf40;
lua_pushstring = 0x802cdfd4;
lua_pushvalue = 0x802cd99c;
lua_settop = 0x802cd808;
lua_toboolean = 0x802cdcb0;
lua_tonumber = 0x802cdc5c;
lua_touserdata = 0x802cde08;
lua_type = 0x802cd9e8;
str_append_803a999c = 0x803a999c;
str_set_803a99a4 = 0x803a99a4;
strncmp = 0x802efb1c;
w3d_auto_801fffc8 = 0x801fffc8;
w3d_d29e_find_by_name_801e9e84 = 0x801e9e84;
w3d_dtor_node_8020d36c = 0x8020d36c;
w3d_format_into_80347a10 = 0x80347a10;
w3d_format_into_80351df8 = 0x80351df8;
w3d_registry_retain_8020d2b8 = 0x8020d2b8;
w3d_s21_kind_is_t_801fff60 = 0x801fff60;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_default = 0x803426b8;
w3d_string_release = 0x80341588;
w3d_tagged_construct_8020d318 = 0x8020d318;
SECTIONS {
  .text.w3d_d40n_lua_property_access_8019eed4 0x8019eed4 : { *(.text.w3d_d40n_lua_property_access_8019eed4) }
  .rodata 0x803a99a8 : { *(.rodata) }
  .sdata 0x804ab728 (NOLOAD) : {
    . = 0x0; lbl_804ab728 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
