/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d29k_textbox_message_8026e288)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
atol = 0x802ed8c4;
current_802b264c__3Ctl = 0x802b264c;
fn_80069a50 = 0x80069a50;
fn_8010a904 = 0x8010a904;
fn_8015f65c = 0x8015f65c;
fn_8015fb34 = 0x8015fb34;
fn_8026e98c = 0x8026e98c;
fn_8026ec30 = 0x8026ec30;
fn_8026f820 = 0x8026f820;
fn_8026f948 = 0x8026f948;
fn_8026fc98 = 0x8026fc98;
fn_80270300 = 0x80270300;
fn_802bc71c = 0x802bc71c;
fn_802bc8b4 = 0x802bc8b4;
forward_802aff9c__3CtlP3Msg = 0x802aff9c;
strcmp = 0x802ef234;
SECTIONS {
  .text.w3d_d29k_textbox_message_8026e288 0x8026e288 : { *(.text.w3d_d29k_textbox_message_8026e288) }
  .rodata 0x803cbde8 : { *(.rodata) }
  .sdata 0x804abb48 (NOLOAD) : {
    . = 0x0; lbl_804abb48 = .;
    . = 0x4f98; lbl_804b0ae0 = .;
    . = 0x4fa0; lbl_804b0ae8 = .;
    . = 0x4fa8; lbl_804b0af0 = .;
    . = 0x4fb0; lbl_804b0af8 = .;
    . = 0x4fb8; lbl_804b0b00 = .;
    . = 0x4fc0; lbl_804b0b08 = .;
    . = 0x4fc8; lbl_804b0b10 = .;
    . = 0x4fd0; lbl_804b0b18 = .;
    . = 0x4fd8; lbl_804b0b20 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
