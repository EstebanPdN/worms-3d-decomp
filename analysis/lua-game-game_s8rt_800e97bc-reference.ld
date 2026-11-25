/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_recovered_800e97bc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800E8EE0 = 0x800e8ee0;
fn_800E8F40 = 0x800e8f40;
fn_800E9830 = 0x800e9830;
fn_801797B4 = 0x801797b4;
fn_80341584 = 0x80341584;
SECTIONS {
  .text.s8_recovered_800e97bc 0x800e97bc : { *(.text.s8_recovered_800e97bc) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
