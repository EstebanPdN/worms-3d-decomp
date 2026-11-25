/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_bound_800cc620)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8015f518 = 0x8015f518;
lbl_80387d60 = 0x80387d60;
SECTIONS {
  .text.s8_bound_800cc620 0x800cc620 : { *(.text.s8_bound_800cc620) }
  .sdata 0x804aae24 (NOLOAD) : {
    . = 0x0; lbl_804aae24 = .;
    . = 0x39f0; lbl_804ae814 = .;
    . = 0x39f4; lbl_804ae818 = .;
    . = 0x39f8; lbl_804ae81c = .;
    . = 0x39fc; lbl_804ae820 = .;
    . = 0x3a00; lbl_804ae824 = .;
    . = 0x3a04; lbl_804ae828 = .;
    . = 0x3a08; lbl_804ae82c = .;
    . = 0x3a0c; lbl_804ae830 = .;
    . = 0x3a10; lbl_804ae834 = .;
    . = 0x3a14; lbl_804ae838 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
