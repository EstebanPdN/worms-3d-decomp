/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_transplant_800bea4c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80174820 = 0x80174820;
fn_8020b680 = 0x8020b680;
lbl_804144f8 = 0x804144f8;
SECTIONS {
  .text.s8_transplant_800bea4c 0x800bea4c : { *(.text.s8_transplant_800bea4c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
