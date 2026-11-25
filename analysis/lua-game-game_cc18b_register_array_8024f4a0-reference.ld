/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc18b_register_array_8024f4a0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e8d9c = 0x801e8d9c;
fn_801eff8c = 0x801eff8c;
lbl_803c5614 = 0x803c5614;
lbl_80401060 = 0x80401060;
lbl_8045e004 = 0x8045e004;
lbl_80464fe0 = 0x80464fe0;
memset = 0x802eefe0;
SECTIONS {
  .text.w3d_cc18b_register_array_8024f4a0 0x8024f4a0 : { *(.text.w3d_cc18b_register_array_8024f4a0) }
  .sdata 0x804b08f4 (NOLOAD) : {
    . = 0x0; lbl_804b08f4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
