/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_describe_two_fields_801904c0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_803a8200 = 0x803a8200;
lbl_803a820c = 0x803a820c;
lbl_803a84bc = 0x803a84bc;
lbl_803a84c0 = 0x803a84c0;
SECTIONS {
  .text.w3d_s20_describe_two_fields_801904c0 0x801904c0 : { *(.text.w3d_s20_describe_two_fields_801904c0) }
  .text.w3d_s20_find_float_epsilon_80196668 0x80196668 : { *(.text.w3d_s20_find_float_epsilon_80196668) }
  .sdata 0x804ab6e4 (NOLOAD) : {
    . = 0x0; lbl_804ab6e4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
