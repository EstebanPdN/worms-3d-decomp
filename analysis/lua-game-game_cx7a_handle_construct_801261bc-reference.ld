/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx7a_handle_construct_801261bc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
allocate_8003f400 = 0x8003f400;
bounds_8003fa2c = 0x8003fa2c;
slot_8003fbb8 = 0x8003fbb8;
SECTIONS {
  .text.w3d_cx7a_handle_construct_801261bc 0x801261bc : { *(.text.w3d_cx7a_handle_construct_801261bc) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
