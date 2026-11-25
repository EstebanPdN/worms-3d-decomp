/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc29b_replace_font_8018dfa0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801b14e8 = 0x801b14e8;
fn_801ea470 = 0x801ea470;
fn_8034435c = 0x8034435c;
SECTIONS {
  .text.w3d_cc29b_replace_font_8018dfa0 0x8018dfa0 : { *(.text.w3d_cc29b_replace_font_8018dfa0) }
  .sdata 0x804b0238 (NOLOAD) : {
    . = 0x0; lbl_804b0238 = .;
    . = 0x4; lbl_804b023c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
