/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_8005150c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8015FEF0 = 0x8015fef0;
lbl_8040EB20 = 0x8040eb20;
SECTIONS {
  .text.w3d_auto_8005150c 0x8005150c : { *(.text.w3d_auto_8005150c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
