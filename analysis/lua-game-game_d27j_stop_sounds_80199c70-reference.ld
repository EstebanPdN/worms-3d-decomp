/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27j_stop_sounds_80199c70)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
drop_8019ab0c = 0x8019ab0c;
SECTIONS {
  .text.d27j_stop_sounds_80199c70 0x80199c70 : { *(.text.d27j_stop_sounds_80199c70) }
  .rodata 0x803a86f0 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
