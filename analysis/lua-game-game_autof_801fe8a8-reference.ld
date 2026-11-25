/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_801fe8a8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8020D8F8 = 0x8020d8f8;
fn_802ED89C = 0x802ed89c;
SECTIONS {
  .text.w3d_auto_801fe8a8 0x801fe8a8 : { *(.text.w3d_auto_801fe8a8) }
  .text.w3d_auto_801fe910 0x801fe910 : { *(.text.w3d_auto_801fe910) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
