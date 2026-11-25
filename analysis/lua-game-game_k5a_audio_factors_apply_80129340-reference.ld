/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(k5a_audio_factors_apply_80129340)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_800fc270 = 0x800fc270;
w3d_f32_8039c93c = 0x8039c93c;
w3d_f32_8039c940 = 0x8039c940;
w3d_string_8039c8fc = 0x8039c8fc;
w3d_string_8039c914 = 0x8039c914;
w3d_string_8039c928 = 0x8039c928;
SECTIONS {
  .text.k5a_audio_factors_apply_80129340 0x80129340 : { *(.text.k5a_audio_factors_apply_80129340) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; w3d_audio_context_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
