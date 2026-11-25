/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d25g_body_bounce_8004ce58)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
rest_8043ae20 = 0x8043ae20;
settle_8004b8f4 = 0x8004b8f4;
sqrt_802e82c0 = 0x802e82c0;
zero_8045e788 = 0x8045e788;
SECTIONS {
  .text.w3d_d25g_body_bounce_8004ce58 0x8004ce58 : { *(.text.w3d_d25g_body_bounce_8004ce58) }
  .rodata 0x80377424 : { *(.rodata) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; game_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
