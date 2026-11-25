/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(tterra_cw39_shift_word_803339f4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.tterra_cw39_shift_word_803339f4 0x803339f4 : { *(.text.tterra_cw39_shift_word_803339f4) }
  .text.tterra_cw39_shift_80333a4c 0x80333a4c : { *(.text.tterra_cw39_shift_80333a4c) }
  .text.tterra_cw39_set_byte_80333c94 0x80333c94 : { *(.text.tterra_cw39_set_byte_80333c94) }
  .text.tterra_cw39_get_byte_80333c9c 0x80333c9c : { *(.text.tterra_cw39_get_byte_80333c9c) }
  .text.tterra_cw39_set_word_80333cc4 0x80333cc4 : { *(.text.tterra_cw39_set_word_80333cc4) }
  .text.tterra_cw39_reset_word_803349b0 0x803349b0 : { *(.text.tterra_cw39_reset_word_803349b0) }
  .sdata 0x804b1648 (NOLOAD) : {
    . = 0x0; state_804b1648 = .;
    . = 0xec; state_804b1734 = .;
    . = 0x100; state_804b1748 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
