/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d29c_script_get_data_801016ec)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__15String_8020bb54PCc = 0x8020bb54;
asFloat_80342a74 = 0x80342a74;
asInt2_80342a78 = 0x80342a78;
asInt_803426b4 = 0x803426b4;
asText_80343744 = 0x80343744;
error_801022ec = 0x801022ec;
getFloat_80178df0 = 0x80178df0;
getInt2_80178d1c = 0x80178d1c;
getInt_80178c48 = 0x80178c48;
getText_80179170 = 0x80179170;
lookup_800fc1b0 = 0x800fc1b0;
lua_gettop = 0x802cd7f4;
lua_isstring = 0x802cdaf4;
lua_pushnumber = 0x802cdf40;
lua_pushstring = 0x802cdfd4;
lua_settop = 0x802cd808;
lua_tostring = 0x802cdd04;
s1_80398be0 = 0x80398be0;
s2_80398c14 = 0x80398c14;
s3_80398c40 = 0x80398c40;
s4_80398c68 = 0x80398c68;
s5_80398c74 = 0x80398c74;
str_append_8020bf2c = 0x8020bf2c;
str_finish_8020c5c4 = 0x8020c5c4;
str_header_80341884 = 0x80341884;
str_init_8020c5c0 = 0x8020c5c0;
str_release_80341588 = 0x80341588;
SECTIONS {
  .text.d29c_script_get_data_801016ec 0x801016ec : { *(.text.d29c_script_get_data_801016ec) }
  .rodata 0x80398c90 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
