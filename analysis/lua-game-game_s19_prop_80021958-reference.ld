/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_check_bullet_count_80021958)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_800fc230 = 0x800fc230;
SECTIONS {
  .text.s19_check_bullet_count_80021958 0x80021958 : { *(.text.s19_check_bullet_count_80021958) }
  .rodata 0x8036c090 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
