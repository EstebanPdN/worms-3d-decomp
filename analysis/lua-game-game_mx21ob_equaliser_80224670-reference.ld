/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(__15Mx21obEqualiserUs)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__12Mx21obWidgetUs = 0x8021ef08;
_vt.15Mx21obEqualiser = 0x8041a398;
w3d_empty_string_804b06a0 = 0x804b06a0;
w3d_string_base_init = 0x8020c5c0;
w3d_string_from_text = 0x8020bb54;
w3d_string_header = 0x80341884;
w3d_text_fe_button_pattern_803b61f8 = 0x803b61f8;
SECTIONS {
  .text.__15Mx21obEqualiserUs 0x80224670 : { *(.text.__15Mx21obEqualiserUs) }
  .rodata 0x803b78bc : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
