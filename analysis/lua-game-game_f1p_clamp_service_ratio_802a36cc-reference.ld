/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_clamp_service_ratio_802a36cc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8015ae3c = 0x8015ae3c;
fn_8018b4cc = 0x8018b4cc;
fn_8034435c = 0x8034435c;
zero_803d2e38 = 0x803d2e38;
SECTIONS {
  .text.w3d_clamp_service_ratio_802a36cc 0x802a36cc : { *(.text.w3d_clamp_service_ratio_802a36cc) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
