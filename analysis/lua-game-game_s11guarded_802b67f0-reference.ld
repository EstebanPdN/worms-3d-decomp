/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_802b67f0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80296518 = 0x80296518;
fn_802B0990 = 0x802b0990;
fn_802B1258 = 0x802b1258;
fn_802B6EFC = 0x802b6efc;
fn_802B8418 = 0x802b8418;
fn_802BC8B4 = 0x802bc8b4;
SECTIONS {
  .text.w3d_auto_802b67f0 0x802b67f0 : { *(.text.w3d_auto_802b67f0) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
