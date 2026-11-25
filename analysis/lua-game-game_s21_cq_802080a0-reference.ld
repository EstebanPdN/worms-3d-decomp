/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_refill_802080a0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8020810c = 0x8020810c;
fn_8020b884 = 0x8020b884;
SECTIONS {
  .text.w3d_s21_refill_802080a0 0x802080a0 : { *(.text.w3d_s21_refill_802080a0) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
