/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_trace_stub_80347324)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.w3d_trace_stub_80347324 0x80347324 : { *(.text.w3d_trace_stub_80347324) }
  .text.w3d_block_owner_set_80348764 0x80348764 : { *(.text.w3d_block_owner_set_80348764) }
  .text.w3d_bits_assign_8034bef8 0x8034bef8 : { *(.text.w3d_bits_assign_8034bef8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
