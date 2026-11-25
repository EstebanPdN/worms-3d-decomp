/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(terra_only_c7_registry_801fca98)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801fc7b0 = 0x801fc7b0;
fn_80200af8 = 0x80200af8;
lbl_803b1d2c = 0x803b1d2c;
lbl_8045e890 = 0x8045e890;
lbl_8045e92c = 0x8045e92c;
lbl_80463308 = 0x80463308;
SECTIONS {
  .text.terra_only_c7_registry_801fca98 0x801fca98 : { *(.text.terra_only_c7_registry_801fca98) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
