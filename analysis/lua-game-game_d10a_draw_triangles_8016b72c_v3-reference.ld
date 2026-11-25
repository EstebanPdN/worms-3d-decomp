/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d10a_draw_triangles_8016b72c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d10a_allocate_80166fd0 = 0x80166fd0;
d10a_apply_mesh_8016b5a0 = 0x8016b5a0;
d10a_begin_list_8016aef0 = 0x8016aef0;
d10a_call_list_8016aec0 = 0x8016aec0;
d10a_emit_8016b384 = 0x8016b384;
d10a_finish_streams_8016b040 = 0x8016b040;
d10a_save_list_8016afc8 = 0x8016afc8;
d10a_set_format_8016797c = 0x8016797c;
SECTIONS {
  .text.d10a_draw_triangles_8016b72c 0x8016b72c : { *(.text.d10a_draw_triangles_8016b72c) }
  .sdata 0x804b1884 (NOLOAD) : {
    . = 0x0; d10a_renderer_804b1884 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
