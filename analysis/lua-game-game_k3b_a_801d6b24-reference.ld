/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k3b_math_sinc_801d6b24)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_math_sinf_802e88ac = 0x802e88ac;
SECTIONS {
  .text.w3d_k3b_math_sinc_801d6b24 0x801d6b24 : { *(.text.w3d_k3b_math_sinc_801d6b24) }
  .rodata 0x803af66c : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
