/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_800e0678)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800DE988 = 0x800de988;
fn_8015FEF0 = 0x8015fef0;
lbl_8040FFB8 = 0x8040ffb8;
lbl_8040FFD8 = 0x8040ffd8;
SECTIONS {
  .text.w3d_auto_800e0678 0x800e0678 : { *(.text.w3d_auto_800e0678) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
