/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d25d_worm_turn_step_8014b6b0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
context_80165254 = 0x80165254;
move_800b0824 = 0x800b0824;
react_80149348 = 0x80149348;
SECTIONS {
  .text.d25d_worm_turn_step_8014b6b0 0x8014b6b0 : { *(.text.d25d_worm_turn_step_8014b6b0) }
  .rodata 0x803a13f8 : { *(.rodata) }
  .sdata 0x804b1764 (NOLOAD) : {
    . = 0x0; contacts_804b1764 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
