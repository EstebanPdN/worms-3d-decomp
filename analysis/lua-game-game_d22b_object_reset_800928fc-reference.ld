/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d22b_object_reset_800928fc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d22b_array_append_801ef174 = 0x801ef174;
d22b_array_erase_801ef380 = 0x801ef380;
d22b_attach_800927b4 = 0x800927b4;
d22b_clear_pair_8008ecac = 0x8008ecac;
d22b_prepare_80092388 = 0x80092388;
d22b_set_colour_80092234 = 0x80092234;
d22b_set_mode_800919cc = 0x800919cc;
SECTIONS {
  .text.d22b_object_reset_800928fc 0x800928fc : { *(.text.d22b_object_reset_800928fc) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
