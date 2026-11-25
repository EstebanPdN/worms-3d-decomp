/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_dispatch_by_kind_80168c08)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.w3d_dispatch_by_kind_80168c08 0x80168c08 : { *(.text.w3d_dispatch_by_kind_80168c08) }
  .text.w3d_dispatch_by_kind_801ac49c 0x801ac49c : { *(.text.w3d_dispatch_by_kind_801ac49c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
