/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx11b_string_uppercase_8020c2e8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
allocate_8020bc88 = 0x8020bc88;
classes_803db449 = 0x803db449;
release_8020bb2c = 0x8020bb2c;
SECTIONS {
  .text.w3d_cx11b_string_uppercase_8020c2e8 0x8020c2e8 : { *(.text.w3d_cx11b_string_uppercase_8020c2e8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
