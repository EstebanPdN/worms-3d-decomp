/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d32l_rect_mesh_b_802baf1c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801750d4 = 0x801750d4;
fn_801ef048 = 0x801ef048;
fn_801f55ec = 0x801f55ec;
lbl_80403c48 = 0x80403c48;
SECTIONS {
  .text.d32l_rect_mesh_b_802baf1c 0x802baf1c : { *(.text.d32l_rect_mesh_b_802baf1c) }
  .rodata 0x803d8244 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
