/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d25h_jet_sound_800aec68)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80178df0 = 0x80178df0;
SECTIONS {
  .text.w3d_d25h_jet_sound_800aec68 0x800aec68 : { *(.text.w3d_d25h_jet_sound_800aec68) }
  .rodata 0x803821e8 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
