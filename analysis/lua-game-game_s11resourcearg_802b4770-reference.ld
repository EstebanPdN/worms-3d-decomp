/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_802b4770)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802B0990 = 0x802b0990;
fn_802B1258 = 0x802b1258;
fn_802B4D58 = 0x802b4d58;
SECTIONS {
  .text.w3d_auto_802b4770 0x802b4770 : { *(.text.w3d_auto_802b4770) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
