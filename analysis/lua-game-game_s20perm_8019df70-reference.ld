/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_8019df70)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802CD808 = 0x802cd808;
fn_802CD9E8 = 0x802cd9e8;
fn_802CDFD4 = 0x802cdfd4;
fn_802CE264 = 0x802ce264;
fn_802CE6E4 = 0x802ce6e4;
SECTIONS {
  .text.w3d_auto_8019df70 0x8019df70 : { *(.text.w3d_auto_8019df70) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
