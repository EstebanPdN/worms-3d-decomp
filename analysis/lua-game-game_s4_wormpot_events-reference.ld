/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s4_wormpot_first_changed)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_fn_802aa5f0 = 0x802aa5f0;
w3d_fn_802ab378 = 0x802ab378;
w3d_string_base_init = 0x8020c5c0;
w3d_string_header = 0x80341884;
SECTIONS {
  .text.w3d_s4_wormpot_first_changed 0x802aa3ec : { *(.text.w3d_s4_wormpot_first_changed) }
  .text.w3d_s4_wormpot_second_changed 0x802aa498 : { *(.text.w3d_s4_wormpot_second_changed) }
  .text.w3d_s4_wormpot_third_changed 0x802aa544 : { *(.text.w3d_s4_wormpot_third_changed) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
