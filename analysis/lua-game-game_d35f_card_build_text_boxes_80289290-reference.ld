/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d35f_card_build_text_boxes_80289290)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6StringPCc = 0x8020bb54;
fn_8006ee88 = 0x8006ee88;
fn_800fc2b0 = 0x800fc2b0;
fn_8018c5b0 = 0x8018c5b0;
fn_8018d35c = 0x8018d35c;
fn_8018d434 = 0x8018d434;
fn_80289914 = 0x80289914;
fn_80289a08 = 0x80289a08;
fn_80289a34 = 0x80289a34;
fn_8028a1c0 = 0x8028a1c0;
fn_8028a2b0 = 0x8028a2b0;
fn_8028a784 = 0x8028a784;
fn_80343580 = 0x80343580;
lbl_803cf9f4 = 0x803cf9f4;
lbl_803cf9fc = 0x803cf9fc;
w3d_handle_load_8015adf4 = 0x8015adf4;
w3d_string_finish_8020c5c4 = 0x8020c5c4;
w3d_string_release_80341588 = 0x80341588;
SECTIONS {
  .text.d35f_card_build_text_boxes_80289290 0x80289290 : { *(.text.d35f_card_build_text_boxes_80289290) }
  .rodata 0x803cfa00 : { *(.rodata) }
  .sdata 0x804aaabc (NOLOAD) : {
    . = 0x0; lbl_804aaabc = .;
    . = 0x10a0; lbl_804abb5c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
