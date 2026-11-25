/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc31b_accept_endpoint_802cc8ec)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802cce78 = 0x802cce78;
fn_802ef9c0 = 0x802ef9c0;
lbl_80403f54 = 0x80403f54;
lbl_80473764 = 0x80473764;
SECTIONS {
  .text.w3d_cc31b_accept_endpoint_802cc8ec 0x802cc8ec : { *(.text.w3d_cc31b_accept_endpoint_802cc8ec) }
  .sdata 0x804abcc4 (NOLOAD) : {
    . = 0x0; lbl_804abcc4 = .;
    . = 0x20; lbl_804abce4 = .;
    . = 0x53ec; lbl_804b10b0 = .;
    . = 0x5c9c; lbl_804b1960 = .;
    . = 0x5ca0; lbl_804b1964 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
