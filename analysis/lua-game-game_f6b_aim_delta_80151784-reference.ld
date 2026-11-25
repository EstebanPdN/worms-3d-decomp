/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f6b_aim_delta_80151784)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
allocate_801613f0 = 0x801613f0;
atan_802e7e5c = 0x802e7e5c;
construct_80131b50 = 0x80131b50;
high_803a1930 = 0x803a1930;
low_803a1928 = 0x803a1928;
mode_800154e0 = 0x800154e0;
one_803a1924 = 0x803a1924;
period_803a192c = 0x803a192c;
post_8016239c = 0x8016239c;
reset_8015286c = 0x8015286c;
threshold_803a1934 = 0x803a1934;
zero_803a1920 = 0x803a1920;
SECTIONS {
  .text.f6b_aim_delta_80151784 0x80151784 : { *(.text.f6b_aim_delta_80151784) }
  .sdata 0x804b1754 (NOLOAD) : {
    . = 0x0; queue_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
