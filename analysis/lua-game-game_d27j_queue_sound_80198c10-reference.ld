/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27j_queue_sound_80198c10)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
alloc_801907a8 = 0x801907a8;
release_801907d0 = 0x801907d0;
start_8019a30c = 0x8019a30c;
SECTIONS {
  .text.d27j_queue_sound_80198c10 0x80198c10 : { *(.text.d27j_queue_sound_80198c10) }
  .rodata 0x803a86d4 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
