/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_worm_pot_tick)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_worm_pot_update_text_80140fc8 = 0x80140fc8;
SECTIONS {
  .text.w3d_worm_pot_tick 0x80140a5c : { *(.text.w3d_worm_pot_tick) }
  .rodata 0x803a0408 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
