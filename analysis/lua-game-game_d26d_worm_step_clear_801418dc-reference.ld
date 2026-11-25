/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d26d_worm_step_clear_801418dc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
corners_80453030 = 0x80453030;
reference_8045e788 = 0x8045e788;
test_800b0824 = 0x800b0824;
SECTIONS {
  .text.d26d_worm_step_clear_801418dc 0x801418dc : { *(.text.d26d_worm_step_clear_801418dc) }
  .rodata 0x803a0478 : { *(.rodata) }
  .sdata 0x804ab3d0 (NOLOAD) : {
    . = 0x0; edges_804ab3d0 = .;
    . = 0x6394; traceFrac_804b1764 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
