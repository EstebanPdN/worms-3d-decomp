/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_802661ac)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8026710C = 0x8026710c;
fn_802B0990 = 0x802b0990;
fn_802B1258 = 0x802b1258;
SECTIONS {
  .text.w3d_auto_802661ac 0x802661ac : { *(.text.w3d_auto_802661ac) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
