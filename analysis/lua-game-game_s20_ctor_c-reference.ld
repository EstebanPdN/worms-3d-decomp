/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_construct_header_801b440c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_80414488 = 0x80414488;
lbl_804144b0 = 0x804144b0;
SECTIONS {
  .text.w3d_s20_construct_header_801b440c 0x801b440c : { *(.text.w3d_s20_construct_header_801b440c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
