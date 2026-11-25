/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_finish_chain_80200bfc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80200c44 = 0x80200c44;
SECTIONS {
  .text.w3d_s21_finish_chain_80200bfc 0x80200bfc : { *(.text.w3d_s21_finish_chain_80200bfc) }
  .sdata 0x804b18e8 (NOLOAD) : {
    . = 0x0; lbl_804b18e8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
