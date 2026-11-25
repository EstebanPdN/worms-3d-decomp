/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_handle_message_80022d00)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_80022d6c = 0x80022d6c;
w3d_auto_8016293c = 0x8016293c;
SECTIONS {
  .text.s19_handle_message_80022d00 0x80022d00 : { *(.text.s19_handle_message_80022d00) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
