/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24z_sin_802e787c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d24z_ieee754_rem_pio2_802e9134 = 0x802e9134;
d24z_kernel_cos_802e8d38 = 0x802e8d38;
d24z_kernel_sin_802e8e2c = 0x802e8e2c;
SECTIONS {
  .text.w3d_d24z_sin_802e787c 0x802e787c : { *(.text.w3d_d24z_sin_802e787c) }
  .sdata 0x804ac120 (NOLOAD) : {
    . = 0x0; d24z_lit_d_0_804ac120 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
