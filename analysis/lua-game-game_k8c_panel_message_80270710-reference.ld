/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k8c_panel_message_80270710)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8015fb34 = 0x8015fb34;
fn_802707f0 = 0x802707f0;
fn_80270bdc = 0x80270bdc;
fn_802aff9c = 0x802aff9c;
fn_802b264c = 0x802b264c;
SECTIONS {
  .text.w3d_k8c_panel_message_80270710 0x80270710 : { *(.text.w3d_k8c_panel_message_80270710) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
