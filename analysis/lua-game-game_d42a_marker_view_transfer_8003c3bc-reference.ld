/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d42a_marker_view_transfer_8003c3bc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__5Point = 0x80343740;
w3d_auto_801f76e0 = 0x801f76e0;
w3d_d30a_marker_screen_project_8003cac8 = 0x8003cac8;
w3d_k5b_mtx34_from_mtx44_801f74d0 = 0x801f74d0;
SECTIONS {
  .text.w3d_d42a_marker_view_transfer_8003c3bc 0x8003c3bc : { *(.text.w3d_d42a_marker_view_transfer_8003c3bc) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; lbl_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
