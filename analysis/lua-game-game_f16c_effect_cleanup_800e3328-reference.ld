/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f16c_effect_cleanup_800e3328)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
arrayfree_801fe240 = 0x801fe240;
SECTIONS {
  .text.f16c_effect_cleanup_800e3328 0x800e3328 : { *(.text.f16c_effect_cleanup_800e3328) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; context_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
