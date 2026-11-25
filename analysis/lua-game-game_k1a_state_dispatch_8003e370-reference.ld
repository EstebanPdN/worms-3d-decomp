/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(k1a_state_dispatch_8003e370)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
k1a_fn_8003ed10 = 0x8003ed10;
SECTIONS {
  .text.k1a_state_dispatch_8003e370 0x8003e370 : { *(.text.k1a_state_dispatch_8003e370) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
