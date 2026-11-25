/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d28k_gauge_message_80265294)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
current_802b264c__3Ctx = 0x802b264c;
fn_80069a50 = 0x80069a50;
fn_8015f65c = 0x8015f65c;
fn_8015fb34 = 0x8015fb34;
fn_80265d34 = 0x80265d34;
fn_80265fb4 = 0x80265fb4;
fn_80268420 = 0x80268420;
fn_802684c4 = 0x802684c4;
fn_802b1258 = 0x802b1258;
fn_802b22e4 = 0x802b22e4;
forward_802aff9c__3CtxP3Msg = 0x802aff9c;
report_802b22b0__3Ctx = 0x802b22b0;
SECTIONS {
  .text.w3d_d28k_gauge_message_80265294 0x80265294 : { *(.text.w3d_d28k_gauge_message_80265294) }
  .sdata 0x804abb48 (NOLOAD) : {
    . = 0x0; lbl_804abb48 = .;
    . = 0x4f4c; lbl_804b0a94 = .;
    . = 0x4f54; lbl_804b0a9c = .;
    . = 0x4f5c; lbl_804b0aa4 = .;
    . = 0x4f64; lbl_804b0aac = .;
    . = 0x4f6c; lbl_804b0ab4 = .;
    . = 0x4f74; lbl_804b0abc = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
