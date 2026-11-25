/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k6b_font_box_construct_80222880)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8021ef08 = 0x8021ef08;
lbl_803b6408 = 0x803b6408;
lbl_803b6e84 = 0x803b6e84;
lbl_8041a460 = 0x8041a460;
lbl_804b06a0 = 0x804b06a0;
w3d_string_base_init = 0x8020c5c0;
w3d_string_from_text = 0x8020bb54;
w3d_string_header = 0x80341884;
SECTIONS {
  .text.w3d_k6b_font_box_construct_80222880 0x80222880 : { *(.text.w3d_k6b_font_box_construct_80222880) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
