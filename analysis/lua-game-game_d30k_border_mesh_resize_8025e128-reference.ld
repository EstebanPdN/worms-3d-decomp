/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d30k_border_mesh_resize_8025e128)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801750d4 = 0x801750d4;
fn_801ef048 = 0x801ef048;
fn_801f55ec = 0x801f55ec;
lbl_804012c0 = 0x804012c0;
SECTIONS {
  .text.w3d_d30k_border_mesh_resize_8025e128 0x8025e128 : { *(.text.w3d_d30k_border_mesh_resize_8025e128) }
  .rodata 0x803caa78 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
