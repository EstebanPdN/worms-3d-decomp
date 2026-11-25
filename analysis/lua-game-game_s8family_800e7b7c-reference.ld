/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_message_initialize_800e7b7c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800e7be8 = 0x800e7be8;
fn_8016293c = 0x8016293c;
SECTIONS {
  .text.s8_message_initialize_800e7b7c 0x800e7b7c : { *(.text.s8_message_initialize_800e7b7c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
