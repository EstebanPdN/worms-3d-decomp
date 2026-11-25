/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(tsonnet_c30_ctor_801be730)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801b4e94 = 0x801b4e94;
lbl_80415050 = 0x80415050;
lbl_8045e708 = 0x8045e708;
SECTIONS {
  .text.tsonnet_c30_ctor_801be730 0x801be730 : { *(.text.tsonnet_c30_ctor_801be730) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
