/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_set_highlight_80188570)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801d4544 = 0x801d4544;
SECTIONS {
  .text.w3d_set_highlight_80188570 0x80188570 : { *(.text.w3d_set_highlight_80188570) }
  .text.w3d_set_highlight_80188618 0x80188618 : { *(.text.w3d_set_highlight_80188618) }
  .sdata 0x804b0204 (NOLOAD) : {
    . = 0x0; lbl_804b0204 = .;
    . = 0x4; lbl_804b0208 = .;
    . = 0x10; lbl_804b0214 = .;
    . = 0x14; lbl_804b0218 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
