/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d26d_worm_ground_normal_8014157c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
corners_80453030 = 0x80453030;
reference_8045e788 = 0x8045e788;
rotation_801f725c = 0x801f725c;
sqrt_802e82c0 = 0x802e82c0;
test_800b0824 = 0x800b0824;
SECTIONS {
  .text.d26d_worm_ground_normal_8014157c 0x8014157c : { *(.text.d26d_worm_ground_normal_8014157c) }
  .rodata 0x803a0460 : { *(.rodata) }
  .sdata 0x804b1764 (NOLOAD) : {
    . = 0x0; traceFrac_804b1764 = .;
    . = 0xac; traceDone_804b1810 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
