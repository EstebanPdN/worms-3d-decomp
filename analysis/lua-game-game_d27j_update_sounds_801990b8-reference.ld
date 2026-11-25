/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27j_update_sounds_801990b8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
drop_8019ab0c = 0x8019ab0c;
SECTIONS {
  .text.d27j_update_sounds_801990b8 0x801990b8 : { *(.text.d27j_update_sounds_801990b8) }
  .rodata 0x803a86d8 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
