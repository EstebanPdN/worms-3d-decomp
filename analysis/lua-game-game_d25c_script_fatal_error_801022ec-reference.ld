/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d25c_script_fatal_error_801022ec)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6String = 0x803426b8;
arena_alloc_801613f0 = 0x801613f0;
cached_id_8015f5a0 = 0x8015f5a0;
info_what_80398da4 = 0x80398da4;
log_801022b0 = 0x801022b0;
lua_getinfo = 0x802cef54;
lua_getstack = 0x802ceb88;
message_init_8010a8e0 = 0x8010a8e0;
message_post_8016239c = 0x8016239c;
output_801022e8 = 0x801022e8;
set_state_8010272c = 0x8010272c;
source_line_80102890 = 0x80102890;
string_finish_8020c5c4 = 0x8020c5c4;
string_format_8020c510 = 0x8020c510;
string_release_80341588 = 0x80341588;
SECTIONS {
  .text.d25c_script_fatal_error_801022ec 0x801022ec : { *(.text.d25c_script_fatal_error_801022ec) }
  .rodata 0x80398de8 : { *(.rodata) }
  .sdata 0x804af164 (NOLOAD) : {
    . = 0x0; fail_id_804af164 = .;
    . = 0x25f0; arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
