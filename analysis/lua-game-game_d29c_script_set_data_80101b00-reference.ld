/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d29c_script_set_data_80101b00)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__15String_8020bb54PCc = 0x8020bb54;
asFloat_80342a74 = 0x80342a74;
asInt2_80342a78 = 0x80342a78;
asInt_803426b4 = 0x803426b4;
asText_80343744 = 0x80343744;
error_801022ec = 0x801022ec;
lookup_800fc1b0 = 0x800fc1b0;
lua_gettop = 0x802cd7f4;
lua_isnumber = 0x802cda9c;
lua_isstring = 0x802cdaf4;
lua_settop = 0x802cd808;
lua_tonumber = 0x802cdc5c;
lua_tostring = 0x802cdd04;
s1_80398ca0 = 0x80398ca0;
s2_80398cd4 = 0x80398cd4;
s3_80398d00 = 0x80398d00;
s4_80398d28 = 0x80398d28;
s5_80398d54 = 0x80398d54;
s6_80398d80 = 0x80398d80;
setFloat_80178dfc = 0x80178dfc;
setInt2_80178d28 = 0x80178d28;
setInt_80178c54 = 0x80178c54;
setText_801790bc = 0x801790bc;
str_default_803426b8 = 0x803426b8;
str_finish_8020c5c4 = 0x8020c5c4;
str_format_8020c510 = 0x8020c510;
str_release_80341588 = 0x80341588;
SECTIONS {
  .text.d29c_script_set_data_80101b00 0x80101b00 : { *(.text.d29c_script_set_data_80101b00) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
