/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27j_start_sound_8019a30c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
drop_8019ab0c = 0x8019ab0c;
play_8019a868 = 0x8019a868;
SECTIONS {
  .text.d27j_start_sound_8019a30c 0x8019a30c : { *(.text.d27j_start_sound_8019a30c) }
  .rodata 0x803a86f4 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
