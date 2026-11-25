/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k4b_mapped_box_construct_801c1864)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_80414da8 = 0x80414da8;
w3d_k4b_box_construct_801b5b30 = 0x801b5b30;
SECTIONS {
  .text.w3d_k4b_mapped_box_construct_801c1864 0x801c1864 : { *(.text.w3d_k4b_mapped_box_construct_801c1864) }
  .sdata 0x804b05a8 (NOLOAD) : {
    . = 0x0; lbl_804b05a8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
