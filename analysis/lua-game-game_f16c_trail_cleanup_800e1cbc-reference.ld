/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f16c_trail_cleanup_800e1cbc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
arrayfree_801fe240 = 0x801fe240;
base_800df684 = 0x800df684;
lookup_80164fc8 = 0x80164fc8;
mark_80122af8 = 0x80122af8;
type_803613b0 = 0x803613b0;
SECTIONS {
  .text.f16c_trail_cleanup_800e1cbc 0x800e1cbc : { *(.text.f16c_trail_cleanup_800e1cbc) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
