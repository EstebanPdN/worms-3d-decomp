/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k4b_font_ref_construct_80226e20)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_803b6408 = 0x803b6408;
lbl_8041a1b8 = 0x8041a1b8;
w3d_string_from_text = 0x8020bb54;
w3d_tagged_construct_801ea0ec = 0x801ea0ec;
SECTIONS {
  .text.w3d_k4b_font_ref_construct_80226e20 0x80226e20 : { *(.text.w3d_k4b_font_ref_construct_80226e20) }
  .rodata 0x803b80c8 : { *(.rodata) }
  .sdata 0x804b05ac (NOLOAD) : {
    . = 0x0; lbl_804b05ac = .;
    . = 0x4; lbl_804b05b0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
