/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d32l_rect_mesh_802ae5f8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801750d4 = 0x801750d4;
fn_801ef048 = 0x801ef048;
fn_801f55ec = 0x801f55ec;
lbl_80403c0c = 0x80403c0c;
SECTIONS {
  .text.d32l_rect_mesh_802ae5f8 0x802ae5f8 : { *(.text.d32l_rect_mesh_802ae5f8) }
  .rodata 0x803d784c : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
