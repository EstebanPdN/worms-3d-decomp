/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc29b_update_text_8018c3a0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8018dc98 = 0x8018dc98;
lbl_803a7e28 = 0x803a7e28;
SECTIONS {
  .text.w3d_cc29b_update_text_8018c3a0 0x8018c3a0 : { *(.text.w3d_cc29b_update_text_8018c3a0) }
  .sdata 0x804ab5fc (NOLOAD) : {
    . = 0x0; lbl_804ab5fc = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
