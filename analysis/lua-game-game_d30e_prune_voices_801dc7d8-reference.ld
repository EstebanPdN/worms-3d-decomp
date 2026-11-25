/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d30e_prune_voices_801dc7d8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_._4Gain = 0x801daf5c;
f4c_erase_80210dd8 = 0x80210dd8;
w3d_r25b_step_gain_801db06c = 0x801db06c;
SECTIONS {
  .text.w3d_d30e_prune_voices_801dc7d8 0x801dc7d8 : { *(.text.w3d_d30e_prune_voices_801dc7d8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
