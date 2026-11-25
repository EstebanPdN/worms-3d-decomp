/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s9_permute_80160708)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8015FC84 = 0x8015fc84;
fn_801613F0 = 0x801613f0;
lbl_8040DB38 = 0x8040db38;
SECTIONS {
  .text.s9_permute_80160708 0x80160708 : { *(.text.s9_permute_80160708) }
  .sdata 0x804b1754 (NOLOAD) : {
    . = 0x0; lbl_804B1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
