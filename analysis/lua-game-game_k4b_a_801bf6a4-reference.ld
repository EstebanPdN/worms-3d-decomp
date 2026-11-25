/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k4b_placement_construct_801bf6a4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_80414f60 = 0x80414f60;
lbl_8045e708 = 0x8045e708;
w3d_k4b_named_color_construct_801b4bcc = 0x801b4bcc;
SECTIONS {
  .text.w3d_k4b_placement_construct_801bf6a4 0x801bf6a4 : { *(.text.w3d_k4b_placement_construct_801bf6a4) }
  .rodata 0x803abf80 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
