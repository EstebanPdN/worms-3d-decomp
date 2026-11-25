/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx9c_cosf_802e86d4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cx9c_cos_kernel_802e9498 = 0x802e9498;
cx9c_reduce_802e9ad0 = 0x802e9ad0;
cx9c_sin_kernel_802e9580 = 0x802e9580;
SECTIONS {
  .text.w3d_cx9c_cosf_802e86d4 0x802e86d4 : { *(.text.w3d_cx9c_cosf_802e86d4) }
  .sdata 0x804ac2dc (NOLOAD) : {
    . = 0x0; cx9c_zero_804ac2dc = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
