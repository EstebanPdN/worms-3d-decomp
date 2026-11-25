/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k4b_named_links_construct_801c9b74)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_80416320 = 0x80416320;
w3d_k4b_named_construct_801c90c0 = 0x801c90c0;
SECTIONS {
  .text.w3d_k4b_named_links_construct_801c9b74 0x801c9b74 : { *(.text.w3d_k4b_named_links_construct_801c9b74) }
  .rodata 0x803ad908 : { *(.rodata) }
  .sdata 0x804b05ac (NOLOAD) : {
    . = 0x0; lbl_804b05ac = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
