/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(billboard_quads_emit_8016cd38)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d30j_set_vertex_format_8016797c = 0x8016797c;
fifo_cc008000 = 0xcc008000;
gx_begin_803089c8 = 0x803089c8;
lbl_803a5f3c = 0x803a5f3c;
SECTIONS {
  .text.billboard_quads_emit_8016cd38 0x8016cd38 : { *(.text.billboard_quads_emit_8016cd38) }
  .rodata 0x803a5718 : { *(.rodata) }
  .sdata 0x804b0100 (NOLOAD) : {
    . = 0x0; lbl_804b0100 = .;
    . = 0x8; lbl_804b0108 = .;
    . = 0x1784; lbl_804b1884 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
