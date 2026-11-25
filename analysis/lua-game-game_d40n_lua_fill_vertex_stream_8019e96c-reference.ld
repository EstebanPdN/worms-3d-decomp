/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d40n_lua_fill_vertex_stream_8019e96c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
convert_key_80419500 = 0x80419500;
fn_801ffea8 = 0x801ffea8;
fn_80200050 = 0x80200050;
fn_80200134 = 0x80200134;
fn_80200158 = 0x80200158;
fn_8020b648 = 0x8020b648;
lua_gettable = 0x802ce264;
lua_isnumber = 0x802cda9c;
lua_pushnumber = 0x802cdf40;
lua_pushstring = 0x802cdfd4;
lua_settop = 0x802cd808;
lua_tonumber = 0x802cdc5c;
lua_type = 0x802cd9e8;
type_float_8045ed7c = 0x8045ed7c;
w3d_k6b_lua_table_length_802cd408 = 0x802cd408;
SECTIONS {
  .text.w3d_d40n_lua_fill_vertex_stream_8019e96c 0x8019e96c : { *(.text.w3d_d40n_lua_fill_vertex_stream_8019e96c) }
  .rodata 0x803a9988 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
