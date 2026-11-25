/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_transplant_800e3528)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800de930 = 0x800de930;
fn_800e35fc = 0x800e35fc;
fn_8020fd04 = 0x8020fd04;
lbl_80360d50 = 0x80360d50;
SECTIONS {
  .text.s8_transplant_800e3528 0x800e3528 : { *(.text.s8_transplant_800e3528) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
