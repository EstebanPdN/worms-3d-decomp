/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_randomize_three_80015910)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_80015f80 = 0x80015f80;
FUN_80016494 = 0x80016494;
w3d_auto_800158b8 = 0x800158b8;
SECTIONS {
  .text.s19_randomize_three_80015910 0x80015910 : { *(.text.s19_randomize_three_80015910) }
  .text.s19_poll_then_80015f38 0x80015f38 : { *(.text.s19_poll_then_80015f38) }
  .text.s19_poll_then_8001644c 0x8001644c : { *(.text.s19_poll_then_8001644c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
