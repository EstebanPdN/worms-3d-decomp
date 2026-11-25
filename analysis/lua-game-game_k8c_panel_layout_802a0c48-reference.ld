/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k8c_panel_layout_802a0c48)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802a06ac = 0x802a06ac;
fn_802a0f98 = 0x802a0f98;
fn_802b1880 = 0x802b1880;
SECTIONS {
  .text.w3d_k8c_panel_layout_802a0c48 0x802a0c48 : { *(.text.w3d_k8c_panel_layout_802a0c48) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
