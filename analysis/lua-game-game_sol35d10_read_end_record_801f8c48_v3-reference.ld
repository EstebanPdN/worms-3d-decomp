/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(sol35d10_read_end_record_801f8c48_v3)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801f87f0 = 0x801f87f0;
fn_801f881c = 0x801f881c;
fn_801f8830 = 0x801f8830;
SECTIONS {
  .text.sol35d10_read_end_record_801f8c48_v3 0x801f8c48 : { *(.text.sol35d10_read_end_record_801f8c48_v3) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
