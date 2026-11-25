/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_advance_by_weight_800179ac)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_80017380 = 0x80017380;
SECTIONS {
  .text.s19_advance_by_weight_800179ac 0x800179ac : { *(.text.s19_advance_by_weight_800179ac) }
  .rodata 0x8036a7e8 : { *(.rodata) }
  .sdata 0x804aa750 (NOLOAD) : {
    . = 0x0; lbl_804aa750 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
