/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k6b_named_panel_construct_8022526c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8021fd28 = 0x8021fd28;
lbl_8041a348 = 0x8041a348;
lbl_804b06a0 = 0x804b06a0;
w3d_string_base_init = 0x8020c5c0;
w3d_string_header = 0x80341884;
SECTIONS {
  .text.w3d_k6b_named_panel_construct_8022526c 0x8022526c : { *(.text.w3d_k6b_named_panel_construct_8022526c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
