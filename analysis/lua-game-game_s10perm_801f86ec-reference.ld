/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_801f86ec)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801F8F68 = 0x801f8f68;
fn_801F9164 = 0x801f9164;
fn_801FE1D8 = 0x801fe1d8;
SECTIONS {
  .text.w3d_auto_801f86ec 0x801f86ec : { *(.text.w3d_auto_801f86ec) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
