/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d30j_set_vertex_format_8016797c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80306cd0 = 0x80306cd0;
fn_80307558 = 0x80307558;
fn_80307590 = 0x80307590;
fn_8030972c = 0x8030972c;
fn_8030981c = 0x8030981c;
s9_apply_render_state_80167dd4 = 0x80167dd4;
w3d_auto_8016803c = 0x8016803c;
w3d_auto_8016804c = 0x8016804c;
SECTIONS {
  .text.d30j_set_vertex_format_8016797c 0x8016797c : { *(.text.d30j_set_vertex_format_8016797c) }
  .sdata 0x804ab500 (NOLOAD) : {
    . = 0x0; lbl_804ab500 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
