/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k3b_math_lanczos3_801d6b7c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_math_sinc_801d6b24 = 0x801d6b24;
SECTIONS {
  .text.w3d_k3b_math_lanczos3_801d6b7c 0x801d6b7c : { *(.text.w3d_k3b_math_lanczos3_801d6b7c) }
  .rodata 0x803af678 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
