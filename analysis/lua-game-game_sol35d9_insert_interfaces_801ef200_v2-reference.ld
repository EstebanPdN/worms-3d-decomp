/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(sol35d9_insert_interfaces_801ef200_v2)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801ef048 = 0x801ef048;
SECTIONS {
  .text.sol35d9_insert_interfaces_801ef200_v2 0x801ef200 : { *(.text.sol35d9_insert_interfaces_801ef200_v2) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
