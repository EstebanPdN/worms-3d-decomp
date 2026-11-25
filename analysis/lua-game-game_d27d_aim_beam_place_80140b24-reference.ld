/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27d_aim_beam_place_80140b24)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
invert_801f6c2c = 0x801f6c2c;
lookup_80164fc8 = 0x80164fc8;
ratio_8011ba08 = 0x8011ba08;
SECTIONS {
  .text.d27d_aim_beam_place_80140b24 0x80140b24 : { *(.text.d27d_aim_beam_place_80140b24) }
  .rodata 0x803a0420 : { *(.rodata) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; settings_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
