/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k6b_font_label_construct_80220afc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8021ef08 = 0x8021ef08;
lbl_803b6408 = 0x803b6408;
lbl_803b6654 = 0x803b6654;
lbl_8041a550 = 0x8041a550;
lbl_804b06a0 = 0x804b06a0;
w3d_string_base_init = 0x8020c5c0;
w3d_string_from_text = 0x8020bb54;
w3d_string_header = 0x80341884;
SECTIONS {
  .text.w3d_k6b_font_label_construct_80220afc 0x80220afc : { *(.text.w3d_k6b_font_label_construct_80220afc) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
