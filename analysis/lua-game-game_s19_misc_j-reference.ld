/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_try_two_checks_80009a94)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_80009b04 = 0x80009b04;
FUN_80009f08 = 0x80009f08;
FUN_8000affc = 0x8000affc;
FUN_8001b660 = 0x8001b660;
SECTIONS {
  .text.s19_try_two_checks_80009a94 0x80009a94 : { *(.text.s19_try_two_checks_80009a94) }
  .text.s19_apply_scaled_length_8000d004 0x8000d004 : { *(.text.s19_apply_scaled_length_8000d004) }
  .sdata 0x804aa6d8 (NOLOAD) : {
    . = 0x0; lbl_804aa6d8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
