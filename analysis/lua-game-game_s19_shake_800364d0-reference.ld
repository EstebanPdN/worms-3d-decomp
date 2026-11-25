/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_update_shake_800364d0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_8003671c = 0x8003671c;
s8_property_write_800fc43c = 0x800fc43c;
w3d_auto_80036abc = 0x80036abc;
SECTIONS {
  .text.s19_update_shake_800364d0 0x800364d0 : { *(.text.s19_update_shake_800364d0) }
  .rodata 0x80373c94 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
