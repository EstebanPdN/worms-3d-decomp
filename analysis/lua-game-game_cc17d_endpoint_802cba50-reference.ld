/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc17d_endpoint_has_queued_802cba50)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802cb314 = 0x802cb314;
lbl_80473724 = 0x80473724;
lbl_804737a4 = 0x804737a4;
lbl_804738a4 = 0x804738a4;
SECTIONS {
  .text.w3d_cc17d_endpoint_has_queued_802cba50 0x802cba50 : { *(.text.w3d_cc17d_endpoint_has_queued_802cba50) }
  .text.w3d_cc17d_endpoint_query_802cbacc 0x802cbacc : { *(.text.w3d_cc17d_endpoint_query_802cbacc) }
  .sdata 0x804abce4 (NOLOAD) : {
    . = 0x0; lbl_804abce4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
