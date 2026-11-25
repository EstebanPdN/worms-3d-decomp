/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k8b_item_emit_8016b640)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8016797c = 0x8016797c;
w3d_cx13b_gx_index_stream_emit_8016b3f0 = 0x8016b3f0;
w3d_s20_dispatch_item_fields_8016b488 = 0x8016b488;
SECTIONS {
  .text.w3d_k8b_item_emit_8016b640 0x8016b640 : { *(.text.w3d_k8b_item_emit_8016b640) }
  .sdata 0x804b1884 (NOLOAD) : {
    . = 0x0; lbl_804b1884 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
