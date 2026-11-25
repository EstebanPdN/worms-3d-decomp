/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_reset_typed_800eba70)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8015f5a0 = 0x8015f5a0;
fn_8015fc58 = 0x8015fc58;
fn_801613f0 = 0x801613f0;
lbl_8040db38 = 0x8040db38;
SECTIONS {
  .text.s8_reset_typed_800eba70 0x800eba70 : { *(.text.s8_reset_typed_800eba70) }
  .sdata 0x804aef08 (NOLOAD) : {
    . = 0x0; lbl_804aef08 = .;
    . = 0x284c; lbl_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
