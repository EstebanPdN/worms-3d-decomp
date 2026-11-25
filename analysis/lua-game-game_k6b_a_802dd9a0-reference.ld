/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k6b_lua_errfile_802dd9a0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802ef3f0 = 0x802ef3f0;
lbl_803da870 = 0x803da870;
lua_pushfstring = 0x802ce07c;
lua_remove = 0x802cd878;
lua_tostring = 0x802cdd04;
w3d_heap_errno = 0x802eafc4;
SECTIONS {
  .text.w3d_k6b_lua_errfile_802dd9a0 0x802dd9a0 : { *(.text.w3d_k6b_lua_errfile_802dd9a0) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
