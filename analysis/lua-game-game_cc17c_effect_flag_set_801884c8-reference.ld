/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc17c_effect_flag_set_801884c8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801d4544 = 0x801d4544;
SECTIONS {
  .text.w3d_cc17c_effect_flag_set_801884c8 0x801884c8 : { *(.text.w3d_cc17c_effect_flag_set_801884c8) }
  .sdata 0x804b0220 (NOLOAD) : {
    . = 0x0; lbl_804b0220 = .;
    . = 0x4; lbl_804b0224 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
