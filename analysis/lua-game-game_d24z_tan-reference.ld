/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24z_tan_802e795c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d24z_ieee754_rem_pio2_802e9134 = 0x802e9134;
d24z_kernel_tan_802e8ed8 = 0x802e8ed8;
SECTIONS {
  .text.w3d_d24z_tan_802e795c 0x802e795c : { *(.text.w3d_d24z_tan_802e795c) }
  .sdata 0x804ac128 (NOLOAD) : {
    . = 0x0; d24z_lit_d_0_804ac128 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
