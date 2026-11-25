/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc18b_register_array_8025011c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e8d9c = 0x801e8d9c;
fn_801eff8c = 0x801eff8c;
lbl_803c59c0 = 0x803c59c0;
lbl_80401090 = 0x80401090;
lbl_8045e004 = 0x8045e004;
lbl_8046501c = 0x8046501c;
memset = 0x802eefe0;
SECTIONS {
  .text.w3d_cc18b_register_array_8025011c 0x8025011c : { *(.text.w3d_cc18b_register_array_8025011c) }
  .sdata 0x804b0900 (NOLOAD) : {
    . = 0x0; lbl_804b0900 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
