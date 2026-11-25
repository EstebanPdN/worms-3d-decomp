/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_8020d44c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8020C3A0 = 0x8020c3a0;
fn_8020C43C = 0x8020c43c;
SECTIONS {
  .text.w3d_auto_8020d44c 0x8020d44c : { *(.text.w3d_auto_8020d44c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
