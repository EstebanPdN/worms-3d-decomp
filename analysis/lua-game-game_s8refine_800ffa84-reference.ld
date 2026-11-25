/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_recovered_800ffa84)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800FE820 = 0x800fe820;
fn_80160038 = 0x80160038;
lbl_80361050 = 0x80361050;
lbl_803617D0 = 0x803617d0;
lbl_803E838C = 0x803e838c;
SECTIONS {
  .text.s8_recovered_800ffa84 0x800ffa84 : { *(.text.s8_recovered_800ffa84) }
  .sdata 0x804af158 (NOLOAD) : {
    . = 0x0; lbl_804AF15A = .;
    . = 0x1; lbl_804AF159 = .;
    . = 0x2; lbl_804AF158 = .;
    . = 0x3; lbl_804AF15B = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
