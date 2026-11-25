/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_80021ce8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80035714 = 0x80035714;
lbl_8036C174 = 0x8036c174;
SECTIONS {
  .text.w3d_auto_80021ce8 0x80021ce8 : { *(.text.w3d_auto_80021ce8) }
  .sdata 0x804aa8c8 (NOLOAD) : {
    . = 0x0; lbl_804AA8C8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
