/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s9_permute_8018b4cc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8018A864 = 0x8018a864;
fn_8018B404 = 0x8018b404;
fn_801FE160 = 0x801fe160;
SECTIONS {
  .text.s9_permute_8018b4cc 0x8018b4cc : { *(.text.s9_permute_8018b4cc) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
