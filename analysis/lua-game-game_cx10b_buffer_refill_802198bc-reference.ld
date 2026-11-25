/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx10b_buffer_refill_802198bc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
allocate_801fe2a8 = 0x801fe2a8;
SECTIONS {
  .text.w3d_cx10b_buffer_refill_802198bc 0x802198bc : { *(.text.w3d_cx10b_buffer_refill_802198bc) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
