/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k3b_tagged_construct_80207fec)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_vtable_80419238 = 0x80419238;
w3d_vtable_80419268 = 0x80419268;
SECTIONS {
  .text.w3d_k3b_tagged_construct_80207fec 0x80207fec : { *(.text.w3d_k3b_tagged_construct_80207fec) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
