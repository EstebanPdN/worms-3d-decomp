/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(particle_quads_emit_8016c7d0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d30j_set_vertex_format_8016797c = 0x8016797c;
fifo_cc008000 = 0xcc008000;
gx_begin_803089c8 = 0x803089c8;
lbl_803a5f3c = 0x803a5f3c;
pop_world_8016a194 = 0x8016a194;
push_world_8016a1bc = 0x8016a1bc;
SECTIONS {
  .text.particle_quads_emit_8016c7d0 0x8016c7d0 : { *(.text.particle_quads_emit_8016c7d0) }
  .rodata 0x803a570c : { *(.rodata) }
  .sdata 0x804b00f4 (NOLOAD) : {
    . = 0x0; lbl_804b00f4 = .;
    . = 0x8; lbl_804b00fc = .;
    . = 0x1790; lbl_804b1884 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
