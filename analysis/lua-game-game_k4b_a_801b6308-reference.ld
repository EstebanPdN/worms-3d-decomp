/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k4b_textured_box_construct_801b6308)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_80415a78 = 0x80415a78;
w3d_k4b_box_construct_801b5b30 = 0x801b5b30;
SECTIONS {
  .text.w3d_k4b_textured_box_construct_801b6308 0x801b6308 : { *(.text.w3d_k4b_textured_box_construct_801b6308) }
  .sdata 0x804b05a8 (NOLOAD) : {
    . = 0x0; lbl_804b05a8 = .;
    . = 0x8; lbl_804b05b0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
