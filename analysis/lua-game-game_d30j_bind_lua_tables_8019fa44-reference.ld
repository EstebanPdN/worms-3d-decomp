/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d30j_bind_lua_tables_8019fa44)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8019e710 = 0x8019e710;
fn_8019f838 = 0x8019f838;
fn_8019f8a0 = 0x8019f8a0;
fn_8019f8f0 = 0x8019f8f0;
lbl_803a9a5c = 0x803a9a5c;
lbl_803a9a64 = 0x803a9a64;
lbl_803a9a70 = 0x803a9a70;
lbl_803a9a94 = 0x803a9a94;
luaL_ref = 0x802dd76c;
lua_gettop = 0x802cd7f4;
lua_pushcclosure = 0x802ce148;
lua_pushstring = 0x802cdfd4;
lua_pushvalue = 0x802cd99c;
lua_settable = 0x802ce4d8;
lua_settop = 0x802cd808;
w3d_auto_801a0304 = 0x801a0304;
w3d_auto_801a03f0 = 0x801a03f0;
w3d_auto_801a0448 = 0x801a0448;
SECTIONS {
  .text.d30j_bind_lua_tables_8019fa44 0x8019fa44 : { *(.text.d30j_bind_lua_tables_8019fa44) }
  .sdata 0x804b1950 (NOLOAD) : {
    . = 0x0; lbl_804b1950 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
