/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(sol35e5b_ldexp_802e77f4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
sol35e5b_errno_802eafc4 = 0x802eafc4;
sol35e5b_finite_802e8a08 = 0x802e8a08;
sol35e5b_scalbn_802e8a28 = 0x802e8a28;
SECTIONS {
  .text.sol35e5b_ldexp_802e77f4 0x802e77f4 : { *(.text.sol35e5b_ldexp_802e77f4) }
  .sdata 0x804ac118 (NOLOAD) : {
    . = 0x0; sol35e5b_zero_804ac118 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
