/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(g2b_accumulate_callbacks_801a572c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
default_8045e63c = 0x8045e63c;
fn_801f53bc = 0x801f53bc;
SECTIONS {
  .text.g2b_accumulate_callbacks_801a572c 0x801a572c : { *(.text.g2b_accumulate_callbacks_801a572c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
